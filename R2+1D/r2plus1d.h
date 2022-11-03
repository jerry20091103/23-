#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__

#include <stdint.h>

#define N_ 1
#define C_ 1152
#define D_ 16
typedef uint8_t dtype;
typedef int int_t;

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
                double* Bias_seq2_0_conv1_0_1, double* Bias_seq2_0_conv1_1, double* Bias_seq2_0_conv2_0_1, double* Bias_seq2_0_conv2_1, double* Bias_seq2_0_downsample_1, double* Bias_seq2_1_conv1_0_1, double* Bias_seq2_1_conv1_1, double* Bias_seq2_1_conv2_0_1, double* Bias_seq2_1_conv2_1,
            dtype* Kernel_seq3_0_conv1_0_0, dtype* Kernel_seq3_0_conv1_0_3, dtype* Kernel_seq3_0_conv2_0_0, dtype* Kernel_seq3_0_conv2_0_3, dtype* Kernel_seq3_0_downsample_0, dtype* Kernel_seq3_1_conv1_0_0, dtype* Kernel_seq3_1_conv1_0_3, dtype* Kernel_seq3_1_conv2_0_0, dtype* Kernel_seq3_1_conv2_0_3,
            double* Kernel_seq3_0_conv1_0_0_scale, double* Kernel_seq3_0_conv1_0_3_scale, double* Kernel_seq3_0_conv2_0_0_scale, double* Kernel_seq3_0_conv2_0_3_scale, double* Kernel_seq3_0_downsample_0_scale, double* Kernel_seq3_1_conv1_0_0_scale, double* Kernel_seq3_1_conv1_0_3_scale, double* Kernel_seq3_1_conv2_0_0_scale, double* Kernel_seq3_1_conv2_0_3_scale,
                double* Mu_seq3_0_conv1_0_1, double* Mu_seq3_0_conv1_1, double* Mu_seq3_0_conv2_0_1, double* Mu_seq3_0_conv2_1, double* Mu_seq3_0_downsample_1, double* Mu_seq3_1_conv1_0_1, double* Mu_seq3_1_conv1_1, double* Mu_seq3_1_conv2_0_1, double* Mu_seq3_1_conv2_1,
                double* Var_seq3_0_conv1_0_1, double* Var_seq3_0_conv1_1, double* Var_seq3_0_conv2_0_1, double* Var_seq3_0_conv2_1, double* Var_seq3_0_downsample_1, double* Var_seq3_1_conv1_0_1, double* Var_seq3_1_conv1_1, double* Var_seq3_1_conv2_0_1, double* Var_seq3_1_conv2_1,
                double* Gamma_seq3_0_conv1_0_1, double* Gamma_seq3_0_conv1_1, double* Gamma_seq3_0_conv2_0_1, double* Gamma_seq3_0_conv2_1, double* Gamma_seq3_0_downsample_1, double* Gamma_seq3_1_conv1_0_1, double* Gamma_seq3_1_conv1_1, double* Gamma_seq3_1_conv2_0_1, double* Gamma_seq3_1_conv2_1,
                double* Bias_seq3_0_conv1_0_1, double* Bias_seq3_0_conv1_1, double* Bias_seq3_0_conv2_0_1, double* Bias_seq3_0_conv2_1, double* Bias_seq3_0_downsample_1, double* Bias_seq3_1_conv1_0_1, double* Bias_seq3_1_conv1_1, double* Bias_seq3_1_conv2_0_1, double* Bias_seq3_1_conv2_1,
            dtype* Kernel_seq4_0_conv1_0_0, dtype* Kernel_seq4_0_conv1_0_3, dtype* Kernel_seq4_0_conv2_0_0, dtype* Kernel_seq4_0_conv2_0_3, dtype* Kernel_seq4_0_downsample_0, dtype* Kernel_seq4_1_conv1_0_0, dtype* Kernel_seq4_1_conv1_0_3, dtype* Kernel_seq4_1_conv2_0_0, dtype* Kernel_seq4_1_conv2_0_3,
            double* Kernel_seq4_0_conv1_0_0_scale, double* Kernel_seq4_0_conv1_0_3_scale, double* Kernel_seq4_0_conv2_0_0_scale, double* Kernel_seq4_0_conv2_0_3_scale, double* Kernel_seq4_0_downsample_0_scale, double* Kernel_seq4_1_conv1_0_0_scale, double* Kernel_seq4_1_conv1_0_3_scale, double* Kernel_seq4_1_conv2_0_0_scale, double* Kernel_seq4_1_conv2_0_3_scale,
                double* Mu_seq4_0_conv1_0_1, double* Mu_seq4_0_conv1_1, double* Mu_seq4_0_conv2_0_1, double* Mu_seq4_0_conv2_1, double* Mu_seq4_0_downsample_1, double* Mu_seq4_1_conv1_0_1, double* Mu_seq4_1_conv1_1, double* Mu_seq4_1_conv2_0_1, double* Mu_seq4_1_conv2_1,
                double* Var_seq4_0_conv1_0_1, double* Var_seq4_0_conv1_1, double* Var_seq4_0_conv2_0_1, double* Var_seq4_0_conv2_1, double* Var_seq4_0_downsample_1, double* Var_seq4_1_conv1_0_1, double* Var_seq4_1_conv1_1, double* Var_seq4_1_conv2_0_1, double* Var_seq4_1_conv2_1,
                double* Gamma_seq4_0_conv1_0_1, double* Gamma_seq4_0_conv1_1, double* Gamma_seq4_0_conv2_0_1, double* Gamma_seq4_0_conv2_1, double* Gamma_seq4_0_downsample_1, double* Gamma_seq4_1_conv1_0_1, double* Gamma_seq4_1_conv1_1, double* Gamma_seq4_1_conv2_0_1, double* Gamma_seq4_1_conv2_1,
                double* Bias_seq4_0_conv1_0_1, double* Bias_seq4_0_conv1_1, double* Bias_seq4_0_conv2_0_1, double* Bias_seq4_0_conv2_1, double* Bias_seq4_0_downsample_1, double* Bias_seq4_1_conv1_0_1, double* Bias_seq4_1_conv1_1, double* Bias_seq4_1_conv2_0_1, double* Bias_seq4_1_conv2_1,
            dtype* Kernel_linear, double* Kernel_linear_scale);
