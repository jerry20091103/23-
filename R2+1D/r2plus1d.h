#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__

typedef int dtype;
typedef int int_t;

void r2plus1d(dtype* X, dtype* Y, dtype* Kernel_stem_0, dtype* Kernel_stem_3,
                double* Mu_stem_1, double* Mu_stem_4, double* Var_stem_1, double* Var_stem_4, double* Gamma_stem_1, double* Gamma_stem_4, double* Bias_stem_1, double* Bias_stem_4,
            dtype* Kernel_seq1_0_conv1_0_0, dtype* Kernel_seq1_0_conv1_0_3, dtype* Kernel_seq1_0_conv2_0_0, dtype* Kernel_seq1_0_conv2_0_3, dtype* Kernel_seq1_1_conv1_0_0, dtype* Kernel_seq1_1_conv1_0_3, dtype* Kernel_seq1_1_conv2_0_0, dtype* Kernel_seq1_1_conv2_0_3,
                double* Mu_seq1_0_conv1_0_1, double* Mu_seq1_0_conv1_1, double* Mu_seq1_0_conv2_0_1, double* Mu_seq1_0_conv2_1, double* Mu_seq1_1_conv1_0_1, double* Mu_seq1_1_conv1_1, double* Mu_seq1_1_conv2_0_1, double* Mu_seq1_1_conv2_1,
                double* Var_seq1_0_conv1_0_1, double* Var_seq1_0_conv1_1, double* Var_seq1_0_conv2_0_1, double* Var_seq1_0_conv2_1, double* Var_seq1_1_conv1_0_1, double* Var_seq1_1_conv1_1, double* Var_seq1_1_conv2_0_1, double* Var_seq1_1_conv2_1,
                double* Gamma_seq1_0_conv1_0_1, double* Gamma_seq1_0_conv1_1, double* Gamma_seq1_0_conv2_0_1, double* Gamma_seq1_0_conv2_1, double* Gamma_seq1_1_conv1_0_1, double* Gamma_seq1_1_conv1_1, double* Gamma_seq1_1_conv2_0_1, double* Gamma_seq1_1_conv2_1,
                double* Bias_seq1_0_conv1_0_1, double* Bias_seq1_0_conv1_1, double* Bias_seq1_0_conv2_0_1, double* Bias_seq1_0_conv2_1, double* Bias_seq1_1_conv1_0_1, double* Bias_seq1_1_conv1_1, double* Bias_seq1_1_conv2_0_1, double* Bias_seq1_1_conv2_1,
            dtype* Kernel_seq2_0_conv1_0_0, dtype* Kernel_seq2_0_conv1_0_3, dtype* Kernel_seq2_0_conv2_0_0, dtype* Kernel_seq2_0_conv2_0_3, dtype* Kernel_seq2_0_downsample_0, dtype* Kernel_seq2_1_conv1_0_0, dtype* Kernel_seq2_1_conv1_0_3, dtype* Kernel_seq2_1_conv2_0_0, dtype* Kernel_seq2_1_conv2_0_3,
                double* Mu_seq2_0_conv1_0_1, double* Mu_seq2_0_conv1_1, double* Mu_seq2_0_conv2_0_1, double* Mu_seq2_0_conv2_1, double* Mu_seq2_0_downsample_1, double* Mu_seq2_1_conv1_0_1, double* Mu_seq2_1_conv1_1, double* Mu_seq2_1_conv2_0_1, double* Mu_seq2_1_conv2_1,
                double* Var_seq2_0_conv1_0_1, double* Var_seq2_0_conv1_1, double* Var_seq2_0_conv2_0_1, double* Var_seq2_0_conv2_1, double* Var_seq2_0_downsample_1, double* Var_seq2_1_conv1_0_1, double* Var_seq2_1_conv1_1, double* Var_seq2_1_conv2_0_1, double* Var_seq2_1_conv2_1,
                double* Gamma_seq2_0_conv1_0_1, double* Gamma_seq2_0_conv1_1, double* Gamma_seq2_0_conv2_0_1, double* Gamma_seq2_0_conv2_1, double* Gamma_seq2_0_downsample_1, double* Gamma_seq2_1_conv1_0_1, double* Gamma_seq2_1_conv1_1, double* Gamma_seq2_1_conv2_0_1, double* Gamma_seq2_1_conv2_1,
                double* Bais_seq2_0_conv1_0_1, double* Bais_seq2_0_conv1_1, double* Bais_seq2_0_conv2_0_1, double* Bais_seq2_0_conv2_1, double* Bais_seq2_0_downsample_1, double* Bais_seq2_1_conv1_0_1, double* Bais_seq2_1_conv1_1, double* Bais_seq2_1_conv2_0_1, double* Bais_seq2_1_conv2_1,
            dtype* Kernel_seq3_0_conv1_0_0, dtype* Kernel_seq3_0_conv1_0_3, dtype* Kernel_seq3_0_conv2_0_0, dtype* Kernel_seq3_0_conv2_0_3, dtype* Kernel_seq3_0_downsample_0, dtype* Kernel_seq3_1_conv1_0_0, dtype* Kernel_seq3_1_conv1_0_3, dtype* Kernel_seq3_1_conv2_0_0, dtype* Kernel_seq3_1_conv2_0_3,
                double* Mu_seq3_0_conv1_0_1, double* Mu_seq3_0_conv1_1, double* Mu_seq3_0_conv2_0_1, double* Mu_seq3_0_conv2_1, double* Mu_seq3_0_downsample_1, double* Mu_seq3_1_conv1_0_1, double* Mu_seq3_1_conv1_1, double* Mu_seq3_1_conv2_0_1, double* Mu_seq3_1_conv2_1,
                double* Var_seq3_0_conv1_0_1, double* Var_seq3_0_conv1_1, double* Var_seq3_0_conv2_0_1, double* Var_seq3_0_conv2_1, double* Var_seq3_0_downsample_1, double* Var_seq3_1_conv1_0_1, double* Var_seq3_1_conv1_1, double* Var_seq3_1_conv2_0_1, double* Var_seq3_1_conv2_1,
                double* Gamma_seq3_0_conv1_0_1, double* Gamma_seq3_0_conv1_1, double* Gamma_seq3_0_conv2_0_1, double* Gamma_seq3_0_conv2_1, double* Gamma_seq3_0_downsample_1, double* Gamma_seq3_1_conv1_0_1, double* Gamma_seq3_1_conv1_1, double* Gamma_seq3_1_conv2_0_1, double* Gamma_seq3_1_conv2_1,
                double* Bais_seq3_0_conv1_0_1, double* Bais_seq3_0_conv1_1, double* Bais_seq3_0_conv2_0_1, double* Bais_seq3_0_conv2_1, double* Bais_seq3_0_downsample_1, double* Bais_seq3_1_conv1_0_1, double* Bais_seq3_1_conv1_1, double* Bais_seq3_1_conv2_0_1, double* Bais_seq3_1_conv2_1,
            dtype* Kernel_seq4_0_conv1_0_0, dtype* Kernel_seq4_0_conv1_0_3, dtype* Kernel_seq4_0_conv2_0_0, dtype* Kernel_seq4_0_conv2_0_3, dtype* Kernel_seq4_0_downsample_0, dtype* Kernel_seq4_1_conv1_0_0, dtype* Kernel_seq4_1_conv1_0_3, dtype* Kernel_seq4_1_conv2_0_0, dtype* Kernel_seq4_1_conv2_0_3,
                double* Mu_seq4_0_conv1_0_1, double* Mu_seq4_0_conv1_1, double* Mu_seq4_0_conv2_0_1, double* Mu_seq4_0_conv2_1, double* Mu_seq4_0_downsample_1, double* Mu_seq4_1_conv1_0_1, double* Mu_seq4_1_conv1_1, double* Mu_seq4_1_conv2_0_1, double* Mu_seq4_1_conv2_1,
                double* Var_seq4_0_conv1_0_1, double* Var_seq4_0_conv1_1, double* Var_seq4_0_conv2_0_1, double* Var_seq4_0_conv2_1, double* Var_seq4_0_downsample_1, double* Var_seq4_1_conv1_0_1, double* Var_seq4_1_conv1_1, double* Var_seq4_1_conv2_0_1, double* Var_seq4_1_conv2_1,
                double* Gamma_seq4_0_conv1_0_1, double* Gamma_seq4_0_conv1_1, double* Gamma_seq4_0_conv2_0_1, double* Gamma_seq4_0_conv2_1, double* Gamma_seq4_0_downsample_1, double* Gamma_seq4_1_conv1_0_1, double* Gamma_seq4_1_conv1_1, double* Gamma_seq4_1_conv2_0_1, double* Gamma_seq4_1_conv2_1,
                double* Bais_seq4_0_conv1_0_1, double* Bais_seq4_0_conv1_1, double* Bais_seq4_0_conv2_0_1, double* Bais_seq4_0_conv2_1, double* Bais_seq4_0_downsample_1, double* Bais_seq4_1_conv1_0_1, double* Bais_seq4_1_conv1_1, double* Bais_seq4_1_conv2_0_1, double* Bais_seq4_1_conv2_1,
            dtype* Kernel_linear);
