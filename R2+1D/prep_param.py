import cv2
import os
import torch
import torch.nn as nn
import numpy as np
import argparse
import logging
import zipfile

from tqdm import tqdm
from torchvision import models
from torchvision import transforms
from torch.utils.data import DataLoader

from utils.sample import linspace_sampling
from dataset import EgoGestureDataset
from torch.quantization import QuantStub, DeQuantStub
import torch.quantization
from torchinfo import summary
from torch import Tensor
from functools import partial

def parse_opts():
    parser = argparse.ArgumentParser()
    parser.add_argument('--model_path', type=str,
                        default='./weights/16_r2plus1d_18_egogesture_10cls.pt')
    parser.add_argument('--n_frame', type=int, default=16)
    parser.add_argument('--device', type=str, default='cuda')
    parser.add_argument('--half', action='store_true')

    args = parser.parse_args()

    return args


def accuracy(output, target, topk=(1,)):
    """
    Computes the accuracy over the k top predictions for the specified values of k
    In top-5 accuracy you give yourself credit for having the right answer
    if the right answer appears in your top five guesses.
    """
    with torch.no_grad():
        maxk = max(topk)
        batch_size = target.size(0)
        _, pred = output.topk(maxk, 1, True, True)
        pred = pred.t()
        correct = (pred == target.unsqueeze(dim=0)).expand_as(pred)

        res = []
        for k in topk:
            correct_k = correct[:k].reshape(-1).float().sum(0, keepdim=True)
            res.append(correct_k)
        return res

def forward(self, x: Tensor) -> Tensor:
    x = self.quant(x)
    x = self.stem(x)
    x = self.layer1(x)
    x = self.layer2(x)
    x = self.layer3(x)
    x = self.layer4(x)

    x = self.avgpool(x)

    x = x.flatten(1)
    x = self.fc(x)
    x = self.dequant(x)
    return x

def print_model_size(mdl):
    torch.save(mdl.state_dict(), "tmp.pt")
    print("%.2f MB" %(os.path.getsize("tmp.pt")/1e6))
    os.remove('tmp.pt')

def load_model(model_path, device):

    model = models.video.r2plus1d_18(pretrained=True)
    model.fc = nn.Sequential(
        nn.Dropout(0.5),
        nn.Linear(model.fc.in_features, 10, bias=True)
    )

    model.quant = torch.quantization.QuantStub()
    model.dequant = torch.quantization.DeQuantStub()
    model.load_state_dict(torch.load(model_path, map_location=torch.device('cpu'))['state_dict'])

    model.forward = partial(forward, model)
    if args.half:
        model = model.half()
    model.to(device)
    model.eval()
    print("original model size: ",end = "")
    print_model_size(model)
    torch.ao.quantization.fuse_modules(model, [["stem.0", "stem.1","stem.2" ],["stem.3", "stem.4","stem.5" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer1.0.conv1.0.0", "layer1.0.conv1.0.1","layer1.0.conv1.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer1.0.conv2.0.0", "layer1.0.conv2.0.1","layer1.0.conv2.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer1.1.conv1.0.0", "layer1.1.conv1.0.1","layer1.1.conv1.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer1.1.conv2.0.0", "layer1.1.conv2.0.1","layer1.1.conv2.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer2.0.conv1.0.0", "layer2.0.conv1.0.1","layer2.0.conv1.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer2.0.conv2.0.0", "layer2.0.conv2.0.1","layer2.0.conv2.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer2.0.downsample.0", "layer2.0.downsample.1" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer2.1.conv1.0.0", "layer2.1.conv1.0.1","layer2.1.conv1.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer2.1.conv2.0.0", "layer2.1.conv2.0.1","layer2.1.conv2.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer3.0.conv1.0.0", "layer3.0.conv1.0.1","layer3.0.conv1.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer3.0.conv2.0.0", "layer3.0.conv2.0.1","layer3.0.conv2.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer3.0.downsample.0", "layer3.0.downsample.1" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer3.1.conv1.0.0", "layer3.1.conv1.0.1","layer3.1.conv1.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer3.1.conv2.0.0", "layer3.1.conv2.0.1","layer3.1.conv2.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer4.0.conv1.0.0", "layer4.0.conv1.0.1","layer4.0.conv1.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer4.0.conv2.0.0", "layer4.0.conv2.0.1","layer4.0.conv2.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer4.0.downsample.0", "layer4.0.downsample.1" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer4.1.conv1.0.0", "layer4.1.conv1.0.1","layer4.1.conv1.0.2" ]], inplace=True)
    torch.ao.quantization.fuse_modules(model, [["layer4.1.conv2.0.0", "layer4.1.conv2.0.1","layer4.1.conv2.0.2" ]], inplace=True)
    


    model.qconfig = torch.quantization.get_default_qconfig('fbgemm')
    model_prepared = torch.quantization.prepare(model)

    return model_prepared

