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
    #pragma HLS INTERFACE m_axi depth=602112  bundle=gmem0 port=X            max_widen_bitwidth=32 
    #pragma HLS INTERFACE m_axi depth=2257920 bundle=gmem1 port=X_stem_1     max_widen_bitwidth=32 
    #pragma HLS INTERFACE m_axi depth=3211264 bundle=gmem0 port=X_stem_2     max_widen_bitwidth=32 
    #pragma HLS INTERFACE m_axi depth=3211264 bundle=gmem0 port=X_data       max_widen_bitwidth=32 
    #pragma HLS INTERFACE m_axi depth=802816  bundle=gmem0 port=X2_data      max_widen_bitwidth=32 
    #pragma HLS INTERFACE m_axi depth=200704  bundle=gmem0 port=X3_data      max_widen_bitwidth=32 
    #pragma HLS INTERFACE m_axi depth=50176   bundle=gmem0 port=X_seq        max_widen_bitwidth=32 
    #pragma HLS INTERFACE m_axi depth=512     bundle=gmem1 port=X_adap       max_widen_bitwidth=32 
	#pragma HLS INTERFACE m_axi depth=10      bundle=gmem0 port=X_linear     max_widen_bitwidth=32 
    #pragma HLS INTERFACE m_axi depth=3211264 bundle=gmem1 port=X_tmp_data   max_widen_bitwidth=32 
    #pragma HLS INTERFACE m_axi depth=7225344 bundle=gmem2 port=X_batch_data max_widen_bitwidth=32 
    #pragma HLS INTERFACE m_axi depth=7225344 bundle=gmem1 port=X_mid_data   max_widen_bitwidth=32 

    #pragma HLS INTERFACE m_axi depth=6615    port=Kernel_stem_0               max_widen_bitwidth=32
	#pragma HLS INTERFACE m_axi depth=8640    port=Kernel_stem_3               max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=82944   port=Kernel_seq1_0_conv1_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=27648   port=Kernel_seq1_0_conv1_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=82944   port=Kernel_seq1_0_conv2_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=27648   port=Kernel_seq1_0_conv2_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=82944   port=Kernel_seq1_1_conv1_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=27648   port=Kernel_seq1_1_conv1_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=82944   port=Kernel_seq1_1_conv2_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=27648   port=Kernel_seq1_1_conv2_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=132480  port=Kernel_seq2_0_conv1_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=88320   port=Kernel_seq2_0_conv1_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=264960  port=Kernel_seq2_0_conv2_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=88320   port=Kernel_seq2_0_conv2_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=8192    port=Kernel_seq2_0_downsample_0  max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=331776  port=Kernel_seq2_1_conv1_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=110592  port=Kernel_seq2_1_conv1_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=331776  port=Kernel_seq2_1_conv2_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=110592  port=Kernel_seq2_1_conv2_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=529920  port=Kernel_seq3_0_conv1_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=353280  port=Kernel_seq3_0_conv1_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=1059840 port=Kernel_seq3_0_conv2_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=353280  port=Kernel_seq3_0_conv2_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=32768   port=Kernel_seq3_0_downsample_0  max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=1327104 port=Kernel_seq3_1_conv1_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=442368  port=Kernel_seq3_1_conv1_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=1327104 port=Kernel_seq3_1_conv2_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=442368  port=Kernel_seq3_1_conv2_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=2121984 port=Kernel_seq4_0_conv1_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=1414656 port=Kernel_seq4_0_conv1_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=4243968 port=Kernel_seq4_0_conv2_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=1414656 port=Kernel_seq4_0_conv2_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=131072  port=Kernel_seq4_0_downsample_0  max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=5308416 port=Kernel_seq4_1_conv1_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=1769472 port=Kernel_seq4_1_conv1_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=5308416 port=Kernel_seq4_1_conv2_0_0     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=1769472 port=Kernel_seq4_1_conv2_0_3     max_widen_bitwidth=32
    #pragma HLS INTERFACE m_axi depth=5120    port=Kernel_linear               max_widen_bitwidth=32
    
    // URAM kernel buffer
    #pragma HLS BIND_STORAGE variable=Kernel_bram type=RAM_2P impl=URAM
    #pragma HLS ARRAY_RESHAPE variable= Kernel_bram factor=9 type=cyclic

    #pragma HLS BIND_STORAGE variable=X_bram type=RAM_2P impl=URAM
    #pragma HLS ARRAY_RESHAPE variable= X_bram factor=9 type=block
    // ========================R2Plus1dStem ==================================
	int_t X_num[5] = {1, 3, 16, 112, 112};
    int_t Y_num[5] = {1, 45, 16, 56, 56};
    int_t Kernel_num[3] = {1, 7, 7};
    int_t stride[3] = {1, 2, 2};
    int_t padding[3] = {0, 3, 3};
    CBR(X, X_num, 1, 
		X_stem_1, Y_num, 5, 
		Kernel_stem_0, Kernel_num, 
		stride, padding, 
		56, 3.756307810544967651e-02, 60, 0.4609071612358093262, 55, 0.07323520630598068237, 
        Kernel_stem_0_scale, Mu_stem_1, Var_stem_1, Gamma_stem_1, Bias_stem_1);
    
    int_t X_num2[5] = {1, 45, 16, 56, 56};
    int_t Y_num2[5] = {1, 64, 16, 56, 56};
    int_t Kernel_num2[3] = {3, 1, 1};
    int_t stride2[3] = {1, 1, 1};
    int_t padding2[3] = {1, 0, 0};
    CBR(X_stem_1, X_num2, 5, 
		X_stem_2, Y_num2, 8, 
		Kernel_stem_3, Kernel_num2, 
		stride2, padding2, 
		55, 0.07323520630598068237, 70, 0.09311912953853607178, 65, 0.07423608750104904175, 
        Kernel_stem_3_scale, Mu_stem_4, Var_stem_4, Gamma_stem_4, Bias_stem_4);

    // ========================Sequential 1==================================
    //                      ====basicblock 0=================================
    int_t X_num3[5] = {1, 64, 16, 56, 56};
    int_t Y_num3[5] = {1, 144, 16, 56, 56};
    int_t Kernel_num3[3] = {1, 3, 3};
    int_t stride3[3] = {1, 1, 1};
    int_t padding3[3] = {0, 1, 1};
    CBR(X_stem_2, X_num3, 8, 
		X_mid_data, Y_num3, 8, 
		Kernel_seq1_0_conv1_0_0, Kernel_num3, 
		stride3, padding3, 
		65, 0.07423608750104904175, 64, 8.706942945718765259e-02, 60, 4.489336907863616943e-02, 
        Kernel_seq1_0_conv1_0_0_scale, Mu_seq1_0_conv1_0_1, Var_seq1_0_conv1_0_1, Gamma_seq1_0_conv1_0_1, Bias_seq1_0_conv1_0_1);
    
    int_t X_num4[5] = {1, 144, 16, 56, 56};
    int_t Y_num4[5] = {1, 64, 16, 56, 56};
    int_t Kernel_num4[3] = {3, 1, 1};
    int_t stride4[3] = {1, 1, 1};
    int_t padding4[3] = {1, 0, 0};
    CBR(X_mid_data, X_num4, 8, 
		X_data, Y_num4, 8, 
		Kernel_seq1_0_conv1_0_3, Kernel_num4, 
		stride4, padding4, 
		60, 4.489336907863616943e-02, 71, 4.961582273244857788e-02, 74, 5.436319485306739807e-02,
        Kernel_seq1_0_conv1_0_3_scale, Mu_seq1_0_conv1_1, Var_seq1_0_conv1_1, Gamma_seq1_0_conv1_1, Bias_seq1_0_conv1_1);
    
    // seq1.0.conv2
    int_t X_num5[5] = {1, 64, 16, 56, 56};
    int_t Y_num5[5] = {1, 144, 16, 56, 56};
    int_t Kernel_num5[3] = {1, 3, 3};
    int_t stride5[3] = {1, 1, 1};
    int_t padding5[3] = {0, 1, 1};
    CBR(X_data, X_num5, 8, 
		X_mid_data, Y_num5, 8, 
		Kernel_seq1_0_conv2_0_0, Kernel_num5, 
		stride5, padding5, 
		74, 5.436319485306739807e-02, 60, 6.804036349058151245e-02, 62, 4.303903132677078247e-02,
        Kernel_seq1_0_conv2_0_0_scale, Mu_seq1_0_conv2_0_1, Var_seq1_0_conv2_0_1, Gamma_seq1_0_conv2_0_1, Bias_seq1_0_conv2_0_1);
    
    int_t X_num6[5] = {1, 144, 16, 56, 56};
    int_t Y_num6[5] = {1, 64, 16, 56, 56};
    int_t Kernel_num6[3] = {3, 1, 1};
    int_t stride6[3] = {1, 1, 1};
    int_t padding6[3] = {1, 0, 0};
    CBRR(X_mid_data, X_stem_2, X_num6, 8, 
		X_data, X_tmp_data, Y_num6, 8, 
		Kernel_seq1_0_conv2_0_3, Kernel_num6,
		stride6, padding6, 
		62, 4.303903132677078247e-02, 66, 3.850702568888664246e-02, 65, 0.07423608750104904175, 68, 4.517441987991333008e-02, 46, 7.029289007186889648e-02, 
		Kernel_seq1_0_conv2_0_3_scale, Mu_seq1_0_conv2_1, Var_seq1_0_conv2_1, Gamma_seq1_0_conv2_1, Bias_seq1_0_conv2_1);
    
    //                      ====basicblock 1=================================
    int_t X_num7[5] = {1, 64, 16, 56, 56};
    int_t Y_num7[5] = {1, 144, 16, 56, 56};
    int_t Kernel_num7[3] = {1, 3, 3};
    int_t stride7[3] = {1, 1, 1};
    int_t padding7[3] = {0, 1, 1};
    CBR(X_data, X_num7, 8, 
		X_mid_data, Y_num7, 8, 
		Kernel_seq1_1_conv1_0_0, Kernel_num7, 
		stride7, padding7, 
		46, 7.029289007186889648e-02, 72, 9.410868585109710693e-02, 76, 3.406318649649620056e-02,
        Kernel_seq1_1_conv1_0_0_scale, Mu_seq1_1_conv1_0_1, Var_seq1_1_conv1_0_1, Gamma_seq1_1_conv1_0_1, Bias_seq1_1_conv1_0_1);

    int_t X_num8[5] = {1, 144, 16, 56, 56};
    int_t Y_num8[5] = {1, 64, 16, 56, 56};
    int_t Kernel_num8[3] = {3, 1, 1};
    int_t stride8[3] = {1, 1, 1};
    int_t padding8[3] = {1, 0, 0};
    CBR(X_mid_data, X_num8, 8, 
		X_data, Y_num8, 8, 
		Kernel_seq1_1_conv1_0_3, Kernel_num8, 
		stride8, padding8, 
		76, 3.406318649649620056e-02, 67, 3.386811539530754089e-02, 70, 4.148417711257934570e-02,
        Kernel_seq1_1_conv1_0_3_scale, Mu_seq1_1_conv1_1, Var_seq1_1_conv1_1, Gamma_seq1_1_conv1_1, Bias_seq1_1_conv1_1);
    
    // seq1.1.conv2
    int_t X_num9[5] = {1, 64, 16, 56, 56};
    int_t Y_num9[5] = {1, 144, 16, 56, 56};
    int_t Kernel_num9[3] = {1, 3, 3};
    int_t stride9[3] = {1, 1, 1};
    int_t padding9[3] = {0, 1, 1};
    CBR(X_data, X_num9, 8, 
		X_mid_data, Y_num9, 8, 
		Kernel_seq1_1_conv2_0_0, Kernel_num9, 
		stride9, padding9, 
		70, 4.148417711257934570e-02, 68, 3.422784805297851562e-02, 61, 2.891838178038597107e-02, 
        Kernel_seq1_1_conv2_0_0_scale, Mu_seq1_1_conv2_0_1, Var_seq1_1_conv2_0_1, Gamma_seq1_1_conv2_0_1, Bias_seq1_1_conv2_0_1);

    int_t X_num10[5] = {1, 144, 16, 56, 56};
    int_t Y_num10[5] = {1, 64, 16, 56, 56};
    int_t Kernel_num10[3] = {3, 1, 1};
    int_t stride10[3] = {1, 1, 1};
    int_t padding10[3] = {1, 0, 0};
    CBRR(X_mid_data, X_tmp_data, X_num10, 8, 
		X_data, X_tmp_data, Y_num10, 8, 
		Kernel_seq1_1_conv2_0_3, Kernel_num10,
		stride10, padding10, 
		61, 2.891838178038597107e-02, 71, 2.731916867196559906e-02, 46, 7.029289007186889648e-02, 53, 5.917721241712570190e-02, 49, 7.128605991601943970e-02, 
		Kernel_seq1_1_conv2_0_3_scale, Mu_seq1_1_conv2_1, Var_seq1_1_conv2_1, Gamma_seq1_1_conv2_1, Bias_seq1_1_conv2_1);
    
    // ========================== CSIM PASS =================================
    // ========================Sequential 2==================================
    //                      ====basicblock 0=================================
    // int_t X_num11[5] = {1, 64, 16, 56, 56};
    // int_t Y_num11[5] = {1, 230, 16, 28, 28};
    // int_t Kernel_num11[3] = {1, 3, 3};
    // int_t stride11[3] = {1, 2, 2};
    // int_t padding11[3] = {0, 1, 1};
    // CBR(X_data, X_num11, 8, 
	// 	X_mid_data, Y_num11, 32, 
	// 	Kernel_seq2_0_conv1_0_0, Kernel_num11, 
	// 	stride11, padding11, 
	// 	49, 7.128605991601943970e-02, 76, 1.296460330486297607e-01, 66, 3.834486752748489380e-02, 
    //     Kernel_seq2_0_conv1_0_0_scale, Mu_seq2_0_conv1_0_1, Var_seq2_0_conv1_0_1, Gamma_seq2_0_conv1_0_1, Bias_seq2_0_conv1_0_1);
    
    // int_t X_num12[5] = {1, 230, 16, 28, 28};
    // int_t Y_num12[5] = {1, 128, 8, 28, 28};
    // int_t Kernel_num12[3] = {3, 1, 1};
    // int_t stride12[3] = {2, 1, 1};
    // int_t padding12[3] = {1, 0, 0};
    // CBR(X_mid_data, X_num12, 32, 
	// 	X2_data, Y_num12, 64, 
	// 	Kernel_seq2_0_conv1_0_3, Kernel_num12, 
	// 	stride12, padding12, 
	// 	66, 3.834486752748489380e-02, 64, 3.311596438288688660e-02, 52, 3.730613738298416138e-02,
    //     Kernel_seq2_0_conv1_0_3_scale, Mu_seq2_0_conv1_1, Var_seq2_0_conv1_1, Gamma_seq2_0_conv1_1, Bias_seq2_0_conv1_1);

    // // seq2.0.conv2
    // X_num[0] = 1; X_num[1] = 128; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    // Y_num[0] = 1; Y_num[1] = 230; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    // CBR(X2_data, X_num, 64, 
	// 	X_mid_data, Y_num, 64, 
	// 	Kernel_seq2_0_conv2_0_0, Kernel_num, 
	// 	stride, padding, 
	// 	52, 3.730613738298416138e-02, 68, 6.581791490316390991e-02, 75, 3.696846589446067810e-02, 
    //     Kernel_seq2_0_conv2_0_0_scale, Mu_seq2_0_conv2_0_1, Var_seq2_0_conv2_0_1, Gamma_seq2_0_conv2_0_1, Bias_seq2_0_conv2_0_1);
    
    // // seq2.0.downsample
    // X_num[0] = 1; X_num[1] = 64; X_num[2] = 16; X_num[3] = 56; X_num[4] = 56;
    // Y_num[0] = 1; Y_num[1] = 128; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    // Kernel_num[0] = 1; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 2; stride[1] = 2; stride[2] = 2;
    // padding[0] = 0; padding[1] = 0; padding[2] = 0;
    // CB(X_data, X_num, 8, 
	// 	X_tmp_data, Y_num, 64, 
	// 	Kernel_seq2_0_downsample_0, Kernel_num, 
	// 	stride, padding, 
	// 	49, 7.128605991601943970e-02, 68, 5.711162462830543518e-02, 53, 5.571814253926277161e-02, 
    //     Kernel_seq2_0_downsample_0_scale, Mu_seq2_0_downsample_1, Var_seq2_0_downsample_1, Gamma_seq2_0_downsample_1, Bias_seq2_0_downsample_1);

    // X_num[0] = 1; X_num[1] = 230; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    // Y_num[0] = 1; Y_num[1] = 128; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    // CBRR(X_mid_data, X_tmp_data, X_num, 64, 
	// 	X2_data, X_tmp_data, Y_num, 64, 
	// 	Kernel_seq2_0_conv2_0_3, Kernel_num,
	// 	stride, padding, 
	// 	75, 3.696846589446067810e-02, 70, 3.792280331254005432e-02, 53, 5.571814253926277161e-02, 61, 5.221061781048774719e-02, 59, 5.941560864448547363e-02, 
	// 	Kernel_seq2_0_conv2_0_3_scale, Mu_seq2_0_conv2_1, Var_seq2_0_conv2_1, Gamma_seq2_0_conv2_1, Bias_seq2_0_conv2_1);

    // //                      ====basicblock 1=================================   need to clip kernel
    // X_num[0] = 1; X_num[1] = 128; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    // Y_num[0] = 1; Y_num[1] = 288; Y_num[2] = 8; Y_num[3] = 28; Y_num[4] = 28;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    // CBR(X2_data, X_num, 64, 
	// 	X_mid_data, Y_num, 64, 
	// 	Kernel_seq2_1_conv1_0_0,  Kernel_num,
	// 	stride, padding, 
	// 	59, 5.941560864448547363e-02, 74, 2.571923658251762390e-02, 
	// 	Kernel_seq2_1_conv1_0_0_scale, Mu_seq2_1_conv1_0_1, Var_seq2_1_conv1_0_1, Gamma_seq2_1_conv1_0_1, Bias_seq2_1_conv1_0_1);
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
    // CBR(X_mid_data, X_num, 64, 
	// 	X2_data, Y_num, 64, 
	// 	Kernel_seq2_1_conv1_0_3,  Kernel_num,
	// 	stride, padding, 
	// 	74, 2.571923658251762390e-02, 69, 4.108780622482299805e-02, 
	// 	Kernel_seq2_1_conv1_0_3_scale, Mu_seq2_1_conv1_1, Var_seq2_1_conv1_1, Gamma_seq2_1_conv1_1, Bias_seq2_1_conv1_1);
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
    // CBR(X2_data, X_num, 64, 
	// 	X_mid_data, Y_num, 64, 
	// 	Kernel_seq2_1_conv2_0_0,  Kernel_num,
	// 	stride, padding, 
	// 	69, 4.108780622482299805e-02, 69, 3.150121122598648071e-02, 
	// 	Kernel_seq2_1_conv2_0_0_scale, Mu_seq2_1_conv2_0_1, Var_seq2_1_conv2_0_1, Gamma_seq2_1_conv2_0_1, Bias_seq2_1_conv2_0_1);
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
    // CBRR(X_mid_data, X_tmp_data, X_num, 64, 
	// 	X2_data, X_tmp_data, Y_num, 64, 
	// 	Kernel_seq2_1_conv2_0_3, Kernel_num,
	// 	stride, padding, 
	// 	69, 3.150121122598648071e-02, 59, 5.941560864448547363e-02, 58, 7.469348609447479248e-02, 
	// 	Kernel_seq2_1_conv2_0_3_scale, Mu_seq2_1_conv2_1, Var_seq2_1_conv2_1, Gamma_seq2_1_conv2_1, Bias_seq2_1_conv2_1);
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

    // // ========================Sequential 3==================================
    // //                      ====basicblock 0=================================
    // X_num[0] = 1; X_num[1] = 128; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    // Y_num[0] = 1; Y_num[1] = 460; Y_num[2] = 8; Y_num[3] = 14; Y_num[4] = 14;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 2; stride[2] = 2;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    // CBR(X2_data, X_num, 64, 
	// 	X_mid_data, Y_num, 230, 
	// 	Kernel_seq3_0_conv1_0_0, Kernel_num, 
	// 	stride, padding, 
	// 	58, 7.469348609447479248e-02, 66, 1.026936098933219910e-01, 55, 3.207130357623100281e-02, 
    //     Kernel_seq3_0_conv1_0_0_scale, Mu_seq3_0_conv1_0_1, Var_seq3_0_conv1_0_1, Gamma_seq3_0_conv1_0_1, Bias_seq3_0_conv1_0_1);
    

    // X_num[0] = 1; X_num[1] = 460; X_num[2] = 8; X_num[3] = 14; X_num[4] = 14;
    // Y_num[0] = 1; Y_num[1] = 256; Y_num[2] = 4; Y_num[3] = 14; Y_num[4] = 14;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 2; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    // CBR(X_mid_data, X_num, 230, 
	// 	X3_data, Y_num, 256, 
	// 	Kernel_seq3_0_conv1_0_3, Kernel_num, 
	// 	stride, padding, 
	// 	55, 3.207130357623100281e-02, 64, 3.513325005769729614e-02, 59, 3.827788308262825012e-02,
    //     Kernel_seq3_0_conv1_0_3_scale, Mu_seq3_0_conv1_1, Var_seq3_0_conv1_1, Gamma_seq3_0_conv1_1, Bias_seq3_0_conv1_1);

    // // seq3.0.conv2
    // X_num[0] = 1; X_num[1] = 256; X_num[2] = 4; X_num[3] = 14; X_num[4] = 14;
    // Y_num[0] = 1; Y_num[1] = 460; Y_num[2] = 4; Y_num[3] = 14; Y_num[4] = 14;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    // CBR(X3_data, X_num, 256, 
	// 	X_mid_data, Y_num, 460, 
	// 	Kernel_seq3_0_conv2_0_0, Kernel_num, 
	// 	stride, padding, 
	// 	59, 3.827788308262825012e-02, 74, 7.229902595281600952e-02, 61, 2.794230915606021881e-02, 
    //     Kernel_seq3_0_conv2_0_0_scale, Mu_seq3_0_conv2_0_1, Var_seq3_0_conv2_0_1, Gamma_seq3_0_conv2_0_1, Bias_seq3_0_conv2_0_1);
    
    // // seq3.0.downsample
    // X_num[0] = 1; X_num[1] = 128; X_num[2] = 8; X_num[3] = 28; X_num[4] = 28;
    // Y_num[0] = 1; Y_num[1] = 256; Y_num[2] = 4; Y_num[3] = 14; Y_num[4] = 14;
    // Kernel_num[0] = 1; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 2; stride[1] = 2; stride[2] = 2;
    // padding[0] = 0; padding[1] = 0; padding[2] = 0;
    // CB(X2_data, X_num, 64, 
	// 	X_tmp_data, Y_num, 256, 
	// 	Kernel_seq3_0_downsample_0, Kernel_num, 
	// 	stride, padding, 
	// 	58, 7.469348609447479248e-02, 72, 3.776641562581062317e-02, 52, 4.242179170250892639e-02, 
    //     Kernel_seq3_0_downsample_0_scale, Mu_seq3_0_downsample_1, Var_seq3_0_downsample_1, Gamma_seq3_0_downsample_1, Bias_seq3_0_downsample_1);
    
    // X_num[0] = 1; X_num[1] = 460; X_num[2] = 4; X_num[3] = 14; X_num[4] = 14;
    // Y_num[0] = 1; Y_num[1] = 256; Y_num[2] = 4; Y_num[3] = 14; Y_num[4] = 14;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    // CBRR(X_mid_data, X_tmp_data, X_num, 460, 
	// 	X3_data, X_tmp_data, Y_num, 256, 
	// 	Kernel_seq3_0_conv2_0_3, Kernel_num,
	// 	stride, padding, 
	// 	61, 2.794230915606021881e-02, 57, 3.355694189667701721e-02, 52, 4.242179170250892639e-02, 63, 3.775262087583541870e-02, 56, 4.819526150822639465e-02, 
	// 	Kernel_seq3_0_conv2_0_3_scale, Mu_seq3_0_conv2_1, Var_seq3_0_conv2_1, Gamma_seq3_0_conv2_1, Bias_seq3_0_conv2_1);
    
    // //                      ====basicblock 1================================= 
    // X_num[0] = 1; X_num[1] = 256; X_num[2] = 4; X_num[3] = 14; X_num[4] = 14;
    // Y_num[0] = 1; Y_num[1] = 576; Y_num[2] = 4; Y_num[3] = 14; Y_num[4] = 14;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    // CBR(X3_data, X_num, 256, 
	// 	X_mid_data, Y_num, 288, 
	// 	Kernel_seq3_1_conv1_0_0,  Kernel_num,
	// 	stride, padding, 
	// 	56, 4.819526150822639465e-02, 60, 9.108851104974746704e-02, 64, 1.979854144155979156e-02, 
	// 	Kernel_seq3_1_conv1_0_0_scale, Mu_seq3_1_conv1_0_1, Var_seq3_1_conv1_0_1, Gamma_seq3_1_conv1_0_1, Bias_seq3_1_conv1_0_1);
    
    // X_num[0] = 1; X_num[1] = 576; X_num[2] = 4; X_num[3] = 14; X_num[4] = 14;
    // Y_num[0] = 1; Y_num[1] = 256; Y_num[2] = 4; Y_num[3] = 14; Y_num[4] = 14;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    // CBR(X_mid_data, X_num, 288, 
	// 	X3_data, Y_num, 256, 
	// 	Kernel_seq3_1_conv1_0_3,  Kernel_num,
	// 	stride, padding, 
	// 	64, 1.979854144155979156e-02, 64, 2.204562351107597351e-02, 55, 2.682571485638618469e-02,
	// 	Kernel_seq3_1_conv1_0_3_scale, Mu_seq3_1_conv1_1, Var_seq3_1_conv1_1, Gamma_seq3_1_conv1_1, Bias_seq3_1_conv1_1);
    
    // // seq3.1.conv2
    // X_num[0] = 1; X_num[1] = 256; X_num[2] = 4; X_num[3] = 14; X_num[4] = 14;
    // Y_num[0] = 1; Y_num[1] = 576; Y_num[2] = 4; Y_num[3] = 14; Y_num[4] = 14;
    // Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 0; padding[1] = 1; padding[2] = 1;
    // CBR(X3_data, X_num, 256, 
	// 	X_mid_data, Y_num, 288, 
	// 	Kernel_seq3_1_conv2_0_0,  Kernel_num,
	// 	stride, padding, 
	// 	55, 2.682571485638618469e-02, 58, 4.488958418369293213e-02, 74, 2.272782102227210999e-02,
	// 	Kernel_seq3_1_conv2_0_0_scale, Mu_seq3_1_conv2_0_1, Var_seq3_1_conv2_0_1, Gamma_seq3_1_conv2_0_1, Bias_seq3_1_conv2_0_1);
    
    // X_num[0] = 1; X_num[1] = 576; X_num[2] = 4; X_num[3] = 14; X_num[4] = 14;
    // Y_num[0] = 1; Y_num[1] = 256; Y_num[2] = 4; Y_num[3] = 14; Y_num[4] = 14;
    // Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
    // stride[0] = 1; stride[1] = 1; stride[2] = 1;
    // padding[0] = 1; padding[1] = 0; padding[2] = 0;
    // CBRR(X_mid_data, X_tmp_data, X_num, 288, 
	// 	X3_data, X_tmp_data, Y_num, 256, 
	// 	Kernel_seq3_1_conv2_0_3, Kernel_num,
	// 	stride, padding, 
	// 	74, 2.272782102227210999e-02, 82, 3.477662429213523865e-02, 56, 4.819526150822639465e-02, 78, 3.744378685951232910e-02, 58, 4.908789321780204773e-02,
	// 	Kernel_seq3_1_conv2_0_3_scale, Mu_seq3_1_conv2_1, Var_seq3_1_conv2_1, Gamma_seq3_1_conv2_1, Bias_seq3_1_conv2_1);
    





    
