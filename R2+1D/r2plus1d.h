#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__

void r2plus1d(float* X_data, float* Y_data, float* Kernel_1_data, float* Kernel_2_data);
void Conv3d(float* X_data, int* X_num, float* Y_data, int* Y_num, float* Kernel_data, int* Kernel_num, int* stride, int* padding);
void BatchNorm3d(float* X_data, int* X_num, float e, int r, int b);
void ReLU(float* X_data, int* X_num);
// void Sequential(float* X_data, float* Y_data, float* Kernel_1_data, float* Kernel_2_data, float* Kernel_3_data, float* Kernel_4_data, float* Kernel_5_data, float* Kernel_6_data, float* Kernel_7_data, float* Kernel_8_data, float* Kernel_9_data, float* Kernel_10_data, float* Kernel_11_data, float* Kernel_12_data);
void Conv2Plus1D(float* X_data, int* X_num, float* X_out_data, int* X_out_num, int midplanes, float* Kernel_1_data, float* Kernel_2_data, int s, int p);
void AdaptiveAvgPool3d(float* X_data,int* X_num, int* out_size, float* Y_data, int* Y_num);
void Sequential(float* X_data, float* Y_data, float* Kernel_1_1_data, float* Kernel_1_2_data, float* Kernel_1_3_data, float* Kernel_1_4_data, float* Kernel_1_5_data, float* Kernel_1_6_data, float* Kernel_1_7_data, float* Kernel_1_8_data, 
                float* Kernel_2_1_data, float* Kernel_2_2_data, float* Kernel_2_3_data, float* Kernel_2_4_data, float* Kernel_2_5_data, float* Kernel_2_6_data, float* Kernel_2_7_data, float* Kernel_2_8_data, float* Kernel_2_9_data, 
                float* Kernel_3_1_data, float* Kernel_3_2_data, float* Kernel_3_3_data, float* Kernel_3_4_data, float* Kernel_3_5_data, float* Kernel_3_6_data, float* Kernel_3_7_data, float* Kernel_3_8_data, float* Kernel_3_9_data, 
                float* Kernel_4_1_data, float* Kernel_4_2_data, float* Kernel_4_3_data, float* Kernel_4_4_data, float* Kernel_4_5_data, float* Kernel_4_6_data, float* Kernel_4_7_data, float* Kernel_4_8_data, float* Kernel_4_9_data);

//void Linear(int* psum_range,float* x,int* x_num, float* weights, int* weights_num , int* weightsBias, bool bias,float* x_out);
#endif

