#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__

void r2plus1d(float* X_data, float* Y_data, float* Kernel_1_data, float* Kernel_2_data);
void Conv3d(float* X_data, int* X_num, float* Y_data, int* Y_num, float* Kernel_data, int* Kernel_num, int* stride, int* padding);
void BatchNorm3d(float* X_data, int* X_num, float e, int r, int b);
void ReLU(float* X_data, int* X_num);
void Sequential_1(float* X_data, float* Y_data, float* Kernel_1_data, float* Kernel_2_data, float* Kernel_3_data, float* Kernel_4_data, float* Kernel_5_data, float* Kernel_6_data, float* Kernel_7_data, float* Kernel_8_data, float* Kernel_9_data, float* Kernel_10_data, float* Kernel_11_data, float* Kernel_12_data);
//void Linear(int* psum_range,float* x,int* x_num, float* weights, int* weights_num , int* weightsBias, bool bias,float* x_out);
#endif

