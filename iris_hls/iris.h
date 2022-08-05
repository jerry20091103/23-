#ifndef __IRIS_H__
#define __IRIS_H__


#include "ap_int.h"
typedef signed int int32_t;
typedef short int int16_t;
void sw_compute(volatile ap_int<8>* im, volatile ap_int<3>* output);

#endif