// // ========================Sequential 4==================================
//     //                      ====basicblock 0=================================
//     X_num[0] = 1; X_num[1] = 256; X_num[2] = 4; X_num[3] = 14; X_num[4] = 14;
//     Y_num[0] = 1; Y_num[1] = 921; Y_num[2] = 4; Y_num[3] = 7; Y_num[4] = 7;
//     Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
//     stride[0] = 1; stride[1] = 2; stride[2] = 2;
//     padding[0] = 0; padding[1] = 1; padding[2] = 1;
//     CBR(X3_data, X_num, 256, 
// 		X_mid_data, Y_num, 921, 
// 		Kernel_seq4_0_conv1_0_0, Kernel_num, 
// 		stride, padding, 
// 		58, 4.908789321780204773e-02, 64, 7.933901995420455933e-02, 71, 2.300033532083034515e-02,
//         Kernel_seq4_0_conv1_0_0_scale, Mu_seq4_0_conv1_0_1, Var_seq4_0_conv1_0_1, Gamma_seq4_0_conv1_0_1, Bias_seq4_0_conv1_0_1);
    

//     X_num[0] = 1; X_num[1] = 921; X_num[2] = 4; X_num[3] = 7; X_num[4] = 7;
//     Y_num[0] = 1; Y_num[1] = 512; Y_num[2] = 2; Y_num[3] = 7; Y_num[4] = 7;
//     Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
//     stride[0] = 2; stride[1] = 1; stride[2] = 1;
//     padding[0] = 1; padding[1] = 0; padding[2] = 0;
//     CBR(X_mid_data, X_num, 230, 
// 		X_seq, Y_num, 256, 
// 		Kernel_seq4_0_conv1_0_3, Kernel_num, 
// 		stride, padding, 
// 		71, 2.300033532083034515e-02, 60, 4.174583032727241516e-02, 49, 3.296769410371780396e-02,
//         Kernel_seq4_0_conv1_0_3_scale, Mu_seq4_0_conv1_1, Var_seq4_0_conv1_1, Gamma_seq4_0_conv1_1, Bias_seq4_0_conv1_1);

