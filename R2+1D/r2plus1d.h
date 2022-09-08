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

#endif
