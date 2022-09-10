# -*- coding: utf-8 -*-
"""R2_1D.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1yykTdfRAIax310-U8H79oBoeog8ToDSY
"""

import torch
import torchvision
import torch.nn as nn
import torch.nn.functional as F
from torchvision import transforms
from torchvision import models
import matplotlib.pyplot as plt
import numpy as np
from torch import optim
import pandas as pd
from torch.utils.data import Dataset,DataLoader,random_split
import os,cv2,glob
from PIL import Image,ImageSequence
from skimage import io
import skimage

test_array = torch.randn(1, 3, 1, 111, 111)

test_array_flat = torch.flatten(test_array)
np.savetxt('input.dat',test_array_flat, fmt='%f')

Conv3d1 = nn.Conv3d(3, 45, (1, 7, 7), stride=(1, 2, 2), padding=(0, 3, 3),bias=False)
Conv3d1output = Conv3d1(test_array)
print(Conv3d1.weight.shape)
Conv3d1weight_flat = torch.flatten(Conv3d1.weight).detach().numpy()
np.savetxt('Conv3d1weight.dat',Conv3d1weight_flat, fmt='%f')

Conv3d1output_flat = torch.flatten(Conv3d1output).detach().numpy()
np.savetxt('Conv3d1output.dat',Conv3d1output_flat, fmt='%f')

BatchNorm3d1 = nn.BatchNorm3d(45)
BatchNorm3d1output = BatchNorm3d1(Conv3d1output)
BatchNorm3d1output_flat = torch.flatten(BatchNorm3d1output).detach().numpy()
np.savetxt('BatchNorm3d1output.dat',BatchNorm3d1output_flat, fmt='%f')

ReLU = nn.ReLU(inplace=True)
ReLU1output = ReLU(BatchNorm3d1output)
ReLU1output_flat = torch.flatten(ReLU1output).detach().numpy()
np.savetxt('ReLU1output.txt',ReLU1output_flat, fmt='%f')

Conv3d2 = nn.Conv3d(45, 64, kernel_size=(3, 1, 1),stride=(1, 1, 1), padding=(1, 0, 0),bias=False)
Conv3d2weight_flat = torch.flatten(Conv3d2.weight).detach().numpy()
print(Conv3d2.weight.shape)
print(Conv3d2weight_flat.shape)
np.savetxt('Conv3d2weight.dat',Conv3d2weight_flat, fmt='%f')
Conv3d2output = Conv3d2(ReLU1output)
Conv3d2output_flat = torch.flatten(Conv3d2output).detach().numpy()
np.savetxt('Conv3d2output.dat',Conv3d2output_flat, fmt='%f')

BatchNorm3d2 = nn.BatchNorm3d(64)
BatchNorm3d2output = BatchNorm3d2(Conv3d2output)
BatchNorm3d2output_flat = torch.flatten(BatchNorm3d2output).detach().numpy()
np.savetxt('BatchNorm3d2output.dat',BatchNorm3d2output_flat, fmt='%f')

ReLU2output = ReLU(BatchNorm3d2output)
ReLU2output_flat = torch.flatten(ReLU2output).detach().numpy()
np.savetxt('ReLU2output.dat',ReLU2output_flat, fmt='%f')

