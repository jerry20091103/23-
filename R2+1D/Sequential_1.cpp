#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Sequential_1(float* X_data, float* Kernel_1_data, float* Kernel_2_data, float* Kernel_3_data, float* Kernel_4_data)
{
 #ifdef __SYNTHESIS__
    float X_tmp_data[200704];
 #else
    float* X_tmp_data = (float*)malloc(200704*sizeof(float));
 #endif
 
    for(int i = 0; i< 200704; i++)
        X_tmp_data[i] = X_data[i];

    int X_num[5] = {1, 64, 1, 56, 56};
    for(int t = 0; t < 3; t++){
        Conv2Plus1D(X_data, X_num, X_data, 64, 144, Kernel_1_data, Kernel_2_data, 1, 0) // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes);
        BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
        ReLU(X_data, X_num);

        Conv2Plus1D(X_data, X_num, Y_data, Y_num, Kernel_3_data, Kernel_4_data, 1, 0);
        BatchNorm3d(X_data, X_num, 0.00001, 1, 0);

        for(int i = 0; i < 200704; i++)
            X_data[i] += X_tmp_data[i];
        
        ReLU(X_data, X_num);
    }
        
        // out = nn.Sequential(
        //     Conv2Plus1D(inplanes, planes, midplanes, stride), nn.BatchNorm3d(planes), nn.ReLU(inplace=True)
        // )
        // out = nn.Sequential(Conv2Plus1D(planes, planes, midplanes), nn.BatchNorm3d(planes))
        // out += (downsample) ? downsample : x
        // out = nn.ReLU(inplace=True)
    return;

        // layer1 = BasicBlock(64, 64, Conv2Plus1D, 1, None)
        //          BasicBlock(64, 64, Conv2Plus1D)
        //          BasicBlock(64, 64, Conv2Plus1D)
        //
        // layer2 = BasicBlock(64, 128, Conv2Plus1D, 2, nn.Sequential(
        //                                             nn.Conv3d(self.inplanes, planes, kernel_size=1, stride={stride, stride, stride}),
        //                                             nn.BatchNorm3d(planes),
        //                                         ))
        //          BasicBlock(128, 128, Conv2Plus1D)
        //          BasicBlock(128, 128, Conv2Plus1D)
        //
        // layer3 = BasicBlock(128, 256, Conv2Plus1D, 2, nn.Sequential(
        //                                             nn.Conv3d(self.inplanes, planes, kernel_size=1, stride={stride, stride, stride}),
        //                                             nn.BatchNorm3d(planes),
        //                                         ))
        //          BasicBlock(256, 256, Conv2Plus1D)
        //          BasicBlock(256, 256, Conv2Plus1D)
        //
        // layer4 = BasicBlock(256, 512, Conv2Plus1D, 2, nn.Sequential(
        //                                             nn.Conv3d(self.inplanes, planes, kernel_size=1, stride={stride, stride, stride}),
        //                                             nn.BatchNorm3d(planes),
        //                                         ))
        //          BasicBlock(512, 512, Conv2Plus1D)
        //          BasicBlock(512, 512, Conv2Plus1D)
        //
        // =============================================================================
        //
        // self.conv1 = nn.Sequential(
        //     conv_builder(inplanes, planes, midplanes, stride), nn.BatchNorm3d(planes), nn.ReLU(inplace=True)
        // )
        // self.conv2 = nn.Sequential(conv_builder(planes, planes, midplanes), nn.BatchNorm3d(planes))
        // out += (downsample) ? downsample : x
        // self.relu = nn.ReLU(inplace=True)