def visualizeActivations(module, input, output):
    if module.profile_activations == True:
        module.inAct = input[0].cpu().reshape(-1)
        module.outAct = output[0].cpu().reshape(-1)

def loadvideo(video, transform):
    capture = cv2.VideoCapture(video)
    original_frame_count = int(capture.get(cv2.CAP_PROP_FRAME_COUNT))

    # Sampling
    frame_indices = linspace_sampling(original_frame_count, args.n_frame)
    buffer = torch.zeros((args.n_frames, 3, 112, 112))

    for i, v in enumerate(frame_indices):
        capture.set(cv2.CAP_PROP_POS_FRAMES, v)
        _, frame = capture.read()
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        frame = transform(frame)
        buffer[i] = frame

    capture.release()

    # convert from [D, H, W, C] format to [C, D, H, W] (what PyTorch uses)
    # D = Depth (in this case, time), H = Height, W = Width, C = Channels
    buffer = buffer.permute((1, 0, 2, 3))

    return buffer


# Used Variable
top1_correct = 0
top5_correct = 0

# Args
args = parse_opts()
print(args)

# Logger
SAVE_FOLDER = './eval/'
if not os.path.exists(SAVE_FOLDER):
    os.mkdir(SAVE_FOLDER)
logging.basicConfig(filename=SAVE_FOLDER+'eval.log',
                    level=logging.INFO, format='%(asctime)s %(message)s')

# Device
device = torch.device(args.device)
print("Device: ", device)

# Define Transform
transform = transforms.Compose([
    transforms.ToPILImage(),
    transforms.Resize((112, 112)),
    transforms.ToTensor(),
    transforms.Normalize((0.485, 0.456, 0.406), (0.229, 0.224, 0.225))
])

# Define Dataset and Dataloader
test_subset = EgoGestureDataset(
    split='test',
    clip_len=args.n_frame,
    transform=transform
)

test_loader = DataLoader(
    dataset=test_subset,
    shuffle=False,
    batch_size=1
)


FILE = "model_quantized.pt"

#save model
model = models.video.r2plus1d_18(pretrained=True)
model.fc = nn.Sequential(
    nn.Dropout(0.5),
    nn.Linear(model.fc.in_features, 10, bias=True)
)

model.quant = torch.quantization.QuantStub()
model.dequant = torch.quantization.DeQuantStub()
model.load_state_dict(torch.load('./weights/16_r2plus1d_18_egogesture_10cls.pt', map_location=torch.device('cpu'))['state_dict'])

model.forward = partial(forward, model)
if args.half:
    model = model.half()
model.to(device)

model.eval()


"""
torch.ao.quantization.fuse_modules(model, [["stem.0", "stem.1","stem.2" ],["stem.3", "stem.4","stem.5" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer1.0.conv1.0.0", "layer1.0.conv1.0.1","layer1.0.conv1.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer1.0.conv2.0.0", "layer1.0.conv2.0.1","layer1.0.conv2.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer1.1.conv1.0.0", "layer1.1.conv1.0.1","layer1.1.conv1.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer1.1.conv2.0.0", "layer1.1.conv2.0.1","layer1.1.conv2.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer2.0.conv1.0.0", "layer2.0.conv1.0.1","layer2.0.conv1.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer2.0.conv2.0.0", "layer2.0.conv2.0.1","layer2.0.conv2.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer2.0.downsample.0", "layer2.0.downsample.1" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer2.1.conv1.0.0", "layer2.1.conv1.0.1","layer2.1.conv1.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer2.1.conv2.0.0", "layer2.1.conv2.0.1","layer2.1.conv2.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer3.0.conv1.0.0", "layer3.0.conv1.0.1","layer3.0.conv1.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer3.0.conv2.0.0", "layer3.0.conv2.0.1","layer3.0.conv2.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer3.0.downsample.0", "layer3.0.downsample.1" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer3.1.conv1.0.0", "layer3.1.conv1.0.1","layer3.1.conv1.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer3.1.conv2.0.0", "layer3.1.conv2.0.1","layer3.1.conv2.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer4.0.conv1.0.0", "layer4.0.conv1.0.1","layer4.0.conv1.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer4.0.conv2.0.0", "layer4.0.conv2.0.1","layer4.0.conv2.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer4.0.downsample.0", "layer4.0.downsample.1" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer4.1.conv1.0.0", "layer4.1.conv1.0.1","layer4.1.conv1.0.2" ]], inplace=True)
torch.ao.quantization.fuse_modules(model, [["layer4.1.conv2.0.0", "layer4.1.conv2.0.1","layer4.1.conv2.0.2" ]], inplace=True)
"""
model.qconfig = torch.quantization.get_default_qconfig('fbgemm')
model_prepared = torch.quantization.prepare(model)
model_load = torch.quantization.convert(model_prepared)
model_load.load_state_dict(torch.load(FILE))

