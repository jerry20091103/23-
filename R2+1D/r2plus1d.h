#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__

void r2plus1d(float* X_data, float* Y_data, float* Kernel_1_data, float* Kernel_2_data);
void Conv3d(float* X_data, int* X_num, float* Y_data, int* Y_num, float* Kernel_data, int* Kernel_num, int* stride, int* padding);
void BatchNorm3d(float* X_data, int* X_num, float e, int r, int b);
void ReLU(float* X_data, int* X_num);

//void Linear(int* psum_range, float* X_data, int* X_num, float* weights_data, int* weights_num, int* weightsBias, bool bias, float* X_out, int* X_out_num);

#endif
