#include "r2plus1d.h"
#include<iostream>
using namespace std;

void r2plus1d(float* X_data, float* Y_data, float* Kernel_1_data, float* Kernel_2_data)
{
 #ifdef __SYNTHESIS__
    float X_out_data[141120];
    float Y_tmp_data[200704];
 #else
     float* X_out_data = (float*)malloc(141120*sizeof(float)); // value after first Conv-Batch-ReLU layer
     float* Y_tmp_data = (float*)malloc(200704*sizeof(float)); // value after second Conv-Batch-ReLU layer
 #endif

	for(int i = 0; i < 141120; i++)
        X_out_data[i] = 0; // init X_out_data[]

	int X_num[5] = {1, 3, 1, 111, 111};
    int X_out_num[5] = {1, 45, 1, 56, 56};
    int Kernel_1_num[5] = {1, 7, 7};
    int stride_1[3] = {1, 2, 2};
    int padding_1[3] = {0, 3, 3};

    Conv3d(X_data, X_num, X_out_data, X_out_num, Kernel_1_data, Kernel_1_num, stride_1, padding_1);
    BatchNorm3d(X_out_data, X_out_num, 0.00001, 1, 0);
    ReLU(X_out_data, X_out_num);

    // ==========================================================
    
	for(int i = 0; i < 200704; i++)
        Y_tmp_data[i] = 0; // init Y_tmp_data[]
    
    int Y_num[5] = {1, 64, 1, 56, 56};
    int Kernel_2_num[5] = {3, 1, 1};
    int stride_2[3] = {1, 1, 1};
    int padding_2[3] = {1, 0, 0};

    Conv3d(X_out_data, X_out_num, Y_tmp_data, Y_num, Kernel_2_data, Kernel_2_num, stride_2, padding_2);
    BatchNorm3d(Y_tmp_data, Y_num, 0.00001, 1, 0);
    ReLU(Y_tmp_data, Y_num);
    
    for(int i = 0; i < 200704; i++)
        Y_data[i] = Y_tmp_data[i]; // assign result to output

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
