#ifndef __IMAGE_IO_H__
#define __IMAGE_IO_H__


#include "ap_int.h"

typedef unsigned char uint8_t;
typedef ap_uint<1024> packet_t;
typedef ap_uint<24> pixel_t;
void imageIO_RAM(packet_t* input, packet_t* output, uint8_t* ram_buffer);

#endif
