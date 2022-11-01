#include "r2plus1d.h"
#include<iostream>
using namespace std;

void r2plus1d(dtype* X, dtype* Y, dtype* Kernel_stem_0, dtype* Kernel_stem_3, double* Kernel_stem_0_scale, double* Kernel_stem_3_scale,
                double* Mu_stem_1, double* Mu_stem_4, double* Var_stem_1, double* Var_stem_4, double* Gamma_stem_1, double* Gamma_stem_4, double* Bias_stem_1, double* Bias_stem_4,
            dtype* Kernel_seq1_0_conv1_0_0, dtype* Kernel_seq1_0_conv1_0_3, dtype* Kernel_seq1_0_conv2_0_0, dtype* Kernel_seq1_0_conv2_0_3, dtype* Kernel_seq1_1_conv1_0_0, dtype* Kernel_seq1_1_conv1_0_3, dtype* Kernel_seq1_1_conv2_0_0, dtype* Kernel_seq1_1_conv2_0_3,
            double* Kernel_seq1_0_conv1_0_0_scale, double* Kernel_seq1_0_conv1_0_3_scale, double* Kernel_seq1_0_conv2_0_0_scale, double* Kernel_seq1_0_conv2_0_3_scale, double* Kernel_seq1_1_conv1_0_0_scale, double* Kernel_seq1_1_conv1_0_3_scale, double* Kernel_seq1_1_conv2_0_0_scale, double* Kernel_seq1_1_conv2_0_3_scale,
                double* Mu_seq1_0_conv1_0_1, double* Mu_seq1_0_conv1_1, double* Mu_seq1_0_conv2_0_1, double* Mu_seq1_0_conv2_1, double* Mu_seq1_1_conv1_0_1, double* Mu_seq1_1_conv1_1, double* Mu_seq1_1_conv2_0_1, double* Mu_seq1_1_conv2_1,
                double* Var_seq1_0_conv1_0_1, double* Var_seq1_0_conv1_1, double* Var_seq1_0_conv2_0_1, double* Var_seq1_0_conv2_1, double* Var_seq1_1_conv1_0_1, double* Var_seq1_1_conv1_1, double* Var_seq1_1_conv2_0_1, double* Var_seq1_1_conv2_1,
                double* Gamma_seq1_0_conv1_0_1, double* Gamma_seq1_0_conv1_1, double* Gamma_seq1_0_conv2_0_1, double* Gamma_seq1_0_conv2_1, double* Gamma_seq1_1_conv1_0_1, double* Gamma_seq1_1_conv1_1, double* Gamma_seq1_1_conv2_0_1, double* Gamma_seq1_1_conv2_1,
                double* Bias_seq1_0_conv1_0_1, double* Bias_seq1_0_conv1_1, double* Bias_seq1_0_conv2_0_1, double* Bias_seq1_0_conv2_1, double* Bias_seq1_1_conv1_0_1, double* Bias_seq1_1_conv1_1, double* Bias_seq1_1_conv2_0_1, double* Bias_seq1_1_conv2_1,
            dtype* Kernel_seq2_0_conv1_0_0, dtype* Kernel_seq2_0_conv1_0_3, dtype* Kernel_seq2_0_conv2_0_0, dtype* Kernel_seq2_0_conv2_0_3, dtype* Kernel_seq2_0_downsample_0, dtype* Kernel_seq2_1_conv1_0_0, dtype* Kernel_seq2_1_conv1_0_3, dtype* Kernel_seq2_1_conv2_0_0, dtype* Kernel_seq2_1_conv2_0_3,
            double* Kernel_seq2_0_conv1_0_0_scale, double* Kernel_seq2_0_conv1_0_3_scale, double* Kernel_seq2_0_conv2_0_0_scale, double* Kernel_seq2_0_conv2_0_3_scale, double* Kernel_seq2_0_downsample_0_scale, double* Kernel_seq2_1_conv1_0_0_scale, double* Kernel_seq2_1_conv1_0_3_scale, double* Kernel_seq2_1_conv2_0_0_scale, double* Kernel_seq2_1_conv2_0_3_scale,
                double* Mu_seq2_0_conv1_0_1, double* Mu_seq2_0_conv1_1, double* Mu_seq2_0_conv2_0_1, double* Mu_seq2_0_conv2_1, double* Mu_seq2_0_downsample_1, double* Mu_seq2_1_conv1_0_1, double* Mu_seq2_1_conv1_1, double* Mu_seq2_1_conv2_0_1, double* Mu_seq2_1_conv2_1,
                double* Var_seq2_0_conv1_0_1, double* Var_seq2_0_conv1_1, double* Var_seq2_0_conv2_0_1, double* Var_seq2_0_conv2_1, double* Var_seq2_0_downsample_1, double* Var_seq2_1_conv1_0_1, double* Var_seq2_1_conv1_1, double* Var_seq2_1_conv2_0_1, double* Var_seq2_1_conv2_1,
                double* Gamma_seq2_0_conv1_0_1, double* Gamma_seq2_0_conv1_1, double* Gamma_seq2_0_conv2_0_1, double* Gamma_seq2_0_conv2_1, double* Gamma_seq2_0_downsample_1, double* Gamma_seq2_1_conv1_0_1, double* Gamma_seq2_1_conv1_1, double* Gamma_seq2_1_conv2_0_1, double* Gamma_seq2_1_conv2_1,
                double* Bais_seq2_0_conv1_0_1, double* Bais_seq2_0_conv1_1, double* Bais_seq2_0_conv2_0_1, double* Bais_seq2_0_conv2_1, double* Bais_seq2_0_downsample_1, double* Bais_seq2_1_conv1_0_1, double* Bais_seq2_1_conv1_1, double* Bais_seq2_1_conv2_0_1, double* Bais_seq2_1_conv2_1,
            dtype* Kernel_seq3_0_conv1_0_0, dtype* Kernel_seq3_0_conv1_0_3, dtype* Kernel_seq3_0_conv2_0_0, dtype* Kernel_seq3_0_conv2_0_3, dtype* Kernel_seq3_0_downsample_0, dtype* Kernel_seq3_1_conv1_0_0, dtype* Kernel_seq3_1_conv1_0_3, dtype* Kernel_seq3_1_conv2_0_0, dtype* Kernel_seq3_1_conv2_0_3,
            double* Kernel_seq3_0_conv1_0_0_scale, double* Kernel_seq3_0_conv1_0_3_scale, double* Kernel_seq3_0_conv2_0_0_scale, double* Kernel_seq3_0_conv2_0_3_scale, double* Kernel_seq3_0_downsample_0_scale, double* Kernel_seq3_1_conv1_0_0_scale, double* Kernel_seq3_1_conv1_0_3_scale, double* Kernel_seq3_1_conv2_0_0_scale, double* Kernel_seq3_1_conv2_0_3_scale,
                double* Mu_seq3_0_conv1_0_1, double* Mu_seq3_0_conv1_1, double* Mu_seq3_0_conv2_0_1, double* Mu_seq3_0_conv2_1, double* Mu_seq3_0_downsample_1, double* Mu_seq3_1_conv1_0_1, double* Mu_seq3_1_conv1_1, double* Mu_seq3_1_conv2_0_1, double* Mu_seq3_1_conv2_1,
                double* Var_seq3_0_conv1_0_1, double* Var_seq3_0_conv1_1, double* Var_seq3_0_conv2_0_1, double* Var_seq3_0_conv2_1, double* Var_seq3_0_downsample_1, double* Var_seq3_1_conv1_0_1, double* Var_seq3_1_conv1_1, double* Var_seq3_1_conv2_0_1, double* Var_seq3_1_conv2_1,
                double* Gamma_seq3_0_conv1_0_1, double* Gamma_seq3_0_conv1_1, double* Gamma_seq3_0_conv2_0_1, double* Gamma_seq3_0_conv2_1, double* Gamma_seq3_0_downsample_1, double* Gamma_seq3_1_conv1_0_1, double* Gamma_seq3_1_conv1_1, double* Gamma_seq3_1_conv2_0_1, double* Gamma_seq3_1_conv2_1,
                double* Bais_seq3_0_conv1_0_1, double* Bais_seq3_0_conv1_1, double* Bais_seq3_0_conv2_0_1, double* Bais_seq3_0_conv2_1, double* Bais_seq3_0_downsample_1, double* Bais_seq3_1_conv1_0_1, double* Bais_seq3_1_conv1_1, double* Bais_seq3_1_conv2_0_1, double* Bais_seq3_1_conv2_1,
            dtype* Kernel_seq4_0_conv1_0_0, dtype* Kernel_seq4_0_conv1_0_3, dtype* Kernel_seq4_0_conv2_0_0, dtype* Kernel_seq4_0_conv2_0_3, dtype* Kernel_seq4_0_downsample_0, dtype* Kernel_seq4_1_conv1_0_0, dtype* Kernel_seq4_1_conv1_0_3, dtype* Kernel_seq4_1_conv2_0_0, dtype* Kernel_seq4_1_conv2_0_3,
            double* Kernel_seq4_0_conv1_0_0_scale, double* Kernel_seq4_0_conv1_0_3_scale, double* Kernel_seq4_0_conv2_0_0_scale, double* Kernel_seq4_0_conv2_0_3_scale, double* Kernel_seq4_0_downsample_0_scale, double* Kernel_seq4_1_conv1_0_0_scale, double* Kernel_seq4_1_conv1_0_3_scale, double* Kernel_seq4_1_conv2_0_0_scale, double* Kernel_seq4_1_conv2_0_3_scale,
                double* Mu_seq4_0_conv1_0_1, double* Mu_seq4_0_conv1_1, double* Mu_seq4_0_conv2_0_1, double* Mu_seq4_0_conv2_1, double* Mu_seq4_0_downsample_1, double* Mu_seq4_1_conv1_0_1, double* Mu_seq4_1_conv1_1, double* Mu_seq4_1_conv2_0_1, double* Mu_seq4_1_conv2_1,
                double* Var_seq4_0_conv1_0_1, double* Var_seq4_0_conv1_1, double* Var_seq4_0_conv2_0_1, double* Var_seq4_0_conv2_1, double* Var_seq4_0_downsample_1, double* Var_seq4_1_conv1_0_1, double* Var_seq4_1_conv1_1, double* Var_seq4_1_conv2_0_1, double* Var_seq4_1_conv2_1,
                double* Gamma_seq4_0_conv1_0_1, double* Gamma_seq4_0_conv1_1, double* Gamma_seq4_0_conv2_0_1, double* Gamma_seq4_0_conv2_1, double* Gamma_seq4_0_downsample_1, double* Gamma_seq4_1_conv1_0_1, double* Gamma_seq4_1_conv1_1, double* Gamma_seq4_1_conv2_0_1, double* Gamma_seq4_1_conv2_1,
                double* Bais_seq4_0_conv1_0_1, double* Bais_seq4_0_conv1_1, double* Bais_seq4_0_conv2_0_1, double* Bais_seq4_0_conv2_1, double* Bais_seq4_0_downsample_1, double* Bais_seq4_1_conv1_0_1, double* Bais_seq4_1_conv1_1, double* Bais_seq4_1_conv2_0_1, double* Bais_seq4_1_conv2_1,
            dtype* Kernel_linear, double* Kernel_linear_scale)
{
 #ifdef __SYNTHESIS__
    dtype X_stem_1[2257920];
    dtype X_stem_2[3211264];
    // // Sequential 1~4
    dtype X_seq[50176]; // value after 1~4 sequential layer
    // AdaptiveAvgPool3d
    dtype X_adap[512]; // value after AdaptiveAvgPool3d
    // Linear
    dtype X_linear[400];

    #pragma HLS int_tERFACE s_axilite port=return
	#pragma HLS int_tERFACE m_axi port=X
	#pragma HLS int_tERFACE m_axi port=Y
    #pragma HLS int_tERFACE m_axi port=Kernel_stem_0
	#pragma HLS int_tERFACE m_axi port=Kernel_stem_3
    #pragma HLS int_tERFACE m_axi port=Mu_stem_1
    #pragma HLS int_tERFACE m_axi port=Mu_stem_4
    #pragma HLS int_tERFACE m_axi port=Var_stem_1
    #pragma HLS int_tERFACE m_axi port=Var_stem_4
    #pragma HLS int_tERFACE m_axi port=Bias_stem_1
    #pragma HLS int_tERFACE m_axi port=Bias_stem_4
    #pragma HLS int_tERFACE m_axi port=Gamma_stem_1
    #pragma HLS int_tERFACE m_axi port=Gamma_stem_4
    #pragma HLS int_tERFACE m_axi port=Kernel_seq1_0_conv1_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq1_0_conv1_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq1_0_conv2_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq1_0_conv2_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq1_1_conv1_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq1_1_conv1_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq1_1_conv2_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq1_1_conv2_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq3_0_conv1_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq3_0_conv1_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq3_0_conv2_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq3_0_conv2_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq3_0_downsample_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq3_1_conv1_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq3_1_conv1_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq3_1_conv2_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq3_1_conv2_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq4_0_conv1_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq4_0_conv1_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq4_0_conv2_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq4_0_conv2_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq4_0_downsample_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq4_1_conv1_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq4_1_conv1_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq4_1_conv2_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq4_1_conv2_0_3
    #pragma HLS int_tERFACE m_axi port=Mu_seq1_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq1_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq1_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq1_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq1_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq1_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq1_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq1_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq4_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq4_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq4_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq4_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq4_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq4_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq4_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq4_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq4_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Var_seq1_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq1_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Var_seq1_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq1_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Var_seq1_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq1_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Var_seq1_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq1_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Var_seq4_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq3_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq3_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Var_seq3_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq3_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Var_seq3_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Var_seq3_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq3_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Var_seq3_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq3_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Var_seq4_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Var_seq4_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq4_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Var_seq4_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Var_seq4_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq4_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Var_seq4_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq4_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq1_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq1_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq1_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq1_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq1_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq1_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq1_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq1_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq3_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq3_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq3_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq3_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq3_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq3_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq3_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq3_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq3_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq4_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq4_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq4_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq4_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq4_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq4_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq4_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq4_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq4_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq3_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq3_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq3_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq3_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq3_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq3_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq3_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq3_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq3_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq4_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq4_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq4_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq4_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq4_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq4_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq4_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq4_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq4_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Kernel_seq2_0_conv1_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq2_0_conv1_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq2_0_conv2_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq2_0_conv2_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq2_0_downsample_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq2_1_conv1_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq2_1_conv1_0_3
    #pragma HLS int_tERFACE m_axi port=Kernel_seq2_1_conv2_0_0
    #pragma HLS int_tERFACE m_axi port=Kernel_seq2_1_conv2_0_3
    #pragma HLS int_tERFACE m_axi port=Mu_seq2_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq2_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq2_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq2_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq2_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq2_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq2_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq2_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq2_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq3_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq3_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq3_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq3_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq3_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq3_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq3_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq3_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Mu_seq3_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Bias_seq1_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Bias_seq1_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Bias_seq1_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Bias_seq1_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Bias_seq1_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Bias_seq1_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Bias_seq1_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Bias_seq1_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq2_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq2_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq2_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq2_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq2_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq2_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq2_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq2_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Bais_seq2_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Var_seq2_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq2_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Var_seq2_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq2_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Var_seq2_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Var_seq2_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq2_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Var_seq2_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Var_seq2_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq2_0_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq2_0_conv1_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq2_0_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq2_0_conv2_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq2_0_downsample_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq2_1_conv1_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq2_1_conv1_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq2_1_conv2_0_1
    #pragma HLS int_tERFACE m_axi port=Gamma_seq2_1_conv2_1
    #pragma HLS int_tERFACE m_axi port=Kernel_linear


 #else
    // R2Plus1dStem
    dtype* X_stem_1 = (dtype*)malloc(2257920*sizeof(dtype)); // value after first Conv-Batch-ReLU layer
    dtype* X_stem_2 = (dtype*)malloc(3211264*sizeof(dtype)); // value after second Conv-Batch-ReLU layer
    // // Sequential 1~4
    dtype* X_seq = (dtype*)malloc(50176*sizeof(dtype)); // value after 1~4 sequential layer
    // AdaptiveAvgPool3d
    dtype* X_adap = (dtype*)malloc(512*sizeof(dtype)); // value after AdaptiveAvgPool3d
    // Linear
    dtype* X_linear = (dtype*)malloc(400*sizeof(dtype)); // value after Linear layer
 #endif

    // ========================R2Plus1dStem ==================================
	int_t X_num[5] = {N_, 3, D_, 112, 112};
    int_t X_stem_1_num[5] = {N_, 45, D_, 56, 56};
    int_t Kernel_stem_1_num[3] = {1, 7, 7};
    int_t stride_1[3] = {1, 2, 2};
    int_t padding_1[3] = {0, 3, 3};

    Conv3d(X, X_num, X_stem_1, X_stem_1_num, Kernel_stem_0, Kernel_stem_1_num, Kernel_stem_0_scale, stride_1, padding_1, 3.756307810544967651e-02, 56, 0.4609071612358093262, 60);
    BatchNorm3d(X_stem_1, X_stem_1_num, Mu_stem_1, Var_stem_1, Gamma_stem_1, Bias_stem_1, 0.4609071612358093262, 60, 0.07323520630598068237, 55);
    ReLU(X_stem_1, X_stem_1_num, 55);

    int_t X_stem_2_num[5] = {N_, 64, D_, 56, 56};
    int_t Kernel_stem_2_num[3] = {3, 1, 1};
    int_t stride_2[3] = {1, 1, 1};
    int_t padding_2[3] = {1, 0, 0};

    Conv3d(X_stem_1, X_stem_1_num, X_stem_2, X_stem_2_num, Kernel_stem_3, Kernel_stem_2_num, Kernel_stem_3_scale, stride_2, padding_2, 0.07323520630598068237, 55, 0.09311912953853607178, 70);
    BatchNorm3d(X_stem_2, X_stem_2_num, Mu_stem_4, Var_stem_4, Gamma_stem_4, Bias_stem_4, 0.09311912953853607178, 70, 0.07423608750104904175, 65);
    ReLU(X_stem_2, X_stem_2_num, 65);
    
    // // for stem test
    // for(int_t i = 0; i < 3211264; i++)
    //     Y[i] = X_stem_2[i]; // assign result to output
    
    // // ========================Sequential 1~4==================================
    Sequential(X_stem_2, X_seq, 
        Kernel_seq1_0_conv1_0_0, Kernel_seq1_0_conv1_0_3, Kernel_seq1_0_conv2_0_0, Kernel_seq1_0_conv2_0_3, Kernel_seq1_1_conv1_0_0, Kernel_seq1_1_conv1_0_3, Kernel_seq1_1_conv2_0_0, Kernel_seq1_1_conv2_0_3, 
        Kernel_seq2_0_conv1_0_0, Kernel_seq2_0_conv1_0_3, Kernel_seq2_0_conv2_0_0, Kernel_seq2_0_conv2_0_3, Kernel_seq2_0_downsample_0, Kernel_seq2_1_conv1_0_0, Kernel_seq2_1_conv1_0_3, Kernel_seq2_1_conv2_0_0, Kernel_seq2_1_conv2_0_3,
        Kernel_seq3_0_conv1_0_0, Kernel_seq3_0_conv1_0_3, Kernel_seq3_0_conv2_0_0, Kernel_seq3_0_conv2_0_3, Kernel_seq3_0_downsample_0, Kernel_seq3_1_conv1_0_0, Kernel_seq3_1_conv1_0_3, Kernel_seq3_1_conv2_0_0, Kernel_seq3_1_conv2_0_3,
        Kernel_seq4_0_conv1_0_0, Kernel_seq4_0_conv1_0_3, Kernel_seq4_0_conv2_0_0, Kernel_seq4_0_conv2_0_3, Kernel_seq4_0_downsample_0, Kernel_seq4_1_conv1_0_0, Kernel_seq4_1_conv1_0_3, Kernel_seq4_1_conv2_0_0, Kernel_seq4_1_conv2_0_3,
        0.07423608750104904175, 65,
        Kernel_seq1_0_conv1_0_0_scale, Kernel_seq1_0_conv1_0_3_scale, Kernel_seq1_0_conv2_0_0_scale, Kernel_seq1_0_conv2_0_3_scale, Kernel_seq1_1_conv1_0_0_scale, Kernel_seq1_1_conv1_0_3_scale, Kernel_seq1_1_conv2_0_0_scale, Kernel_seq1_1_conv2_0_3_scale, 
        Kernel_seq2_0_conv1_0_0_scale, Kernel_seq2_0_conv1_0_3_scale, Kernel_seq2_0_conv2_0_0_scale, Kernel_seq2_0_conv2_0_3_scale, Kernel_seq2_0_downsample_0_scale, Kernel_seq2_1_conv1_0_0_scale, Kernel_seq2_1_conv1_0_3_scale, Kernel_seq2_1_conv2_0_0_scale, Kernel_seq2_1_conv2_0_3_scale,
        Kernel_seq3_0_conv1_0_0_scale, Kernel_seq3_0_conv1_0_3_scale, Kernel_seq3_0_conv2_0_0_scale, Kernel_seq3_0_conv2_0_3_scale, Kernel_seq3_0_downsample_0_scale, Kernel_seq3_1_conv1_0_0_scale, Kernel_seq3_1_conv1_0_3_scale, Kernel_seq3_1_conv2_0_0_scale, Kernel_seq3_1_conv2_0_3_scale,
        Kernel_seq4_0_conv1_0_0_scale, Kernel_seq4_0_conv1_0_3_scale, Kernel_seq4_0_conv2_0_0_scale, Kernel_seq4_0_conv2_0_3_scale, Kernel_seq4_0_downsample_0_scale, Kernel_seq4_1_conv1_0_0_scale, Kernel_seq4_1_conv1_0_3_scale, Kernel_seq4_1_conv2_0_0_scale, Kernel_seq4_1_conv2_0_3_scale,
        Mu_seq1_0_conv1_0_1, Mu_seq1_0_conv1_1, Mu_seq1_0_conv2_0_1, Mu_seq1_0_conv2_1, Mu_seq1_1_conv1_0_1, Mu_seq1_1_conv1_1, Mu_seq1_1_conv2_0_1, Mu_seq1_1_conv2_1,
        Mu_seq2_0_conv1_0_1, Mu_seq2_0_conv1_1, Mu_seq2_0_conv2_0_1, Mu_seq2_0_conv2_1, Mu_seq2_0_downsample_1, Mu_seq2_1_conv1_0_1, Mu_seq2_1_conv1_1, Mu_seq2_1_conv2_0_1, Mu_seq2_1_conv2_1,
        Mu_seq3_0_conv1_0_1, Mu_seq3_0_conv1_1, Mu_seq3_0_conv2_0_1, Mu_seq3_0_conv2_1, Mu_seq3_0_downsample_1, Mu_seq3_1_conv1_0_1, Mu_seq3_1_conv1_1, Mu_seq3_1_conv2_0_1, Mu_seq3_1_conv2_1,
        Mu_seq4_0_conv1_0_1, Mu_seq4_0_conv1_1, Mu_seq4_0_conv2_0_1, Mu_seq4_0_conv2_1, Mu_seq4_0_downsample_1, Mu_seq4_1_conv1_0_1, Mu_seq4_1_conv1_1, Mu_seq4_1_conv2_0_1, Mu_seq4_1_conv2_1,
        Var_seq1_0_conv1_0_1, Var_seq1_0_conv1_1, Var_seq1_0_conv2_0_1, Var_seq1_0_conv2_1, Var_seq1_1_conv1_0_1, Var_seq1_1_conv1_1, Var_seq1_1_conv2_0_1, Var_seq1_1_conv2_1,
        Var_seq2_0_conv1_0_1, Var_seq2_0_conv1_1, Var_seq2_0_conv2_0_1, Var_seq2_0_conv2_1, Var_seq2_0_downsample_1, Var_seq2_1_conv1_0_1, Var_seq2_1_conv1_1, Var_seq2_1_conv2_0_1, Var_seq2_1_conv2_1,
        Var_seq3_0_conv1_0_1, Var_seq3_0_conv1_1, Var_seq3_0_conv2_0_1, Var_seq3_0_conv2_1, Var_seq3_0_downsample_1, Var_seq3_1_conv1_0_1, Var_seq3_1_conv1_1, Var_seq3_1_conv2_0_1, Var_seq3_1_conv2_1,
        Var_seq4_0_conv1_0_1, Var_seq4_0_conv1_1, Var_seq4_0_conv2_0_1, Var_seq4_0_conv2_1, Var_seq4_0_downsample_1, Var_seq4_1_conv1_0_1, Var_seq4_1_conv1_1, Var_seq4_1_conv2_0_1, Var_seq4_1_conv2_1,
        Gamma_seq1_0_conv1_0_1, Gamma_seq1_0_conv1_1, Gamma_seq1_0_conv2_0_1, Gamma_seq1_0_conv2_1, Gamma_seq1_1_conv1_0_1, Gamma_seq1_1_conv1_1, Gamma_seq1_1_conv2_0_1, Gamma_seq1_1_conv2_1,
        Gamma_seq2_0_conv1_0_1, Gamma_seq2_0_conv1_1, Gamma_seq2_0_conv2_0_1, Gamma_seq2_0_conv2_1, Gamma_seq2_0_downsample_1, Gamma_seq2_1_conv1_0_1, Gamma_seq2_1_conv1_1, Gamma_seq2_1_conv2_0_1, Gamma_seq2_1_conv2_1,
        Gamma_seq3_0_conv1_0_1, Gamma_seq3_0_conv1_1, Gamma_seq3_0_conv2_0_1, Gamma_seq3_0_conv2_1, Gamma_seq3_0_downsample_1, Gamma_seq3_1_conv1_0_1, Gamma_seq3_1_conv1_1, Gamma_seq3_1_conv2_0_1, Gamma_seq3_1_conv2_1,
        Gamma_seq4_0_conv1_0_1, Gamma_seq4_0_conv1_1, Gamma_seq4_0_conv2_0_1, Gamma_seq4_0_conv2_1, Gamma_seq4_0_downsample_1, Gamma_seq4_1_conv1_0_1, Gamma_seq4_1_conv1_1, Gamma_seq4_1_conv2_0_1, Gamma_seq4_1_conv2_1,
        Bias_seq1_0_conv1_0_1, Bias_seq1_0_conv1_1, Bias_seq1_0_conv2_0_1, Bias_seq1_0_conv2_1, Bias_seq1_1_conv1_0_1, Bias_seq1_1_conv1_1, Bias_seq1_1_conv2_0_1, Bias_seq1_1_conv2_1,
        Bais_seq2_0_conv1_0_1, Bais_seq2_0_conv1_1, Bais_seq2_0_conv2_0_1, Bais_seq2_0_conv2_1, Bais_seq2_0_downsample_1, Bais_seq2_1_conv1_0_1, Bais_seq2_1_conv1_1, Bais_seq2_1_conv2_0_1, Bais_seq2_1_conv2_1,
        Bais_seq3_0_conv1_0_1, Bais_seq3_0_conv1_1, Bais_seq3_0_conv2_0_1, Bais_seq3_0_conv2_1, Bais_seq3_0_downsample_1, Bais_seq3_1_conv1_0_1, Bais_seq3_1_conv1_1, Bais_seq3_1_conv2_0_1, Bais_seq3_1_conv2_1,
        Bais_seq4_0_conv1_0_1, Bais_seq4_0_conv1_1, Bais_seq4_0_conv2_0_1, Bais_seq4_0_conv2_1, Bais_seq4_0_downsample_1, Bais_seq4_1_conv1_0_1, Bais_seq4_1_conv1_1, Bais_seq4_1_conv2_0_1, Bais_seq4_1_conv2_1);

    // for sequential test
    for(int_t i = 0; i < 50176; i++)
        Y[i] = X_seq[i]; // assign result to output
    
    // // ======================== AdaptiveAvgPool3d ==================================
    // int_t X_seq_num[5] = {N_, 512, 2, 7, 7};
    // int_t X_adap_num[5] = {N_, 512, 1, 1, 1};
    // AdaptiveAvgPool3d(X_seq, X_seq_num, X_adap, X_adap_num);

    // // // for sequential test
    // // for(int_t i = 0; i < 512; i++)
    // //     Y[i] = X_adap[i]; // assign result to output

    // // ======================== Linear ==================================
    // int_t X_adap_flat_num[2] = {N_, 512};
    // Linear(X_adap, X_adap_flat_num, X_linear, Kernel_linear, Kernel_linear_scale);
    // for linear test
    // for(int_t i = 0; i < 10; i++)
    //     Y[i] = X_linear[i]; // assign result to output
 
 #ifndef __SYNTHESIS__
    free(X_stem_1);
    free(X_stem_2);
    free(X_seq);
    free(X_adap);
    free(X_linear);
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
