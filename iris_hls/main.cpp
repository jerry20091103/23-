#include "iris.h"

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


void sw_compute(volatile int* im, volatile int* out, int inputNum){
    #pragma HLS INTERFACE  s_axilite port=return
    #pragma HLS INTERFACE  m_axi depth=125 offset=slave port=im
    #pragma HLS INTERFACE  m_axi depth=125 offset=slave port=out
    #pragma HLS INTERFACE  s_axilite port=inputNum

    for(int i = 0; i < totalmem; i++){
        out[i] = im[i];
    }
    //FC1
    for(int i = 0; i < inputNum; i++){
        for(int j = 0; j < 8; j++){
			#pragma HLS UNROLL
            for(int k = 0; k < 4; k++){
				#pragma HLS UNROLL
                out[inputNum*4+8*i+j] += out[4*i+k]*w[4*j+k];
            }
        }
    }


    for(int i = inputNum*4; i < inputNum*12; i++){
		#pragma HLS UNROLL
    	//Relu
        if(out[i]<0)out[i] = 0;
        //Quan
        out[i] = out[i]*scale_FC1 / 65536;
        if(out[i]>127)out[i] = 127;
    }
    //FC2
    for(int i = 0; i < inputNum; i++){
        for(int j = 0; j < 3; j++){
			#pragma HLS UNROLL
            out[inputNum*12+3*i+j] += w[56+j];
            for(int k = 0; k < 8; k++){
				#pragma HLS UNROLL
                out[inputNum*12+3*i+j] += out[inputNum*4+8*i+k]*w[32+8*j+k];
            }
        }
    }
    //maxpooling
    for(int i = 0; i < inputNum; i++){
        //find max
        int max = out[inputNum*12+3*i];
        int max_index = 0, j;
        for(j = 0; j < 3; j++){
            if(out[inputNum*12+3*i+j] > max){
                max = out[inputNum*12+3*i+j];
                max_index = j;
            }
        }
        out[inputNum*15+i] = max_index;
    }
    return;
}



