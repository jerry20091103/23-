#include "../r2plus1d.h"
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
 #ifdef __SYNTHESIS__

    #pragma HLS INTERFACE s_axilite port=return
	#pragma HLS INTERFACE m_axi port=X
	#pragma HLS INTERFACE m_axi port=Y
    #pragma HLS INTERFACE m_axi port=Kernel_stem_0
	#pragma HLS INTERFACE m_axi port=Kernel_stem_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq1_0_conv1_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq1_0_conv1_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq1_0_conv2_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq1_0_conv2_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq1_1_conv1_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq1_1_conv1_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq1_1_conv2_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq1_1_conv2_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq3_0_conv1_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq3_0_conv1_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq3_0_conv2_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq3_0_conv2_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq3_0_downsample_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq3_1_conv1_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq3_1_conv1_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq3_1_conv2_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq3_1_conv2_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq4_0_conv1_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq4_0_conv1_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq4_0_conv2_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq4_0_conv2_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq4_0_downsample_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq4_1_conv1_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq4_1_conv1_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq4_1_conv2_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq4_1_conv2_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq2_0_conv1_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq2_0_conv1_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq2_0_conv2_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq2_0_conv2_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq2_0_downsample_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq2_1_conv1_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq2_1_conv1_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_seq2_1_conv2_0_0
    #pragma HLS INTERFACE m_axi port=Kernel_seq2_1_conv2_0_3
    #pragma HLS INTERFACE m_axi port=Kernel_linear
    #pragma HLS INTERFACE m_axi port=X_stem_1
    #pragma HLS INTERFACE m_axi port=X_stem_2
    #pragma HLS INTERFACE m_axi port=X_seq
    #pragma HLS INTERFACE m_axi port=X_adap
    #pragma HLS INTERFACE m_axi port=X_tmp_data
    #pragma HLS INTERFACE m_axi port=X2_data
    #pragma HLS INTERFACE m_axi port=X2_tmp_data
    #pragma HLS INTERFACE m_axi port=X_mid_data
    #pragma HLS INTERFACE m_axi port=X_batch_data

 #endif

    for(int_t i=0; i<10; i++)
    {
        Y[i] = X[i];
    }

    return;
}
