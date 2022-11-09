#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__

#include <stdint.h>
// It works!
typedef int dtype;
// typedef uint8_t dtype;
typedef int int_t;
typedef float ftype;
typedef int8_t ktype;
#include "inner_data.h"
void r2plus1d(dtype* X, ktype* Kernel_stem_0, ktype* Kernel_stem_3,
            ktype* Kernel_seq1_0_conv1_0_0, ktype* Kernel_seq1_0_conv1_0_3, ktype* Kernel_seq1_0_conv2_0_0, ktype* Kernel_seq1_0_conv2_0_3, ktype* Kernel_seq1_1_conv1_0_0, ktype* Kernel_seq1_1_conv1_0_3, ktype* Kernel_seq1_1_conv2_0_0, ktype* Kernel_seq1_1_conv2_0_3,
            ktype* Kernel_seq2_0_conv1_0_0, ktype* Kernel_seq2_0_conv1_0_3, ktype* Kernel_seq2_0_conv2_0_0, ktype* Kernel_seq2_0_conv2_0_3, ktype* Kernel_seq2_0_downsample_0, ktype* Kernel_seq2_1_conv1_0_0, ktype* Kernel_seq2_1_conv1_0_3, ktype* Kernel_seq2_1_conv2_0_0, ktype* Kernel_seq2_1_conv2_0_3,
            ktype* Kernel_seq3_0_conv1_0_0, ktype* Kernel_seq3_0_conv1_0_3, ktype* Kernel_seq3_0_conv2_0_0, ktype* Kernel_seq3_0_conv2_0_3, ktype* Kernel_seq3_0_downsample_0, ktype* Kernel_seq3_1_conv1_0_0, ktype* Kernel_seq3_1_conv1_0_3, ktype* Kernel_seq3_1_conv2_0_0, ktype* Kernel_seq3_1_conv2_0_3,
            ktype* Kernel_seq4_0_conv1_0_0, ktype* Kernel_seq4_0_conv1_0_3, ktype* Kernel_seq4_0_conv2_0_0, ktype* Kernel_seq4_0_conv2_0_3, ktype* Kernel_seq4_0_downsample_0, ktype* Kernel_seq4_1_conv1_0_0, ktype* Kernel_seq4_1_conv1_0_3, ktype* Kernel_seq4_1_conv2_0_0, ktype* Kernel_seq4_1_conv2_0_3,
            ktype* Kernel_linear,
            dtype* X_stem_1, dtype* X_stem_2, dtype* X2_data, dtype* X3_data, dtype* X_seq, dtype* X_adap, dtype* X_linear, 
            dtype* X_tmp_data, dtype* X2_tmp_data, dtype* X3_tmp_data, dtype* X4_tmp_data,
            dtype* X_batch_data, dtype* X2_batch_data, dtype* X3_batch_data, dtype* X4_batch_data,
            dtype* X_mid_data, dtype* X2_mid_data, dtype* X3_mid_data, dtype* X4_mid_data);
void Conv3d(dtype* X_data, int_t* X_num, int_t XI, int_t XC, dtype* Y_data, int_t* Y_num, int_t YI, int_t YC, ktype* Kernel_data, int_t* Kernel_num, int_t* stride, int_t* padding, dtype zp_in);
void BatchNorm3d(dtype* X_data, dtype* Y_data, int_t* X_num, ftype* mu_, ftype* var_, ftype* r, ftype* b, ftype scale_in, dtype zp_in, ftype scale_out, dtype zp_out);
void ReLU(dtype* X_data, dtype* Y_data, int_t* X_num, dtype zp);
void Conv2Plus1D(dtype* X_data, int_t* X_num, dtype* X_mid_data, dtype* X_batch_data, dtype* X_out_data, int_t* X_out_num, int_t midplanes,
                ktype* Kernel_1_data, ktype* Kernel_2_data, ftype* Kernel_1_data_scale, ftype* Kernel_2_data_scale, int_t s, int_t p, 
                ftype X_scale, ftype Conv3d_1_scale, ftype Conv3d_2_scale, dtype X_zeropoint, dtype Conv3d_1_zeropoint, dtype Conv3d_2_zeropoint,
                ftype* mu_, ftype* var_, ftype* r, ftype* b, ftype BatchNorm3d_scale, dtype BatchNorm3d_zeropoint);
void Sequential(dtype* X_data, dtype* X2_data, dtype* X3_data, dtype* X4_data, 
                dtype* X_tmp_data, dtype* X2_tmp_data, dtype* X3_tmp_data, dtype* X4_tmp_data,
                dtype* X_batch_data, dtype* X2_batch_data, dtype* X3_batch_data, dtype* X4_batch_data,
                dtype* X_mid_data, dtype* X2_mid_data, dtype* X3_mid_data, dtype* X4_mid_data,
                ftype X_scale, dtype X_zeropoint,
                ktype* Kernel_1_1_data, ktype* Kernel_1_2_data, ktype* Kernel_1_3_data, ktype* Kernel_1_4_data, ktype* Kernel_1_5_data, ktype* Kernel_1_6_data, ktype* Kernel_1_7_data, ktype* Kernel_1_8_data, 
                ktype* Kernel_2_1_data, ktype* Kernel_2_2_data, ktype* Kernel_2_3_data, ktype* Kernel_2_4_data, ktype* Kernel_2_5_data, ktype* Kernel_2_6_data, ktype* Kernel_2_7_data, ktype* Kernel_2_8_data, ktype* Kernel_2_9_data, 
                ktype* Kernel_3_1_data, ktype* Kernel_3_2_data, ktype* Kernel_3_3_data, ktype* Kernel_3_4_data, ktype* Kernel_3_5_data, ktype* Kernel_3_6_data, ktype* Kernel_3_7_data, ktype* Kernel_3_8_data, ktype* Kernel_3_9_data, 
                ktype* Kernel_4_1_data, ktype* Kernel_4_2_data, ktype* Kernel_4_3_data, ktype* Kernel_4_4_data, ktype* Kernel_4_5_data, ktype* Kernel_4_6_data, ktype* Kernel_4_7_data, ktype* Kernel_4_8_data, ktype* Kernel_4_9_data);
void Residual(dtype* X, dtype* X_tmp, int_t* size, ftype X_scale, ftype X_tmp_scale, ftype out_scale, dtype X_zeropoint, dtype X_tmp_zeropoint, dtype out_zeropoint);
void AdaptiveAvgPool3d(dtype* X_data, dtype* Y_data);
void Linear(dtype* X_data, int_t* X_num, dtype* Y_data, ktype* Kernel);
#endif

