

#include "iris.h"
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
    int acc[125];
    for(int i=0;i<125;i++){
        acc[i] = im[i];
    }
    //FC1
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 4; k++){
                acc[32+8*i+j] += acc[4*i+k]*w[4*j+k];
                //cout << 32+8*i+j << ", " << 4*i+k << ", " << 4*j+k <<"\n";
            }
        }
    }


    for(int i = 32; i < 96; i++){
        //Relu
        if(acc[i]<0)acc[i] = 0;
        //Quan
        acc[i] = acc[i]*scale_FC1 / 65536;
        //cout << i << ": = "<<im[i]<<"\n";
        if(acc[i]>127)acc[i] = 127;
    }
    //FC2
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 3; j++){
            acc[96+3*i+j] += w[56+j];
            for(int k = 0; k < 8; k++){
                acc[96+3*i+j] += acc[32+8*i+k]*w[32+8*j+k];
                //cout << 96+3*i+j << ", " << 32+8*i+k << ", " << 32+8*j+k <<"\n";
            }
        }
    }
    for(int i=0;i<120;i++){
        out[i] = acc[i];
    }
    return;
}



