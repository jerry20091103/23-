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
    
    
    param_t Y_num2[5] = {1, 64, 16, 56, 56};
    param_t Kernel_num2[3] = {3, 1, 1};
    param_t stride2[3] = {1, 1, 1};
    param_t padding2[3] = {1, 0, 0};
    CBR(X_stem_1, Y_num, 5, 
		X_stem_2, Y_num2, 8, 
		Kernel_stem_3, Kernel_num2, 
		stride2, padding2, 
		55, 0.07323520630598068237, 70, 0.09311912953853607178, 65, 0.07423608750104904175, 
        Kernel_stem_3_scale, Mu_stem_4, Var_stem_4, Gamma_stem_4, Bias_stem_4);

    // ========================Sequential 1==================================
    //                      ====basicblock 0=================================
    param_t Y_num3[5] = {1, 144, 16, 56, 56};
    param_t Kernel_num3[3] = {1, 3, 3};
    param_t padding3[3] = {0, 1, 1};
    CBR(X_stem_2, Y_num2, 8, 
		X_mid_data, Y_num3, 8, 
		Kernel_seq1_0_conv1_0_0, Kernel_num3, 
		stride2, padding3, 
		65, 0.07423608750104904175, 64, 8.706942945718765259e-02, 60, 4.489336907863616943e-02, 
        Kernel_seq1_0_conv1_0_0_scale, Mu_seq1_0_conv1_0_1, Var_seq1_0_conv1_0_1, Gamma_seq1_0_conv1_0_1, Bias_seq1_0_conv1_0_1);
    
    
    CBR(X_mid_data, Y_num3, 8, 
		X_data, Y_num2, 8, 
		Kernel_seq1_0_conv1_0_3, Kernel_num2, 
		stride2, padding2, 
		60, 4.489336907863616943e-02, 71, 4.961582273244857788e-02, 74, 5.436319485306739807e-02,
        Kernel_seq1_0_conv1_0_3_scale, Mu_seq1_0_conv1_1, Var_seq1_0_conv1_1, Gamma_seq1_0_conv1_1, Bias_seq1_0_conv1_1);
    
    // seq1.0.conv2
    CBR(X_data, Y_num2, 8, 
		X_mid_data, Y_num3, 8, 
		Kernel_seq1_0_conv2_0_0, Kernel_num3, 
		stride2, padding3, 
		74, 5.436319485306739807e-02, 60, 6.804036349058151245e-02, 62, 4.303903132677078247e-02,
        Kernel_seq1_0_conv2_0_0_scale, Mu_seq1_0_conv2_0_1, Var_seq1_0_conv2_0_1, Gamma_seq1_0_conv2_0_1, Bias_seq1_0_conv2_0_1);
    
    
    CBRR(X_mid_data, X_stem_2, Y_num3, 8, 
		X_data, X_tmp_data, Y_num2, 8, 
		Kernel_seq1_0_conv2_0_3, Kernel_num2,
		stride2, padding2, 
		62, 4.303903132677078247e-02, 66, 3.850702568888664246e-02, 65, 0.07423608750104904175, 68, 4.517441987991333008e-02, 46, 7.029289007186889648e-02, 
		Kernel_seq1_0_conv2_0_3_scale, Mu_seq1_0_conv2_1, Var_seq1_0_conv2_1, Gamma_seq1_0_conv2_1, Bias_seq1_0_conv2_1);
    
    //                      ====basicblock 1=================================
    CBR(X_data, Y_num2, 8, 
		X_mid_data, Y_num3, 8, 
		Kernel_seq1_1_conv1_0_0, Kernel_num3, 
		stride2, padding3, 
		46, 7.029289007186889648e-02, 72, 9.410868585109710693e-02, 76, 3.406318649649620056e-02,
        Kernel_seq1_1_conv1_0_0_scale, Mu_seq1_1_conv1_0_1, Var_seq1_1_conv1_0_1, Gamma_seq1_1_conv1_0_1, Bias_seq1_1_conv1_0_1);

    
    CBR(X_mid_data, Y_num3, 8, 
		X_data, Y_num2, 8, 
		Kernel_seq1_1_conv1_0_3, Kernel_num2, 
		stride2, padding2, 
		76, 3.406318649649620056e-02, 67, 3.386811539530754089e-02, 70, 4.148417711257934570e-02,
        Kernel_seq1_1_conv1_0_3_scale, Mu_seq1_1_conv1_1, Var_seq1_1_conv1_1, Gamma_seq1_1_conv1_1, Bias_seq1_1_conv1_1);
    
    // seq1.1.conv2
    CBR(X_data, Y_num2, 8, 
		X_mid_data, Y_num3, 8, 
		Kernel_seq1_1_conv2_0_0, Kernel_num3, 
		stride2, padding3, 
		70, 4.148417711257934570e-02, 68, 3.422784805297851562e-02, 61, 2.891838178038597107e-02, 
        Kernel_seq1_1_conv2_0_0_scale, Mu_seq1_1_conv2_0_1, Var_seq1_1_conv2_0_1, Gamma_seq1_1_conv2_0_1, Bias_seq1_1_conv2_0_1);

    CBRR(X_mid_data, X_tmp_data, Y_num3, 8, 
		X_data, X_batch_data, Y_num2, 8, 
		Kernel_seq1_1_conv2_0_3, Kernel_num2,
		stride2, padding2, 
		61, 2.891838178038597107e-02, 71, 2.731916867196559906e-02, 46, 7.029289007186889648e-02, 53, 5.917721241712570190e-02, 49, 7.128605991601943970e-02, 
		Kernel_seq1_1_conv2_0_3_scale, Mu_seq1_1_conv2_1, Var_seq1_1_conv2_1, Gamma_seq1_1_conv2_1, Bias_seq1_1_conv2_1);
    
    // ========================Sequential 2==================================
    //                      ====basicblock 0=================================
    param_t Y_num11[5] = {1, 230, 16, 28, 28};
    CBR(X_data, Y_num2, 8, 
		X_mid_data, Y_num11, 32, 
		Kernel_seq2_0_conv1_0_0, Kernel_num3, 
		stride, padding3, 
		49, 7.128605991601943970e-02, 76, 1.296460330486297607e-01, 66, 3.834486752748489380e-02, 
        Kernel_seq2_0_conv1_0_0_scale, Mu_seq2_0_conv1_0_1, Var_seq2_0_conv1_0_1, Gamma_seq2_0_conv1_0_1, Bias_seq2_0_conv1_0_1);
    
    
    param_t Y_num12[5] = {1, 128, 8, 28, 28};
    param_t stride12[3] = {2, 1, 1};
    CBR(X_mid_data, Y_num11, 32, 
		X2_data, Y_num12, 64, 
		Kernel_seq2_0_conv1_0_3, Kernel_num2, 
		stride12, padding2, 
		66, 3.834486752748489380e-02, 64, 3.311596438288688660e-02, 52, 3.730613738298416138e-02,
        Kernel_seq2_0_conv1_0_3_scale, Mu_seq2_0_conv1_1, Var_seq2_0_conv1_1, Gamma_seq2_0_conv1_1, Bias_seq2_0_conv1_1);

    // seq2.0.conv2
    param_t Y_num13[5] = {1, 230, 8, 28, 28};
    CBR(X2_data, Y_num12, 64, 
		X_mid_data, Y_num13, 64, 
		Kernel_seq2_0_conv2_0_0, Kernel_num3, 
		stride2, padding3, 
		52, 3.730613738298416138e-02, 68, 6.581791490316390991e-02, 75, 3.696846589446067810e-02, 
        Kernel_seq2_0_conv2_0_0_scale, Mu_seq2_0_conv2_0_1, Var_seq2_0_conv2_0_1, Gamma_seq2_0_conv2_0_1, Bias_seq2_0_conv2_0_1);
    
    // seq2.0.downsample
    param_t stride14[3] = {2, 2, 2};
    param_t padding14[3] = {0, 0, 0};
    CB(X_data, Y_num2, 8, 
		X_batch_data, Y_num12, 64, 
		Kernel_seq2_0_downsample_0, stride2, 
		stride14, padding14, 
		49, 7.128605991601943970e-02, 68, 5.711162462830543518e-02, 53, 5.571814253926277161e-02, 
        Kernel_seq2_0_downsample_0_scale, Mu_seq2_0_downsample_1, Var_seq2_0_downsample_1, Gamma_seq2_0_downsample_1, Bias_seq2_0_downsample_1);

    
    CBRR(X_mid_data, X_batch_data, Y_num13, 64, 
		X2_data, X_tmp_data, Y_num12, 64, 
		Kernel_seq2_0_conv2_0_3, Kernel_num2,
		stride2, padding2, 
		75, 3.696846589446067810e-02, 70, 3.792280331254005432e-02, 53, 5.571814253926277161e-02, 61, 5.221061781048774719e-02, 59, 5.941560864448547363e-02, 
		Kernel_seq2_0_conv2_0_3_scale, Mu_seq2_0_conv2_1, Var_seq2_0_conv2_1, Gamma_seq2_0_conv2_1, Bias_seq2_0_conv2_1);

    //                      ====basicblock 1=================================   need to clip kernel
    param_t Y_num16[5] = {1, 288, 8, 28, 28};
    CBR(X2_data, Y_num12, 64, 
		X_mid_data, Y_num16, 64, 
		Kernel_seq2_1_conv1_0_0,  Kernel_num3,
		stride2, padding3, 
		59, 5.941560864448547363e-02, 64, 1.044261455535888672e-01, 74, 2.571923658251762390e-02, 
		Kernel_seq2_1_conv1_0_0_scale, Mu_seq2_1_conv1_0_1, Var_seq2_1_conv1_0_1, Gamma_seq2_1_conv1_0_1, Bias_seq2_1_conv1_0_1);

    
    CBR(X_mid_data, Y_num16, 64, 
		X2_data, Y_num12, 64, 
		Kernel_seq2_1_conv1_0_3,  Kernel_num2,
		stride2, padding2, 
		74, 2.571923658251762390e-02, 63, 2.876071259379386902e-02, 69, 4.108780622482299805e-02, 
		Kernel_seq2_1_conv1_0_3_scale, Mu_seq2_1_conv1_1, Var_seq2_1_conv1_1, Gamma_seq2_1_conv1_1, Bias_seq2_1_conv1_1);

    // seq2.1.conv2
    CBR(X2_data, Y_num12, 64, 
		X_mid_data, Y_num16, 64, 
		Kernel_seq2_1_conv2_0_0,  Kernel_num3,
		stride2, padding3, 
		69, 4.108780622482299805e-02, 55, 4.689884185791015625e-02, 69, 3.150121122598648071e-02, 
		Kernel_seq2_1_conv2_0_0_scale, Mu_seq2_1_conv2_0_1, Var_seq2_1_conv2_0_1, Gamma_seq2_1_conv2_0_1, Bias_seq2_1_conv2_0_1);

    
    CBRR(X_mid_data, X_tmp_data, Y_num16, 64, 
		X2_data, X_batch_data, Y_num12, 64, 
		Kernel_seq2_1_conv2_0_3, Kernel_num2,
		stride2, padding2, 
		69, 3.150121122598648071e-02, 66, 2.438377402722835541e-02, 59, 5.941560864448547363e-02, 70, 6.300298124551773071e-02, 58, 7.469348609447479248e-02, 
		Kernel_seq2_1_conv2_0_3_scale, Mu_seq2_1_conv2_1, Var_seq2_1_conv2_1, Gamma_seq2_1_conv2_1, Bias_seq2_1_conv2_1);

    // ========================Sequential 3==================================
    //                      ====basicblock 0=================================
    param_t Y_num20[5] = {1, 460, 8, 14, 14};
    CBR(X2_data, Y_num12, 64, 
		X_mid_data, Y_num20, 230, 
		Kernel_seq3_0_conv1_0_0, Kernel_num3, 
		stride, padding3, 
		58, 7.469348609447479248e-02, 66, 1.026936098933219910e-01, 55, 3.207130357623100281e-02, 
        Kernel_seq3_0_conv1_0_0_scale, Mu_seq3_0_conv1_0_1, Var_seq3_0_conv1_0_1, Gamma_seq3_0_conv1_0_1, Bias_seq3_0_conv1_0_1);
    
    
    param_t Y_num21[5] = {1, 256, 4, 14, 14};
    CBR(X_mid_data, Y_num20, 230, 
		X3_data, Y_num21, 256, 
		Kernel_seq3_0_conv1_0_3, Kernel_num2, 
		stride12, padding2, 
		55, 3.207130357623100281e-02, 64, 3.513325005769729614e-02, 59, 3.827788308262825012e-02,
        Kernel_seq3_0_conv1_0_3_scale, Mu_seq3_0_conv1_1, Var_seq3_0_conv1_1, Gamma_seq3_0_conv1_1, Bias_seq3_0_conv1_1);

    // seq3.0.conv2
    param_t Y_num22[5] = {1, 460, 4, 14, 14};
    CBR(X3_data, Y_num21, 256, 
		X_mid_data, Y_num22, 460, 
		Kernel_seq3_0_conv2_0_0, Kernel_num3, 
		stride2, padding3, 
		59, 3.827788308262825012e-02, 74, 7.229902595281600952e-02, 61, 2.794230915606021881e-02, 
        Kernel_seq3_0_conv2_0_0_scale, Mu_seq3_0_conv2_0_1, Var_seq3_0_conv2_0_1, Gamma_seq3_0_conv2_0_1, Bias_seq3_0_conv2_0_1);
    
    // seq3.0.downsample
    CB(X2_data, Y_num12, 64, 
		X_batch_data, Y_num21, 256, 
		Kernel_seq3_0_downsample_0, stride2, 
		stride14, padding14, 
		58, 7.469348609447479248e-02, 72, 3.776641562581062317e-02, 52, 4.242179170250892639e-02, 
        Kernel_seq3_0_downsample_0_scale, Mu_seq3_0_downsample_1, Var_seq3_0_downsample_1, Gamma_seq3_0_downsample_1, Bias_seq3_0_downsample_1);
    
    
    CBRR(X_mid_data, X_batch_data, Y_num22, 460, 
		X3_data, X_tmp_data, Y_num21, 256, 
		Kernel_seq3_0_conv2_0_3, Kernel_num2,
		stride2, padding2, 
		61, 2.794230915606021881e-02, 57, 3.355694189667701721e-02, 52, 4.242179170250892639e-02, 63, 3.775262087583541870e-02, 56, 4.819526150822639465e-02, 
		Kernel_seq3_0_conv2_0_3_scale, Mu_seq3_0_conv2_1, Var_seq3_0_conv2_1, Gamma_seq3_0_conv2_1, Bias_seq3_0_conv2_1);
    
    // ========================== CSIM PASS =================================
    //                      ====basicblock 1================================= 
    param_t Y_num25[5] = {1, 576, 4, 14, 14};
    CBR(X3_data, Y_num21, 256, 
		X_mid_data, Y_num25, 288, 
		Kernel_seq3_1_conv1_0_0,  Kernel_num3,
		stride2, padding3, 
		56, 4.819526150822639465e-02, 60, 9.108851104974746704e-02, 64, 1.979854144155979156e-02, 
		Kernel_seq3_1_conv1_0_0_scale, Mu_seq3_1_conv1_0_1, Var_seq3_1_conv1_0_1, Gamma_seq3_1_conv1_0_1, Bias_seq3_1_conv1_0_1);
    
    CBR(X_mid_data, Y_num25, 288, 
		X3_data, Y_num21, 256, 
		Kernel_seq3_1_conv1_0_3,  Kernel_num2,
		stride2, padding2, 
		64, 1.979854144155979156e-02, 64, 2.204562351107597351e-02, 55, 2.682571485638618469e-02,
		Kernel_seq3_1_conv1_0_3_scale, Mu_seq3_1_conv1_1, Var_seq3_1_conv1_1, Gamma_seq3_1_conv1_1, Bias_seq3_1_conv1_1);
    
    // seq3.1.conv2
    CBR(X3_data, Y_num21, 256, 
		X_mid_data, Y_num25, 288, 
		Kernel_seq3_1_conv2_0_0,  Kernel_num3,
		stride2, padding3, 
		55, 2.682571485638618469e-02, 58, 4.488958418369293213e-02, 74, 2.272782102227210999e-02,
		Kernel_seq3_1_conv2_0_0_scale, Mu_seq3_1_conv2_0_1, Var_seq3_1_conv2_0_1, Gamma_seq3_1_conv2_0_1, Bias_seq3_1_conv2_0_1);
    
    
    CBRR(X_mid_data, X_tmp_data, Y_num25, 288, 
		X3_data, X_batch_data, Y_num21, 256, 
		Kernel_seq3_1_conv2_0_3, Kernel_num2,
		stride2, padding2, 
		74, 2.272782102227210999e-02, 82, 3.477662429213523865e-02, 56, 4.819526150822639465e-02, 78, 3.744378685951232910e-02, 58, 4.908789321780204773e-02,
		Kernel_seq3_1_conv2_0_3_scale, Mu_seq3_1_conv2_1, Var_seq3_1_conv2_1, Gamma_seq3_1_conv2_1, Bias_seq3_1_conv2_1);
    
    // ========================Sequential 4==================================
    //                      ====basicblock 0=================================
    param_t Y_num29[5] = {1, 921, 4, 7, 7};
    CBR(X3_data, Y_num21, 256, 
		X_mid_data, Y_num29, 921, 
		Kernel_seq4_0_conv1_0_0, Kernel_num3, 
		stride, padding3, 
		58, 4.908789321780204773e-02, 64, 7.933901995420455933e-02, 71, 2.300033532083034515e-02,
        Kernel_seq4_0_conv1_0_0_scale, Mu_seq4_0_conv1_0_1, Var_seq4_0_conv1_0_1, Gamma_seq4_0_conv1_0_1, Bias_seq4_0_conv1_0_1);

    
    param_t Y_num30[5] = {1, 512, 2, 7, 7};
    CBR(X_mid_data, Y_num29, 921, 
		X_seq, Y_num30, 512, 
		Kernel_seq4_0_conv1_0_3, Kernel_num2, 
		stride12, padding2, 
		71, 2.300033532083034515e-02, 60, 4.174583032727241516e-02, 49, 3.296769410371780396e-02,
        Kernel_seq4_0_conv1_0_3_scale, Mu_seq4_0_conv1_1, Var_seq4_0_conv1_1, Gamma_seq4_0_conv1_1, Bias_seq4_0_conv1_1);

    // seq4.0.conv2
    param_t Y_num31[5] = {1, 921, 2, 7, 7};
    CBR_k(X_seq, Y_num30, 512, 
		X_mid_data, Y_num31, 461, 
		Kernel_seq4_0_conv2_0_0, Kernel_num3, 
		stride2, padding3, 
		49, 3.296769410371780396e-02, 61, 5.654629692435264587e-02, 60, 2.629663422703742981e-02,
        Kernel_seq4_0_conv2_0_0_scale, Mu_seq4_0_conv2_0_1, Var_seq4_0_conv2_0_1, Gamma_seq4_0_conv2_0_1, Bias_seq4_0_conv2_0_1);
    
    // seq4.0.downsample
    CB(X3_data, Y_num21, 64, 
		X_batch_data, Y_num30, 256, 
		Kernel_seq4_0_downsample_0, stride2, 
		stride14, padding14, 
		58, 4.908789321780204773e-02, 60, 2.351688779890537262e-02, 59, 5.310279503464698792e-02,
        Kernel_seq4_0_downsample_0_scale, Mu_seq4_0_downsample_1, Var_seq4_0_downsample_1, Gamma_seq4_0_downsample_1, Bias_seq4_0_downsample_1);
    
    
    CBRR(X_mid_data, X_batch_data, Y_num31, 921, 
		X_seq, X_tmp_data, Y_num30, 512, 
		Kernel_seq4_0_conv2_0_3, Kernel_num2,
		stride2, padding2, 
		60, 2.629663422703742981e-02, 56, 3.702012076973915100e-02, 59, 5.310279503464698792e-02, 57, 8.961183577775955200e-02, 53, 1.033632829785346985e-01,
		Kernel_seq4_0_conv2_0_3_scale, Mu_seq4_0_conv2_1, Var_seq4_0_conv2_1, Gamma_seq4_0_conv2_1, Bias_seq4_0_conv2_1);
    
    //                      ====basicblock 1================================= 
    param_t Y_num34[5] = {1, 1152, 2, 7, 7};
    CBR_k(X_seq, Y_num30, 512, 
		X_mid_data, Y_num34, 576, 
		Kernel_seq4_1_conv1_0_0,  Kernel_num3,
		stride2, padding3, 
		53, 1.033632829785346985e-01, 59, 5.083529949188232422e-01, 66, 2.375184185802936554e-02,
		Kernel_seq4_1_conv1_0_0_scale, Mu_seq4_1_conv1_0_1, Var_seq4_1_conv1_0_1, Gamma_seq4_1_conv1_0_1, Bias_seq4_1_conv1_0_1);
    
    
    CBR(X_mid_data, Y_num34, 1152, 
		X_seq, Y_num30, 512, 
		Kernel_seq4_1_conv1_0_3,  Kernel_num2,
		stride2, padding2, 
		66, 2.375184185802936554e-02, 57, 3.209327906370162964e-02, 68, 2.595668099820613861e-02,
		Kernel_seq4_1_conv1_0_3_scale, Mu_seq4_1_conv1_1, Var_seq4_1_conv1_1, Gamma_seq4_1_conv1_1, Bias_seq4_1_conv1_1);
    
    // seq4.1.conv2
    CBR_k(X_seq, Y_num30, 512, 
		X_mid_data, Y_num34, 576, 
		Kernel_seq4_1_conv2_0_0,  Kernel_num3,
		stride2, padding3, 
		68, 2.595668099820613861e-02, 67, 8.170315623283386230e-02, 63, 2.590175159275531769e-02,
		Kernel_seq4_1_conv2_0_0_scale, Mu_seq4_1_conv2_0_1, Var_seq4_1_conv2_0_1, Gamma_seq4_1_conv2_0_1, Bias_seq4_1_conv2_0_1);

    
    
    CBRRAL(X_mid_data, X_tmp_data, Y_num34, 1152,
		X_linear, Y_num30, 512, 
		Kernel_seq4_1_conv2_0_3, Kernel_num2, Kernel_linear,
		stride2, padding2, 
		63, 2.590175159275531769e-02, 59, 2.505685016512870789e-02, 53, 1.033632829785346985e-01, 42, 1.026933342218399048e-01, 31, 1.290386915206909180e-01,
    Kernel_seq4_1_conv2_0_3_scale, Mu_seq4_1_conv2_1, Var_seq4_1_conv2_1, Gamma_seq4_1_conv2_1, Bias_seq4_1_conv2_1);

    return;
}
