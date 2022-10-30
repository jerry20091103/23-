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


def load_model(model_path, device):

    model = models.video.r2plus1d_18(pretrained=True)
    model.fc = nn.Sequential(
        nn.Dropout(0.5),
        nn.Linear(model.fc.in_features, 10, bias=True)
    )

    #model.load_state_dict(torch.load(model_path)['state_dict'])
    model.load_state_dict(torch.load(model_path, map_location=torch.device('cpu'))['state_dict'])
# model.load_state_dict(torch.load(model_path)['state_dict'])

    # FP16
    if args.half:
        model = model.half()

    model.to(device)
    model.eval()

    return model


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

def visualizeActivations(layer, input, output):
    if layer.profile_activations == True:
        layer.inAct = input[0].cpu().reshape(-1)
        layer.outAct = output[0].cpu().reshape(-1)

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

# TODO: Define Model
ckpt_path = args.model_path
model = load_model(ckpt_path, device)

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

print("Start Evaluation")
logging.info("Start Evaluation")

zf = zipfile.ZipFile('parameters.zip', 'w', zipfile.ZIP_DEFLATED)

if not os.path.exists('./activations'):
    os.mkdir('./activations')


# Evaluation
for i, sample in enumerate(tqdm(test_loader)):
    if(i>0):break
    video_id = sample['rgb_id'][0]
    video = sample['video'].to(device)
    labels = sample['action'].to(device)
    class_num = sample['class'].to(device)
    
    if not os.path.exists('./activations/video%s' %(video_id)):
            os.mkdir('./activations/video%s' %(video_id))
    for name, layer in model.named_modules():
        layer.profile_activations = True
        layer.register_forward_hook(visualizeActivations)
        
    # Forward
    outputs = model(video)
    outputs = torch.nn.Softmax(dim=1)(outputs)
    _, preds = torch.max(outputs, 1)
    for name, layer in model.named_modules():
        layer.profile_activations = False
    
    np.savetxt('./activations/video{}/input.csv'.format(video_id), video.cpu().data.numpy().reshape(-1), delimiter=',')
    np.savetxt('./activations/video{}/output.csv'.format(video_id), preds.cpu().data.numpy().reshape(-1).astype(int), delimiter=',')
    zf.write('./activations/video{}/input.csv'.format(video_id))
    zf.write('./activations/video{}/output.csv'.format(video_id))
    
    for name, layer in model.named_modules():
        print(name)
        if not os.path.exists('./activations/video%s/%s' %(video_id, name)):
            os.mkdir('./activations/video%s/%s' %(video_id, name))
        name_split = name.split('.')
        
        if(layer.inAct!= None):
            if(layer.inAct.type()== "torch.quantized.QInt8Tensor" or layer.inAct.type()== "torch.quantized.QUInt8Tensor"):
                temp = layer.inAct.cpu().int_repr()
                np.savetxt('./activations/video%s/%s/%s.csv' %(video_id, name, "input") , temp.cpu().detach().numpy().reshape(-1).astype(int), delimiter=',')
            else:
                np.savetxt('./activations/video%s/%s/%s.csv' %(video_id, name, "input") , layer.inAct.cpu().detach().numpy().reshape(-1), delimiter=',')
            if(layer.outAct.type()== "torch.quantized.QInt8Tensor" or layer.outAct.type()== "torch.quantized.QUInt8Tensor"):
                temp = layer.outAct.cpu().int_repr()
                np.savetxt('./activations/video%s/%s/%s.csv' %(video_id, name, "output") , temp.cpu().detach().numpy().reshape(-1).astype(int), delimiter=',')
            else:
                np.savetxt('./activations/video%s/%s/%s.csv' %(video_id, name, "output") , layer.outAct.cpu().detach().numpy().reshape(-1), delimiter=',')
                
            zf.write('./activations/video%s/%s/%s.csv' %(video_id, name, "output"))
            zf.write('./activations/video%s/%s/%s.csv' %(video_id, name, "input"))

'''

for name, weights in model.state_dict().items():
    name_split = name
    name = name.split('.')
    if(weights!= None):
        if(name[-2] != "_packed_params"):
            if not os.path.exists('./%s' %(name[-1])):
                os.mkdir('./%s' %(name[-1]))
            np.savetxt('./%s/%s.csv' %(name[-1], name_split) , weights.cpu().numpy().reshape(-1).astype(float), delimiter=',')

            zf.write('./%s/%s.csv' %(name[-1], name_split))

'''
zf.close()

