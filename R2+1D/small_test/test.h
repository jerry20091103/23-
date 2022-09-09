#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__


typedef struct Array_5D_ {
    float *data;
    int *num;
} Array_5D;

void test(float* X, float* Xout);
void BatchNorm3d(Array_5D X, float e, int r, int b);
#endif
