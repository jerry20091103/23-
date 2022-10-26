#include "r2plus1d.h"
#include<iostream>
using namespace std;

void r2plus1d(dtype* X_data, dtype* Y_data, dtype* Kernel_1_data, dtype* Kernel_2_data)
{
 #ifdef __SYNTHESIS__
    dtype X_out_data[141120];
    dtype Y_tmp_data[200704];

    #pragma HLS int_tERFACE s_axilite port=return
	#pragma HLS int_tERFACE m_axi port=X_data
	#pragma HLS int_tERFACE m_axi port=Y_data
    #pragma HLS int_tERFACE m_axi port=Kernel_1_data
	#pragma HLS int_tERFACE m_axi port=Kernel_2_data
 #else
     dtype* X_out_data = (dtype*)malloc(141120*sizeof(dtype)); // value after first Conv-Batch-ReLU layer
     dtype* Y_tmp_data = (dtype*)malloc(200704*sizeof(dtype)); // value after second Conv-Batch-ReLU layer
 #endif

    // ========================R2Plus1dStem ==================================
	int_t X_num[5] = {1, 3, 1, 111, 111};
    int_t X_out_num[5] = {1, 45, 1, 56, 56};
    int_t Kernel_1_num[3] = {1, 7, 7};
    int_t stride_1[3] = {1, 2, 2};
    int_t padding_1[3] = {0, 3, 3};

    Conv3d(X_data, X_num, X_out_data, X_out_num, Kernel_1_data, Kernel_1_num, stride_1, padding_1);
    BatchNorm3d(X_out_data, X_out_num, 0.00001, 1, 0);
    ReLU(X_out_data, X_out_num);
    

    int_t Y_num[5] = {1, 64, 1, 56, 56};
    int_t Kernel_2_num[3] = {3, 1, 1};
    int_t stride_2[3] = {1, 1, 1};
    int_t padding_2[3] = {1, 0, 0};

    Conv3d(X_out_data, X_out_num, Y_tmp_data, Y_num, Kernel_2_data, Kernel_2_num, stride_2, padding_2);
    BatchNorm3d(Y_tmp_data, Y_num, 0.00001, 1, 0);
    ReLU(Y_tmp_data, Y_num);
    
    for(int_t i = 0; i < 200704; i++)
        Y_data[i] = Y_tmp_data[i]; // assign result to output

    // ========================R2Plus1dStem end ==================================
    
    
    
    // ========================Sequential 1~4==================================

    // 

    // ========================Sequential 1~4 end==============================
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
