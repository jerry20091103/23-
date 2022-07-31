#include "iris.h"
#define inputNum 16
#define totalmem  15*inputNum
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


void sw_compute(volatile int* im, volatile int* out){
    #pragma HLS INTERFACE  s_axilite port=return
    #pragma HLS INTERFACE  m_axi depth=125 offset=slave port=im
    #pragma HLS INTERFACE  m_axi depth=125 offset=slave port=out
    
    int acc[totalmem];
    for(int i = 0; i < totalmem; i++){
        acc[i] = im[i];
    }
    //FC1
    for(int i = 0; i < inputNum; i++){
        for(int j = 0; j < 8; j++){
			#pragma HLS UNROLL
            for(int k = 0; k < 4; k++){
				#pragma HLS UNROLL
                acc[inputNum*4+8*i+j] += acc[4*i+k]*w[4*j+k];
            }
        }
    }


    for(int i = inputNum*4; i < inputNum*12; i++){
		#pragma HLS UNROLL
    	//Relu
        if(acc[i]<0)acc[i] = 0;
        //Quan
        acc[i] = acc[i]*scale_FC1 / 65536;
        if(acc[i]>127)acc[i] = 127;
    }
    //FC2
    for(int i = 0; i < inputNum; i++){
        for(int j = 0; j < 3; j++){
			#pragma HLS UNROLL
            acc[inputNum*12+3*i+j] += w[56+j];
            for(int k = 0; k < 8; k++){
				#pragma HLS UNROLL
                acc[inputNum*12+3*i+j] += acc[inputNum*4+8*i+k]*w[32+8*j+k];
            }
        }
    }
    for(int i=0;i<totalmem;i++){
        out[i] = acc[i];
    }
    return;
}



