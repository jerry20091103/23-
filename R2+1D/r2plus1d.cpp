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
    #pragma HLS INTERFACE m_axi depth=3211264 bundle=gmem0 port=X_data
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
    
    // URAM kernel buffer
    #pragma HLS BIND_STORAGE variable=Kernel_bram type=RAM_2P impl=URAM
    #pragma HLS ARRAY_RESHAPE variable= Kernel_bram factor=9 type=cyclic

    #pragma HLS BIND_STORAGE variable=X_bram type=RAM_2P impl=URAM
    #pragma HLS ARRAY_RESHAPE variable= X_bram factor=9 type=cyclic
    // ========================R2Plus1dStem ==================================
	int_t X_num[5] = {1, 3, 16, 112, 112};
    int_t Y_num[5] = {1, 45, 16, 56, 56};
    int_t Kernel_num[3] = {1, 7, 7};
    int_t stride[3] = {1, 2, 2};
    int_t padding[3] = {0, 3, 3};
    // CBR(X, X_num, 1, 
	// 	X_stem_1, Y_num, 5, 
	// 	Kernel_stem_0, Kernel_num, 
	// 	stride, padding, 
	// 	56, 3.756307810544967651e-02, 55, 0.07323520630598068237, 
    //     Kernel_stem_0_scale, Mu_stem_1, Var_stem_1, Gamma_stem_1, Bias_stem_1);
    
    // X_num[0] = 1; X_num[1] = 45; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 64; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    // CBR(X_stem_1, X_num, 5, 
	// 	X_stem_2, Y_num, 8, 
	// 	Kernel_stem_3, Kernel_num, 
	// 	stride, padding, 
	// 	55, 0.07323520630598068237, 65, 0.07423608750104904175, 
    //     Kernel_stem_3_scale, Mu_stem_4, Var_stem_4, Gamma_stem_4, Bias_stem_4);

    // // ========================Sequential 1==================================
    // //                      ====basicblock 0=================================
    // X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 144; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    
    // CBR(X_stem_2, X_num, 8, 
	// 	X_mid_data, Y_num, 8, 
	// 	Kernel_seq1_0_conv1_0_0, Kernel_num, 
	// 	stride, padding, 
	// 	65, 0.07423608750104904175, 60, 4.489336907863616943e-02, 
    //     Kernel_seq1_0_conv1_0_0_scale, Mu_seq1_0_conv1_0_1, Var_seq1_0_conv1_0_1, Gamma_seq1_0_conv1_0_1, Bias_seq1_0_conv1_0_1);
    
    
    // X_num[0] = 1; X_num[1] = 144; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 64; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    // CBR(X_mid_data, X_num, 8, 
	// 	X_data, Y_num, 8, 
	// 	Kernel_seq1_0_conv1_0_3, Kernel_num, 
	// 	stride, padding, 
	// 	60, 4.489336907863616943e-02, 74, 5.436319485306739807e-02,
    //     Kernel_seq1_0_conv1_0_3_scale, Mu_seq1_0_conv1_1, Var_seq1_0_conv1_1, Gamma_seq1_0_conv1_1, Bias_seq1_0_conv1_1);
    
    // // seq1.0.conv2
    // X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 144; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    // CBR(X_data, X_num, 8, 
	// 	X_mid_data, Y_num, 8, 
	// 	Kernel_seq1_0_conv2_0_0, Kernel_num, 
	// 	stride, padding, 
	// 	74, 5.436319485306739807e-02, 62, 4.303903132677078247e-02,
    //     Kernel_seq1_0_conv2_0_0_scale, Mu_seq1_0_conv2_0_1, Var_seq1_0_conv2_0_1, Gamma_seq1_0_conv2_0_1, Bias_seq1_0_conv2_0_1);
    
    
    // X_num[0] = 1; X_num[1] = 144; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 64; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    // CBRR(X_mid_data, X_stem_2, X_num, 8, 
	// 	X_data, X_tmp_data, Y_num, 8, 
	// 	Kernel_seq1_0_conv2_0_3, Kernel_num,
	// 	stride, padding, 
	// 	62, 4.303903132677078247e-02, 65, 0.07423608750104904175, 46, 7.029289007186889648e-02, 
	// 	Kernel_seq1_0_conv2_0_3_scale, Mu_seq1_0_conv2_1, Var_seq1_0_conv2_1, Gamma_seq1_0_conv2_1, Bias_seq1_0_conv2_1);
    
    // //                      ====basicblock 1=================================
    // X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 144; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    // CBR(X_data, X_num, 8, 
	// 	X_mid_data, Y_num, 8, 
	// 	Kernel_seq1_1_conv1_0_0, Kernel_num, 
	// 	stride, padding, 
	// 	46, 7.029289007186889648e-02, 76, 3.406318649649620056e-02,
    //     Kernel_seq1_1_conv1_0_0_scale, Mu_seq1_1_conv1_0_1, Var_seq1_1_conv1_0_1, Gamma_seq1_1_conv1_0_1, Bias_seq1_1_conv1_0_1);

    
    // X_num[0] = 1; X_num[1] = 144; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 64; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    // CBR(X_mid_data, X_num, 8, 
	// 	X_data, Y_num, 8, 
	// 	Kernel_seq1_1_conv1_0_3, Kernel_num, 
	// 	stride, padding, 
	// 	76, 3.406318649649620056e-02, 70, 4.148417711257934570e-02,
    //     Kernel_seq1_1_conv1_0_3_scale, Mu_seq1_1_conv1_1, Var_seq1_1_conv1_1, Gamma_seq1_1_conv1_1, Bias_seq1_1_conv1_1);
    
    // ======= CSIM PASS =====
    
    // seq1.1.conv2
    X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    Y_num[0] = 1; Y_num[1] = 144; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    stride[0] = 1; stride[1] = 1; stride[2] = 1;
    padding[0] = 0; padding[1] = 1; padding[2] = 1;
    CBR(X_data, X_num, 8, 
		X_mid_data, Y_num, 8, 
		Kernel_seq1_1_conv2_0_0, Kernel_num, 
		stride, padding, 
		70, 4.148417711257934570e-02, 61, 2.891838178038597107e-02, 
        Kernel_seq1_1_conv2_0_0_scale, Mu_seq1_1_conv2_0_1, Var_seq1_1_conv2_0_1, Gamma_seq1_1_conv2_0_1, Bias_seq1_1_conv2_0_1);
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

    X_num[0] = 1; X_num[1] = 144; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    Y_num[0] = 1; Y_num[1] = 64; Y_num[2] = 16; Y_num[3] = 56; Y_num[4] = 56;
    Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    stride[0] = 1; stride[1] = 1; stride[2] = 1;
    padding[0] = 1; padding[1] = 0; padding[2] = 0;
    CBRR(X_mid_data, X_tmp_data, X_num, 8, 
		X_data, X_tmp_data, Y_num, 8, 
		Kernel_seq1_1_conv2_0_3, Kernel_num,
		stride, padding, 
		61, 2.891838178038597107e-02, 46, 7.029289007186889648e-02, 49, 7.128605991601943970e-02, 
		Kernel_seq1_1_conv2_0_3_scale, Mu_seq1_1_conv2_1, Var_seq1_1_conv2_1, Gamma_seq1_1_conv2_1, Bias_seq1_1_conv2_1);
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
    //             ftype ftmp = (((ftype)(Y_bram[offset+k]*2.891838178038597107e-02*Kernel_seq1_1_conv2_0_3_scale[yi*8+c]) - Mu_seq1_1_conv2_1[yi*8+c]) / sqrtf(Var_seq1_1_conv2_1[yi*8+c]+0.00001)) * Gamma_seq1_1_conv2_1[yi*8+c] + Bias_seq1_1_conv2_1[yi*8+c];
    //             int_t tmp = (ftmp + (ftype)((X_tmp_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k]-46)*7.029289007186889648e-02)) / 7.128605991601943970e-02;
    //             Y_bram[offset+k] = (tmp+49 > 255) ? 255 : (tmp < 0) ? 49 : tmp+49;
    //             X_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }

    // ========================Sequential 2==================================
    //                      ====basicblock 0=================================
    X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    Y_num[0] = 1; Y_num[1] = 230; Y_num[2] = 16; Y_num[3] = 28; Y_num[4] = 28;
    Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    stride[0] = 1; stride[1] = 2; stride[2] = 2;
    padding[0] = 0; padding[1] = 1; padding[2] = 1;
    CBR(X_data, X_num, 8, 
		X_mid_data, Y_num, 32, 
		Kernel_seq2_0_conv1_0_0, Kernel_num, 
		stride, padding, 
		49, 7.128605991601943970e-02, 66, 3.834486752748489380e-02, 
        Kernel_seq2_0_conv1_0_0_scale, Mu_seq2_0_conv1_0_1, Var_seq2_0_conv1_0_1, Gamma_seq2_0_conv1_0_1, Bias_seq2_0_conv1_0_1);
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq2_0_conv1_0_0[i];

    // for(int_t yi = 0; yi < 8; yi++){
    //     for(int_t k = 0; k < 32*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 8; xi++){
    //         for(int_t k = 0; k < 8*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_data[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 8, Y_bram, Y_num, yi, 32, Kernel_bram, Kernel_num, stride, padding, 49);
    //     }
        
    //     for(int_t c = 0; c < 32; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*7.128605991601943970e-02*Kernel_seq2_0_conv1_0_0_scale[yi*32+c] - Mu_seq2_0_conv1_0_1[yi*32+c]) / sqrtf(Var_seq2_0_conv1_0_1[yi*32+c]+0.00001)) * Gamma_seq2_0_conv1_0_1[yi*32+c] + Bias_seq2_0_conv1_0_1[yi*32+c])/3.834486752748489380e-02);
    //             Y_bram[offset+k] = (tmp+66 > 255) ? 255 : (tmp < 0) ? 66 : tmp+66;
    //             X_mid_data[yi*32*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }
    

    X_num[0] = 1; X_num[1] = 230; X_num[2] = 16; X_num[3] = 28; X_num[4] = 28;
    Y_num[0] = 1; Y_num[1] = 128; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    stride[0] = 1; stride[1] = 1; stride[2] = 1;
    padding[0] = 1; padding[1] = 0; padding[2] = 0;
    CBR(X_mid_data, X_num, 32, 
		X2_data, Y_num, 64, 
		Kernel_seq2_0_conv1_0_3, Kernel_num, 
		stride, padding, 
		66, 3.834486752748489380e-02, 52, 3.730613738298416138e-02,
        Kernel_seq2_0_conv1_0_3_scale, Mu_seq2_0_conv1_1, Var_seq2_0_conv1_1, Gamma_seq2_0_conv1_1, Bias_seq2_0_conv1_1);
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq2_0_conv1_0_3[i];

    // for(int_t yi = 0; yi < 2; yi++){
    //     for(int_t k = 0; k < 64*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 8; xi++){
    //         for(int_t k = 0; k < 32*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_mid_data[xi*32*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 32, Y_bram, Y_num, yi, 64, Kernel_bram, Kernel_num, stride, padding, 66);
    //     }
        
    //     for(int_t c = 0; c < 64; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*3.834486752748489380e-02*Kernel_seq2_0_conv1_0_3_scale[yi*64+c] - Mu_seq2_0_conv1_1[yi*64+c]) / sqrtf(Var_seq2_0_conv1_1[yi*64+c]+0.00001)) * Gamma_seq2_0_conv1_1[yi*64+c] + Bias_seq2_0_conv1_1[yi*64+c])/3.730613738298416138e-02);
    //             Y_bram[offset+k] = (tmp+52 > 255) ? 255 : (tmp < 0) ? 52 : tmp+52;
    //             X2_data[yi*64*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }

    // seq2.0.conv2
    X_num[0] = 1; X_num[1] = 128; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    Y_num[0] = 1; Y_num[1] = 230; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    stride[0] = 1; stride[1] = 1; stride[2] = 1;
    padding[0] = 0; padding[1] = 1; padding[2] = 1;
    CBR(X2_data, X_num, 64, 
		X_mid_data, Y_num, 64, 
		Kernel_seq2_0_conv2_0_0, Kernel_num, 
		stride, padding, 
		52, 3.730613738298416138e-02, 75, 3.696846589446067810e-02, 
        Kernel_seq2_0_conv2_0_0_scale, Mu_seq2_0_conv2_0_1, Var_seq2_0_conv2_0_1, Gamma_seq2_0_conv2_0_1, Bias_seq2_0_conv2_0_1);
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq2_0_conv2_0_0[i];

    // for(int_t yi = 0; yi < 3; yi++){
    //     for(int_t k = 0; k < 64*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 2; xi++){
    //         for(int_t k = 0; k < 64*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X2_data[xi*64*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 64, Y_bram, Y_num, yi, 64, Kernel_bram, Kernel_num, stride, padding, 52);
    //     }
        
    //     for(int_t c = 0; c < 64; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*3.730613738298416138e-02*Kernel_seq2_0_conv2_0_0_scale[yi*64+c] - Mu_seq2_0_conv2_0_1[yi*64+c]) / sqrtf(Var_seq2_0_conv2_0_1[yi*64+c]+0.00001)) * Gamma_seq2_0_conv2_0_1[yi*64+c] + Bias_seq2_0_conv2_0_1[yi*8+c])/3.696846589446067810e-02);
    //             Y_bram[offset+k] = (tmp+75 > 255) ? 255 : (tmp < 0) ? 75 : tmp+75;
    //             X_mid_data[yi*64*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }

    // seq2.0.downsample
    X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    Y_num[0] = 1; Y_num[1] = 128; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    Kernel_num[0] = 1; Kernel_num[1] = 1; Kernel_num[2] = 1;
    stride[0] = 2; stride[1] = 2; stride[2] = 2;
    padding[0] = 0; padding[1] = 0; padding[2] = 0;
    CBR(X_data, X_num, 8, 
		X_tmp_data, Y_num, 64, 
		Kernel_seq2_0_downsample_0, Kernel_num, 
		stride, padding, 
		49, 7.128605991601943970e-02, 53, 5.571814253926277161e-02, 
        Kernel_seq2_0_downsample_0_scale, Mu_seq2_0_downsample_1, Var_seq2_0_downsample_1, Gamma_seq2_0_downsample_1, Bias_seq2_0_downsample_1);
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq2_0_downsample_0[i];

    // for(int_t yi = 0; yi < 2; yi++){
    //     for(int_t k = 0; k < 64*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;

    //     for(int_t xi = 0; xi < 8; xi++){
    //         for(int_t k = 0; k < 8*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_data[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 8, Y_bram, Y_num, yi, 64, Kernel_bram, Kernel_num, stride, padding, 49);
    //     }
        
    //     for(int_t c = 0; c < 64; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*7.128605991601943970e-02*Kernel_seq2_0_downsample_0_scale[yi*64+c] - Mu_seq2_0_downsample_1[yi*64+c]) / sqrtf(Var_seq2_0_downsample_1[yi*64+c]+0.00001)) * Gamma_seq2_0_downsample_1[yi*64+c] + Bias_seq2_0_downsample_1[yi*8+c])/5.571814253926277161e-02);
    //             Y_bram[offset+k] = (tmp+53 > 255) ? 255 : (tmp < 0) ? 0 : tmp+53;
    //             X_tmp_data[yi*64*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }

    X_num[0] = 1; X_num[1] = 230; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    Y_num[0] = 1; Y_num[1] = 128; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    stride[0] = 1; stride[1] = 1; stride[2] = 1;
    padding[0] = 1; padding[1] = 0; padding[2] = 0;
    CBRR(X_mid_data, X_tmp_data, X_num, 64, 
		X2_data, X_tmp_data, Y_num, 64, 
		Kernel_seq2_0_conv2_0_3, Kernel_num,
		stride, padding, 
		75, 3.696846589446067810e-02, 53, 5.571814253926277161e-02, 59, 5.941560864448547363e-02, 
		Kernel_seq2_0_conv2_0_3_scale, Mu_seq2_0_conv2_1, Var_seq2_0_conv2_1, Gamma_seq2_0_conv2_1, Bias_seq2_0_conv2_1);
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq2_0_conv2_0_3[i];

    // for(int_t yi = 0; yi < 2; yi++){
    //     for(int_t k = 0; k < 64*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 4; xi++){
    //         for(int_t k = 0; k < 64*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_mid_data[xi*8*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 64, Y_bram, Y_num, yi, 64, Kernel_bram, Kernel_num, stride, padding, 75);
    //     }
        
    //     for(int_t c = 0; c < 64; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             ftype ftmp = (((ftype)(Y_bram[offset+k]*3.696846589446067810e-02*Kernel_seq2_0_conv2_0_3_scale[yi*64+c]) - Mu_seq2_0_conv2_1[yi*64+c]) / sqrtf(Var_seq2_0_conv2_1[yi*64+c]+0.00001)) * Gamma_seq2_0_conv2_1[yi*64+c] + Bias_seq2_0_conv2_1[yi*64+c];
    //             int_t tmp = (ftmp + (ftype)(((X_tmp_data[yi*64*Y_num[2]*Y_num[3]*Y_num[4]+offset+k])-53)*5.571814253926277161e-02)) / 5.941560864448547363e-02;
    //             Y_bram[offset+k] = (tmp+59 > 255) ? 255 : (tmp < 0) ? 59 : tmp+59;
    //             X2_data[yi*64*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //             X_tmp_data[yi*64*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }

    //                      ====basicblock 1=================================   need to clip kernel
    // X_num[0] = 1; X_num[1] = 128; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    // Y_num[0] = 1; Y_num[1] = 288; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    // CBR_k(X_data, X_num,  XC, 
	// 	Y_data, Y_num,  YC, 
	// 	Kernel_data,  Kernel_num,
	// 	stride, padding, 
	// 	conv_zp, conv_scale, batch_zp, batch_scale, 
	// 	Kernel_scale, Mu, Var, Gamma, Bias)
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq2_1_conv1_0_0[i];

    // for(int_t yi = 0; yi < 5; yi++){
    //     for(int_t k = 0; k < 64*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 2; xi++){
    //         for(int_t k = 0; k < 64*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X2_data[xi*64*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 64, Y_bram, Y_num, yi, 64, Kernel_bram, Kernel_num, stride, padding, 59);
    //     }
        
    //     for(int_t c = 0; c < 64; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*5.941560864448547363e-02*Kernel_seq2_1_conv1_0_0_scale[yi*64+c] - Mu_seq2_1_conv1_0_1[yi*64+c]) / sqrtf(Var_seq2_1_conv1_0_1[yi*64+c]+0.00001)) * Gamma_seq2_1_conv1_0_1[yi*64+c] + Bias_seq2_1_conv1_0_1[yi*8+c])/2.571923658251762390e-02);
    //             Y_bram[offset+k] = (tmp+74 > 255) ? 255 : (tmp < 0) ? 74 : tmp+74;
    //             X_mid_data[yi*64*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }

    // X_num[0] = 1; X_num[1] = 288; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    // Y_num[0] = 1; Y_num[1] = 128; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq2_1_conv1_0_3[i];

    // for(int_t yi = 0; yi < 2; yi++){
    //     for(int_t k = 0; k < 64*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 5; xi++){
    //         for(int_t k = 0; k < 64*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_mid_data[xi*64*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 64, Y_bram, Y_num, yi, 64, Kernel_bram, Kernel_num, stride, padding, 74);
    //     }
        
    //     for(int_t c = 0; c < 64; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*2.571923658251762390e-02*Kernel_seq2_1_conv1_0_3_scale[yi*64+c] - Mu_seq2_1_conv1_1[yi*64+c]) / sqrtf(Var_seq2_1_conv1_1[yi*64+c]+0.00001)) * Gamma_seq2_1_conv1_1[yi*64+c] + Bias_seq2_1_conv1_1[yi*64+c])/4.108780622482299805e-02);
    //             Y_bram[offset+k] = (tmp+69 > 255) ? 255 : (tmp < 0) ? 69 : tmp+69;
    //             X2_data[yi*8*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }

    // // seq2.1.conv2
    // X_num[0] = 1; X_num[1] = 128; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    // Y_num[0] = 1; Y_num[1] = 288; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq2_1_conv2_0_0[i];

    // for(int_t yi = 0; yi < 5; yi++){
    //     for(int_t k = 0; k < 64*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 2; xi++){
    //         for(int_t k = 0; k < 64*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X2_data[xi*64*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 64, Y_bram, Y_num, yi, 64, Kernel_bram, Kernel_num, stride, padding, 69);
    //     }
        
    //     for(int_t c = 0; c < 64; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf((((Y_bram[offset+k]*4.108780622482299805e-02*Kernel_seq2_1_conv2_0_0_scale[yi*64+c] - Mu_seq2_1_conv2_0_1[yi*64+c]) / sqrtf(Var_seq2_1_conv2_0_1[yi*64+c]+0.00001)) * Gamma_seq2_1_conv2_0_1[yi*64+c] + Bias_seq2_1_conv2_0_1[yi*64+c])/3.150121122598648071e-02);
    //             Y_bram[offset+k] = (tmp+69 > 255) ? 255 : (tmp < 0) ? 69 : tmp+69;
    //             X_mid_data[yi*64*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }

    // X_num[0] = 1; X_num[1] = 288; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    // Y_num[0] = 1; Y_num[1] = 128; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    
    // for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
    //     Kernel_bram[i] = Kernel_seq1_1_conv2_0_3[i];

    // for(int_t yi = 0; yi < 2; yi++){
    //     for(int_t k = 0; k < 64*Y_num[2]*Y_num[3]*Y_num[4]; k++)
    //         Y_bram[k] = 0;
        
    //     for(int_t xi = 0; xi < 5; xi++){
    //         for(int_t k = 0; k < 64*X_num[2]*X_num[3]*X_num[4]; k++)
    //             X_bram[k] = X_mid_data[xi*64*X_num[2]*X_num[3]*X_num[4]+k];

    //         Conv3d(X_bram, X_num, xi, 64, Y_bram, Y_num, yi, 64, Kernel_bram, Kernel_num, stride, padding, 69);
    //     }
        
    //     for(int_t c = 0; c < 64; c++){
    //         int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
    //         for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
    //             int_t tmp = (int_t)roundf(((Y_bram[offset+k]*3.150121122598648071e-02*Kernel_seq1_1_conv2_0_3_scale[yi*64+c] - Mu_seq1_1_conv2_1[yi*64+c]) / sqrtf(Var_seq1_1_conv2_1[yi*64+c]+0.00001)) * Gamma_seq1_1_conv2_1[yi*64+c] + Bias_seq1_1_conv2_1[yi*64+c]);
    //             tmp += (dtype)roundf((ftype)((X_tmp_data[yi*64*Y_num[2]*Y_num[3]*Y_num[4]+offset+k])-59) * 5.941560864448547363e-02 / 7.469348609447479248e-02);
    //             Y_bram[offset+k] = (tmp+58 > 255) ? 255 : (tmp < 0) ? 58 : tmp+58;
    //             X2_data[yi*64*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
    //         }
    //     }
    // }
    // ================================ end ===================
    
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
