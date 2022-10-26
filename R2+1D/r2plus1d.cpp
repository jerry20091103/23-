#include "r2plus1d.h"
#include<iostream>
using namespace std;

void r2plus1d(dtype* X, dtype* Y, dtype* Kernel_stem_1, dtype* Kernel_stem_2, 
            dtype* Kernel_seq_1_1, dtype* Kernel_seq_1_2, dtype* Kernel_seq_1_3, dtype* Kernel_seq_1_4, dtype* Kernel_seq_1_5, dtype* Kernel_seq_1_6, dtype* Kernel_seq_1_7, dtype* Kernel_seq_1_8, 
            dtype* Kernel_seq_2_1, dtype* Kernel_seq_2_2, dtype* Kernel_seq_2_3, dtype* Kernel_seq_2_4, dtype* Kernel_seq_2_5, dtype* Kernel_seq_2_6, dtype* Kernel_seq_2_7, dtype* Kernel_seq_2_8, dtype* Kernel_seq_2_9, 
            dtype* Kernel_seq_3_1, dtype* Kernel_seq_3_2, dtype* Kernel_seq_3_3, dtype* Kernel_seq_3_4, dtype* Kernel_seq_3_5, dtype* Kernel_seq_3_6, dtype* Kernel_seq_3_7, dtype* Kernel_seq_3_8, dtype* Kernel_seq_3_9, 
            dtype* Kernel_seq_4_1, dtype* Kernel_seq_4_2, dtype* Kernel_seq_4_3, dtype* Kernel_seq_4_4, dtype* Kernel_seq_4_5, dtype* Kernel_seq_4_6, dtype* Kernel_seq_4_7, dtype* Kernel_seq_4_8, dtype* Kernel_seq_4_9)
{
 #ifdef __SYNTHESIS__
    dtype X_stem_1[141120];
    dtype X_stem_2[200704];

    #pragma HLS int_tERFACE s_axilite port=return
	#pragma HLS int_tERFACE m_axi port=X
	#pragma HLS int_tERFACE m_axi port=Y
    #pragma HLS int_tERFACE m_axi port=Kernel_stem_1
	#pragma HLS int_tERFACE m_axi port=Kernel_stem_2
 #else
     // R2Plus1dStem
     dtype* X_stem_1 = (dtype*)malloc(141120*sizeof(dtype)); // value after first Conv-Batch-ReLU layer
     dtype* X_stem_2 = (dtype*)malloc(200704*sizeof(dtype)); // value after second Conv-Batch-ReLU layer
     // Sequential 1~4
     dtype* X_seq = (dtype*)malloc(200704*sizeof(dtype)); // value after second Conv-Batch-ReLU layer
 #endif

    // ========================R2Plus1dStem ==================================
	int_t X_num[5] = {1, 3, 1, 111, 111};
    int_t X_stem_1_num[5] = {1, 45, 1, 56, 56};
    int_t Kernel_stem_1_num[3] = {1, 7, 7};
    int_t stride_1[3] = {1, 2, 2};
    int_t padding_1[3] = {0, 3, 3};

    Conv3d(X, X_num, X_stem_1, X_stem_1_num, Kernel_stem_1, Kernel_stem_1_num, stride_1, padding_1);
    BatchNorm3d(X_stem_1, X_stem_1_num, 0.00001, 1, 0);
    ReLU(X_stem_1, X_stem_1_num);
    

    int_t X_stem_2_num[5] = {1, 64, 1, 56, 56};
    int_t Kernel_stem_2_num[3] = {3, 1, 1};
    int_t stride_2[3] = {1, 1, 1};
    int_t padding_2[3] = {1, 0, 0};

    Conv3d(X_stem_1, X_stem_1_num, X_stem_2, X_stem_2_num, Kernel_stem_2, Kernel_stem_2_num, stride_2, padding_2);
    BatchNorm3d(X_stem_2, X_stem_2_num, 0.00001, 1, 0);
    ReLU(X_stem_2, X_stem_2_num);
    
    
    // // for stem test
    // for(int_t i = 0; i < 200704; i++)
    //     Y[i] = X_stem_2[i]; // assign result to output
    
    // ========================Sequential 1~4==================================
    Sequential(X_stem_2, X_seq, Kernel_seq_1_1, Kernel_seq_1_2, Kernel_seq_1_3, Kernel_seq_1_4, Kernel_seq_1_5, Kernel_seq_1_6, Kernel_seq_1_7, Kernel_seq_1_8, 
            Kernel_seq_2_1, Kernel_seq_2_2, Kernel_seq_2_3, Kernel_seq_2_4, Kernel_seq_2_5, Kernel_seq_2_6, Kernel_seq_2_7, Kernel_seq_2_8, Kernel_seq_2_9, 
            Kernel_seq_3_1, Kernel_seq_3_2, Kernel_seq_3_3, Kernel_seq_3_4, Kernel_seq_3_5, Kernel_seq_3_6, Kernel_seq_3_7, Kernel_seq_3_8, Kernel_seq_3_9, 
            Kernel_seq_4_1, Kernel_seq_4_2, Kernel_seq_4_3, Kernel_seq_4_4, Kernel_seq_4_5, Kernel_seq_4_6, Kernel_seq_4_7, Kernel_seq_4_8, Kernel_seq_4_9);

    // for sequential test
    for(int_t i = 0; i < 25088; i++)
        Y[i] = X_seq[i]; // assign result to output

 #ifndef __SYNTHESIS__
    free(X_stem_1);
    free(X_stem_2);
    free(X_seq);
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
