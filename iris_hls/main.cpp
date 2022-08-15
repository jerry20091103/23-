// stream
#include "iris.h"
#include "ap_int.h"

const int32_t scale_FC1 = 402;

int32_t w[] = {
    31,
    46,
    -99,
    -89,
    26,
    20,
    -91,
    -85,
    62,
    -125,
    127,
    -31,
    60,
    -92,
    112,
    -17,
    24,
    -40,
    98,
    14,
    -2,
    -9,
    -44,
    -66,
    2,
    -17,
    -49,
    -66,
    -8,
    -16,
    3,
    13,
    82,
    68,
    -128,
    -128,
    -126,
    38,
    37,
    1,
    29,
    34,
    4,
    0,
    -19,
    29,
    35,
    -4,
    -80,
    -66,
    14,
    19,
    26,
    -45,
    -48,
    -3,
    -843,
    -91,
    654};

void iris_compute(stream32u_t* im, stream3_t* out)
{
	#pragma HLS INTERFACE s_axilite port = return
	#pragma HLS INTERFACE axis register both port = im
	#pragma HLS INTERFACE axis register both port = out

    int8_t in_acc[4];
    int8_t acc[8];
    int32_t fc2_acc[3];
    int8_t result;

	#pragma HLS ARRAY_PARTITION variable = in_acc type = cyclic factor = 4
	#pragma HLS ARRAY_PARTITION variable = acc type = cyclic factor = 16
	#pragma HLS ARRAY_PARTITION variable = fc2_acc type = cyclic factor = 6

    bool eos = false;

    OUTER_LOOP: do {
    	value32u_t valTemp;
        // Packet for Output
        value3_t valTemp_out;

        LOAD_LOOP:
        valTemp = im->read();
        in_acc[0] = valTemp.data & 0xff;
        in_acc[1] = (valTemp.data >> 8) & 0xff;
        in_acc[2] = (valTemp.data >> 16) & 0xff;
        in_acc[3] = (valTemp.data >> 24) & 0xff;

        ACC_ZERO_LOOP:
        for (int j = 0; j < 8; j++)
        {
            #pragma HLS UNROLL // factor=16
            acc[j] = 0;
        }

        // FC1
        FC1_LOOP:
        for (int j = 0; j < 8; j++)
        {
            #pragma HLS UNROLL
            int temp = 0;
            for (int k = 0; k < 4; k++)
            {
                #pragma HLS UNROLL
                temp += in_acc[k] * w[4 * j + k];
            }
            if (temp < 0)
                temp = 0;
            else
            {
                temp = temp * scale_FC1 / 65536;
                if (temp > 127)
                    temp = 127;
            }
            acc[j] = temp;
        }

        // FC2
        FC2_MAX_LOOP:
        int max = 0;
        int max_index = 0;
        for (int j = 0; j < 3; j++)
        {
            #pragma HLS UNROLL
            fc2_acc[j] = w[56 + j];
            for (int k = 0; k < 8; k++)
            {
                #pragma HLS UNROLL
                fc2_acc[j] += acc[k] * w[32 + 8 * j + k];
            }
            if (fc2_acc[j] > max)
            {
                max = fc2_acc[j];
                max_index = j;
            }
        }
        result = max_index;

        WRITE_LOOP:
        // Setting data and configuration to output packet
        valTemp_out.data = result;
        valTemp_out.last = valTemp.last;
        valTemp_out.keep = -1; //Enabling all bytes
        out->write(valTemp_out); // Writing packet to output stream
        if (valTemp.last) {
            eos = true;
        }
    } while (eos == false);

    return;
}
