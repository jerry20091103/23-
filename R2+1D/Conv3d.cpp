#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void Conv3d(dtype* X_data, int_t* X_num, int_t xi, int_t XC, dtype* Y_data, int_t* Y_num, int_t yi, int_t YC, ktype* Kernel_data, int_t* Kernel_num, int_t* stride, int_t* padding, dtype zp_in)
{
	// get X(input) size
	int_t KC = X_num[1];
	int_t XD = X_num[2];
	int_t XH = X_num[3];
	int_t XW = X_num[4];

	// get Kernel size
	int_t KD = Kernel_num[0];
	int_t KH = Kernel_num[1];
	int_t KW = Kernel_num[2];

	// get Y(output) size
	int_t YD = Y_num[2]; // (D+2*padding[0]-KD)/stride[0] + 1
	int_t YH = Y_num[3]; // (H+2*padding[1]-KH)/stride[1] + 1
	int_t YW = Y_num[4]; // (W+2*padding[2]-KW)/stride[2] + 1
	
	for(int_t yc = 0; yc < YC/* && yi*YC+yc < Y_num[1]*/; yc++)
		for (int_t yd = 0; yd < YD; yd++)
			for (int_t yh = 0; yh < YH; yh++)
				for (int_t yw = 0; yw < YW; yw++){
					int_t yPos = yc*YD*YH*YW + yd*YH*YW + yh*YW + yw;
					int_t tmp_Y = 0;
					
					for(int_t xc = 0; xc < XC; xc++)
						for(int_t kd = 0; kd < KD; kd++)
							for(int_t kh = 0; kh < KH; kh++)
								for(int_t kw = 0; kw < KW; kw++){
									int_t dPos = yd*stride[0]+kd-padding[0];
									int_t hPos = yh*stride[1]+kh-padding[1];
									int_t wPos = yw*stride[2]+kw-padding[2];

									if(dPos >= 0 && hPos >= 0 && wPos >= 0 && dPos < XD && hPos < XH && wPos < XW)
										tmp_Y += ((int_t)X_data[xc*XD*XH*XW + dPos*XH*XW + hPos*XW + wPos]- zp_in) * Kernel_data[(yi*YC + yc)*KC*KD*KH*KW + (xi*XC + xc)*KD*KH*KW + kd*KH*KW + kh*KW + kw];
								}
					Y_data[yPos] += tmp_Y;
				}
	return;
}