#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__

#include <stdint.h>
// It works!
#define N_ 1
#define C_ 1152
#define D_ 16
typedef uint8_t dtype;
typedef int int_t;
typedef float ftype;
typedef int8_t ktype;
void r2plus1d(dtype* X, dtype* Y, ktype* Kernel_stem_0,ktype* Kernel_stem_3, ftype* Kernel_stem_0_scale, ftype* Kernel_stem_3_scale,
                ftype* Mu_stem_1, ftype* Mu_stem_4, ftype* Var_stem_1, ftype* Var_stem_4, ftype* Gamma_stem_1, ftype* Gamma_stem_4, ftype* Bias_stem_1, ftype* Bias_stem_4,
            ktype* Kernel_seq1_0_conv1_0_0, ktype* Kernel_seq1_0_conv1_0_3, ktype* Kernel_seq1_0_conv2_0_0, ktype* Kernel_seq1_0_conv2_0_3, ktype* Kernel_seq1_1_conv1_0_0, ktype* Kernel_seq1_1_conv1_0_3, ktype* Kernel_seq1_1_conv2_0_0, ktype* Kernel_seq1_1_conv2_0_3,
            ftype* Kernel_seq1_0_conv1_0_0_scale, ftype* Kernel_seq1_0_conv1_0_3_scale, ftype* Kernel_seq1_0_conv2_0_0_scale, ftype* Kernel_seq1_0_conv2_0_3_scale, ftype* Kernel_seq1_1_conv1_0_0_scale, ftype* Kernel_seq1_1_conv1_0_3_scale, ftype* Kernel_seq1_1_conv2_0_0_scale, ftype* Kernel_seq1_1_conv2_0_3_scale,
                ftype* Mu_seq1_0_conv1_0_1, ftype* Mu_seq1_0_conv1_1, ftype* Mu_seq1_0_conv2_0_1, ftype* Mu_seq1_0_conv2_1, ftype* Mu_seq1_1_conv1_0_1, ftype* Mu_seq1_1_conv1_1, ftype* Mu_seq1_1_conv2_0_1, ftype* Mu_seq1_1_conv2_1,
                ftype* Var_seq1_0_conv1_0_1, ftype* Var_seq1_0_conv1_1, ftype* Var_seq1_0_conv2_0_1, ftype* Var_seq1_0_conv2_1, ftype* Var_seq1_1_conv1_0_1, ftype* Var_seq1_1_conv1_1, ftype* Var_seq1_1_conv2_0_1, ftype* Var_seq1_1_conv2_1,
                ftype* Gamma_seq1_0_conv1_0_1, ftype* Gamma_seq1_0_conv1_1, ftype* Gamma_seq1_0_conv2_0_1, ftype* Gamma_seq1_0_conv2_1, ftype* Gamma_seq1_1_conv1_0_1, ftype* Gamma_seq1_1_conv1_1, ftype* Gamma_seq1_1_conv2_0_1, ftype* Gamma_seq1_1_conv2_1,
                ftype* Bias_seq1_0_conv1_0_1, ftype* Bias_seq1_0_conv1_1, ftype* Bias_seq1_0_conv2_0_1, ftype* Bias_seq1_0_conv2_1, ftype* Bias_seq1_1_conv1_0_1, ftype* Bias_seq1_1_conv1_1, ftype* Bias_seq1_1_conv2_0_1, ftype* Bias_seq1_1_conv2_1,
            ktype* Kernel_seq2_0_conv1_0_0, ktype* Kernel_seq2_0_conv1_0_3, ktype* Kernel_seq2_0_conv2_0_0, ktype* Kernel_seq2_0_conv2_0_3, ktype* Kernel_seq2_0_downsample_0, ktype* Kernel_seq2_1_conv1_0_0, ktype* Kernel_seq2_1_conv1_0_3, ktype* Kernel_seq2_1_conv2_0_0, ktype* Kernel_seq2_1_conv2_0_3,
            ftype* Kernel_seq2_0_conv1_0_0_scale, ftype* Kernel_seq2_0_conv1_0_3_scale, ftype* Kernel_seq2_0_conv2_0_0_scale, ftype* Kernel_seq2_0_conv2_0_3_scale, ftype* Kernel_seq2_0_downsample_0_scale, ftype* Kernel_seq2_1_conv1_0_0_scale, ftype* Kernel_seq2_1_conv1_0_3_scale, ftype* Kernel_seq2_1_conv2_0_0_scale, ftype* Kernel_seq2_1_conv2_0_3_scale,
                ftype* Mu_seq2_0_conv1_0_1, ftype* Mu_seq2_0_conv1_1, ftype* Mu_seq2_0_conv2_0_1, ftype* Mu_seq2_0_conv2_1, ftype* Mu_seq2_0_downsample_1, ftype* Mu_seq2_1_conv1_0_1, ftype* Mu_seq2_1_conv1_1, ftype* Mu_seq2_1_conv2_0_1, ftype* Mu_seq2_1_conv2_1,
                ftype* Var_seq2_0_conv1_0_1, ftype* Var_seq2_0_conv1_1, ftype* Var_seq2_0_conv2_0_1, ftype* Var_seq2_0_conv2_1, ftype* Var_seq2_0_downsample_1, ftype* Var_seq2_1_conv1_0_1, ftype* Var_seq2_1_conv1_1, ftype* Var_seq2_1_conv2_0_1, ftype* Var_seq2_1_conv2_1,
                ftype* Gamma_seq2_0_conv1_0_1, ftype* Gamma_seq2_0_conv1_1, ftype* Gamma_seq2_0_conv2_0_1, ftype* Gamma_seq2_0_conv2_1, ftype* Gamma_seq2_0_downsample_1, ftype* Gamma_seq2_1_conv1_0_1, ftype* Gamma_seq2_1_conv1_1, ftype* Gamma_seq2_1_conv2_0_1, ftype* Gamma_seq2_1_conv2_1,
                ftype* Bias_seq2_0_conv1_0_1, ftype* Bias_seq2_0_conv1_1, ftype* Bias_seq2_0_conv2_0_1, ftype* Bias_seq2_0_conv2_1, ftype* Bias_seq2_0_downsample_1, ftype* Bias_seq2_1_conv1_0_1, ftype* Bias_seq2_1_conv1_1, ftype* Bias_seq2_1_conv2_0_1, ftype* Bias_seq2_1_conv2_1,
            ktype* Kernel_seq3_0_conv1_0_0, ktype* Kernel_seq3_0_conv1_0_3, ktype* Kernel_seq3_0_conv2_0_0, ktype* Kernel_seq3_0_conv2_0_3, ktype* Kernel_seq3_0_downsample_0, ktype* Kernel_seq3_1_conv1_0_0, ktype* Kernel_seq3_1_conv1_0_3, ktype* Kernel_seq3_1_conv2_0_0, ktype* Kernel_seq3_1_conv2_0_3,
            ftype* Kernel_seq3_0_conv1_0_0_scale, ftype* Kernel_seq3_0_conv1_0_3_scale, ftype* Kernel_seq3_0_conv2_0_0_scale, ftype* Kernel_seq3_0_conv2_0_3_scale, ftype* Kernel_seq3_0_downsample_0_scale, ftype* Kernel_seq3_1_conv1_0_0_scale, ftype* Kernel_seq3_1_conv1_0_3_scale, ftype* Kernel_seq3_1_conv2_0_0_scale, ftype* Kernel_seq3_1_conv2_0_3_scale,
                ftype* Mu_seq3_0_conv1_0_1, ftype* Mu_seq3_0_conv1_1, ftype* Mu_seq3_0_conv2_0_1, ftype* Mu_seq3_0_conv2_1, ftype* Mu_seq3_0_downsample_1, ftype* Mu_seq3_1_conv1_0_1, ftype* Mu_seq3_1_conv1_1, ftype* Mu_seq3_1_conv2_0_1, ftype* Mu_seq3_1_conv2_1,
                ftype* Var_seq3_0_conv1_0_1, ftype* Var_seq3_0_conv1_1, ftype* Var_seq3_0_conv2_0_1, ftype* Var_seq3_0_conv2_1, ftype* Var_seq3_0_downsample_1, ftype* Var_seq3_1_conv1_0_1, ftype* Var_seq3_1_conv1_1, ftype* Var_seq3_1_conv2_0_1, ftype* Var_seq3_1_conv2_1,
                ftype* Gamma_seq3_0_conv1_0_1, ftype* Gamma_seq3_0_conv1_1, ftype* Gamma_seq3_0_conv2_0_1, ftype* Gamma_seq3_0_conv2_1, ftype* Gamma_seq3_0_downsample_1, ftype* Gamma_seq3_1_conv1_0_1, ftype* Gamma_seq3_1_conv1_1, ftype* Gamma_seq3_1_conv2_0_1, ftype* Gamma_seq3_1_conv2_1,
                ftype* Bias_seq3_0_conv1_0_1, ftype* Bias_seq3_0_conv1_1, ftype* Bias_seq3_0_conv2_0_1, ftype* Bias_seq3_0_conv2_1, ftype* Bias_seq3_0_downsample_1, ftype* Bias_seq3_1_conv1_0_1, ftype* Bias_seq3_1_conv1_1, ftype* Bias_seq3_1_conv2_0_1, ftype* Bias_seq3_1_conv2_1,
            ktype* Kernel_seq4_0_conv1_0_0, ktype* Kernel_seq4_0_conv1_0_3, ktype* Kernel_seq4_0_conv2_0_0, ktype* Kernel_seq4_0_conv2_0_3, ktype* Kernel_seq4_0_downsample_0, ktype* Kernel_seq4_1_conv1_0_0, ktype* Kernel_seq4_1_conv1_0_3, ktype* Kernel_seq4_1_conv2_0_0, ktype* Kernel_seq4_1_conv2_0_3,
            ftype* Kernel_seq4_0_conv1_0_0_scale, ftype* Kernel_seq4_0_conv1_0_3_scale, ftype* Kernel_seq4_0_conv2_0_0_scale, ftype* Kernel_seq4_0_conv2_0_3_scale, ftype* Kernel_seq4_0_downsample_0_scale, ftype* Kernel_seq4_1_conv1_0_0_scale, ftype* Kernel_seq4_1_conv1_0_3_scale, ftype* Kernel_seq4_1_conv2_0_0_scale, ftype* Kernel_seq4_1_conv2_0_3_scale,
                ftype* Mu_seq4_0_conv1_0_1, ftype* Mu_seq4_0_conv1_1, ftype* Mu_seq4_0_conv2_0_1, ftype* Mu_seq4_0_conv2_1, ftype* Mu_seq4_0_downsample_1, ftype* Mu_seq4_1_conv1_0_1, ftype* Mu_seq4_1_conv1_1, ftype* Mu_seq4_1_conv2_0_1, ftype* Mu_seq4_1_conv2_1,
                ftype* Var_seq4_0_conv1_0_1, ftype* Var_seq4_0_conv1_1, ftype* Var_seq4_0_conv2_0_1, ftype* Var_seq4_0_conv2_1, ftype* Var_seq4_0_downsample_1, ftype* Var_seq4_1_conv1_0_1, ftype* Var_seq4_1_conv1_1, ftype* Var_seq4_1_conv2_0_1, ftype* Var_seq4_1_conv2_1,
                ftype* Gamma_seq4_0_conv1_0_1, ftype* Gamma_seq4_0_conv1_1, ftype* Gamma_seq4_0_conv2_0_1, ftype* Gamma_seq4_0_conv2_1, ftype* Gamma_seq4_0_downsample_1, ftype* Gamma_seq4_1_conv1_0_1, ftype* Gamma_seq4_1_conv1_1, ftype* Gamma_seq4_1_conv2_0_1, ftype* Gamma_seq4_1_conv2_1,
                ftype* Bias_seq4_0_conv1_0_1, ftype* Bias_seq4_0_conv1_1, ftype* Bias_seq4_0_conv2_0_1, ftype* Bias_seq4_0_conv2_1, ftype* Bias_seq4_0_downsample_1, ftype* Bias_seq4_1_conv1_0_1, ftype* Bias_seq4_1_conv1_1, ftype* Bias_seq4_1_conv2_0_1, ftype* Bias_seq4_1_conv2_1,
            ktype* Kernel_linear, ftype* Kernel_linear_scale,
            dtype* X_stem_1, dtype* X_stem_2, dtype* X_seq,dtype* X_adap, dtype* X_tmp_data, dtype* X2_data, dtype* X2_tmp_data, dtype* X_mid_data, dtype* X_batch_data);
