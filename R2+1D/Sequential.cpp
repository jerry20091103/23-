#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Sequential(double* X_data, double* Y_data, double* Kernel_1_1_data, double* Kernel_1_2_data, double* Kernel_1_3_data, double* Kernel_1_4_data, double* Kernel_1_5_data, double* Kernel_1_6_data, double* Kernel_1_7_data, double* Kernel_1_8_data, 
                    double* Kernel_2_1_data, double* Kernel_2_2_data, double* Kernel_2_3_data, double* Kernel_2_4_data, double* Kernel_2_5_data, double* Kernel_2_6_data, double* Kernel_2_7_data, double* Kernel_2_8_data, double* Kernel_2_9_data, 
                    double* Kernel_3_1_data, double* Kernel_3_2_data, double* Kernel_3_3_data, double* Kernel_3_4_data, double* Kernel_3_5_data, double* Kernel_3_6_data, double* Kernel_3_7_data, double* Kernel_3_8_data, double* Kernel_3_9_data, 
                    double* Kernel_4_1_data, double* Kernel_4_2_data, double* Kernel_4_3_data, double* Kernel_4_4_data, double* Kernel_4_5_data, double* Kernel_4_6_data, double* Kernel_4_7_data, double* Kernel_4_8_data, double* Kernel_4_9_data)
{
 #ifdef __SYNTHESIS__
    double X_tmp_data[200704];
    // double X2_data[100352];
    // double X2_tmp_data[100352];
    // double X3_data[50176];
    // double X3_tmp_data[50176];
    // double X4_data[25088];
    // double X4_tmp_data[25088];
 #else
    double* X_tmp_data = (double*)malloc(200704*sizeof(double));
    // double* X2_data = (double*)malloc(100352*sizeof(double));
    // double* X2_tmp_data = (double*)malloc(100352*sizeof(double));
    // double* X3_data = (double*)malloc(50176*sizeof(double));
    // double* X3_tmp_data = (double*)malloc(50176*sizeof(double));
    // double* X4_data = (double*)malloc(25088*sizeof(double));
    // double* X4_tmp_data = (double*)malloc(25088*sizeof(double));
 #endif

    int Kernel_num[3] = {1, 1, 1};
    int stride[3] = {2, 2, 2};
    int padding[3] = {0, 0, 0};

    // layer 1
    int X_num[5] = {1, 64, 1, 56, 56};

    for(int i = 0; i < 200704; i++)
        X_tmp_data[i] = X_data[i];
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_1_data, Kernel_1_2_data, 1, 1); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    ReLU(X_data, X_num);
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_3_data, Kernel_1_4_data, 1, 1);
    BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    for(int i = 0; i < 200704; i++)
        X_data[i] += X_tmp_data[i];
    ReLU(X_data, X_num);

    for(int i = 0; i < 200704; i++)
        X_tmp_data[i] = X_data[i];
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_5_data, Kernel_1_6_data, 1, 1); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    ReLU(X_data, X_num);
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_7_data, Kernel_1_8_data, 1, 1);
    BatchNorm3d(X_data, X_num, 0.00001, 1, 0);
    for(int i = 0; i < 200704; i++)
        X_data[i] += X_tmp_data[i];
    ReLU(X_data, X_num);

    // // =============================================================================
    // // layer 2
    // int X2_num[5] = {1, 128, 1, 28, 28};

    // for(int i = 0; i < 200704; i++)
    //     X_tmp_data[i] = X_data[i];
    // Conv2Plus1D(X_data, X_num, X2_data, X2_num, 230, Kernel_2_1_data, Kernel_2_2_data, 2, 1); // 230 = (64 * 128 * 3 * 3) / (64 * 3 + 128)
    // BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);
    // ReLU(X2_data, X2_num);
    // Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 230, Kernel_2_3_data, Kernel_2_4_data, 1, 1);
    // BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);

    // Conv3d(X_tmp_data, X_num, X2_tmp_data, X2_num, Kernel_2_5_data, Kernel_num, stride, padding);
    // BatchNorm3d(X2_tmp_data, X2_num, 0.00001, 1, 0);
    // for(int i = 0; i< 100352; i++)
    //     X2_data[i] += X2_tmp_data[i];
    // ReLU(X2_data, X2_num);
    
    // for(int i = 0; i < 100352; i++)
    //     X2_tmp_data[i] = X2_data[i];
    // Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 288, Kernel_2_6_data, Kernel_2_7_data, 1, 1); // 288 = (128 * 128 * 3 * 3) / (128 * 3 + 128)
    // BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);
    // ReLU(X2_data, X2_num);
    // Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 288, Kernel_2_8_data, Kernel_2_9_data, 1, 1);
    // BatchNorm3d(X2_data, X2_num, 0.00001, 1, 0);
    // for(int i = 0; i < 100352; i++)
    //     X2_data[i] += X2_tmp_data[i];
    // ReLU(X2_data, X2_num);

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

    for(int i = 0; i < 200704; i++)  //for test
        Y_data[i] = X_data[i];
    
