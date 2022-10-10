#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Sequential(float* X_data, float* Y_data, float* Kernel_1_1_data, float* Kernel_1_2_data, float* Kernel_1_3_data, float* Kernel_1_4_data, float* Kernel_1_5_data, float* Kernel_1_6_data, float* Kernel_1_7_data, float* Kernel_1_8_data, 
                    float* Kernel_2_1_data, float* Kernel_2_2_data, float* Kernel_2_3_data, float* Kernel_2_4_data, float* Kernel_2_5_data, float* Kernel_2_6_data, float* Kernel_2_7_data, float* Kernel_2_8_data, float* Kernel_2_9_data, 
                    float* Kernel_3_1_data, float* Kernel_3_2_data, float* Kernel_3_3_data, float* Kernel_3_4_data, float* Kernel_3_5_data, float* Kernel_3_6_data, float* Kernel_3_7_data, float* Kernel_3_8_data, float* Kernel_3_9_data, 
                    float* Kernel_4_1_data, float* Kernel_4_2_data, float* Kernel_4_3_data, float* Kernel_4_4_data, float* Kernel_4_5_data, float* Kernel_4_6_data, float* Kernel_4_7_data, float* Kernel_4_8_data, float* Kernel_4_9_data)
{
 #ifdef __SYNTHESIS__
    float X_tmp_data[200704];
    float X2_data[100352];
    float X2_tmp_data[100352];
    // float X3_data[50176];
    // float X3_tmp_data[50176];
    // float X4_data[25088];
    // float X4_tmp_data[25088];
 #else
    float* X_tmp_data = (float*)malloc(200704*sizeof(float));
    float* X2_data = (float*)malloc(100352*sizeof(float));
    float* X2_tmp_data = (float*)malloc(100352*sizeof(float));
    // float* X3_data = (float*)malloc(50176*sizeof(float));
    // float* X3_tmp_data = (float*)malloc(50176*sizeof(float));
    // float* X4_data = (float*)malloc(25088*sizeof(float));
    // float* X4_tmp_data = (float*)malloc(25088*sizeof(float));
 #endif

    int Kernel_num[3] = {1, 1, 1};
    int stride[3] = {2, 2, 2};
    int padding[3] = {0, 0, 0};

    // layer 1
    int X_num[5] = {1, 64, 1, 56, 56};

    // for(int i = 0; i < 200704; i++)
    //     X_tmp_data[i] = X_data[i];
    // Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_1_data, Kernel_1_2_data, 1, 1); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    // BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    // ReLU(X_data, X_num);
    // Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_3_data, Kernel_1_4_data, 1, 1);
    // BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    // for(int i = 0; i < 200704; i++)
    //     X_data[i] += X_tmp_data[i];
    // ReLU(X_data, X_num);

    // for(int i = 0; i < 200704; i++)
    //     X_tmp_data[i] = X_data[i];
    // Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_5_data, Kernel_1_6_data, 1, 1); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    // BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    // ReLU(X_data, X_num);
    // Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_7_data, Kernel_1_8_data, 1, 1);
    // BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    // for(int i = 0; i < 200704; i++)
    //     X_data[i] += X_tmp_data[i];
    // ReLU(X_data, X_num);

    // =============================================================================
    // layer 2
    int X2_num[5] = {1, 128, 1, 28, 28};

    for(int i = 0; i < 200704; i++)
        X_tmp_data[i] = X_data[i];
    Conv2Plus1D(X_data, X_num, X2_data, X2_num, 230, Kernel_2_1_data, Kernel_2_2_data, 2, 1); // 230 = (64 * 128 * 3 * 3) / (64 * 3 + 128)
    BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);
    ReLU(X2_data, X2_num);
    Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 230, Kernel_2_3_data, Kernel_2_4_data, 1, 1);
    BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);

    Conv3d(X_tmp_data, X_num, X2_tmp_data, X2_num, Kernel_2_5_data, Kernel_num, stride, padding);
    BatchNorm3d(X2_tmp_data, X2_num, 0.00001, 1, 0);
    for(int i = 0; i< 100352; i++)
        X2_data[i] += X2_tmp_data[i];
    ReLU(X2_data, X2_num);
    
    for(int i = 0; i < 100352; i++)
        X2_tmp_data[i] = X2_data[i];
    Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 288, Kernel_2_6_data, Kernel_2_7_data, 1, 1); // 288 = (128 * 128 * 3 * 3) / (128 * 3 + 128)
    BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);
    ReLU(X2_data, X2_num);
    Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 288, Kernel_2_8_data, Kernel_2_9_data, 1, 1);
    BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);
    for(int i = 0; i < 100352; i++)
        X2_data[i] += X2_tmp_data[i];
    ReLU(X2_data, X2_num);

    // // =============================================================================
    // // layer 3
    // int X3_num[5] = {1, 256, 1, 14, 14};

    // for(int i = 0; i< 100352; i++)
    //     X2_tmp_data[i] = X2_data[i];
    // Conv2Plus1D(X2_data, X2_num, X3_data, X3_num, 460, Kernel_3_1_data, Kernel_3_2_data, 2, 1); // 460 = (128 * 256 * 3 * 3) / (128 * 3 + 256)
    // BatchNorm3d(X3_data, X3_num, 0.00001, 1, 0);
    // ReLU(X3_data, X3_num);
    // Conv2Plus1D(X3_data, X3_num, X3_data, X3_num, 460, Kernel_3_3_data, Kernel_3_4_data, 1, 1);
    // BatchNorm3d(X3_data, X3_num, 0.00001, 1, 0);

    // Conv3d(X2_tmp_data, X2_num, X3_tmp_data, X3_num, Kernel_3_5_data, Kernel_num, stride, padding);
    // BatchNorm3d(X3_tmp_data, X3_num, 0.00001, 1, 0);
    // for(int i = 0; i< 50176; i++)
    //     X3_data[i] += X3_tmp_data[i];
    // ReLU(X3_data, X3_num);
    
    // for(int i = 0; i< 50176; i++)
    //     X3_tmp_data[i] = X3_data[i];
    // Conv2Plus1D(X3_data, X3_num, X3_data, X3_num, 576, Kernel_3_6_data, Kernel_3_7_data, 1, 1);
    // BatchNorm3d(X3_data, X3_num, 0.00001, 1, 0);
    // ReLU(X3_data, X3_num);
    // Conv2Plus1D(X3_data, X3_num, X3_data, X3_num, 576, Kernel_3_8_data, Kernel_3_9_data, 1, 1);
    // BatchNorm3d(X3_data, X3_num, 0.00001, 1, 0);
    // for(int i = 0; i< 50176; i++)
    //     X3_data[i] += X3_tmp_data[i];
    // ReLU(X3_data, X3_num);

    // // =============================================================================

    // // layer 4
    // int X4_num[5] = {1, 512, 1, 7, 7};

    // for(int i = 0; i< 50176; i++)
    //     X3_tmp_data[i] = X3_data[i];
    // Conv2Plus1D(X3_data, X3_num, X4_data, X4_num, 921, Kernel_4_1_data, Kernel_4_2_data, 2, 1); // 921 = (256 * 512 * 3 * 3) / (256 * 3 + 512)
    // BatchNorm3d(X4_data, X4_num, 0.00001, 1, 0);
    // ReLU(X4_data, X4_num);
    // Conv2Plus1D(X4_data, X4_num, X4_data, X4_num, 921, Kernel_4_3_data, Kernel_4_4_data, 1, 1);
    // BatchNorm3d(X4_data, X4_num, 0.00001, 1, 0);

    // Conv3d(X3_tmp_data, X3_num, X4_tmp_data, X4_num, Kernel_4_5_data, Kernel_num, stride, padding);
    // BatchNorm3d(X4_tmp_data, X4_num, 0.00001, 1, 0);
    // for(int i = 0; i< 25088; i++)
    //     X4_data[i] += X4_tmp_data[i];
    // ReLU(X4_data, X4_num);
    
    // for(int i = 0; i< 25088; i++)
    //     X4_tmp_data[i] = X4_data[i];
    // Conv2Plus1D(X4_data, X4_num, X4_data, X4_num, 1152, Kernel_4_6_data, Kernel_4_7_data, 1, 1); // 1152 = (512 * 512 * 3 * 3) / (512 * 3 + 512)
    // BatchNorm3d(X4_data, X4_num, 0.00001, 1, 0);
    // ReLU(X4_data, X4_num);
    // Conv2Plus1D(X4_data, X4_num, X4_data, X4_num, 1152, Kernel_4_8_data, Kernel_4_9_data, 1, 1);
    // BatchNorm3d(X4_data, X4_num, 0.00001, 1, 0);
    // for(int i = 0; i< 25088; i++)
    //     X4_data[i] += X4_tmp_data[i];
    // ReLU(X4_data, X4_num);

    // =============================================================================

    for(int i = 0; i < 100352; i++)  //for test
        Y_data[i] = X2_data[i];
    
    return;
}



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
