#include "r2plus1d.h"
#include<iostream>
using namespace std;


void Conv2Plus1D(dtype* X_data, int_t* X_num, dtype* X_mid_data, dtype* X_batch_data, dtype* X_out_data, int_t* X_out_num, int_t midplanes,
                ktype* Kernel_1_data, ktype* Kernel_2_data, ftype* Kernel_1_data_scale, ftype* Kernel_2_data_scale, int_t s, int_t p, 
                ftype X_scale, ftype Conv3d_1_scale, ftype Conv3d_2_scale, dtype X_zeropoint, dtype Conv3d_1_zeropoint, dtype Conv3d_2_zeropoint,
                ftype* mu_, ftype* var_, ftype* r, ftype* b, ftype BatchNorm3d_scale, dtype BatchNorm3d_zeropoint)
{
    int_t stride[3] = {1, 1, 1};
    int_t padding[3] = {0, 1, 1};

    int_t Kernel_1_num[3] = {1, 3, 3};
    stride[1] = s;  stride[2] = s;
    padding[1] = p; padding[2] = p;

    int_t X_mid_num[5];
    X_mid_num[0] = X_num[0];
    X_mid_num[1] = midplanes;
    X_mid_num[2] = X_num[2]; // (D+2*padding[0]-KD)/stride[0] + 1 // (X_num[2] + 2*0 - 1) / 1 + 1
    X_mid_num[3] = (X_num[3] + 2*p - 3) / s + 1; // (H+2*padding[1]-KH)/stride[1] + 1
    X_mid_num[4] = (X_num[4] + 2*p - 3) / s + 1; // (W+2*padding[2]-KW)/stride[2] + 1
    
    Conv3d(X_data, X_num, xi, XC, X_mid_data, X_mid_num, yi, YC, Kernel_1_data, Kernel_1_num, stride, padding, X_zeropoint);
    // Conv3d(X_data, X_num, X_mid_data, X_mid_num, Kernel_1_data, Kernel_1_num, Kernel_1_data_scale, stride, padding, X_scale, X_zeropoint, Conv3d_1_scale, Conv3d_1_zeropoint);
    // BatchNorm3d(X_mid_data, X_batch_data, X_mid_num, mu_, var_, r, b, Conv3d_1_scale, Conv3d_1_zeropoint, BatchNorm3d_scale, BatchNorm3d_zeropoint);
    // ReLU(X_batch_data, X_mid_data, X_mid_num, BatchNorm3d_zeropoint);

    int_t Kernel_2_num[3] = {3, 1, 1};
    stride[0] = s;  stride[1] = 1;  stride[2] = 1;
    padding[0] = p; padding[1] = 0; padding[2] = 0;
    Conv3d(X_mid_data, X_mid_num, xi, XC, X_out_data, X_out_num, yi, YC, Kernel_2_data, Kernel_2_num, stride, padding, BatchNorm3d_zeropoint);
    // Conv3d(X_mid_data, X_mid_num, X_out_data, X_out_num, Kernel_2_data, Kernel_2_num, Kernel_2_data_scale, stride, padding, BatchNorm3d_scale, BatchNorm3d_zeropoint, Conv3d_2_scale, Conv3d_2_zeropoint);

    return;
}