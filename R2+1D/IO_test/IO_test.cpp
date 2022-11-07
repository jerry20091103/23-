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

    for(int_t i=0; i<10; i++)
    {
        Y[i] = X[i];
    }

    return;
}
