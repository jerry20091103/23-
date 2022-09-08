#include "imageIO.h"
#include "ap_int.h"

#define width 112
#define height 112

// This function streams one 1024 bits at a time and store a full frame in buffer
// Then the blue component is removed
// We can not stream the whole image at once because the max bitwidth of the AXI stream seems to be 4096 bits.
void imageIO_test(packet_t* input, packet_t* output)
{
	#pragma HLS INTERFACE s_axilite port=return
	#pragma HLS INTERFACE m_axi depth=294 port=input
	#pragma HLS INTERFACE m_axi depth=294 port=output

	uint8_t buffer[width*height*3];
	#pragma HLS ARRAY_PARTITION variable=buffer type=cyclic factor=64

	// put the frame into the buffer
	READ_LOOP:
	for (int i = 0; i < width*height*3 / 128; i++)
	{
		packet_t temp = input[i];
		for(int j = 0; j < 128; j++)
		{
			#pragma HLS UNROLL
			buffer[i * 128 + j] = *((uint8_t*) &temp + j);
		}
	}

	CALC_LOOP:
	// remove blue component
    for (int i = 2; i < width*height*3; i+=3)
    {
		#pragma HLS UNROLL
        buffer[i] = 0;
    }

    WRITE_LOOP:
    // write output
    for(int i = 0; i < width*height*3 / 128; i++)
    {
    	packet_t temp;
    	for(int j = 0; j < 128; j++)
    	{
			#pragma HLS UNROLL
    		*((uint8_t*) &temp + j) = buffer[i * 128 + j];
    	}
    	output[i] = temp;
    }
}
