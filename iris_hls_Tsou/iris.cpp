#include "iris.h"

void iris_module(int32_t* act , int32_t* weight, int32_t scale_FC1, int32_t scale_FC2)
{
	// there are 4 input features (int) * 8 set of data
	// set 1 is input_features[0~3], set 2 is input_features[4~7] ... etc.
	// output is an array pointer to DRAM, 120 (int).

#pragma HLS INTERFACE  s_axilite port=return
#pragma HLS INTERFACE  m_axi depth=300 offset=slave port=act
#pragma HLS INTERFACE  m_axi depth=300 offset=slave port=weight
#pragma HLS INTERFACE  s_axilite port=scale_FC1
#pragma HLS INTERFACE  s_axilite port=scale_FC2

	FC1:
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
#pragma HLS UNROLL
            for(int k = 0; k < 4; k++){
#pragma HLS UNROLL
            	act[32+8*i+j] += act[4*i+k]*weight[4*j+k];
                //cout << 32+8*i+j << ", " << 4*i+k << ", " << 4*j+k <<"\n";
            }
        }
    }


    for(int i = 32; i < 96; i++){
#pragma HLS UNROLL
        //Relu
        if(act[i]<0)act[i] = 0;
        //Quan
        act[i] = act[i]*scale_FC1 / 65536;
        //cout << i << ": = "<<act[i]<<"\n";
        if(act[i]>127)act[i] = 127;
    }

    FC2:
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 3; j++){
#pragma HLS UNROLL
            act[96+3*i+j] += weight[56+j];
            for(int k = 0; k < 8; k++){
#pragma HLS UNROLL
                act[96+3*i+j] += act[32+8*i+k]*weight[32+8*j+k];
                //cout << 96+3*i+j << ", " << 32+8*i+k << ", " << 32+8*j+k <<"\n";
            }
        }
    }
}