#ifndef __SYNTHESIS__
    free(X_tmp_data);
    // free(X2_data);
    // free(X2_tmp_data);
    // free(X3_data);
    // free(X3_tmp_data);
    // free(X4_data);
    // free(X4_tmp_data);
#endif
    
    return;
}


// =====================================================================

//   (layer1): Sequential(
//     (0): BasicBlock(
//       (conv1): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(64, 144, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(144, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(144, 64, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//         (2): ReLU(inplace=True)
//       )
//       (conv2): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(64, 144, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(144, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(144, 64, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//       (relu): ReLU(inplace=True)
//     )
//     (1): BasicBlock(
//       (conv1): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(64, 144, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(144, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(144, 64, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//         (2): ReLU(inplace=True)
//       )
//       (conv2): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(64, 144, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(144, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(144, 64, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//       (relu): ReLU(inplace=True)
//     )
//   )

// =====================================================================

//   (layer2): Sequential(
//     (0): BasicBlock(
//       (conv1): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(64, 230, kernel_size=(1, 3, 3), stride=(1, 2, 2), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(230, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(230, 128, kernel_size=(3, 1, 1), stride=(2, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(128, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//         (2): ReLU(inplace=True)
//       )
//       (conv2): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(128, 230, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(230, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(230, 128, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(128, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//       (relu): ReLU(inplace=True)
//       (downsample): Sequential(
//         (0): Conv3d(64, 128, kernel_size=(1, 1, 1), stride=(2, 2, 2), bias=False)
//         (1): BatchNorm3d(128, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//     )
//     (1): BasicBlock(
//       (conv1): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(128, 288, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(288, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(288, 128, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(128, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//         (2): ReLU(inplace=True)
//       )
//       (conv2): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(128, 288, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(288, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(288, 128, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(128, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//       (relu): ReLU(inplace=True)
//     )
//   )

// =====================================================================

//   (layer3): Sequential(
//     (0): BasicBlock(
//       (conv1): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(128, 460, kernel_size=(1, 3, 3), stride=(1, 2, 2), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(460, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(460, 256, kernel_size=(3, 1, 1), stride=(2, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(256, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//         (2): ReLU(inplace=True)
//       )
//       (conv2): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(256, 460, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(460, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(460, 256, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(256, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//       (relu): ReLU(inplace=True)
//       (downsample): Sequential(
//         (0): Conv3d(128, 256, kernel_size=(1, 1, 1), stride=(2, 2, 2), bias=False)
//         (1): BatchNorm3d(256, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//     )
//     (1): BasicBlock(
//       (conv1): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(256, 576, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(576, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(576, 256, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(256, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//         (2): ReLU(inplace=True)
//       )
//       (conv2): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(256, 576, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(576, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(576, 256, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(256, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//       (relu): ReLU(inplace=True)
//     )
//   )

// =====================================================================

//   (layer4): Sequential(
//     (0): BasicBlock(
//       (conv1): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(256, 921, kernel_size=(1, 3, 3), stride=(1, 2, 2), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(921, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(921, 512, kernel_size=(3, 1, 1), stride=(2, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(512, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//         (2): ReLU(inplace=True)
//       )
//       (conv2): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(512, 921, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(921, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(921, 512, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(512, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//       (relu): ReLU(inplace=True)
//       (downsample): Sequential(
//         (0): Conv3d(256, 512, kernel_size=(1, 1, 1), stride=(2, 2, 2), bias=False)
//         (1): BatchNorm3d(512, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//     )
//     (1): BasicBlock(
//       (conv1): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(512, 1152, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(1152, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(1152, 512, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(512, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//         (2): ReLU(inplace=True)
//       )
//       (conv2): Sequential(
//         (0): Conv2Plus1D(
//           (0): Conv3d(512, 1152, kernel_size=(1, 3, 3), stride=(1, 1, 1), padding=(0, 1, 1), bias=False)
//           (1): BatchNorm3d(1152, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//           (2): ReLU(inplace=True)
//           (3): Conv3d(1152, 512, kernel_size=(3, 1, 1), stride=(1, 1, 1), padding=(1, 0, 0), bias=False)
//         )
//         (1): BatchNorm3d(512, eps=1e-05, momentum=0.1, affine=True, track_running_stats=False)
//       )
//       (relu): ReLU(inplace=True)
//     )
//   )