// stream
#include "32to8bit.h"
#include "ap_int.h"

#define inputNum 2




void sw_compute(stream32u_t* im, stream32_t* out)
{
	#pragma HLS INTERFACE s_axilite port = return
	#pragma HLS INTERFACE axis register both port = im
	#pragma HLS INTERFACE axis register both port = out

    int8_t in_acc[4 * inputNum];
    int32_t result[4 * inputNum];


    OUTER_LOOP:
    for (int i = 0; i < inputNum; i++)
    {
    	value32u_t valTemp;
        // Packet for Output
        value32_t valTemp_out;

        LOAD_LOOP:
        valTemp = im->read();
        in_acc[0 + i*4] = valTemp.data & 0xff;
        in_acc[1 + i*4] = (valTemp.data >> 8) & 0xff;
        in_acc[2 + i*4] = (valTemp.data >> 16) & 0xff;
        in_acc[3 + i*4] = (valTemp.data >> 24) & 0xff;

        WRITE_LOOP:
        for (int j = 0; j < 4; j++)
        {
            result[j + i*4] = in_acc[j + i*4]*2;
            valTemp_out.data = result[j + i*4];
            valTemp_out.last = 0;
            if(4*i+j >= (inputNum*4-1)) valTemp_out.last = 1;
            valTemp_out.keep = -1; //Enabling all bytes
            out->write(valTemp_out); // Writing packet to output stream
        }
        
    }

    return;
}
