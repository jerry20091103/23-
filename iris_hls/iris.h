#ifndef __IRIS_H__
#define __IRIS_H__


#include "ap_int.h"
#include <ap_axi_sdata.h>
#include <hls_stream.h>

typedef signed int int32_t;
typedef short int int16_t;
typedef ap_axiu<8,1,1,1> value8_t;
typedef ap_axiu<3,1,1,1> value3_t;
typedef hls::stream<value8_t> stream8_t;
typedef hls::stream<value3_t> stream3_t;
void sw_compute(stream8_t* im, stream3_t* out);

#endif