//     // seq4.0.conv2
//     X_num[0] = 1; X_num[1] = 512; X_num[2] = 2; X_num[3] = 7; X_num[4] = 7;
//     Y_num[0] = 1; Y_num[1] = 921; Y_num[2] = 4; Y_num[3] = 7; Y_num[4] = 7;
//     Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
//     stride[0] = 1; stride[1] = 1; stride[2] = 1;
//     padding[0] = 0; padding[1] = 1; padding[2] = 1;
//     CBR_k(X_seq, X_num, 512, 
// 		X_mid_data, Y_num, 461, 
// 		Kernel_seq4_0_conv2_0_0, Kernel_num, 
// 		stride, padding, 
// 		49, 3.296769410371780396e-02, 61, 5.654629692435264587e-02, 60, 2.629663422703742981e-02,
//         Kernel_seq4_0_conv2_0_0_scale, Mu_seq4_0_conv2_0_1, Var_seq4_0_conv2_0_1, Gamma_seq4_0_conv2_0_1, Bias_seq4_0_conv2_0_1);
    
//     // seq4.0.downsample
//     X_num[0] = 1; X_num[1] = 256; X_num[2] = 4; X_num[3] = 14; X_num[4] = 14;
//     Y_num[0] = 1; Y_num[1] = 512; Y_num[2] = 2; Y_num[3] = 7; Y_num[4] = 7;
//     Kernel_num[0] = 1; Kernel_num[1] = 1; Kernel_num[2] = 1;
//     stride[0] = 2; stride[1] = 2; stride[2] = 2;
//     padding[0] = 0; padding[1] = 0; padding[2] = 0;
//     CB(X3_data, X_num, 64, 
// 		X_tmp_data, Y_num, 256, 
// 		Kernel_seq4_0_downsample_0, Kernel_num, 
// 		stride, padding, 
// 		58, 4.908789321780204773e-02, 60, 2.351688779890537262e-02, 59, 5.310279503464698792e-02,
//         Kernel_seq4_0_downsample_0_scale, Mu_seq4_0_downsample_1, Var_seq4_0_downsample_1, Gamma_seq4_0_downsample_1, Bias_seq4_0_downsample_1);
    
