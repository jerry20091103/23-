#include "imageIO.h"
#include "ap_int.h"

#define width 112
#define height 112

// This function stores splits the image into 3 red/green/blue only images and store them in PS RAM.
// Then the image is read from RAM and re-combined for output.
// ram_buffer needs to be uint8_t[3*width*height*3] (three frames)
void imageIO_RAM(packet_t* input, packet_t* output, uint8_t* ram_buffer)
{
	#pragma HLS INTERFACE s_axilite port=return
	#pragma HLS INTERFACE m_axi port=input
	#pragma HLS INTERFACE m_axi port=output
	#pragma HLS INTERFACE m_axi port=ram_buffer

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

	SPLIT_RED_LOOP:
	// split the image into 3 and store in PS ram.
	// red
    for (int i = 0; i < width*height*3; i+=3)
    {
        ram_buffer[i] = buffer[i];
        ram_buffer[i+1] = 0;
        ram_buffer[i+2] = 0;
    }
    SPLIT_GREEN_LOOP:
   	// green
    for (int i = 0; i < width*height*3; i+=3)
    {
        ram_buffer[width*height*3 + i] = 0;
        ram_buffer[width*height*3 + i+1] = buffer[i+1];
        ram_buffer[width*height*3 + i+2] = 0;
    }
    SPLIT_BLUE_LOOP:
    // green
    for (int i = 0; i < width*height*3; i+=3)
    {
        ram_buffer[width*height*6 + i] = 0;
        ram_buffer[width*height*6 + i+1] = 0;
        ram_buffer[width*height*6 + i+2] = buffer[i+2];
    }


    RESET_LOOP:
	// set the internal buffer to zero
    for (int i = 0; i < width*height*3; i++)
    {
    	buffer[i] = 0;
    }

    RESTORE_RED_LOOP:
    // re-combine the image from PS ram
	// red
	for (int i = 0; i < width*height*3; i++)
    {
        buffer[i] += ram_buffer[i];
	}
	RESTORE_GREEN_LOOP:
	// green
	for (int i = 0; i < width*height*3; i++)
    {
        buffer[i] += ram_buffer[width*height*3 + i];
	}
	RESTORE_BLUE_LOOP:
	// blue
	for (int i = 0; i < width*height*3; i++)
    {
        buffer[i] += ram_buffer[width*height*6 + i];
	}

	WRITE_LOOP:
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
