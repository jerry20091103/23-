#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void r2plus1d(dtype* X, ktype* Kernel_stem_0, ktype* Kernel_stem_3,
            ktype* Kernel_seq1_0_conv1_0_0, ktype* Kernel_seq1_0_conv1_0_3, ktype* Kernel_seq1_0_conv2_0_0, ktype* Kernel_seq1_0_conv2_0_3, ktype* Kernel_seq1_1_conv1_0_0, ktype* Kernel_seq1_1_conv1_0_3, ktype* Kernel_seq1_1_conv2_0_0, ktype* Kernel_seq1_1_conv2_0_3,
            ktype* Kernel_seq2_0_conv1_0_0, ktype* Kernel_seq2_0_conv1_0_3, ktype* Kernel_seq2_0_conv2_0_0, ktype* Kernel_seq2_0_conv2_0_3, ktype* Kernel_seq2_0_downsample_0, ktype* Kernel_seq2_1_conv1_0_0, ktype* Kernel_seq2_1_conv1_0_3, ktype* Kernel_seq2_1_conv2_0_0, ktype* Kernel_seq2_1_conv2_0_3,
            ktype* Kernel_seq3_0_conv1_0_0, ktype* Kernel_seq3_0_conv1_0_3, ktype* Kernel_seq3_0_conv2_0_0, ktype* Kernel_seq3_0_conv2_0_3, ktype* Kernel_seq3_0_downsample_0, ktype* Kernel_seq3_1_conv1_0_0, ktype* Kernel_seq3_1_conv1_0_3, ktype* Kernel_seq3_1_conv2_0_0, ktype* Kernel_seq3_1_conv2_0_3,
            ktype* Kernel_seq4_0_conv1_0_0, ktype* Kernel_seq4_0_conv1_0_3, ktype* Kernel_seq4_0_conv2_0_0, ktype* Kernel_seq4_0_conv2_0_3, ktype* Kernel_seq4_0_downsample_0, ktype* Kernel_seq4_1_conv1_0_0, ktype* Kernel_seq4_1_conv1_0_3, ktype* Kernel_seq4_1_conv2_0_0, ktype* Kernel_seq4_1_conv2_0_3,
            ktype* Kernel_linear,
            dtype* X_stem_1, dtype* X_stem_2, dtype* X2_data, dtype* X3_data, dtype* X_seq, dtype* X_adap, dtype* X_linear, 
            dtype* X_tmp_data, dtype* X2_tmp_data, dtype* X3_tmp_data, dtype* X4_tmp_data,
            dtype* X_batch_data, dtype* X2_batch_data, dtype* X3_batch_data, dtype* X4_batch_data,
            dtype* X_mid_data, dtype* X2_mid_data, dtype* X3_mid_data, dtype* X4_mid_data)
{
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS INTERFACE m_axi depth=602112 bundle=gmem0 port=X
    #pragma HLS INTERFACE m_axi depth=2257920 bundle=gmem1 port=X_stem_1
    #pragma HLS INTERFACE m_axi depth=3211264 bundle=gmem0 port=X_stem_2
    #pragma HLS INTERFACE m_axi depth=802816 bundle=gmem0 port=X2_data
    #pragma HLS INTERFACE m_axi depth=200704 bundle=gmem0 port=X3_data
    #pragma HLS INTERFACE m_axi depth=50176 bundle=gmem0 port=X_seq
    #pragma HLS INTERFACE m_axi depth=512 bundle=gmem1 port=X_adap
	#pragma HLS INTERFACE m_axi depth=10 bundle=gmem0 port=X_linear
    #pragma HLS INTERFACE m_axi depth=3211264 bundle=gmem1 port=X_tmp_data
    #pragma HLS INTERFACE m_axi depth=802816 bundle=gmem1 port=X2_tmp_data
    #pragma HLS INTERFACE m_axi depth=200704 bundle=gmem1 port=X3_tmp_data
    #pragma HLS INTERFACE m_axi depth=50176 bundle=gmem1 port=X4_tmp_data
    #pragma HLS INTERFACE m_axi depth=7225344 bundle=gmem2 port=X_batch_data
    #pragma HLS INTERFACE m_axi depth=2885120 bundle=gmem2 port=X2_batch_data
    #pragma HLS INTERFACE m_axi depth=721280 bundle=gmem2 port=X3_batch_data
    #pragma HLS INTERFACE m_axi depth=180516 bundle=gmem2 port=X4_batch_data
    #pragma HLS INTERFACE m_axi depth=7225344 bundle=gmem1 port=X_mid_data
    #pragma HLS INTERFACE m_axi depth=2885120 bundle=gmem1 port=X2_mid_data
    #pragma HLS INTERFACE m_axi depth=721280 bundle=gmem1 port=X3_mid_data
    #pragma HLS INTERFACE m_axi depth=180516 bundle=gmem1 port=X4_mid_data

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
    #pragma HLS INTERFACE m_axi depth=5120 port=Kernel_linear

    // ========================R2Plus1dStem ==================================
	int_t X_num[5] = {1, 3, 16, 112, 112};
    int_t X_stem_1_num[5] = {1, 45, 16, 56, 56};
    int_t Kernel_stem_1_num[3] = {1, 7, 7};
    int_t stride_1[3] = {1, 2, 2};
    int_t padding_1[3] = {0, 3, 3};
    
    for(int_t i = 0; i < X_stem_1_num[1]*X_num[1]*Kernel_stem_1_num[0]*Kernel_stem_1_num[1]*Kernel_stem_1_num[2]; i++)
        Kernel_bram[i] = Kernel_stem_0[i];

    for(int_t yi = 0; yi < 9; yi++){
        for(int_t k = 0; k < 5*X_stem_1_num[2]*X_stem_1_num[3]*X_stem_1_num[4]; k++)
            Y_bram[k] = 0; 
        
        for(int_t xi = 0; xi < 3; xi++){
            for(int_t k = 0; k < X_num[2]*X_num[3]*X_num[4]; k++)
                X_bram[k] = X[xi*X_num[2]*X_num[3]*X_num[4]+k];

            Conv3d(X_bram, X_num, xi, 1, Y_bram, X_stem_1_num, yi, 5, Kernel_bram, Kernel_stem_1_num, Kernel_stem_0_scale, stride_1, padding_1, 3.756307810544967651e-02, 56, 0.4609071612358093262, 60);
        }
        // for(int_t c = 0; c < 5; c++){
        //     for(int_t k = 0; k < X_stem_1_num[2]*X_stem_1_num[3]*X_stem_1_num[4]; k++){
        //         int_t Ypos = c*X_stem_1_num[2]*X_stem_1_num[3]*X_stem_1_num[4] + k;
        //         Y_bram[Ypos] = (Y_bram[Ypos]+60 > 255) ? 255 : (Y_bram[Ypos]+60 < 0) ? 0 : (dtype)Y_bram[Ypos]+60;
            
        //         int_t tmp_X = (int_t)roundf((((ftype((int_t)Y_bram[k]-60)*0.4609071612358093262 - Mu_stem_1[yi*5+c]) / sqrtf(Var_stem_1[yi*9+c]+0.00001)) * Gamma_stem_1[yi*9+c] + Bias_stem_1[yi*9+c])/0.07323520630598068237) + 55;
        //         Y_bram[Ypos] = (tmp_X > 255) ? 255 : (tmp_X < 55) ? 55 : (dtype)tmp_X;
        //         X_stem_1[yi*5*X_stem_1_num[2]*X_stem_1_num[3]*X_stem_1_num[4]+Ypos] = Y_bram[Ypos];
        //     }

        // }
        for(int_t k = 0; k < 5*X_stem_1_num[2]*X_stem_1_num[3]*X_stem_1_num[4]; k++){
            Y_bram[k] = (Y_bram[k]+60 > 255) ? 255 : (Y_bram[k]+60 < 0) ? 0 : Y_bram[k]+60;
            X_stem_1[yi*5*X_stem_1_num[2]*X_stem_1_num[3]*X_stem_1_num[4] + k] = Y_bram[k];
        }
    }

    // BatchNorm3d(X_stem_1, X_batch_data, X_stem_1_num, Mu_stem_1, Var_stem_1, Gamma_stem_1, Bias_stem_1, 0.4609071612358093262, 60, 0.07323520630598068237, 55);
    // ReLU(X_batch_data, X_stem_1, X_stem_1_num, 55);

    // int_t X_stem_2_num[5] = {1, 64, D_, 56, 56};
    // int_t Kernel_stem_2_num[3] = {3, 1, 1};
    // int_t stride_2[3] = {1, 1, 1};
    // int_t padding_2[3] = {1, 0, 0};

    // Conv3d(X_stem_1, X_stem_1_num, X_stem_2, X_stem_2_num, Kernel_stem_3, Kernel_stem_2_num, Kernel_stem_3_scale, stride_2, padding_2, 0.07323520630598068237, 55, 0.09311912953853607178, 70);
    // BatchNorm3d(X_stem_2, X_batch_data, X_stem_2_num, Mu_stem_4, Var_stem_4, Gamma_stem_4, Bias_stem_4, 0.09311912953853607178, 70, 0.07423608750104904175, 65);
    // ReLU(X_batch_data, X_stem_2, X_stem_2_num, 65);
    
    // // // for stem test
    // // for(int_t i = 0; i < 3211264; i++)
    // //     Y[i] = X_stem_2[i]; // assign result to output
    
    // // ========================Sequential 1~4==================================
    // Sequential(X_stem_2, X2_data, X3_data, X_seq,
    //     X_tmp_data, X2_tmp_data, X3_tmp_data, X4_tmp_data,
    //     X_batch_data, X2_batch_data, X3_batch_data, X4_batch_data, 
    //     X_mid_data, X2_mid_data, X3_mid_data, X4_mid_data,
    //     0.07423608750104904175, 65,
    //     Kernel_seq1_0_conv1_0_0, Kernel_seq1_0_conv1_0_3, Kernel_seq1_0_conv2_0_0, Kernel_seq1_0_conv2_0_3, Kernel_seq1_1_conv1_0_0, Kernel_seq1_1_conv1_0_3, Kernel_seq1_1_conv2_0_0, Kernel_seq1_1_conv2_0_3, 
    //     Kernel_seq2_0_conv1_0_0, Kernel_seq2_0_conv1_0_3, Kernel_seq2_0_conv2_0_0, Kernel_seq2_0_conv2_0_3, Kernel_seq2_0_downsample_0, Kernel_seq2_1_conv1_0_0, Kernel_seq2_1_conv1_0_3, Kernel_seq2_1_conv2_0_0, Kernel_seq2_1_conv2_0_3,
    //     Kernel_seq3_0_conv1_0_0, Kernel_seq3_0_conv1_0_3, Kernel_seq3_0_conv2_0_0, Kernel_seq3_0_conv2_0_3, Kernel_seq3_0_downsample_0, Kernel_seq3_1_conv1_0_0, Kernel_seq3_1_conv1_0_3, Kernel_seq3_1_conv2_0_0, Kernel_seq3_1_conv2_0_3,
    //     Kernel_seq4_0_conv1_0_0, Kernel_seq4_0_conv1_0_3, Kernel_seq4_0_conv2_0_0, Kernel_seq4_0_conv2_0_3, Kernel_seq4_0_downsample_0, Kernel_seq4_1_conv1_0_0, Kernel_seq4_1_conv1_0_3, Kernel_seq4_1_conv2_0_0, Kernel_seq4_1_conv2_0_3);

    // // // for sequential test
    // // for(int_t i = 0; i < 50176; i++)
    // //     Y[i] = X_seq[i]; // assign result to output
    
    // // ======================== AdaptiveAvgPool3d ==================================
    // AdaptiveAvgPool3d(X_seq, X_adap);

    // // // for sequential test
    // // for(int_t i = 0; i < 512; i++)
    // //     Y[i] = X_adap[i]; // assign result to output

    // // ======================== Linear ==================================
    // int_t X_adap_flat_num[2] = {1, 512};
    // Linear(X_adap, X_adap_flat_num, X_linear, Kernel_linear);
    
    return;
}
