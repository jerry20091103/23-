#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__


#include "ap_int.h"
typedef signed int int32_t;
typedef short int int16_t;

typedef struct Array_5D_ {
    int *data;
    int *num;
} Array_5D;

void r2plus1d(volatile ap_int<8>* im, volatile ap_int<3>* out);
void Conv3d(DATA_TYPE X_in(N1, C1, D1, H1, W1), DATA_TYPE X_out(N2, C2, D2, H2, W2), DATA_TYPE Kernel(KN, KC, KD, KH, KW), TYPE stride = {1, 1, 1}, TYPE padding = {0, 0, 0});
void BatchNorm3d(DATA_TYPE X(N, C, D, H, W), int e = 0.00001, int r = 1, int b = 0);
void ReLU(DATA_TYPE X(N, C, D, H, W));
void Sequential(psum_range, x, weights, out_channels, kernel_size=5, stride=1, bias=False, psum_record=False);

#endif