void Conv3d(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num, ktype* Kernel_data, int_t* Kernel_num, ftype* kernel_scale, int_t* stride, int_t* padding, ftype scale_in, int_t zp_in, ftype scale_out, int_t zp_out);
void BatchNorm3d(dtype* X_data, dtype* Y_data, int_t* X_num, ftype* mu_, ftype* var_, ftype* r, ftype* b, ftype scale_in, int_t zp_in, ftype scale_out, int_t zp_out);
void ReLU(dtype* X_data, dtype* Y_data, int_t* X_num, int_t zp);
void Conv2Plus1D(dtype* X_data, int_t* X_num, dtype* X_mid_data, dtype* X_batch_data, dtype* X_out_data, int_t* X_out_num, int_t midplanes,
                ktype* Kernel_1_data, ktype* Kernel_2_data, ftype* Kernel_1_data_scale, ftype* Kernel_2_data_scale, int_t s, int_t p, 
                ftype X_scale, ftype Conv3d_1_scale, ftype Conv3d_2_scale, int_t X_zeropoint, int_t Conv3d_1_zeropoint, int_t Conv3d_2_zeropoint,
                ftype* mu_, ftype* var_, ftype* r, ftype* b, ftype BatchNorm3d_scale, int_t BatchNorm3d_zeropoint);