//     X_num[0] = 1; X_num[1] = 921; X_num[2] = 4; X_num[3] = 7; X_num[4] = 7;
//     Y_num[0] = 1; Y_num[1] = 512; Y_num[2] = 2; Y_num[3] = 7; Y_num[4] = 7;
//     Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
//     stride[0] = 1; stride[1] = 1; stride[2] = 1;
//     padding[0] = 1; padding[1] = 0; padding[2] = 0;
//     CBRR(X_mid_data, X_tmp_data, X_num, 921, 
// 		X_seq, X_tmp_data, Y_num, 512, 
// 		Kernel_seq4_0_conv2_0_3, Kernel_num,
// 		stride, padding, 
// 		60, 2.629663422703742981e-02, 56, 3.702012076973915100e-02, 59, 5.310279503464698792e-02, 57, 8.961183577775955200e-02, 53, 1.033632829785346985e-01,
// 		Kernel_seq4_0_conv2_0_3_scale, Mu_seq4_0_conv2_1, Var_seq4_0_conv2_1, Gamma_seq4_0_conv2_1, Bias_seq4_0_conv2_1);
    
//     //                      ====basicblock 1================================= 
//     X_num[0] = 1; X_num[1] = 512; X_num[2] = 2; X_num[3] = 7; X_num[4] = 7;
//     Y_num[0] = 1; Y_num[1] = 1152; Y_num[2] = 2; Y_num[3] = 7; Y_num[4] = 7;
//     Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
//     stride[0] = 1; stride[1] = 1; stride[2] = 1;
//     padding[0] = 0; padding[1] = 1; padding[2] = 1;
//     CBR_k(X_seq, X_num, 512, 
// 		X_mid_data, Y_num, 576, 
// 		Kernel_seq4_1_conv1_0_0,  Kernel_num,
// 		stride, padding, 
// 		53, 1.033632829785346985e-01, 59, 5.083529949188232422e-01, 66, 2.375184185802936554e-02,
// 		Kernel_seq4_1_conv1_0_0_scale, Mu_seq4_1_conv1_0_1, Var_seq4_1_conv1_0_1, Gamma_seq4_1_conv1_0_1, Bias_seq4_1_conv1_0_1);
    
