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
            dtype* X_stem_1, dtype* X_stem_2, dtype* X_data, dtype* X2_data, dtype* X3_data, dtype* X_seq, dtype* X_linear, 
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
	  param_t X_num[5] = {1, 3, 16, 112, 112};
    param_t Y_num[5] = {1, 45, 16, 56, 56};
    param_t Kernel_num[3] = {1, 7, 7};
    param_t stride[3] = {1, 2, 2};
    param_t padding[3] = {0, 3, 3};
    CBR(X, X_num, 1, 
		X_stem_1, Y_num, 5, 
		Kernel_stem_0, Kernel_num, 
		stride, padding, 
		56, 3.756307810544967651e-02, 60, 0.4609071612358093262, 55, 0.07323520630598068237, 
        Kernel_stem_0_scale, Mu_stem_1, Var_stem_1, Gamma_stem_1, Bias_stem_1);
    
    param_t X_num2[5] = {1, 45, 16, 56, 56};
    param_t Y_num2[5] = {1, 64, 16, 56, 56};
    param_t Kernel_num2[3] = {3, 1, 1};
    param_t stride2[3] = {1, 1, 1};
    param_t padding2[3] = {1, 0, 0};
    CBR(X_stem_1, X_num2, 5, 
		X_stem_2, Y_num2, 8, 
		Kernel_stem_3, Kernel_num2, 
		stride2, padding2, 
		55, 0.07323520630598068237, 70, 0.09311912953853607178, 65, 0.07423608750104904175, 
        Kernel_stem_3_scale, Mu_stem_4, Var_stem_4, Gamma_stem_4, Bias_stem_4);

    // ========================Sequential 1==================================
    //                      ====basicblock 0=================================
    param_t X_num3[5] = {1, 64, 16, 56, 56};
    param_t Y_num3[5] = {1, 144, 16, 56, 56};
    param_t Kernel_num3[3] = {1, 3, 3};
    param_t stride3[3] = {1, 1, 1};
    param_t padding3[3] = {0, 1, 1};
    CBR(X_stem_2, X_num3, 8, 
		X_mid_data, Y_num3, 8, 
		Kernel_seq1_0_conv1_0_0, Kernel_num3, 
		stride3, padding3, 
		65, 0.07423608750104904175, 64, 8.706942945718765259e-02, 60, 4.489336907863616943e-02, 
        Kernel_seq1_0_conv1_0_0_scale, Mu_seq1_0_conv1_0_1, Var_seq1_0_conv1_0_1, Gamma_seq1_0_conv1_0_1, Bias_seq1_0_conv1_0_1);
    
    param_t X_num4[5] = {1, 144, 16, 56, 56};
    param_t Y_num4[5] = {1, 64, 16, 56, 56};
    param_t Kernel_num4[3] = {3, 1, 1};
    param_t stride4[3] = {1, 1, 1};
    param_t padding4[3] = {1, 0, 0};
    CBR(X_mid_data, X_num4, 8, 
		X_data, Y_num4, 8, 
		Kernel_seq1_0_conv1_0_3, Kernel_num4, 
		stride4, padding4, 
		60, 4.489336907863616943e-02, 71, 4.961582273244857788e-02, 74, 5.436319485306739807e-02,
        Kernel_seq1_0_conv1_0_3_scale, Mu_seq1_0_conv1_1, Var_seq1_0_conv1_1, Gamma_seq1_0_conv1_1, Bias_seq1_0_conv1_1);
    
    // seq1.0.conv2
    param_t X_num5[5] = {1, 64, 16, 56, 56};
    param_t Y_num5[5] = {1, 144, 16, 56, 56};
    param_t Kernel_num5[3] = {1, 3, 3};
    param_t stride5[3] = {1, 1, 1};
    param_t padding5[3] = {0, 1, 1};
    CBR(X_data, X_num5, 8, 
		X_mid_data, Y_num5, 8, 
		Kernel_seq1_0_conv2_0_0, Kernel_num5, 
		stride5, padding5, 
		74, 5.436319485306739807e-02, 60, 6.804036349058151245e-02, 62, 4.303903132677078247e-02,
        Kernel_seq1_0_conv2_0_0_scale, Mu_seq1_0_conv2_0_1, Var_seq1_0_conv2_0_1, Gamma_seq1_0_conv2_0_1, Bias_seq1_0_conv2_0_1);
    
    param_t X_num6[5] = {1, 144, 16, 56, 56};
    param_t Y_num6[5] = {1, 64, 16, 56, 56};
    param_t Kernel_num6[3] = {3, 1, 1};
    param_t stride6[3] = {1, 1, 1};
    param_t padding6[3] = {1, 0, 0};
    CBRR(X_mid_data, X_stem_2, X_num6, 8, 
		X_data, X_tmp_data, Y_num6, 8, 
		Kernel_seq1_0_conv2_0_3, Kernel_num6,
		stride6, padding6, 
		62, 4.303903132677078247e-02, 66, 3.850702568888664246e-02, 65, 0.07423608750104904175, 68, 4.517441987991333008e-02, 46, 7.029289007186889648e-02, 
		Kernel_seq1_0_conv2_0_3_scale, Mu_seq1_0_conv2_1, Var_seq1_0_conv2_1, Gamma_seq1_0_conv2_1, Bias_seq1_0_conv2_1);
    
    //                      ====basicblock 1=================================
    param_t X_num7[5] = {1, 64, 16, 56, 56};
    param_t Y_num7[5] = {1, 144, 16, 56, 56};
    param_t Kernel_num7[3] = {1, 3, 3};
    param_t stride7[3] = {1, 1, 1};
    param_t padding7[3] = {0, 1, 1};
    CBR(X_data, X_num7, 8, 
		X_mid_data, Y_num7, 8, 
		Kernel_seq1_1_conv1_0_0, Kernel_num7, 
		stride7, padding7, 
		46, 7.029289007186889648e-02, 72, 9.410868585109710693e-02, 76, 3.406318649649620056e-02,
        Kernel_seq1_1_conv1_0_0_scale, Mu_seq1_1_conv1_0_1, Var_seq1_1_conv1_0_1, Gamma_seq1_1_conv1_0_1, Bias_seq1_1_conv1_0_1);

    param_t X_num8[5] = {1, 144, 16, 56, 56};
    param_t Y_num8[5] = {1, 64, 16, 56, 56};
    param_t Kernel_num8[3] = {3, 1, 1};
    param_t stride8[3] = {1, 1, 1};
    param_t padding8[3] = {1, 0, 0};
    CBR(X_mid_data, X_num8, 8, 
		X_data, Y_num8, 8, 
		Kernel_seq1_1_conv1_0_3, Kernel_num8, 
		stride8, padding8, 
		76, 3.406318649649620056e-02, 67, 3.386811539530754089e-02, 70, 4.148417711257934570e-02,
        Kernel_seq1_1_conv1_0_3_scale, Mu_seq1_1_conv1_1, Var_seq1_1_conv1_1, Gamma_seq1_1_conv1_1, Bias_seq1_1_conv1_1);
    
    // seq1.1.conv2
    param_t X_num9[5] = {1, 64, 16, 56, 56};
    param_t Y_num9[5] = {1, 144, 16, 56, 56};
    param_t Kernel_num9[3] = {1, 3, 3};
    param_t stride9[3] = {1, 1, 1};
    param_t padding9[3] = {0, 1, 1};
    CBR(X_data, X_num9, 8, 
		X_mid_data, Y_num9, 8, 
		Kernel_seq1_1_conv2_0_0, Kernel_num9, 
		stride9, padding9, 
		70, 4.148417711257934570e-02, 68, 3.422784805297851562e-02, 61, 2.891838178038597107e-02, 
        Kernel_seq1_1_conv2_0_0_scale, Mu_seq1_1_conv2_0_1, Var_seq1_1_conv2_0_1, Gamma_seq1_1_conv2_0_1, Bias_seq1_1_conv2_0_1);

    param_t X_num10[5] = {1, 144, 16, 56, 56};
    param_t Y_num10[5] = {1, 64, 16, 56, 56};
    param_t Kernel_num10[3] = {3, 1, 1};
    param_t stride10[3] = {1, 1, 1};
    param_t padding10[3] = {1, 0, 0};
    CBRR(X_mid_data, X_tmp_data, X_num10, 8, 
		X_data, X_tmp_data, Y_num10, 8, 
		Kernel_seq1_1_conv2_0_3, Kernel_num10,
		stride10, padding10, 
		61, 2.891838178038597107e-02, 71, 2.731916867196559906e-02, 46, 7.029289007186889648e-02, 53, 5.917721241712570190e-02, 49, 7.128605991601943970e-02, 
		Kernel_seq1_1_conv2_0_3_scale, Mu_seq1_1_conv2_1, Var_seq1_1_conv2_1, Gamma_seq1_1_conv2_1, Bias_seq1_1_conv2_1);
    
    // ========================Sequential 2==================================
    //                      ====basicblock 0=================================
    param_t X_num11[5] = {1, 64, 16, 56, 56};
    param_t Y_num11[5] = {1, 230, 16, 28, 28};
    param_t Kernel_num11[3] = {1, 3, 3};
    param_t stride11[3] = {1, 2, 2};
    param_t padding11[3] = {0, 1, 1};
    CBR(X_data, X_num11, 8, 
		X_mid_data, Y_num11, 32, 
		Kernel_seq2_0_conv1_0_0, Kernel_num11, 
		stride11, padding11, 
		49, 7.128605991601943970e-02, 76, 1.296460330486297607e-01, 66, 3.834486752748489380e-02, 
        Kernel_seq2_0_conv1_0_0_scale, Mu_seq2_0_conv1_0_1, Var_seq2_0_conv1_0_1, Gamma_seq2_0_conv1_0_1, Bias_seq2_0_conv1_0_1);
    
    param_t X_num12[5] = {1, 230, 16, 28, 28};
    param_t Y_num12[5] = {1, 128, 8, 28, 28};
    param_t Kernel_num12[3] = {3, 1, 1};
    param_t stride12[3] = {2, 1, 1};
    param_t padding12[3] = {1, 0, 0};
    CBR(X_mid_data, X_num12, 32, 
		X2_data, Y_num12, 64, 
		Kernel_seq2_0_conv1_0_3, Kernel_num12, 
		stride12, padding12, 
		66, 3.834486752748489380e-02, 64, 3.311596438288688660e-02, 52, 3.730613738298416138e-02,
        Kernel_seq2_0_conv1_0_3_scale, Mu_seq2_0_conv1_1, Var_seq2_0_conv1_1, Gamma_seq2_0_conv1_1, Bias_seq2_0_conv1_1);

    // seq2.0.conv2
    param_t X_num13[5] = {1, 128, 8, 28, 28};
    param_t Y_num13[5] = {1, 230, 8, 28, 28};
    param_t Kernel_num13[3] = {1, 3, 3};
    param_t stride13[3] = {1, 1, 1};
    param_t padding13[3] = {0, 1, 1};
    CBR(X2_data, X_num13, 64, 
		X_mid_data, Y_num13, 64, 
		Kernel_seq2_0_conv2_0_0, Kernel_num13, 
		stride13, padding13, 
		52, 3.730613738298416138e-02, 68, 6.581791490316390991e-02, 75, 3.696846589446067810e-02, 
        Kernel_seq2_0_conv2_0_0_scale, Mu_seq2_0_conv2_0_1, Var_seq2_0_conv2_0_1, Gamma_seq2_0_conv2_0_1, Bias_seq2_0_conv2_0_1);
    
    // seq2.0.downsample
    param_t X_num14[5] = {1, 64, 16, 56, 56};
    param_t Y_num14[5] = {1, 128, 8, 28, 28};
    param_t Kernel_num14[3] = {1, 1, 1};
    param_t stride14[3] = {2, 2, 2};
    param_t padding14[3] = {0, 0, 0};
    CB(X_data, X_num14, 8, 
		X_tmp_data, Y_num14, 64, 
		Kernel_seq2_0_downsample_0, Kernel_num14, 
		stride14, padding14, 
		49, 7.128605991601943970e-02, 68, 5.711162462830543518e-02, 53, 5.571814253926277161e-02, 
        Kernel_seq2_0_downsample_0_scale, Mu_seq2_0_downsample_1, Var_seq2_0_downsample_1, Gamma_seq2_0_downsample_1, Bias_seq2_0_downsample_1);

    param_t X_num15[5] = {1, 230, 8, 28, 28};
    param_t Y_num15[5] = {1, 128, 8, 28, 28};
    param_t Kernel_num15[3] = {3, 1, 1};
    param_t stride15[3] = {1, 1, 1};
    param_t padding15[3] = {1, 0, 0};
    CBRR(X_mid_data, X_tmp_data, X_num15, 64, 
		X2_data, X_tmp_data, Y_num15, 64, 
		Kernel_seq2_0_conv2_0_3, Kernel_num15,
		stride15, padding15, 
		75, 3.696846589446067810e-02, 70, 3.792280331254005432e-02, 53, 5.571814253926277161e-02, 61, 5.221061781048774719e-02, 59, 5.941560864448547363e-02, 
		Kernel_seq2_0_conv2_0_3_scale, Mu_seq2_0_conv2_1, Var_seq2_0_conv2_1, Gamma_seq2_0_conv2_1, Bias_seq2_0_conv2_1);

    //                      ====basicblock 1=================================   need to clip kernel
    param_t X_num16[5] = {1, 128, 8, 28, 28};
    param_t Y_num16[5] = {1, 288, 8, 28, 28};
    param_t Kernel_num16[3] = {1, 3, 3};
    param_t stride16[3] = {1, 1, 1};
    param_t padding16[3] = {0, 1, 1};
    CBR(X2_data, X_num16, 64, 
		X_mid_data, Y_num16, 64, 
		Kernel_seq2_1_conv1_0_0,  Kernel_num16,
		stride16, padding16, 
		59, 5.941560864448547363e-02, 64, 1.044261455535888672e-01, 74, 2.571923658251762390e-02, 
		Kernel_seq2_1_conv1_0_0_scale, Mu_seq2_1_conv1_0_1, Var_seq2_1_conv1_0_1, Gamma_seq2_1_conv1_0_1, Bias_seq2_1_conv1_0_1);

    param_t X_num17[5] = {1, 288, 8, 28, 28};
    param_t Y_num17[5] = {1, 128, 8, 28, 28};
    param_t Kernel_num17[3] = {3, 1, 1};
    param_t stride17[3] = {1, 1, 1};
    param_t padding17[3] = {1, 0, 0};
    CBR(X_mid_data, X_num17, 64, 
		X2_data, Y_num17, 64, 
		Kernel_seq2_1_conv1_0_3,  Kernel_num17,
		stride17, padding17, 
		74, 2.571923658251762390e-02, 63, 2.876071259379386902e-02, 69, 4.108780622482299805e-02, 
		Kernel_seq2_1_conv1_0_3_scale, Mu_seq2_1_conv1_1, Var_seq2_1_conv1_1, Gamma_seq2_1_conv1_1, Bias_seq2_1_conv1_1);

    // seq2.1.conv2
    param_t X_num18[5] = {1, 128, 8, 28, 28};
    param_t Y_num18[5] = {1, 288, 8, 28, 28};
    param_t Kernel_num18[3] = {1, 3, 3};
    param_t stride18[3] = {1, 1, 1};
    param_t padding18[3] = {0, 1, 1};
    CBR(X2_data, X_num18, 64, 
		X_mid_data, Y_num18, 64, 
		Kernel_seq2_1_conv2_0_0,  Kernel_num18,
		stride18, padding18, 
		69, 4.108780622482299805e-02, 55, 4.689884185791015625e-02, 69, 3.150121122598648071e-02, 
		Kernel_seq2_1_conv2_0_0_scale, Mu_seq2_1_conv2_0_1, Var_seq2_1_conv2_0_1, Gamma_seq2_1_conv2_0_1, Bias_seq2_1_conv2_0_1);

    param_t X_num19[5] = {1, 288, 8, 28, 28};
    param_t Y_num19[5] = {1, 128, 8, 28, 28};
    param_t Kernel_num19[3] = {3, 1, 1};
    param_t stride19[3] = {1, 1, 1};
    param_t padding19[3] = {1, 0, 0};
    CBRR(X_mid_data, X_tmp_data, X_num19, 64, 
		X2_data, X_tmp_data, Y_num19, 64, 
		Kernel_seq2_1_conv2_0_3, Kernel_num19,
		stride19, padding19, 
		69, 3.150121122598648071e-02, 66, 2.438377402722835541e-02, 59, 5.941560864448547363e-02, 70, 6.300298124551773071e-02, 58, 7.469348609447479248e-02, 
		Kernel_seq2_1_conv2_0_3_scale, Mu_seq2_1_conv2_1, Var_seq2_1_conv2_1, Gamma_seq2_1_conv2_1, Bias_seq2_1_conv2_1);

    // ========================Sequential 3==================================
    //                      ====basicblock 0=================================
    param_t X_num20[5] = {1, 128, 8, 28, 28};
    param_t Y_num20[5] = {1, 460, 8, 14, 14};
    param_t Kernel_num20[3] = {1, 3, 3};
    param_t stride20[3] = {1, 2, 2};
    param_t padding20[3] = {0, 1, 1};
    CBR(X2_data, X_num20, 64, 
		X_mid_data, Y_num20, 230, 
		Kernel_seq3_0_conv1_0_0, Kernel_num20, 
		stride20, padding20, 
		58, 7.469348609447479248e-02, 66, 1.026936098933219910e-01, 55, 3.207130357623100281e-02, 
        Kernel_seq3_0_conv1_0_0_scale, Mu_seq3_0_conv1_0_1, Var_seq3_0_conv1_0_1, Gamma_seq3_0_conv1_0_1, Bias_seq3_0_conv1_0_1);
    
    param_t X_num21[5] = {1, 460, 8, 14, 14};
    param_t Y_num21[5] = {1, 256, 4, 14, 14};
    param_t Kernel_num21[3] = {3, 1, 1};
    param_t stride21[3] = {2, 1, 1};
    param_t padding21[3] = {1, 0, 0};
    CBR(X_mid_data, X_num21, 230, 
		X3_data, Y_num21, 256, 
		Kernel_seq3_0_conv1_0_3, Kernel_num21, 
		stride21, padding21, 
		55, 3.207130357623100281e-02, 64, 3.513325005769729614e-02, 59, 3.827788308262825012e-02,
        Kernel_seq3_0_conv1_0_3_scale, Mu_seq3_0_conv1_1, Var_seq3_0_conv1_1, Gamma_seq3_0_conv1_1, Bias_seq3_0_conv1_1);

    // seq3.0.conv2
    param_t X_num22[5] = {1, 256, 4, 14, 14};
    param_t Y_num22[5] = {1, 460, 4, 14, 14};
    param_t Kernel_num22[3] = {1, 3, 3};
    param_t stride22[3] = {1, 1, 1};
    param_t padding22[3] = {0, 1, 1};
    CBR(X3_data, X_num22, 256, 
		X_mid_data, Y_num22, 460, 
		Kernel_seq3_0_conv2_0_0, Kernel_num22, 
		stride22, padding22, 
		59, 3.827788308262825012e-02, 74, 7.229902595281600952e-02, 61, 2.794230915606021881e-02, 
        Kernel_seq3_0_conv2_0_0_scale, Mu_seq3_0_conv2_0_1, Var_seq3_0_conv2_0_1, Gamma_seq3_0_conv2_0_1, Bias_seq3_0_conv2_0_1);
    
    // seq3.0.downsample
    param_t X_num23[5] = {1, 128, 8, 28, 28};
    param_t Y_num23[5] = {1, 256, 4, 14, 14};
    param_t Kernel_num23[3] = {1, 1, 1};
    param_t stride23[3] = {2, 2, 2};
    param_t padding23[3] = {0, 0, 0};
    CB(X2_data, X_num23, 64, 
		X_tmp_data, Y_num23, 256, 
		Kernel_seq3_0_downsample_0, Kernel_num23, 
		stride23, padding23, 
		58, 7.469348609447479248e-02, 72, 3.776641562581062317e-02, 52, 4.242179170250892639e-02, 
        Kernel_seq3_0_downsample_0_scale, Mu_seq3_0_downsample_1, Var_seq3_0_downsample_1, Gamma_seq3_0_downsample_1, Bias_seq3_0_downsample_1);
    
    param_t X_num24[5] = {1, 460, 4, 14, 14};
    param_t Y_num24[5] = {1, 256, 4, 14, 14};
    param_t Kernel_num24[3] = {3, 1, 1};
    param_t stride24[3] = {1, 1, 1};
    param_t padding24[3] = {1, 0, 0};
    CBRR(X_mid_data, X_tmp_data, X_num24, 460, 
		X3_data, X_tmp_data, Y_num24, 256, 
		Kernel_seq3_0_conv2_0_3, Kernel_num24,
		stride24, padding24, 
		61, 2.794230915606021881e-02, 57, 3.355694189667701721e-02, 52, 4.242179170250892639e-02, 63, 3.775262087583541870e-02, 56, 4.819526150822639465e-02, 
		Kernel_seq3_0_conv2_0_3_scale, Mu_seq3_0_conv2_1, Var_seq3_0_conv2_1, Gamma_seq3_0_conv2_1, Bias_seq3_0_conv2_1);
    
    // ========================== CSIM PASS =================================
    //                      ====basicblock 1================================= 
    param_t X_num25[5] = {1, 256, 4, 14, 14};
    param_t Y_num25[5] = {1, 576, 4, 14, 14};
    param_t Kernel_num25[3] = {1, 3, 3};
    param_t stride25[3] = {1, 1, 1};
    param_t padding25[3] = {0, 1, 1};
    CBR(X3_data, X_num25, 256, 
		X_mid_data, Y_num25, 288, 
		Kernel_seq3_1_conv1_0_0,  Kernel_num25,
		stride25, padding25, 
		56, 4.819526150822639465e-02, 60, 9.108851104974746704e-02, 64, 1.979854144155979156e-02, 
		Kernel_seq3_1_conv1_0_0_scale, Mu_seq3_1_conv1_0_1, Var_seq3_1_conv1_0_1, Gamma_seq3_1_conv1_0_1, Bias_seq3_1_conv1_0_1);
    
    param_t X_num26[5] = {1, 576, 4, 14, 14};
    param_t Y_num26[5] = {1, 256, 4, 14, 14};
    param_t Kernel_num26[3] = {3, 1, 1};
    param_t stride26[3] = {1, 1, 1};
    param_t padding26[3] = {1, 0, 0};
    CBR(X_mid_data, X_num26, 288, 
		X3_data, Y_num26, 256, 
		Kernel_seq3_1_conv1_0_3,  Kernel_num26,
		stride26, padding26, 
		64, 1.979854144155979156e-02, 64, 2.204562351107597351e-02, 55, 2.682571485638618469e-02,
		Kernel_seq3_1_conv1_0_3_scale, Mu_seq3_1_conv1_1, Var_seq3_1_conv1_1, Gamma_seq3_1_conv1_1, Bias_seq3_1_conv1_1);
    
    // seq3.1.conv2
    param_t X_num27[5] = {1, 256, 4, 14, 14};
    param_t Y_num27[5] = {1, 576, 4, 14, 14};
    param_t Kernel_num27[3] = {1, 3, 3};
    param_t stride27[3] = {1, 1, 1};
    param_t padding27[3] = {0, 1, 1};
    CBR(X3_data, X_num27, 256, 
		X_mid_data, Y_num27, 288, 
		Kernel_seq3_1_conv2_0_0,  Kernel_num27,
		stride27, padding27, 
		55, 2.682571485638618469e-02, 58, 4.488958418369293213e-02, 74, 2.272782102227210999e-02,
		Kernel_seq3_1_conv2_0_0_scale, Mu_seq3_1_conv2_0_1, Var_seq3_1_conv2_0_1, Gamma_seq3_1_conv2_0_1, Bias_seq3_1_conv2_0_1);
    
    param_t X_num28[5] = {1, 576, 4, 14, 14};
    param_t Y_num28[5] = {1, 256, 4, 14, 14};
    param_t Kernel_num28[3] = {3, 1, 1};
    param_t stride28[3] = {1, 1, 1};
    param_t padding28[3] = {1, 0, 0};
    CBRR(X_mid_data, X_tmp_data, X_num28, 288, 
		X3_data, X_tmp_data, Y_num28, 256, 
		Kernel_seq3_1_conv2_0_3, Kernel_num28,
		stride28, padding28, 
		74, 2.272782102227210999e-02, 82, 3.477662429213523865e-02, 56, 4.819526150822639465e-02, 78, 3.744378685951232910e-02, 58, 4.908789321780204773e-02,
		Kernel_seq3_1_conv2_0_3_scale, Mu_seq3_1_conv2_1, Var_seq3_1_conv2_1, Gamma_seq3_1_conv2_1, Bias_seq3_1_conv2_1);
    
    // ========================Sequential 4==================================
    //                      ====basicblock 0=================================
    param_t X_num29[5] = {1, 256, 4, 14, 14};
    param_t Y_num29[5] = {1, 921, 4, 7, 7};
    param_t Kernel_num29[3] = {1, 3, 3};
    param_t stride29[3] = {1, 2, 2};
    param_t padding29[3] = {0, 1, 1};
    CBR(X3_data, X_num29, 256, 
		X_mid_data, Y_num29, 921, 
		Kernel_seq4_0_conv1_0_0, Kernel_num29, 
		stride29, padding29, 
		58, 4.908789321780204773e-02, 64, 7.933901995420455933e-02, 71, 2.300033532083034515e-02,
        Kernel_seq4_0_conv1_0_0_scale, Mu_seq4_0_conv1_0_1, Var_seq4_0_conv1_0_1, Gamma_seq4_0_conv1_0_1, Bias_seq4_0_conv1_0_1);

    param_t X_num30[5] = {1, 921, 4, 7, 7};
    param_t Y_num30[5] = {1, 512, 2, 7, 7};
    param_t Kernel_num30[3] = {3, 1, 1};
    param_t stride30[3] = {2, 1, 1};
    param_t padding30[3] = {1, 0, 0};
    CBR(X_mid_data, X_num30, 921, 
		X_seq, Y_num30, 512, 
		Kernel_seq4_0_conv1_0_3, Kernel_num30, 
		stride30, padding30, 
		71, 2.300033532083034515e-02, 60, 4.174583032727241516e-02, 49, 3.296769410371780396e-02,
        Kernel_seq4_0_conv1_0_3_scale, Mu_seq4_0_conv1_1, Var_seq4_0_conv1_1, Gamma_seq4_0_conv1_1, Bias_seq4_0_conv1_1);

    // seq4.0.conv2
    param_t X_num31[5] = {1, 512, 2, 7, 7};
    param_t Y_num31[5] = {1, 921, 2, 7, 7};
    param_t Kernel_num31[3] = {1, 3, 3};
    param_t stride31[3] = {1, 1, 1};
    param_t padding31[3] = {0, 1, 1};
    CBR_k(X_seq, X_num31, 512, 
		X_mid_data, Y_num31, 461, 
		Kernel_seq4_0_conv2_0_0, Kernel_num31, 
		stride31, padding31, 
		49, 3.296769410371780396e-02, 61, 5.654629692435264587e-02, 60, 2.629663422703742981e-02,
        Kernel_seq4_0_conv2_0_0_scale, Mu_seq4_0_conv2_0_1, Var_seq4_0_conv2_0_1, Gamma_seq4_0_conv2_0_1, Bias_seq4_0_conv2_0_1);
    
    // seq4.0.downsample
    param_t X_num32[5] = {1, 256, 4, 14, 14};
    param_t Y_num32[5] = {1, 512, 2, 7, 7};
    param_t Kernel_num32[3] = {1, 1, 1};
    param_t stride32[3] = {2, 2, 2};
    param_t padding32[3] = {0, 0, 0};
    CB(X3_data, X_num32, 64, 
		X_tmp_data, Y_num32, 256, 
		Kernel_seq4_0_downsample_0, Kernel_num32, 
		stride32, padding32, 
		58, 4.908789321780204773e-02, 60, 2.351688779890537262e-02, 59, 5.310279503464698792e-02,
        Kernel_seq4_0_downsample_0_scale, Mu_seq4_0_downsample_1, Var_seq4_0_downsample_1, Gamma_seq4_0_downsample_1, Bias_seq4_0_downsample_1);
    
    param_t X_num33[5] = {1, 921, 2, 7, 7};
    param_t Y_num33[5] = {1, 512, 2, 7, 7};
    param_t Kernel_num33[3] = {3, 1, 1};
    param_t stride33[3] = {1, 1, 1};
    param_t padding33[3] = {1, 0, 0};
    CBRR(X_mid_data, X_tmp_data, X_num33, 921, 
		X_seq, X_tmp_data, Y_num33, 512, 
		Kernel_seq4_0_conv2_0_3, Kernel_num33,
		stride33, padding33, 
		60, 2.629663422703742981e-02, 56, 3.702012076973915100e-02, 59, 5.310279503464698792e-02, 57, 8.961183577775955200e-02, 53, 1.033632829785346985e-01,
		Kernel_seq4_0_conv2_0_3_scale, Mu_seq4_0_conv2_1, Var_seq4_0_conv2_1, Gamma_seq4_0_conv2_1, Bias_seq4_0_conv2_1);
    
    //                      ====basicblock 1================================= 
    param_t X_num34[5] = {1, 512, 2, 7, 7};
    param_t Y_num34[5] = {1, 1152, 2, 7, 7};
    param_t Kernel_num34[3] = {1, 3, 3};
    param_t stride34[3] = {1, 1, 1};
    param_t padding34[3] = {0, 1, 1};
    CBR_k(X_seq, X_num34, 512, 
		X_mid_data, Y_num34, 576, 
		Kernel_seq4_1_conv1_0_0,  Kernel_num34,
		stride34, padding34, 
		53, 1.033632829785346985e-01, 59, 5.083529949188232422e-01, 66, 2.375184185802936554e-02,
		Kernel_seq4_1_conv1_0_0_scale, Mu_seq4_1_conv1_0_1, Var_seq4_1_conv1_0_1, Gamma_seq4_1_conv1_0_1, Bias_seq4_1_conv1_0_1);
    
    param_t X_num35[5] = {1, 1152, 2, 7, 7};
    param_t Y_num35[5] = {1, 512, 2, 7, 7};
    param_t Kernel_num35[3] = {3, 1, 1};
    param_t stride35[3] = {1, 1, 1};
    param_t padding35[3] = {1, 0, 0};
    CBR(X_mid_data, X_num35, 1152, 
		X_seq, Y_num35, 512, 
		Kernel_seq4_1_conv1_0_3,  Kernel_num35,
		stride35, padding35, 
		66, 2.375184185802936554e-02, 57, 3.209327906370162964e-02, 68, 2.595668099820613861e-02,
		Kernel_seq4_1_conv1_0_3_scale, Mu_seq4_1_conv1_1, Var_seq4_1_conv1_1, Gamma_seq4_1_conv1_1, Bias_seq4_1_conv1_1);
    
    // seq4.1.conv2
    param_t X_num36[5] = {1, 512, 2, 7, 7};
    param_t Y_num36[5] = {1, 1152, 2, 7, 7};
    param_t Kernel_num36[3] = {1, 3, 3};
    param_t stride36[3] = {1, 1, 1};
    param_t padding36[3] = {0, 1, 1};
    CBR_k(X_seq, X_num36, 512, 
		X_mid_data, Y_num36, 576, 
		Kernel_seq4_1_conv2_0_0,  Kernel_num36,
		stride36, padding36, 
		68, 2.595668099820613861e-02, 67, 8.170315623283386230e-02, 63, 2.590175159275531769e-02,
		Kernel_seq4_1_conv2_0_0_scale, Mu_seq4_1_conv2_0_1, Var_seq4_1_conv2_0_1, Gamma_seq4_1_conv2_0_1, Bias_seq4_1_conv2_0_1);

    param_t X_num37[5] = {1, 1152, 2, 7, 7};
    param_t Y_num37[5] = {1, 512, 2, 7, 7};
    param_t Kernel_num37[3] = {3, 1, 1};
    param_t stride37[3] = {1, 1, 1};
    param_t padding37[3] = {1, 0, 0};
    
    CBRRAL(X_mid_data, X_tmp_data, X_num37, 1152,
		X_linear, Y_num37, 512, 
		Kernel_seq4_1_conv2_0_3, Kernel_num37, Kernel_linear,
		stride37, padding37, 
		63, 2.590175159275531769e-02, 59, 2.505685016512870789e-02, 53, 1.033632829785346985e-01, 42, 1.026933342218399048e-01, 31, 1.290386915206909180e-01,
    Kernel_seq4_1_conv2_0_3_scale, Mu_seq4_1_conv2_1, Var_seq4_1_conv2_1, Gamma_seq4_1_conv2_1, Bias_seq4_1_conv2_1);
    
    
    // CBRR(X_mid_data, X_tmp_data, X_num37, 1152, 
		// X_seq, X_tmp_data, Y_num37, 512, 
		// Kernel_seq4_1_conv2_0_3, Kernel_num37,
		// stride37, padding37, 
		// 63, 2.590175159275531769e-02, 59, 2.505685016512870789e-02, 53, 1.033632829785346985e-01, 42, 1.026933342218399048e-01, 31, 1.290386915206909180e-01,
		// Kernel_seq4_1_conv2_0_3_scale, Mu_seq4_1_conv2_1, Var_seq4_1_conv2_1, Gamma_seq4_1_conv2_1, Bias_seq4_1_conv2_1);
    
    // // ======================== AdaptiveAvgPool3d ==================================

    // for(int_t c = 0; c < 512; c++){
    //     int_t tmp_Y = 0;
    //     for(int_t kd = 0; kd < 2; kd++)
    //         for(int_t kh = 0; kh < 7; kh++)
    //             for(int_t kw = 0; kw < 7; kw++)
    //                 tmp_Y += X_seq[c*98 + kd*49 + kh*7 + kw];
    //     X_bram[c] = roundf((ftype)tmp_Y/98);//(ytype)(tmp_Y/98);
    // }

    // // ======================== Linear ==================================

	  // for(int_t i = 0; i < 5120; i++)
    //     Kernel_bram[i] = Kernel_linear[i];
    
    // for(int c = 0; c < 10; c++){
    //     int yPos = c;
    //     int_t tmp_Y = 0;
    //     for(int i = 0; i < 512; i++)
    //         tmp_Y += Kernel_bram[c*512+i]*((int_t)X_bram[i]-31);
    //     tmp_Y = (int_t)roundf((tmp_Y*1.290386915206909180e-01*Kernel_linear_scale[c]+KernelBias[c]) / 3.984360396862030029e-02) + 127;
    //     X_linear[yPos] = (tmp_Y > 255) ? 255 : (tmp_Y < 0) ? 0 : (dtype)tmp_Y;
    // }

    return;
}
