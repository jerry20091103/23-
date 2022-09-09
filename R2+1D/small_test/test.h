#ifndef __R2PLUS1D_H__
#define __R2PLUS1D_H__


typedef struct Array_5D_ {
    float *data;
    int *num;
} Array_5D;

void test(Array_5D X, Array_5D Kernel_1, Array_5D Kernel_2);
#endif