//     X_num[0] = 1; X_num[1] = 1152; X_num[2] = 2; X_num[3] = 7; X_num[4] = 7;
//     Y_num[0] = 1; Y_num[1] = 512; Y_num[2] = 2; Y_num[3] = 7; Y_num[4] = 7;
//     Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
//     stride[0] = 1; stride[1] = 1; stride[2] = 1;
//     padding[0] = 1; padding[1] = 0; padding[2] = 0;
//     CBR(X_mid_data, X_num, 1152, 
// 		X_seq, Y_num, 512, 
// 		Kernel_seq4_1_conv1_0_3,  Kernel_num,
// 		stride, padding, 
// 		66, 2.375184185802936554e-02, 57, 3.209327906370162964e-02, 68, 2.595668099820613861e-02,
// 		Kernel_seq4_1_conv1_0_3_scale, Mu_seq4_1_conv1_1, Var_seq4_1_conv1_1, Gamma_seq4_1_conv1_1, Bias_seq4_1_conv1_1);
    
//     // seq4.1.conv2
//     X_num[0] = 1; X_num[1] = 512; X_num[2] = 2; X_num[3] = 7; X_num[4] = 7;
//     Y_num[0] = 1; Y_num[1] = 1152; Y_num[2] = 2; Y_num[3] = 7; Y_num[4] = 7;
//     Kernel_num[0] = 1; Kernel_num[1] = 3; Kernel_num[2] = 3;
//     stride[0] = 1; stride[1] = 1; stride[2] = 1;
//     padding[0] = 0; padding[1] = 1; padding[2] = 1;
//     CBR_k(X_seq, X_num, 512, 
// 		X_mid_data, Y_num, 576, 
// 		Kernel_seq4_1_conv2_0_0,  Kernel_num,
// 		stride, padding, 
// 		68, 2.595668099820613861e-02, 67, 8.170315623283386230e-02, 63, 2.590175159275531769e-02,
// 		Kernel_seq4_1_conv2_0_0_scale, Mu_seq4_1_conv2_0_1, Var_seq4_1_conv2_0_1, Gamma_seq4_1_conv2_0_1, Bias_seq4_1_conv2_0_1);
    
//     X_num[0] = 1; X_num[1] = 1152; X_num[2] = 2; X_num[3] = 7; X_num[4] = 7;
//     Y_num[0] = 1; Y_num[1] = 512; Y_num[2] = 2; Y_num[3] = 7; Y_num[4] = 7;
//     Kernel_num[0] = 3; Kernel_num[1] = 1; Kernel_num[2] = 1;
//     stride[0] = 1; stride[1] = 1; stride[2] = 1;
//     padding[0] = 1; padding[1] = 0; padding[2] = 0;
//     CBRR(X_mid_data, X_tmp_data, X_num, 1152, 
// 		X_seq, X_tmp_data, Y_num, 512, 
// 		Kernel_seq4_1_conv2_0_3, Kernel_num,
// 		stride, padding, 
// 		63, 2.590175159275531769e-02, 59, 2.505685016512870789e-02, 53, 1.033632829785346985e-01, 42, 1.026933342218399048e-01, 31, 1.290386915206909180e-01,
// 		Kernel_seq4_1_conv2_0_3_scale, Mu_seq4_1_conv2_1, Var_seq4_1_conv2_1, Gamma_seq4_1_conv2_1, Bias_seq4_1_conv2_1);
    
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