void Sequential(dtype* X_data, dtype* Y_data, 
                ktype* Kernel_1_1_data, ktype* Kernel_1_2_data, ktype* Kernel_1_3_data, ktype* Kernel_1_4_data, ktype* Kernel_1_5_data, ktype* Kernel_1_6_data, ktype* Kernel_1_7_data, ktype* Kernel_1_8_data, 
                ktype* Kernel_2_1_data, ktype* Kernel_2_2_data, ktype* Kernel_2_3_data, ktype* Kernel_2_4_data, ktype* Kernel_2_5_data, ktype* Kernel_2_6_data, ktype* Kernel_2_7_data, ktype* Kernel_2_8_data, ktype* Kernel_2_9_data, 
                ktype* Kernel_3_1_data, ktype* Kernel_3_2_data, ktype* Kernel_3_3_data, ktype* Kernel_3_4_data, ktype* Kernel_3_5_data, ktype* Kernel_3_6_data, ktype* Kernel_3_7_data, ktype* Kernel_3_8_data, ktype* Kernel_3_9_data, 
                ktype* Kernel_4_1_data, ktype* Kernel_4_2_data, ktype* Kernel_4_3_data, ktype* Kernel_4_4_data, ktype* Kernel_4_5_data, ktype* Kernel_4_6_data, ktype* Kernel_4_7_data, ktype* Kernel_4_8_data, ktype* Kernel_4_9_data,
                ftype X_scale, int_t X_zeropoint,
                ftype* Kernel_1_1_data_scale, ftype* Kernel_1_2_data_scale, ftype* Kernel_1_3_data_scale, ftype* Kernel_1_4_data_scale, ftype* Kernel_1_5_data_scale, ftype* Kernel_1_6_data_scale, ftype* Kernel_1_7_data_scale, ftype* Kernel_1_8_data_scale, 
                ftype* Kernel_2_1_data_scale, ftype* Kernel_2_2_data_scale, ftype* Kernel_2_3_data_scale, ftype* Kernel_2_4_data_scale, ftype* Kernel_2_5_data_scale, ftype* Kernel_2_6_data_scale, ftype* Kernel_2_7_data_scale, ftype* Kernel_2_8_data_scale, ftype* Kernel_2_9_data_scale, 
                ftype* Kernel_3_1_data_scale, ftype* Kernel_3_2_data_scale, ftype* Kernel_3_3_data_scale, ftype* Kernel_3_4_data_scale, ftype* Kernel_3_5_data_scale, ftype* Kernel_3_6_data_scale, ftype* Kernel_3_7_data_scale, ftype* Kernel_3_8_data_scale, ftype* Kernel_3_9_data_scale, 
                ftype* Kernel_4_1_data_scale, ftype* Kernel_4_2_data_scale, ftype* Kernel_4_3_data_scale, ftype* Kernel_4_4_data_scale, ftype* Kernel_4_5_data_scale, ftype* Kernel_4_6_data_scale, ftype* Kernel_4_7_data_scale, ftype* Kernel_4_8_data_scale, ftype* Kernel_4_9_data_scale,
                ftype* Mu_seq_1_1, ftype* Mu_seq_1_2, ftype* Mu_seq_1_3, ftype* Mu_seq_1_4, ftype* Mu_seq_1_5, ftype* Mu_seq_1_6, ftype* Mu_seq_1_7, ftype* Mu_seq_1_8,
                ftype* Mu_seq_2_1, ftype* Mu_seq_2_2, ftype* Mu_seq_2_3, ftype* Mu_seq_2_4, ftype* Mu_seq_2_5, ftype* Mu_seq_2_6, ftype* Mu_seq_2_7, ftype* Mu_seq_2_8,ftype* Mu_seq_2_9,
                ftype* Mu_seq_3_1, ftype* Mu_seq_3_2, ftype* Mu_seq_3_3, ftype* Mu_seq_3_4, ftype* Mu_seq_3_5, ftype* Mu_seq_3_6, ftype* Mu_seq_3_7, ftype* Mu_seq_3_8,ftype* Mu_seq_3_9,
                ftype* Mu_seq_4_1, ftype* Mu_seq_4_2, ftype* Mu_seq_4_3, ftype* Mu_seq_4_4, ftype* Mu_seq_4_5, ftype* Mu_seq_4_6, ftype* Mu_seq_4_7, ftype* Mu_seq_4_8,ftype* Mu_seq_4_9,
                ftype* Var_seq_1_1, ftype* Var_seq_1_2, ftype* Var_seq_1_3, ftype* Var_seq_1_4, ftype* Var_seq_1_5, ftype* Var_seq_1_6, ftype* Var_seq_1_7, ftype* Var_seq_1_8,
                ftype* Var_seq_2_1, ftype* Var_seq_2_2, ftype* Var_seq_2_3, ftype* Var_seq_2_4, ftype* Var_seq_2_5, ftype* Var_seq_2_6, ftype* Var_seq_2_7, ftype* Var_seq_2_8,ftype* Var_seq_2_9,
                ftype* Var_seq_3_1, ftype* Var_seq_3_2, ftype* Var_seq_3_3, ftype* Var_seq_3_4, ftype* Var_seq_3_5, ftype* Var_seq_3_6, ftype* Var_seq_3_7, ftype* Var_seq_3_8,ftype* Var_seq_3_9,
                ftype* Var_seq_4_1, ftype* Var_seq_4_2, ftype* Var_seq_4_3, ftype* Var_seq_4_4, ftype* Var_seq_4_5, ftype* Var_seq_4_6, ftype* Var_seq_4_7, ftype* Var_seq_4_8,ftype* Var_seq_4_9,
                ftype* Gamma_seq_1_1, ftype* Gamma_seq_1_2, ftype* Gamma_seq_1_3, ftype* Gamma_seq_1_4, ftype* Gamma_seq_1_5, ftype* Gamma_seq_1_6, ftype* Gamma_seq_1_7, ftype* Gamma_seq_1_8,
                ftype* Gamma_seq_2_1, ftype* Gamma_seq_2_2, ftype* Gamma_seq_2_3, ftype* Gamma_seq_2_4, ftype* Gamma_seq_2_5, ftype* Gamma_seq_2_6, ftype* Gamma_seq_2_7, ftype* Gamma_seq_2_8,ftype* Gamma_seq_2_9,
                ftype* Gamma_seq_3_1, ftype* Gamma_seq_3_2, ftype* Gamma_seq_3_3, ftype* Gamma_seq_3_4, ftype* Gamma_seq_3_5, ftype* Gamma_seq_3_6, ftype* Gamma_seq_3_7, ftype* Gamma_seq_3_8,ftype* Gamma_seq_3_9,
                ftype* Gamma_seq_4_1, ftype* Gamma_seq_4_2, ftype* Gamma_seq_4_3, ftype* Gamma_seq_4_4, ftype* Gamma_seq_4_5, ftype* Gamma_seq_4_6, ftype* Gamma_seq_4_7, ftype* Gamma_seq_4_8,ftype* Gamma_seq_4_9,
                ftype* bias_seq_1_1, ftype* bias_seq_1_2, ftype* bias_seq_1_3, ftype* bias_seq_1_4, ftype* bias_seq_1_5, ftype* bias_seq_1_6, ftype* bias_seq_1_7, ftype* bias_seq_1_8,
                ftype* bias_seq_2_1, ftype* bias_seq_2_2, ftype* bias_seq_2_3, ftype* bias_seq_2_4, ftype* bias_seq_2_5, ftype* bias_seq_2_6, ftype* bias_seq_2_7, ftype* bias_seq_2_8,ftype* bias_seq_2_9,
                ftype* bias_seq_3_1, ftype* bias_seq_3_2, ftype* bias_seq_3_3, ftype* bias_seq_3_4, ftype* bias_seq_3_5, ftype* bias_seq_3_6, ftype* bias_seq_3_7, ftype* bias_seq_3_8,ftype* bias_seq_3_9,
                ftype* bias_seq_4_1, ftype* bias_seq_4_2, ftype* bias_seq_4_3, ftype* bias_seq_4_4, ftype* bias_seq_4_5, ftype* bias_seq_4_6, ftype* bias_seq_4_7, ftype* bias_seq_4_8,ftype* bias_seq_4_9,
                dtype* X_tmp_data, dtype* X2_data, dtype* X2_tmp_data, dtype* X_mid_data, dtype* X_batch_data);
void Residual(dtype* X, dtype* X_tmp, int_t* size, ftype X_scale, ftype X_tmp_scale, ftype out_scale, int_t X_zeropoint, int_t X_tmp_zeropoint, int_t out_zeropoint);
void AdaptiveAvgPool3d(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num);
void Linear(dtype* X_data, int_t* X_num, dtype* Y_data, ktype* Kernel, ftype* Kernel_scale);
#endif

