#include<iostream>
using namespace std;
#include "r2plus1d.h"

void r2plus1d(float* input_X_in, float* Conv3d_Kernel_1, float* Conv3d_Kernel_2)
{
	int conv3d_X_in_num[5] = {1, 3, 1, 111, 111};
    Array_5D conv3d_X_in = {.data = X_in, .num = conv3d_X_in_num};
    
    float conv3d_X_out_data[141120];
    int conv3d_X_out_num[5] = {1, 45, 1, 56, 56};
    Array_5D conv3d_X_out = {.data = conv3d_X_out_data, .num = conv3d_X_out_num};
    
    
    int conv3d_Kernel_num[3] = {1, 7, 7};
    Array_5D conv3d_Kernel = {.data = Conv3d_Kernel_1, .num = conv3d_Kernel_num};
    
    int conv3d_stride[3] = {1, 2, 2};
    int conv3d_padding[3] = {0, 3, 3};
    Conv3d(conv3d_X_in, conv3d_X_out, conv3d_Kernel, conv3d_stride, conv3d_padding);
    BatchNorm3d(conv3d_X_out, int e = 0.00001, int r = 1, int b = 0);
    ReLU(conv3d_X_out);
    // ==========================================================
    float conv3d_X_out_data_2[200704];
    int conv3d_X_out_num_2[5] = {1, 64, 1, 56, 56};
    Array_5D conv3d_X_out_2 = {.data = conv3d_X_out_data_2, .num = conv3d_X_out_num_2};
    
    int conv3d_Kernel_num_2[3] = {3, 1, 1};
    Array_5D conv3d_Kernel_2 = {.data = Conv3d_Kernel_2, .num = conv3d_Kernel_num_2};
    
    int conv3d_stride_2[3] = {1, 1, 1};
    int conv3d_padding_2[3] = {1, 0, 0};
    Conv3d(conv3d_X_out, conv3d_X_out_2, conv3d_Kernel_2, conv3d_stride_2, conv3d_padding_2);
    BatchNorm3d(conv3d_X_out_2, int e = 0.00001, int r = 1, int b = 0);
    ReLU(conv3d_X_out_2);

    
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