print(model)
###activation
test_subset = EgoGestureDataset(
    split='test',
    clip_len=args.n_frame,
    transform=transform
)

test_loader = DataLoader(
    dataset=test_subset,
    shuffle=False,
    batch_size=1
)
#print(model_load)
########zip
zf = zipfile.ZipFile('parameters.zip', 'w', zipfile.ZIP_DEFLATED)


if not os.path.exists('./activations'):
    os.mkdir('./activations')
    
for i, sample in enumerate(tqdm(test_loader)):
    if i>30:break
    video_id = sample['rgb_id'][0]
    video = sample['video'].to(device)
    labels = sample['action'].to(device)
    class_num = sample['class'].to(device)

    if not os.path.exists('./activations/video{}'.format(video_id)):
        os.mkdir('./activations/video{}'.format(video_id))

    for name, model in model_load.named_children():
        model.profile_activations = True
        model.register_forward_hook(visualizeActivations)

    outputs = model_load(video)
    outputs = torch.nn.Softmax(dim=1)(outputs)
    _, preds = torch.max(outputs, 1)
    for name, model in model_load.named_children(): model.profile_activations = False
    
    np.savetxt('./activations/video{}/input.csv'.format(video_id), video.cpu().data.numpy().reshape(-1), delimiter=',')
    np.savetxt('./activations/video{}/output.csv'.format(video_id), preds.cpu().data.numpy().reshape(-1).astype(int), delimiter=',')
    zf.write('./activations/video{}/input.csv'.format(video_id))
    zf.write('./activations/video{}/output.csv'.format(video_id))
    
    for name, model in model_load.named_children():
        if not os.path.exists('./activations/video%s/%s' %(video_id, name)):
            os.mkdir('./activations/video%s/%s' %(video_id, name))
        if(model.inAct.type()== "torch.quantized.QInt8Tensor" or model.inAct.type()== "torch.quantized.QUInt8Tensor"):
            temp = model.inAct.cpu().int_repr()
            np.savetxt('./activations/video%s/%s/%s.csv' %(video_id, name, "input") , temp.cpu().numpy().reshape(-1).astype(int), delimiter=',')
        else:
            np.savetxt('./activations/video%s/%s/%s.csv' %(video_id, name, "input") , model.inAct.cpu().numpy().reshape(-1), delimiter=',')
        if(model.outAct.type()== "torch.quantized.QInt8Tensor" or model.outAct.type()== "torch.quantized.QUInt8Tensor"):
            temp = model.outAct.cpu().int_repr()
            np.savetxt('./activations/video%s/%s/%s.csv' %(video_id, name, "output") , temp.cpu().numpy().reshape(-1).astype(int), delimiter=',')
        else:
            np.savetxt('./activations/video%s/%s/%s.csv' %(video_id, name, "output") , model.outAct.cpu().numpy().reshape(-1), delimiter=',')
            
        zf.write('./activations/video%s/%s/%s.csv' %(video_id, name, "output"))
        zf.write('./activations/video%s/%s/%s.csv' %(video_id, name, "input"))
    

    

for name, weights in model_load.state_dict().items():
    name_split = name
    name = name.split('.')
    #name_split = name_split.replace('.', '/')
    print(name_split)
    print(name)
    #print(name, 'with shape:' , weights.shape)
    #print(weights.type())

    if(weights!= None):
        if(name[-2] != "_packed_params"):
            if not os.path.exists('./%s' %(name[-1])):
                os.mkdir('./%s' %(name[-1]))
            if(weights.type()== "torch.quantized.QInt8Tensor"):
                weights = weights.cpu().int_repr()
                np.savetxt('./%s/%s.csv' %(name[-1], name_split)  , weights.cpu().numpy().reshape(-1).astype(int), delimiter=',')
            else:
                np.savetxt('./%s/%s.csv' %(name[-1], name_split) , weights.cpu().numpy().reshape(-1).astype(float), delimiter=',')

            zf.write('./%s/%s.csv' %(name[-1], name_split))

zf.close()
