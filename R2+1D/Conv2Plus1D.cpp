#include "r2plus1d.h"
#include<iostream>
using namespace std;


void Conv2Plus1D(dtype* X_data, int_t* X_num, dtype* X_out_data, int_t* X_out_num, int_t midplanes, dtype* Kernel_1_data, dtype* Kernel_2_data, int_t s, int_t p, 
                double Conv3d_1_scale, double Conv3d_2_scale, int_t Conv3d_1_zeropoint, int_t Conv3d_2_zeropoint,
                double* _mu, double* _var, double* r, double* b, double BatchNorm3d_scale, int_t BatchNorm3d_zeropoint)
{
    int_t stride[3] = {1, 1, 1};
    int_t padding[3] = {0, 1, 1};

    int_t Kernel_1_num[3] = {1, 3, 3};
    stride[1] = s;  stride[2] = s;
    padding[1] = p; padding[2] = p;

 #ifdef __SYNTHESIS__
    dtype X_mid_data[451584];
 #else
    dtype* X_mid_data = (dtype*)malloc(57802752*sizeof(dtype));
 #endif

    int_t X_mid_num[5];
    X_mid_num[0] = X_num[0];
    X_mid_num[1] = midplanes;
    X_mid_num[2] = X_num[2]; // (D+2*padding[0]-KD)/stride[0] + 1 // (X_num[2] + 2*0 - 1) / 1 + 1
    X_mid_num[3] = (X_num[3] + 2*p - 3) / s + 1; // (H+2*padding[1]-KH)/stride[1] + 1
    X_mid_num[4] = (X_num[4] + 2*p - 3) / s + 1; // (W+2*padding[2]-KW)/stride[2] + 1
    
    
    Conv3d(X_data, X_num, X_mid_data, X_mid_num, Kernel_1_data, Kernel_1_num, stride, padding, Conv3d_1_scale, Conv3d_1_zeropoint);
    BatchNorm3d(X_mid_data, X_mid_num, _mu, _var, r, b, BatchNorm3d_scale, BatchNorm3d_zeropoint);
    ReLU(X_mid_data, X_mid_num);

    int_t Kernel_2_num[3] = {3, 1, 1};
    stride[0] = s;  stride[1] = 1;  stride[2] = 1;
    padding[0] = p; padding[1] = 0; padding[2] = 0;
    Conv3d(X_mid_data, X_mid_num, X_out_data, X_out_num, Kernel_2_data, Kernel_2_num, stride, padding, Conv3d_2_scale, Conv3d_2_zeropoint);


#ifndef __SYNTHESIS__
    free(X_mid_data);
#endif

    return;

    // nn.Conv3d(in_planes, midplanes, kernel_size=(1, 3, 3),
    //             stride=(1, stride, stride),padding=(0, padding, padding),
    //             bias=False),
    // nn.BatchNorm3d(midplanes),
    // nn.ReLU(inplace=True),
    // nn.Conv3d(midplanes, out_planes, kernel_size=(3, 1, 1), 
    //             stride=(stride, 1, 1), padding=(padding, 0, 0),
    //             bias=False)
}