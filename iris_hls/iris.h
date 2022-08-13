#ifndef __IRIS_H__
#define __IRIS_H__


#include "ap_int.h"
#include <ap_axi_sdata.h>
#include <hls_stream.h>

typedef signed int int32_t;
typedef ap_axis<8,1,1,1> value8_t;
typedef hls::stream<value8_t> stream8_t;
void sw_compute(stream8_t* im, stream8_t* out);

#endif
