#ifndef __IRIS_H__
#define __IRIS_H__


#include "ap_int.h"
#include <hls_stream.h>

typedef signed int int32_t;
typedef short int int16_t;
typedef hls::stream<ap_int<8>> stream8_t;
typedef hls::stream<ap_int<3>> stream3_t;
void sw_compute(stream8_t* im, stream3_t* out);

#endif