#ifndef __32TO8BIT_H__
#define __32TO8BIT_H__


#include "ap_int.h"
#include <ap_axi_sdata.h>
#include <hls_stream.h>

typedef signed int    int32_t;
typedef unsigned int  uint32_t;
typedef signed char   int8_t;
typedef unsigned char uint8_t;
typedef ap_axiu<32,1,1,1> value32u_t;
typedef ap_axis<32,1,1,1> value32_t;
typedef hls::stream<value32u_t> stream32u_t;
typedef hls::stream<value32_t> stream32_t;
void sw_compute(stream32u_t* im, stream32_t* out);

#endif
