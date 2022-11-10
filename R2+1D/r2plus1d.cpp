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
            dtype* X_stem_1, dtype* X_stem_2, dtype* X_data, dtype* X2_data, dtype* X3_data, dtype* X_seq, dtype* X_adap, dtype* X_linear, 
            dtype* X_tmp_data, dtype* X_batch_data, dtype* X_mid_data)
{
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS INTERFACE m_axi depth=602112 bundle=gmem0 port=X
    #pragma HLS INTERFACE m_axi depth=2257920 bundle=gmem1 port=X_stem_1
    #pragma HLS INTERFACE m_axi depth=3211264 bundle=gmem0 port=X_stem_2
    #pragma HLS INTERFACE m_axi depth=802816 bundle=gmem0 port=X_data
    #pragma HLS INTERFACE m_axi depth=802816 bundle=gmem0 port=X2_data
    #pragma HLS INTERFACE m_axi depth=200704 bundle=gmem0 port=X3_data
    #pragma HLS INTERFACE m_axi depth=50176 bundle=gmem0 port=X_seq
    #pragma HLS INTERFACE m_axi depth=512 bundle=gmem1 port=X_adap
	#pragma HLS INTERFACE m_axi depth=10 bundle=gmem0 port=X_linear
    #pragma HLS INTERFACE m_axi depth=3211264 bundle=gmem1 port=X_tmp_data
    #pragma HLS INTERFACE m_axi depth=7225344 bundle=gmem2 port=X_batch_data
    #pragma HLS INTERFACE m_axi depth=7225344 bundle=gmem1 port=X_mid_data

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
    int_t Y_num[5] = {1, 45, 16, 56, 56};
    int_t Kernel_num[3] = {1, 7, 7};
    int_t stride[3] = {1, 2, 2};
    int_t padding[3] = {0, 3, 3};
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_stem_0[i];

    // for(int_t yi = 0; yi < 9; yi++){
    //     for(int_t k = 0; k < 5*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0; 
        
    //     for(int_t xi = 0; xi < 3; xi++){
    //         for(int_t k = 0; k < X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X[xi*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 1, Y_bram, Y_num, yi, 5, Kernel_bram, Kernel_num, stride, padding, 56);
    //     }
        
    //     for(int_t c = 0; c < 5; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*3.756307810544967651e-02*Kernel_stem_0_scale[yi*5+c] - Mu_stem_1[yi*5+c]) / sqrtf(Var_stem_1[yi*5+c]+0.00001)) * Gamma_stem_1[yi*5+c] + Bias_stem_1[yi*5+c])/0.07323520630598068237);
    //             Y_bram[offset+k] = (tmp+55 > 255) ? 255 : (tmp < 0) ? 55 : tmp+55;
    //             X_stem_1[yi*5*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }
    // // Conv3d(X, X_num, X_stem_1, X_stem_1_num, Kernel_stem_0, Kernel_stem_1_num, Kernel_stem_0_scale, stride_1, padding_1, 3.756307810544967651e-02, 56, 0.4609071612358093262, 60);
    // // BatchNorm3d(X_stem_1, X_batch_data, X_stem_1_num, Mu_stem_1, Var_stem_1, Gamma_stem_1, Bias_stem_1, 0.4609071612358093262, 60, 0.07323520630598068237, 55);
    // // ReLU(X_batch_data, X_stem_1, X_stem_1_num, 55);

    // X_num[0] = 1; X_num[1] = 45; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 64; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;

    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_stem_3[i];

    // for(int_t yi = 0; yi < 8; yi++){
    //     for(int_t k = 0; k < 8*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0; 
        
    //     for(int_t xi = 0; xi < 9; xi++){
    //         for(int_t k = 0; k < 5*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_stem_1[xi*5*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 5, Y_bram, Y_num, yi, 8, Kernel_bram, Kernel_num, stride, padding, 55);
    //     }
        
    //     for(int_t c = 0; c < 8; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*0.07323520630598068237*Kernel_stem_3_scale[yi*8+c] - Mu_stem_4[yi*8+c]) / sqrtf(Var_stem_4[yi*8+c]+0.00001)) * Gamma_stem_4[yi*8+c] + Bias_stem_4[yi*8+c])/0.07423608750104904175);
    //             Y_bram[offset+k] = (tmp+65 > 255) ? 255 : (tmp < 0) ? 65 : tmp+65;
    //             X_stem_2[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }
    // // Conv3d(X_stem_1, X_stem_1_num, X_stem_2, X_stem_2_num, Kernel_stem_3, Kernel_stem_2_num, Kernel_stem_3_scale, stride_2, padding_2, 0.07323520630598068237, 55, 0.09311912953853607178, 70);
    // // BatchNorm3d(X_stem_2, X_batch_data, X_stem_2_num, Mu_stem_4, Var_stem_4, Gamma_stem_4, Bias_stem_4, 0.09311912953853607178, 70, 0.07423608750104904175, 65);
    // // ReLU(X_batch_data, X_stem_2, X_stem_2_num, 65);

    // // ========================Sequential 1==================================
    // //                      ====basicblock 0=================================
    // X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 144; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq1_0_conv1_0_0[i];

    // for(int_t yi = 0; yi < 18; yi++){
    //     for(int_t k = 0; k < 8*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 8; xi++){
    //         for(int_t k = 0; k < 8*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_stem_2[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 8, Y_bram, Y_num, yi, 8, Kernel_bram, Kernel_num, stride, padding, 65);
    //     }
        
    //     for(int_t c = 0; c < 8; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*0.07423608750104904175*Kernel_seq1_0_conv1_0_0_scale[yi*8+c] - Mu_seq1_0_conv1_0_1[yi*8+c]) / sqrtf(Var_seq1_0_conv1_0_1[yi*8+c]+0.00001)) * Gamma_seq1_0_conv1_0_1[yi*8+c] + Bias_seq1_0_conv1_0_1[yi*8+c])/4.489336907863616943e-02);
    //             Y_bram[offset+k] = (tmp+60 > 255) ? 255 : (tmp < 0) ? 60 : tmp+60;
    //             X_mid_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }
    
    // X_num[0] = 1; X_num[1] = 144; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 64; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq1_0_conv1_0_3[i];

    // for(int_t yi = 0; yi < 8; yi++){
    //     for(int_t k = 0; k < 8*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 18; xi++){
    //         for(int_t k = 0; k < 8*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_mid_data[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 8, Y_bram, Y_num, yi, 8, Kernel_bram, Kernel_num, stride, padding, 60);
    //     }
        
    //     for(int_t c = 0; c < 8; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*4.489336907863616943e-02*Kernel_seq1_0_conv1_0_3_scale[yi*8+c] - Mu_seq1_0_conv1_1[yi*8+c]) / sqrtf(Var_seq1_0_conv1_1[yi*8+c]+0.00001)) * Gamma_seq1_0_conv1_1[yi*8+c] + Bias_seq1_0_conv1_1[yi*8+c])/5.436319485306739807e-02);
    //             Y_bram[offset+k] = (tmp+74 > 255) ? 255 : (tmp < 0) ? 74 : tmp+74;
    //             X_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }
    // // seq1.0.conv2
    // X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 144; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq1_0_conv2_0_0[i];

    // for(int_t yi = 0; yi < 18; yi++){
    //     for(int_t k = 0; k < 8*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 8; xi++){
    //         for(int_t k = 0; k < 8*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_data[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 8, Y_bram, Y_num, yi, 8, Kernel_bram, Kernel_num, stride, padding, 74);
    //     }
        
    //     for(int_t c = 0; c < 8; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*5.436319485306739807e-02*Kernel_seq1_0_conv2_0_0_scale[yi*8+c] - Mu_seq1_0_conv2_0_1[yi*8+c]) / sqrtf(Var_seq1_0_conv2_0_1[yi*8+c]+0.00001)) * Gamma_seq1_0_conv2_0_1[yi*8+c] + Bias_seq1_0_conv2_0_1[yi*8+c])/4.303903132677078247e-02);
    //             Y_bram[offset+k] = (tmp+62 > 255) ? 255 : (tmp < 0) ? 62 : tmp+62;
    //             X_mid_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }
    
    // todo: fix residual
    X_num[0] = 1; X_num[1] = 144; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    Y_num[0] = 1; Y_num[1] = 64; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    stride[0] = 1; stride[1] = 1; stride[2] = 1;
    padding[0] = 1; padding[1] = 0; padding[2] = 0;
    
    for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
        Kernel_bram[i] = Kernel_seq1_0_conv2_0_3[i];

    for(int_t yi = 0; yi < 8; yi++){
        for(int_t k = 0; k < 8*Y_num[2]*Y_num[3]*Y_num[4]; k++)
            Y_bram[k] = 0;
        
        for(int_t xi = 0; xi < 18; xi++){
            for(int_t k = 0; k < 8*X_num[2]*X_num[3]*X_num[4]; k++)
                X_bram[k] = X_mid_data[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

            Conv3d(X_bram, X_num, xi, 8, Y_bram, Y_num, yi, 8, Kernel_bram, Kernel_num, stride, padding, 62);
        }
        
        for(int_t c = 0; c < 8; c++){
            int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
            for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
                ftype ftmp = (((ftype)(Y_bram[offset+k]*4.303903132677078247e-02*Kernel_seq1_0_conv2_0_3_scale[yi*8+c]) - Mu_seq1_0_conv2_1[yi*8+c]) / sqrtf(Var_seq1_0_conv2_1[yi*8+c]+0.00001)) * Gamma_seq1_0_conv2_1[yi*8+c] + Bias_seq1_0_conv2_1[yi*8+c];
                int_t tmp = (ftmp + (ftype)((X_stem_2[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k]-65)*0.07423608750104904175)) / 7.029289007186889648e-02;
                Y_bram[offset+k] = (tmp+46 > 255) ? 255 : (tmp < 0) ? 46 : tmp+46;
                X_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];

            }
        }
    }
    // // for(int_t i = 0; i < 3211264; i++)
    // // X_data[i] = (ftype)((X_stem_2[i]-65)*0.07423608750104904175 + (X_data[i]-68)*4.517441987991333008e-02) / 7.029289007186889648e-02 + 46;

    // //                      ====basicblock 1=================================
    // X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 144; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq1_1_conv1_0_0[i];

    // for(int_t yi = 0; yi < 18; yi++){
    //     for(int_t k = 0; k < 8*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 8; xi++){
    //         for(int_t k = 0; k < 8*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_data[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 8, Y_bram, Y_num, yi, 8, Kernel_bram, Kernel_num, stride, padding, 46);
    //     }
        
    //     for(int_t c = 0; c < 8; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*7.029289007186889648e-02*Kernel_seq1_1_conv1_0_0_scale[yi*8+c] - Mu_seq1_1_conv1_0_1[yi*8+c]) / sqrtf(Var_seq1_1_conv1_0_1[yi*8+c]+0.00001)) * Gamma_seq1_1_conv1_0_1[yi*8+c] + Bias_seq1_1_conv1_0_1[yi*8+c])/3.406318649649620056e-02);
    //             Y_bram[offset+k] = (tmp+76 > 255) ? 255 : (tmp < 0) ? 76 : tmp+76;
    //             X_mid_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }
    
    // X_num[0] = 1; X_num[1] = 144; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 64; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq1_1_conv1_0_3[i];

    // for(int_t yi = 0; yi < 8; yi++){
    //     for(int_t k = 0; k < 8*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 18; xi++){
    //         for(int_t k = 0; k < 8*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_mid_data[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 8, Y_bram, Y_num, yi, 8, Kernel_bram, Kernel_num, stride, padding, 76);
    //     }
        
    //     for(int_t c = 0; c < 8; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*3.406318649649620056e-02*Kernel_seq1_1_conv1_0_3_scale[yi*8+c] - Mu_seq1_1_conv1_1[yi*8+c]) / sqrtf(Var_seq1_1_conv1_1[yi*8+c]+0.00001)) * Gamma_seq1_1_conv1_1[yi*8+c] + Bias_seq1_1_conv1_1[yi*8+c])/4.148417711257934570e-02);
    //             Y_bram[offset+k] = (tmp+70 > 255) ? 255 : (tmp < 0) ? 70 : tmp+70;
    //             X_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }

    // // seq1.1.conv2
    // X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 144; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq1_1_conv2_0_0[i];

    // for(int_t yi = 0; yi < 18; yi++){
    //     for(int_t k = 0; k < 8*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 8; xi++){
    //         for(int_t k = 0; k < 8*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_data[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 8, Y_bram, Y_num, yi, 8, Kernel_bram, Kernel_num, stride, padding, 70);
    //     }
        
    //     for(int_t c = 0; c < 8; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*4.148417711257934570e-02*Kernel_seq1_1_conv2_0_0_scale[yi*8+c] - Mu_seq1_1_conv2_0_1[yi*8+c]) / sqrtf(Var_seq1_1_conv2_0_1[yi*8+c]+0.00001)) * Gamma_seq1_1_conv2_0_1[yi*8+c] + Bias_seq1_1_conv2_0_1[yi*8+c])/2.891838178038597107e-02);
    //             Y_bram[offset+k] = (tmp+61 > 255) ? 255 : (tmp < 0) ? 61 : tmp+61;
    //             X_mid_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }

    // // todo: fix residual
    // X_num[0] = 1; X_num[1] = 144; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 64; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq1_1_conv2_0_3[i];

    // for(int_t yi = 0; yi < 8; yi++){
    //     for(int_t k = 0; k < 8*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 18; xi++){
    //         for(int_t k = 0; k < 8*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_mid_data[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 8, Y_bram, Y_num, yi, 8, Kernel_bram, Kernel_num, stride, padding, 61);
    //     }
        
    //     for(int_t c = 0; c < 8; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf(((Y_bram[offset+k]*2.891838178038597107e-02*Kernel_seq1_1_conv2_0_3_scale[yi*8+c] - Mu_seq1_1_conv2_1[yi*8+c]) / sqrtf(Var_seq1_1_conv2_1[yi*8+c]+0.00001)) * Gamma_seq1_1_conv2_1[yi*8+c] + Bias_seq1_1_conv2_1[yi*8+c]);
    //             tmp += (dtype)roundf((ftype)((X_stem_2[offset+k])-65) * 0.07423608750104904175 / 7.029289007186889648e-02);
    //             Y_bram[offset+k] = (tmp+49 > 255) ? 255 : (tmp < 0) ? 49 : tmp+49;
    //             X_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }
    // BatchNorm3d(X_data, X_batch_data, X_num, Mu_seq1_1_conv2_1, Var_seq1_1_conv2_1, Gamma_seq1_1_conv2_1, Bias_seq1_1_conv2_1,2.731916867196559906e-02, 71, 5.917721241712570190e-02, 53);
    // Residual(X_batch_data, X_tmp_data, X_num, 5.917721241712570190e-02, 7.029289007186889648e-02, 7.128605991601943970e-02, 53, 46, 49);
    // ReLU(X_batch_data, X_data, X_num, 49);

    // ================================!!!!===================
    
    // Sequential(X_stem_2, X2_data, X3_data, X_seq,
    //     X_tmp_data, X_batch_data, X_mid_data, 
    //     Kernel_seq2_0_conv1_0_0, Kernel_seq2_0_conv1_0_3, Kernel_seq2_0_conv2_0_0, Kernel_seq2_0_conv2_0_3, Kernel_seq2_0_downsample_0, Kernel_seq2_1_conv1_0_0, Kernel_seq2_1_conv1_0_3, Kernel_seq2_1_conv2_0_0, Kernel_seq2_1_conv2_0_3,
    //     Kernel_seq3_0_conv1_0_0, Kernel_seq3_0_conv1_0_3, Kernel_seq3_0_conv2_0_0, Kernel_seq3_0_conv2_0_3, Kernel_seq3_0_downsample_0, Kernel_seq3_1_conv1_0_0, Kernel_seq3_1_conv1_0_3, Kernel_seq3_1_conv2_0_0, Kernel_seq3_1_conv2_0_3,
    //     Kernel_seq4_0_conv1_0_0, Kernel_seq4_0_conv1_0_3, Kernel_seq4_0_conv2_0_0, Kernel_seq4_0_conv2_0_3, Kernel_seq4_0_downsample_0, Kernel_seq4_1_conv1_0_0, Kernel_seq4_1_conv1_0_3, Kernel_seq4_1_conv2_0_0, Kernel_seq4_1_conv2_0_3);
    
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
