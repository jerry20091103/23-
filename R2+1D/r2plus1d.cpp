#include "r2plus1d.h"
#include<iostream>
using namespace std;

void r2plus1d(float* X_data, float* Y_data, float* Kernel_1_data, float* Kernel_2_data)
{
	int X_num[5] = {1, 3, 1, 111, 111};
    Array_5D X = {.data = X_data, .num = X_num};
    
    float X_out_data[141120];
    int X_out_num[5] = {1, 45, 1, 56, 56};
    Array_5D X_out = {.data = X_out_data, .num = X_out_num};
    
    int Kernel_1_num[3] = {1, 7, 7};
    Array_5D Kernel_1 = {.data = Kernel_1_data, .num = Kernel_1_num};
    
    int stride_1[3] = {1, 2, 2};
    int padding_1[3] = {0, 3, 3};
    Conv3d(X, X_out, Kernel_1, stride_1, padding_1);
    BatchNorm3d(X_out, 0.00001, 1, 0);
    ReLU(X_out);
    // ==========================================================
    float Y_tmp_data[200704];
    int Y_num[5] = {1, 64, 1, 56, 56};
    Array_5D Y = {.data = Y_tmp_data, .num = Y_num};
    
    int Kernel_2_num[3] = {3, 1, 1};
    Array_5D Kernel_2 = {.data = Kernel_2_data, .num = Kernel_2_num};
    
    int stride_2[3] = {1, 1, 1};
    int padding_2[3] = {1, 0, 0};
    Conv3d(X_out, Y, Kernel_2, stride_2, padding_2);
    BatchNorm3d(Y, 0.00001, 1, 0);
    ReLU(Y);
    
    for(int i = 0; i < 200704; i++)
        Y_data[i] = Y.data[i];
    
    return;
	// └─Conv3d: 2-1                            [1, 45, 1, 56, 56]        6,615
    // └─BatchNorm3d: 2-2                       [1, 45, 1, 56, 56]        90
    // └─ReLU: 2-3                              [1, 45, 1, 56, 56]        --
    // └─Conv3d: 2-4                            [1, 64, 1, 56, 56]        8,640
    // └─BatchNorm3d: 2-5                       [1, 64, 1, 56, 56]        128
    // └─ReLU: 2-6 
    // =============================================================================
    // nn.Conv3d(3, 45, kernel_size=(1, 7, 7),
    //                   stride=(1, 2, 2), padding=(0, 3, 3),
    //                   bias=False),
    // nn.BatchNorm3d(45),
    // nn.ReLU(inplace=True),
    // nn.Conv3d(45, 64, kernel_size=(3, 1, 1),
    //                   stride=(1, 1, 1), padding=(1, 0, 0),
    //                   bias=False),
    // nn.BatchNorm3d(64),
    // nn.ReLU(inplace=True))

}
