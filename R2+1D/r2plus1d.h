#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__

void r2plus1d(double* X_data, double* Y_data, double* Kernel_1_data, double* Kernel_2_data);
void Conv3d(double* X_data, int* X_num, double* Y_data, int* Y_num, double* Kernel_data, int* Kernel_num, int* stride, int* padding);
void BatchNorm3d(double* X_data, int* X_num, double e, int r, int b);
void ReLU(double* X_data, int* X_num);
// void Sequential(double* X_data, double* Y_data, double* Kernel_1_data, double* Kernel_2_data, double* Kernel_3_data, double* Kernel_4_data, double* Kernel_5_data, double* Kernel_6_data, double* Kernel_7_data, double* Kernel_8_data, double* Kernel_9_data, double* Kernel_10_data, double* Kernel_11_data, double* Kernel_12_data);
void Conv2Plus1D(double* X_data, int* X_num, double* X_out_data, int* X_out_num, int midplanes, double* Kernel_1_data, double* Kernel_2_data, int s, int p);
void AdaptiveAvgPool3d(double* X_data,int* X_num, int* out_size, double* Y_data, int* Y_num);
void Sequential(double* X_data, double* Y_data, double* Kernel_1_1_data, double* Kernel_1_2_data, double* Kernel_1_3_data, double* Kernel_1_4_data, double* Kernel_1_5_data, double* Kernel_1_6_data, double* Kernel_1_7_data, double* Kernel_1_8_data, 
                double* Kernel_2_1_data, double* Kernel_2_2_data, double* Kernel_2_3_data, double* Kernel_2_4_data, double* Kernel_2_5_data, double* Kernel_2_6_data, double* Kernel_2_7_data, double* Kernel_2_8_data, double* Kernel_2_9_data, 
                double* Kernel_3_1_data, double* Kernel_3_2_data, double* Kernel_3_3_data, double* Kernel_3_4_data, double* Kernel_3_5_data, double* Kernel_3_6_data, double* Kernel_3_7_data, double* Kernel_3_8_data, double* Kernel_3_9_data, 
                double* Kernel_4_1_data, double* Kernel_4_2_data, double* Kernel_4_3_data, double* Kernel_4_4_data, double* Kernel_4_5_data, double* Kernel_4_6_data, double* Kernel_4_7_data, double* Kernel_4_8_data, double* Kernel_4_9_data);

//void Linear(int* psum_range,double* x,int* x_num, double* weights, int* weights_num , int* weightsBias, bool bias,double* x_out);
#endif

