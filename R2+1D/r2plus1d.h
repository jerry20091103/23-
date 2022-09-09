#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__


#include "ap_int.h"
typedef signed int int32_t;
typedef short int int16_t;

typedef struct Array_5D_ {
    float *data;
    int *num;
} Array_5D;

void r2plus1d(float* X_data, float* Y_data, float* Kernel_1_data, float* Kernel_2_data);
void Conv3d(Array_5D X_in, Array_5D X_out, Array_5D Kernel, int* stride, int* padding);
void BatchNorm3d(Array_5D X, float e, int r, int b);
void ReLU(Array_5D X);
void Linear(int* psum_range,Array_5D x, Array_5D weights, int* weightsBias, bool bias,Array_5D x_out);
#endif
