#include "iris.h"

void iris_module(int32_t *input_features, int32_t *output_result)
{
	// there are 4 input features (int) * 8 set of data
	// set 1 is input_features[0~3], set 2 is input_features[4~7] ... etc.
	// output is an array pointer to DRAM, 120 (int).

#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE m_axi port=input_features
#pragma HLS INTERFACE m_axi port=output_result

	// this is dummy code, calculates the average of 4 features
	SET_LOOP:
	for(int set=0; set<8; set++)
	{
#pragma HLS UNROLL
		int offset = set * 4;
		int avg = (input_features[offset] + input_features[offset+1] + input_features[offset+2] + input_features[offset+3]) / 4;
		int offset2 = set * 15;
		RESULT_LOOP:
		for(int i=0; i<15; i++)
		{
#pragma HLS UNROLL
			output_result[offset2 + i] = avg;
		}
	}
}
