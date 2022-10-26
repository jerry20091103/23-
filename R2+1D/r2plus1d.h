#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__

typedef double dtype;
typedef int int_t;

void r2plus1d(dtype* X, dtype* Y, dtype* Kernel_stem_1, dtype* Kernel_stem_2, 
            dtype* Kernel_seq_1_1, dtype* Kernel_seq_1_2, dtype* Kernel_seq_1_3, dtype* Kernel_seq_1_4, dtype* Kernel_seq_1_5, dtype* Kernel_seq_1_6, dtype* Kernel_seq_1_7, dtype* Kernel_seq_1_8, 
            dtype* Kernel_seq_2_1, dtype* Kernel_seq_2_2, dtype* Kernel_seq_2_3, dtype* Kernel_seq_2_4, dtype* Kernel_seq_2_5, dtype* Kernel_seq_2_6, dtype* Kernel_seq_2_7, dtype* Kernel_seq_2_8, dtype* Kernel_seq_2_9, 
            dtype* Kernel_seq_3_1, dtype* Kernel_seq_3_2, dtype* Kernel_seq_3_3, dtype* Kernel_seq_3_4, dtype* Kernel_seq_3_5, dtype* Kernel_seq_3_6, dtype* Kernel_seq_3_7, dtype* Kernel_seq_3_8, dtype* Kernel_seq_3_9, 
            dtype* Kernel_seq_4_1, dtype* Kernel_seq_4_2, dtype* Kernel_seq_4_3, dtype* Kernel_seq_4_4, dtype* Kernel_seq_4_5, dtype* Kernel_seq_4_6, dtype* Kernel_seq_4_7, dtype* Kernel_seq_4_8, dtype* Kernel_seq_4_9);
void Conv3d(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num, dtype* Kernel_data, int_t* Kernel_num, int_t* stride, int_t* padding);
void BatchNorm3d(dtype* X_data, int_t* X_num, double e, int_t r, int_t b);
void ReLU(dtype* X_data, int_t* X_num);
// void Sequential(dtype* X_data, dtype* Y_data, dtype* Kernel_1_data, dtype* Kernel_2_data, dtype* Kernel_3_data, dtype* Kernel_4_data, dtype* Kernel_5_data, dtype* Kernel_6_data, dtype* Kernel_7_data, dtype* Kernel_8_data, dtype* Kernel_9_data, dtype* Kernel_10_data, dtype* Kernel_11_data, dtype* Kernel_12_data);
void Conv2Plus1D(dtype* X_data, int_t* X_num, dtype* X_out_data, int_t* X_out_num, int_t midplanes, dtype* Kernel_1_data, dtype* Kernel_2_data, int_t s, int_t p);
void AdaptiveAvgPool3d(dtype* X_data,int_t* X_num, int_t* out_size, dtype* Y_data, int_t* Y_num);
void Sequential(dtype* X_data, dtype* Y_data, dtype* Kernel_1_1_data, dtype* Kernel_1_2_data, dtype* Kernel_1_3_data, dtype* Kernel_1_4_data, dtype* Kernel_1_5_data, dtype* Kernel_1_6_data, dtype* Kernel_1_7_data, dtype* Kernel_1_8_data, 
                dtype* Kernel_2_1_data, dtype* Kernel_2_2_data, dtype* Kernel_2_3_data, dtype* Kernel_2_4_data, dtype* Kernel_2_5_data, dtype* Kernel_2_6_data, dtype* Kernel_2_7_data, dtype* Kernel_2_8_data, dtype* Kernel_2_9_data, 
                dtype* Kernel_3_1_data, dtype* Kernel_3_2_data, dtype* Kernel_3_3_data, dtype* Kernel_3_4_data, dtype* Kernel_3_5_data, dtype* Kernel_3_6_data, dtype* Kernel_3_7_data, dtype* Kernel_3_8_data, dtype* Kernel_3_9_data, 
                dtype* Kernel_4_1_data, dtype* Kernel_4_2_data, dtype* Kernel_4_3_data, dtype* Kernel_4_4_data, dtype* Kernel_4_5_data, dtype* Kernel_4_6_data, dtype* Kernel_4_7_data, dtype* Kernel_4_8_data, dtype* Kernel_4_9_data);

//void Linear(int_t* psum_range,dtype* x,int_t* x_num, dtype* weights, int_t* weights_num , int_t* weightsBias, bool bias,dtype* x_out);
#endif