void Conv3d(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num, dtype* Kernel_data, int_t* Kernel_num, double* kernel_scale, int_t* stride, int_t* padding, double scale_in, int_t zp_in, double scale_out, int_t zp_out);
void BatchNorm3d(dtype* X_data, int_t* X_num, double* mu_, double* var_, double* r, double* b, double scale_in, int_t zp_in, double scale_out, int_t zp_out);
void ReLU(dtype* X_data, int_t* X_num, int_t zp);
void Conv2Plus1D(dtype* X_data, int_t* X_num, dtype* X_out_data, int_t* X_out_num, int_t midplanes, 
                dtype* Kernel_1_data, dtype* Kernel_2_data, double* Kernel_1_data_scale, double* Kernel_2_data_scale, int_t s, int_t p, 
                double X_scale, double Conv3d_1_scale, double Conv3d_2_scale, int_t X_zeropoint, int_t Conv3d_1_zeropoint, int_t Conv3d_2_zeropoint,
                double* _mu, double* _var, double* r, double* b, double BatchNorm3d_scale, int_t BatchNorm3d_zeropoint);
void Sequential(dtype* X_data, dtype* Y_data, 
                dtype* Kernel_1_1_data, dtype* Kernel_1_2_data, dtype* Kernel_1_3_data, dtype* Kernel_1_4_data, dtype* Kernel_1_5_data, dtype* Kernel_1_6_data, dtype* Kernel_1_7_data, dtype* Kernel_1_8_data, 
                dtype* Kernel_2_1_data, dtype* Kernel_2_2_data, dtype* Kernel_2_3_data, dtype* Kernel_2_4_data, dtype* Kernel_2_5_data, dtype* Kernel_2_6_data, dtype* Kernel_2_7_data, dtype* Kernel_2_8_data, dtype* Kernel_2_9_data, 
                dtype* Kernel_3_1_data, dtype* Kernel_3_2_data, dtype* Kernel_3_3_data, dtype* Kernel_3_4_data, dtype* Kernel_3_5_data, dtype* Kernel_3_6_data, dtype* Kernel_3_7_data, dtype* Kernel_3_8_data, dtype* Kernel_3_9_data, 
                dtype* Kernel_4_1_data, dtype* Kernel_4_2_data, dtype* Kernel_4_3_data, dtype* Kernel_4_4_data, dtype* Kernel_4_5_data, dtype* Kernel_4_6_data, dtype* Kernel_4_7_data, dtype* Kernel_4_8_data, dtype* Kernel_4_9_data,
                double X_scale, int_t X_zeropoint,
                double* Kernel_1_1_data_scale, double* Kernel_1_2_data_scale, double* Kernel_1_3_data_scale, double* Kernel_1_4_data_scale, double* Kernel_1_5_data_scale, double* Kernel_1_6_data_scale, double* Kernel_1_7_data_scale, double* Kernel_1_8_data_scale, 
                double* Kernel_2_1_data_scale, double* Kernel_2_2_data_scale, double* Kernel_2_3_data_scale, double* Kernel_2_4_data_scale, double* Kernel_2_5_data_scale, double* Kernel_2_6_data_scale, double* Kernel_2_7_data_scale, double* Kernel_2_8_data_scale, double* Kernel_2_9_data_scale, 
                double* Kernel_3_1_data_scale, double* Kernel_3_2_data_scale, double* Kernel_3_3_data_scale, double* Kernel_3_4_data_scale, double* Kernel_3_5_data_scale, double* Kernel_3_6_data_scale, double* Kernel_3_7_data_scale, double* Kernel_3_8_data_scale, double* Kernel_3_9_data_scale, 
                double* Kernel_4_1_data_scale, double* Kernel_4_2_data_scale, double* Kernel_4_3_data_scale, double* Kernel_4_4_data_scale, double* Kernel_4_5_data_scale, double* Kernel_4_6_data_scale, double* Kernel_4_7_data_scale, double* Kernel_4_8_data_scale, double* Kernel_4_9_data_scale,
                double* Mu_seq_1_1, double* Mu_seq_1_2, double* Mu_seq_1_3, double* Mu_seq_1_4, double* Mu_seq_1_5, double* Mu_seq_1_6, double* Mu_seq_1_7, double* Mu_seq_1_8,
                double* Mu_seq_2_1, double* Mu_seq_2_2, double* Mu_seq_2_3, double* Mu_seq_2_4, double* Mu_seq_2_5, double* Mu_seq_2_6, double* Mu_seq_2_7, double* Mu_seq_2_8,double* Mu_seq_2_9,
                double* Mu_seq_3_1, double* Mu_seq_3_2, double* Mu_seq_3_3, double* Mu_seq_3_4, double* Mu_seq_3_5, double* Mu_seq_3_6, double* Mu_seq_3_7, double* Mu_seq_3_8,double* Mu_seq_3_9,
                double* Mu_seq_4_1, double* Mu_seq_4_2, double* Mu_seq_4_3, double* Mu_seq_4_4, double* Mu_seq_4_5, double* Mu_seq_4_6, double* Mu_seq_4_7, double* Mu_seq_4_8,double* Mu_seq_4_9,
                double* Var_seq_1_1, double* Var_seq_1_2, double* Var_seq_1_3, double* Var_seq_1_4, double* Var_seq_1_5, double* Var_seq_1_6, double* Var_seq_1_7, double* Var_seq_1_8,
                double* Var_seq_2_1, double* Var_seq_2_2, double* Var_seq_2_3, double* Var_seq_2_4, double* Var_seq_2_5, double* Var_seq_2_6, double* Var_seq_2_7, double* Var_seq_2_8,double* Var_seq_2_9,
                double* Var_seq_3_1, double* Var_seq_3_2, double* Var_seq_3_3, double* Var_seq_3_4, double* Var_seq_3_5, double* Var_seq_3_6, double* Var_seq_3_7, double* Var_seq_3_8,double* Var_seq_3_9,
                double* Var_seq_4_1, double* Var_seq_4_2, double* Var_seq_4_3, double* Var_seq_4_4, double* Var_seq_4_5, double* Var_seq_4_6, double* Var_seq_4_7, double* Var_seq_4_8,double* Var_seq_4_9,
                double* Gamma_seq_1_1, double* Gamma_seq_1_2, double* Gamma_seq_1_3, double* Gamma_seq_1_4, double* Gamma_seq_1_5, double* Gamma_seq_1_6, double* Gamma_seq_1_7, double* Gamma_seq_1_8,
                double* Gamma_seq_2_1, double* Gamma_seq_2_2, double* Gamma_seq_2_3, double* Gamma_seq_2_4, double* Gamma_seq_2_5, double* Gamma_seq_2_6, double* Gamma_seq_2_7, double* Gamma_seq_2_8,double* Gamma_seq_2_9,
                double* Gamma_seq_3_1, double* Gamma_seq_3_2, double* Gamma_seq_3_3, double* Gamma_seq_3_4, double* Gamma_seq_3_5, double* Gamma_seq_3_6, double* Gamma_seq_3_7, double* Gamma_seq_3_8,double* Gamma_seq_3_9,
                double* Gamma_seq_4_1, double* Gamma_seq_4_2, double* Gamma_seq_4_3, double* Gamma_seq_4_4, double* Gamma_seq_4_5, double* Gamma_seq_4_6, double* Gamma_seq_4_7, double* Gamma_seq_4_8,double* Gamma_seq_4_9,
                double* bias_seq_1_1, double* bias_seq_1_2, double* bias_seq_1_3, double* bias_seq_1_4, double* bias_seq_1_5, double* bias_seq_1_6, double* bias_seq_1_7, double* bias_seq_1_8,
                double* bias_seq_2_1, double* bias_seq_2_2, double* bias_seq_2_3, double* bias_seq_2_4, double* bias_seq_2_5, double* bias_seq_2_6, double* bias_seq_2_7, double* bias_seq_2_8,double* bias_seq_2_9,
                double* bias_seq_3_1, double* bias_seq_3_2, double* bias_seq_3_3, double* bias_seq_3_4, double* bias_seq_3_5, double* bias_seq_3_6, double* bias_seq_3_7, double* bias_seq_3_8,double* bias_seq_3_9,
                double* bias_seq_4_1, double* bias_seq_4_2, double* bias_seq_4_3, double* bias_seq_4_4, double* bias_seq_4_5, double* bias_seq_4_6, double* bias_seq_4_7, double* bias_seq_4_8,double* bias_seq_4_9);
void Residual(dtype* X, dtype* X_tmp, int_t* size, double X_scale, double X_tmp_scale, double out_scale, int_t X_zeropoint, int_t X_tmp_zeropoint, int_t out_zeropoint);
void AdaptiveAvgPool3d(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num);
void Linear(dtype* X_data, int_t* X_num, dtype* Y_data, dtype* Kernel, double* Kernel_scale);
#endif

