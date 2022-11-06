#include "r2plus1d.h"
#include<iostream>
using namespace std;

void r2plus1d(dtype* X, dtype* Y, ktype* Kernel_stem_0, ktype* Kernel_stem_3,
            ktype* Kernel_seq1_0_conv1_0_0, ktype* Kernel_seq1_0_conv1_0_3, ktype* Kernel_seq1_0_conv2_0_0, ktype* Kernel_seq1_0_conv2_0_3, ktype* Kernel_seq1_1_conv1_0_0, ktype* Kernel_seq1_1_conv1_0_3, ktype* Kernel_seq1_1_conv2_0_0, ktype* Kernel_seq1_1_conv2_0_3,
            ktype* Kernel_seq2_0_conv1_0_0, ktype* Kernel_seq2_0_conv1_0_3, ktype* Kernel_seq2_0_conv2_0_0, ktype* Kernel_seq2_0_conv2_0_3, ktype* Kernel_seq2_0_downsample_0, ktype* Kernel_seq2_1_conv1_0_0, ktype* Kernel_seq2_1_conv1_0_3, ktype* Kernel_seq2_1_conv2_0_0, ktype* Kernel_seq2_1_conv2_0_3,
            ktype* Kernel_seq3_0_conv1_0_0, ktype* Kernel_seq3_0_conv1_0_3, ktype* Kernel_seq3_0_conv2_0_0, ktype* Kernel_seq3_0_conv2_0_3, ktype* Kernel_seq3_0_downsample_0, ktype* Kernel_seq3_1_conv1_0_0, ktype* Kernel_seq3_1_conv1_0_3, ktype* Kernel_seq3_1_conv2_0_0, ktype* Kernel_seq3_1_conv2_0_3,
            ktype* Kernel_seq4_0_conv1_0_0, ktype* Kernel_seq4_0_conv1_0_3, ktype* Kernel_seq4_0_conv2_0_0, ktype* Kernel_seq4_0_conv2_0_3, ktype* Kernel_seq4_0_downsample_0, ktype* Kernel_seq4_1_conv1_0_0, ktype* Kernel_seq4_1_conv1_0_3, ktype* Kernel_seq4_1_conv2_0_0, ktype* Kernel_seq4_1_conv2_0_3,
            ktype* Kernel_linear,
            dtype* X_stem_1, dtype* X_stem_2, dtype* X_seq,dtype* X_adap, dtype* X_tmp_data, dtype* X2_data, dtype* X2_tmp_data, dtype* X_mid_data, dtype* X_batch_data)
{
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS INTERFACE m_axi depth=602112 bundle=gmem0 port=X
	#pragma HLS INTERFACE m_axi depth=10 port=Y
    #pragma HLS INTERFACE m_axi depth=6615 port=Kernel_stem_0
	#pragma HLS INTERFACE m_axi depth=8640 port=Kernel_stem_3
    #pragma HLS INTERFACE m_axi depth=82944 port=Kernel_seq1_0_conv1_0_0
    #pragma HLS INTERFACE m_axi depth=27648 port=Kernel_seq1_0_conv1_0_3
    #pragma HLS INTERFACE m_axi depth=82944 port=Kernel_seq1_0_conv2_0_0
    #pragma HLS INTERFACE m_axi depth=27648 port=Kernel_seq1_0_conv2_0_3
    #pragma HLS INTERFACE m_axi depth=82944 port=Kernel_seq1_1_conv1_0_0
    #pragma HLS INTERFACE m_axi depth=27648 port=Kernel_seq1_1_conv1_0_3
    #pragma HLS INTERFACE m_axi depth=82944 port=Kernel_seq1_1_conv2_0_0
    #pragma HLS INTERFACE m_axi depth=27648 port=Kernel_seq1_1_conv2_0_3
    #pragma HLS INTERFACE m_axi depth=132480 port=Kernel_seq2_0_conv1_0_0
    #pragma HLS INTERFACE m_axi depth=88320 port=Kernel_seq2_0_conv1_0_3
    #pragma HLS INTERFACE m_axi depth=264960 port=Kernel_seq2_0_conv2_0_0
    #pragma HLS INTERFACE m_axi depth=88320 port=Kernel_seq2_0_conv2_0_3
    #pragma HLS INTERFACE m_axi depth=8192 port=Kernel_seq2_0_downsample_0
    #pragma HLS INTERFACE m_axi depth=331776 port=Kernel_seq2_1_conv1_0_0
    #pragma HLS INTERFACE m_axi depth=110592 port=Kernel_seq2_1_conv1_0_3
    #pragma HLS INTERFACE m_axi depth=331776 port=Kernel_seq2_1_conv2_0_0
    #pragma HLS INTERFACE m_axi depth=110592 port=Kernel_seq2_1_conv2_0_3
    #pragma HLS INTERFACE m_axi depth=529920 port=Kernel_seq3_0_conv1_0_0
    #pragma HLS INTERFACE m_axi depth=353280 port=Kernel_seq3_0_conv1_0_3
    #pragma HLS INTERFACE m_axi depth=1059840 port=Kernel_seq3_0_conv2_0_0
    #pragma HLS INTERFACE m_axi depth=353280 port=Kernel_seq3_0_conv2_0_3
    #pragma HLS INTERFACE m_axi depth=32768 port=Kernel_seq3_0_downsample_0
    #pragma HLS INTERFACE m_axi depth=1327104 port=Kernel_seq3_1_conv1_0_0
    #pragma HLS INTERFACE m_axi depth=442368 port=Kernel_seq3_1_conv1_0_3
    #pragma HLS INTERFACE m_axi depth=1327104 port=Kernel_seq3_1_conv2_0_0
    #pragma HLS INTERFACE m_axi depth=442368 port=Kernel_seq3_1_conv2_0_3
    #pragma HLS INTERFACE m_axi depth=2121984 port=Kernel_seq4_0_conv1_0_0
    #pragma HLS INTERFACE m_axi depth=1414656 port=Kernel_seq4_0_conv1_0_3
    #pragma HLS INTERFACE m_axi depth=4243968 port=Kernel_seq4_0_conv2_0_0
    #pragma HLS INTERFACE m_axi depth=1414656 port=Kernel_seq4_0_conv2_0_3
    #pragma HLS INTERFACE m_axi depth=131072 port=Kernel_seq4_0_downsample_0
    #pragma HLS INTERFACE m_axi depth=5308416 port=Kernel_seq4_1_conv1_0_0
    #pragma HLS INTERFACE m_axi depth=1769472 port=Kernel_seq4_1_conv1_0_3
    #pragma HLS INTERFACE m_axi depth=5308416 port=Kernel_seq4_1_conv2_0_0
    #pragma HLS INTERFACE m_axi depth=1769472 port=Kernel_seq4_1_conv2_0_3
    #pragma HLS INTERFACE m_axi depth=5120 bundle=gmem1 port=Kernel_linear
    #pragma HLS INTERFACE m_axi depth=2257920 bundle=gmem1 port=X_stem_1
    #pragma HLS INTERFACE m_axi depth=3211264 bundle=gmem0 port=X_stem_2
    #pragma HLS INTERFACE m_axi depth=50176 bundle=gmem1 port=X_seq
    #pragma HLS INTERFACE m_axi depth=512 bundle=gmem0 port=X_adap
    #pragma HLS INTERFACE m_axi depth=3211264 bundle=gmem0 port=X_tmp_data
    #pragma HLS INTERFACE m_axi depth=802816 bundle=gmem0 port=X2_data
    #pragma HLS INTERFACE m_axi depth=802816 bundle=gmem1 port=X2_tmp_data
    #pragma HLS INTERFACE m_axi depth=7225344 bundle=gmem1 port=X_mid_data
    #pragma HLS INTERFACE m_axi depth=7225344 port=X_batch_data
 #ifdef __SYNTHESIS__
    // dtype X_stem_1[2257920];
    // dtype X_stem_2[3211264];
    // // Sequential 1~4
    // dtype X_seq[50176]; // value after 1~4 sequential layer
    // // AdaptiveAvgPool3d
    // dtype X_adap[512]; // value after AdaptiveAvgPool3d
    // // Linear



 #else
    // R2Plus1dStem
    // dtype* X_stem_1 = (dtype*)malloc(2257920*sizeof(dtype)); // value after first Conv-Batch-ReLU layer
    // dtype* X_stem_2 = (dtype*)malloc(3211264*sizeof(dtype)); // value after second Conv-Batch-ReLU layer
    // // // Sequential 1~4
    // dtype* X_seq = (dtype*)malloc(50176*sizeof(dtype)); // value after 1~4 sequential layer
    // // AdaptiveAvgPool3d
    // dtype* X_adap = (dtype*)malloc(512*sizeof(dtype)); // value after AdaptiveAvgPool3d
 #endif

    dtype X_linear[10];
    // ========================R2Plus1dStem ==================================
	int_t X_num[5] = {N_, 3, D_, 112, 112};
    int_t X_stem_1_num[5] = {N_, 45, D_, 56, 56};
    int_t Kernel_stem_1_num[3] = {1, 7, 7};
    int_t stride_1[3] = {1, 2, 2};
    int_t padding_1[3] = {0, 3, 3};

    Conv3d(X, X_num, X_stem_1, X_stem_1_num, Kernel_stem_0, Kernel_stem_1_num, Kernel_stem_0_scale, stride_1, padding_1, 3.756307810544967651e-02, 56, 0.4609071612358093262, 60);
    BatchNorm3d(X_stem_1, X_batch_data, X_stem_1_num, Mu_stem_1, Var_stem_1, Gamma_stem_1, Bias_stem_1, 0.4609071612358093262, 60, 0.07323520630598068237, 55);
    ReLU(X_batch_data, X_stem_1, X_stem_1_num, 55);

    int_t X_stem_2_num[5] = {N_, 64, D_, 56, 56};
    int_t Kernel_stem_2_num[3] = {3, 1, 1};
    int_t stride_2[3] = {1, 1, 1};
    int_t padding_2[3] = {1, 0, 0};

    Conv3d(X_stem_1, X_stem_1_num, X_stem_2, X_stem_2_num, Kernel_stem_3, Kernel_stem_2_num, Kernel_stem_3_scale, stride_2, padding_2, 0.07323520630598068237, 55, 0.09311912953853607178, 70);
    BatchNorm3d(X_stem_2, X_batch_data, X_stem_2_num, Mu_stem_4, Var_stem_4, Gamma_stem_4, Bias_stem_4, 0.09311912953853607178, 70, 0.07423608750104904175, 65);
    ReLU(X_batch_data, X_stem_2, X_stem_2_num, 65);
    
    // // for stem test
    // for(int_t i = 0; i < 3211264; i++)
    //     Y[i] = X_stem_2[i]; // assign result to output
    
    // ========================Sequential 1~4==================================
    Sequential(X_stem_2, X_seq, 
        Kernel_seq1_0_conv1_0_0, Kernel_seq1_0_conv1_0_3, Kernel_seq1_0_conv2_0_0, Kernel_seq1_0_conv2_0_3, Kernel_seq1_1_conv1_0_0, Kernel_seq1_1_conv1_0_3, Kernel_seq1_1_conv2_0_0, Kernel_seq1_1_conv2_0_3, 
        Kernel_seq2_0_conv1_0_0, Kernel_seq2_0_conv1_0_3, Kernel_seq2_0_conv2_0_0, Kernel_seq2_0_conv2_0_3, Kernel_seq2_0_downsample_0, Kernel_seq2_1_conv1_0_0, Kernel_seq2_1_conv1_0_3, Kernel_seq2_1_conv2_0_0, Kernel_seq2_1_conv2_0_3,
        Kernel_seq3_0_conv1_0_0, Kernel_seq3_0_conv1_0_3, Kernel_seq3_0_conv2_0_0, Kernel_seq3_0_conv2_0_3, Kernel_seq3_0_downsample_0, Kernel_seq3_1_conv1_0_0, Kernel_seq3_1_conv1_0_3, Kernel_seq3_1_conv2_0_0, Kernel_seq3_1_conv2_0_3,
        Kernel_seq4_0_conv1_0_0, Kernel_seq4_0_conv1_0_3, Kernel_seq4_0_conv2_0_0, Kernel_seq4_0_conv2_0_3, Kernel_seq4_0_downsample_0, Kernel_seq4_1_conv1_0_0, Kernel_seq4_1_conv1_0_3, Kernel_seq4_1_conv2_0_0, Kernel_seq4_1_conv2_0_3,
        0.07423608750104904175, 65,
        X_tmp_data, X2_data, X2_tmp_data,X_mid_data, X_batch_data);

    // // for sequential test
    // for(int_t i = 0; i < 50176; i++)
    //     Y[i] = X_seq[i]; // assign result to output
    
    // ======================== AdaptiveAvgPool3d ==================================
    int_t X_seq_num[5] = {N_, 512, 2, 7, 7};
    int_t X_adap_num[5] = {N_, 512, 1, 1, 1};
    AdaptiveAvgPool3d(X_seq, X_seq_num, X_adap, X_adap_num);

    // // for sequential test
    // for(int_t i = 0; i < 512; i++)
    //     Y[i] = X_adap[i]; // assign result to output

    // ======================== Linear ==================================
    int_t X_adap_flat_num[2] = {N_, 512};
    Linear(X_adap, X_adap_flat_num, X_linear, Kernel_linear);
    
    // for linear test
    for(int_t i = 0; i < 10; i++)
        Y[i] = X_linear[i]; // assign result to output
 
 #ifndef __SYNTHESIS__
    // free(X_stem_1);
    // free(X_stem_2);
    // free(X_seq);
    // free(X_adap);
 #endif

    return;
}
