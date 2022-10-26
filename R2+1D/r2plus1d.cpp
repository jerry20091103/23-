#include "r2plus1d.h"
#include<iostream>
using namespace std;

void r2plus1d(int* X_data, int* Y_data, int* Kernel_1_data, int* Kernel_2_data, double* Batch_mu1, double* Batch_mu2, double* Batch_var1, double* Batch_var2, double* Batch_r1, double* Batch_r2, double* Batch_b1, double* Batch_b2)
{
 #ifdef __SYNTHESIS__
    int X_out_data[141120];
    int Y_tmp_data[200704];

    #pragma HLS INTERFACE s_axilite port=return
	#pragma HLS INTERFACE m_axi port=X_data
	#pragma HLS INTERFACE m_axi port=Y_data
    #pragma HLS INTERFACE m_axi port=Kernel_1_data
	#pragma HLS INTERFACE m_axi port=Kernel_2_data
 #else
    int* X_out_data = (int*)malloc(141120*sizeof(int)); // value after first Conv-Batch-ReLU layer
    int* Y_tmp_data = (int*)malloc(200704*sizeof(int)); // value after second Conv-Batch-ReLU layer
 #endif

    // R2Plus1dStem
	int X_num[5] = {1, 3, 1, 112, 112};
    int X_out_num[5] = {1, 45, 1, 56, 56};
    int Kernel_1_num[3] = {1, 7, 7};
    int stride_1[3] = {1, 2, 2};
    int padding_1[3] = {0, 3, 3};
    
    Conv3d(X_data, X_num, X_out_data, X_out_num, Kernel_1_data, Kernel_1_num, stride_1, padding_1, 0.460907161235809, 60);
    BatchNorm3d(X_out_data, X_out_num, Batch_mu1, Batch_var1, Batch_r1, Batch_b1, 0.0732352063059806, 55);
    ReLU(X_out_data, X_out_num);

    int Y_num[5] = {1, 64, 1, 56, 56};
    int Kernel_2_num[3] = {3, 1, 1};
    int stride_2[3] = {1, 1, 1};
    int padding_2[3] = {1, 0, 0};

    Conv3d(X_out_data, X_out_num, Y_tmp_data, Y_num, Kernel_2_data, Kernel_2_num, stride_2, padding_2, 0.093119129538536, 70);
    BatchNorm3d(Y_tmp_data, Y_num, Batch_mu2, Batch_var2, Batch_r2, Batch_b2, 0.074236087501049, 65);
    ReLU(Y_tmp_data, Y_num);
    
    for(int i = 0; i < 200704; i++)
        Y_data[i] = Y_tmp_data[i]; // assign result to output
    
    // ==========================================================

    // Sequential 1~4

    // ==========================================================
 #ifndef __SYNTHESIS__
    free(X_out_data);
    free(Y_tmp_data);
 #endif

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