void Conv3d(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num, dtype* Kernel_data, int_t* Kernel_num, int_t* stride, int_t* padding, double scale, int_t zeropoint);
void BatchNorm3d(dtype* X_data, int_t* X_num, double* _mu, double* _var, double* r, double* b, double scale, int_t zeropoint);
void ReLU(dtype* X_data, int_t* X_num);

void Conv2Plus1D(dtype* X_data, int_t* X_num, dtype* X_out_data, int_t* X_out_num, int_t midplanes, dtype* Kernel_1_data, dtype* Kernel_2_data, int_t s, int_t p, 
                double Conv3d_1_scale, double Conv3d_2_scale, int_t Conv3d_1_zeropoint, int_t Conv3d_2_zeropoint,
                double* _mu, double* _var, double* r, double* b, double BatchNorm3d_scale, int_t BatchNorm3d_zeropoint);
void AdaptiveAvgPool3d(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num);
void Sequential(dtype* X_data, dtype* Y_data, dtype* Kernel_1_1_data, dtype* Kernel_1_2_data, dtype* Kernel_1_3_data, dtype* Kernel_1_4_data, dtype* Kernel_1_5_data, dtype* Kernel_1_6_data, dtype* Kernel_1_7_data, dtype* Kernel_1_8_data, 
                dtype* Kernel_2_1_data, dtype* Kernel_2_2_data, dtype* Kernel_2_3_data, dtype* Kernel_2_4_data, dtype* Kernel_2_5_data, dtype* Kernel_2_6_data, dtype* Kernel_2_7_data, dtype* Kernel_2_8_data, dtype* Kernel_2_9_data, 
                dtype* Kernel_3_1_data, dtype* Kernel_3_2_data, dtype* Kernel_3_3_data, dtype* Kernel_3_4_data, dtype* Kernel_3_5_data, dtype* Kernel_3_6_data, dtype* Kernel_3_7_data, dtype* Kernel_3_8_data, dtype* Kernel_3_9_data, 
                dtype* Kernel_4_1_data, dtype* Kernel_4_2_data, dtype* Kernel_4_3_data, dtype* Kernel_4_4_data, dtype* Kernel_4_5_data, dtype* Kernel_4_6_data, dtype* Kernel_4_7_data, dtype* Kernel_4_8_data, dtype* Kernel_4_9_data);
void Linear(dtype* X_data, int_t* X_num, dtype* Y_data, dtype* Kernel);
#endif

