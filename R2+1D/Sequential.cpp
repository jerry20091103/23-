#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Sequential(float* X_data, float* Y_data, float* Kernel_1_data, float* Kernel_2_data, float* Kernel_3_data, float* Kernel_4_data, float* Kernel_5_data, float* Kernel_6_data, float* Kernel_7_data, float* Kernel_8_data, float* Kernel_9_data, float* Kernel_10_data, float* Kernel_11_data, float* Kernel_12_data)
{
 #ifdef __SYNTHESIS__
    float X_tmp_data[200704];
//    float X2_data[100352];
//    float X2_tmp_data[100352];
//    float X3_data[50176];
//    float X3_tmp_data[50176];
//    float X4_data[25088];
//    float X4_tmp_data[25088];
 #else
    float* X_tmp_data = (float*)malloc(200704*sizeof(float));
//    float* X2_data = (float*)malloc(100352*sizeof(float));
//    float* X2_tmp_data = (float*)malloc(100352*sizeof(float));
//    float* X3_data = (float*)malloc(50176*sizeof(float));
//    float* X3_tmp_data = (float*)malloc(50176*sizeof(float));
//    float* X4_data = (float*)malloc(25088*sizeof(float));
//    float* X4_tmp_data = (float*)malloc(25088*sizeof(float));
 #endif

    // layer 1
    for(int i = 0; i< 200704; i++)
        X_tmp_data[i] = X_data[i];

    int X_num[5] = {1, 64, 1, 56, 56};
    // //easy to read
    // for(int t = 0; t < 3; t++){
    //     Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_data, Kernel_2_data, 1, 1); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    //     BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    //     ReLU(X_data, X_num);

    //     Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_data, Kernel_2_data, 1, 1);
    //     BatchNorm3d(X_data, X_num, 0.00001, 1, 0);

    //     for(int i = 0; i < 200704; i++)
    //         X_data[i] += X_tmp_data[i];
        
    //     ReLU(X_data, X_num);
    // }
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_data, Kernel_2_data, 1, 1); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    ReLU(X_data, X_num);
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_3_data, Kernel_4_data, 1, 1);
    BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    for(int i = 0; i < 200704; i++)
        X_data[i] += X_tmp_data[i];
    ReLU(X_data, X_num);


    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_5_data, Kernel_6_data, 1, 1); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    ReLU(X_data, X_num);
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_7_data, Kernel_8_data, 1, 1);
    BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    for(int i = 0; i < 200704; i++)
        X_data[i] += X_tmp_data[i];
    ReLU(X_data, X_num);


    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_9_data, Kernel_10_data, 1, 1); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    ReLU(X_data, X_num);
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_11_data, Kernel_12_data, 1, 1);
    BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    for(int i = 0; i < 200704; i++)
        X_data[i] += X_tmp_data[i];
    ReLU(X_data, X_num);


    // =============================================================================

    // layer 2
    // int X2_num[5] = {1, 128, 1, 28, 28};
    // Conv2Plus1D(X_data, X_num, X2_data, X2_num, 230, Kernel_1_data, Kernel_2_data, 2, 1); // 230 = (64 * 128 * 3 * 3) / (64 * 3 + 128)
    // BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);
    // for(int i = 0; i< 100352; i++)
    //     X2_tmp_data[i] = X2_data[i];
    // ReLU(X2_data, X2_num);

    // Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 288, Kernel_1_data, Kernel_2_data, 2, 1); // 288 = (128 * 128 * 3 * 3) / (128 * 3 + 128)
    // BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);

    // for(int i = 0; i< 100352; i++)
    //     X2_data[i] += X2_tmp_data[i];
    
    // ReLU(X2_data, X2_num);
    
    // for(int t = 0; t < 2; t++){
    //     for(int i = 0; i< 100352; i++)
    //         X2_tmp_data[i] += X2_data[i];
    //     Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 288, Kernel_1_data, Kernel_2_data, 2, 1); // 288 = (128 * 128 * 3 * 3) / (128 * 3 + 128)
    //     BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    //     ReLU(X_data, X_num);

    //     Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 288, Kernel_1_data, Kernel_2_data, 2, 1);
    //     BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);

    //     for(int i = 0; i< 100352; i++)
    //         X2_data[i] += X2_tmp_data[i];

    //     ReLU(X2_data, X2_num);
    // }

    // // =============================================================================

    // // layer 3
    // int X3_num[5] = {1, 256, 1, 14, 14};
    // Conv2Plus1D(X2_data, X2_num, X3_data, X3_num, 460, Kernel_1_data, Kernel_2_data, 2, 1); // 460 = (128 * 256 * 3 * 3) / (128 * 3 + 256)
    // BatchNorm3d(X3_data, X3_num, 0.00001, 1, 0);
    // for(int i = 0; i< 50176; i++)
    //     X3_tmp_data[i] = X3_data[i];
    // ReLU(X3_data, X3_num);

    // Conv2Plus1D(X3_data, X3_num, X3_data, X3_num, 576, Kernel_1_data, Kernel_2_data, 2, 1); // 576 = (256 * 256 * 3 * 3) / (256 * 3 + 256)
    // BatchNorm3d(X3_data, X3_num, 0.00001, 1, 0);

    // for(int i = 0; i< 50176; i++)
    //     X3_data[i] += X3_tmp_data[i];
    
    // ReLU(X3_data, X3_num);
    
    // for(int t = 0; t < 2; t++){
    //     for(int i = 0; i< 50176; i++)
    //         X3_tmp_data[i] += X3_data[i];
    //     Conv2Plus1D(X3_data, X3_num, X3_data, X3_num, 576, Kernel_1_data, Kernel_2_data, 2, 1);
    //     BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    //     ReLU(X_data, X_num);

    //     Conv2Plus1D(X3_data, X3_num, X3_data, X3_num, 576, Kernel_1_data, Kernel_2_data, 2, 1);
    //     BatchNorm3d(X3_data, X3_num, 0.00001, 1, 0);

    //     for(int i = 0; i< 50176; i++)
    //         X3_data[i] += X3_tmp_data[i];

    //     ReLU(X3_data, X3_num);
    // }

    // // =============================================================================

    // // layer 4
    // int X4_num[5] = {1, 512, 1, 7, 7};
    // Conv2Plus1D(X3_data, X3_num, X4_data, X4_num, 921, Kernel_1_data, Kernel_2_data, 2, 1); // 921 = (256 * 512 * 3 * 3) / (256 * 3 + 512)
    // BatchNorm3d(X4_data, X4_num, 0.00001, 1, 0);
    // for(int i = 0; i< 25088; i++)
    //     X4_tmp_data[i] = X4_data[i];
    // ReLU(X4_data, X4_num);

    // Conv2Plus1D(X4_data, X4_num, X4_data, X4_num, 1152, Kernel_1_data, Kernel_2_data, 2, 1); // 1152 = (512 * 512 * 3 * 3) / (512 * 3 + 512)
    // BatchNorm3d(X4_data, X4_num, 0.00001, 1, 0);

    // for(int i = 0; i< 25088; i++)
    //     X4_data[i] += X4_tmp_data[i];
    
    // ReLU(X4_data, X4_num);
    
    // for(int t = 0; t < 2; t++){
    //     for(int i = 0; i< 25088; i++)
    //         X4_tmp_data[i] += X4_data[i];
    //     Conv2Plus1D(X4_data, X4_num, X4_data, X4_num, 288, Kernel_1_data, Kernel_2_data, 2, 1); // 288 = (512 * 512 * 3 * 3) / (512 * 3 + 512)
    //     BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    //     ReLU(X_data, X_num);

    //     Conv2Plus1D(X4_data, X4_num, X4_data, X4_num, 288, Kernel_1_data, Kernel_2_data, 2, 1);
    //     BatchNorm3d(X4_data, X4_num, 0.00001, 1, 0);

    //     for(int i = 0; i< 25088; i++)
    //         X4_data[i] += X4_tmp_data[i];

    //     ReLU(X4_data, X4_num);
    // }

    for(int i = 0; i < 200704; i++)  //for test
        Y_data[i] = X_data[i];
    
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
