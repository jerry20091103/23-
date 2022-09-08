#include "iris.h"
#include "ap_int.h"

#define inputNum 30
#define totalmem  16*inputNum
const int32_t scale_FC1 = 402;
const int32_t scale_FC2 = 288;

long long w[] = {
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
654
};


void sw_compute(volatile ap_int<8>* im, volatile ap_int<3>* out){
    #pragma HLS INTERFACE  s_axilite port=return
    #pragma HLS INTERFACE  m_axi depth=120 offset=slave port=im max_widen_bitwidth=64
    #pragma HLS INTERFACE  m_axi depth=30 offset=slave port=out max_widen_bitwidth=64
    ap_int<8> in_acc[4*inputNum];
	ap_int<8> acc[8*inputNum];
	int fc2_acc[3*inputNum];
	ap_int<3>result[inputNum];


	#pragma HLS ARRAY_PARTITION variable=in_acc type=cyclic factor=4
	#pragma HLS ARRAY_PARTITION variable=acc type=cyclic factor=16
	#pragma HLS ARRAY_PARTITION variable=fc2_acc type=cyclic factor=6

    OUTER_LOOP:
    for (int i = 0; i < inputNum; i++)
    {
        LOAD_LOOP:
        for (int j = 0; j < 4; j++)
        {
            #pragma HLS UNROLL factor=8
            in_acc[j + i * 4] = im[j + i * 4];
        }
        ACC_ZERO_LOOP:
        for (int j = 0; j < 8; j++)
        {
            #pragma HLS UNROLL factor=16
            acc[j + i * 8] = 0;
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
                temp += in_acc[4 * i + k] * w[4 * j + k];
            }
            if (temp < 0)
                temp = 0;
            else
            {
                temp = temp * scale_FC1 / 65536;
                if (temp > 127)
                    temp = 127;
            }
            acc[8 * i + j] = temp;
        }

        // FC2
        FC2_MAX_LOOP:
        int max = 0;
        int max_index = 0;
        for (int j = 0; j < 3; j++)
        {
            #pragma HLS UNROLL
            fc2_acc[3 * i + j] = w[56 + j];
            for (int k = 0; k < 8; k++)
            {
                #pragma HLS UNROLL
                fc2_acc[3 * i + j] += acc[8 * i + k] * w[32 + 8 * j + k];
            }
            if (fc2_acc[3 * i + j] > max)
            {
                max = fc2_acc[3 * i + j];
                max_index = j;
            }
        }
        result[i] = max_index;

        WRITE_LOOP:
        out[i] = result[i];
    }
    
    return;
}



