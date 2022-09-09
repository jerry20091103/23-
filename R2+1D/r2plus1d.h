#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__

void r2plus1d(float* X_data, float* Y_data, float* Kernel_1_data, float* Kernel_2_data);
void Conv3d(float* X_data, int* X_num, float* Y_data, int* Y_num, float* Kernel_data, int* Kernel_num, int* stride, int* padding);
void BatchNorm3d(float* X_data, int* X_num, float e, int r, int b);
void ReLU(float* X_data, int* X_num);

//void Linear(int* psum_range,Array_5D x, Array_5D weights, int* weightsBias, bool bias,Array_5D x_out);

#endif
