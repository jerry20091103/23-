#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void Conv3d(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num, dtype* Kernel_data, int_t* Kernel_num, double* kernel_scale, int_t* stride, int_t* padding, double scale_in, int_t zp_in, double scale_out, int_t zp_out)
{
	// get X(input) size
	int_t XN = X_num[0];
	int_t XC = X_num[1];
	int_t XD = X_num[2];
	int_t XH = X_num[3];
	int_t XW = X_num[4];

	// get Kernel size
	int_t KD = Kernel_num[0];
	int_t KH = Kernel_num[1];
	int_t KW = Kernel_num[2];

	// get Y(output) size
	int_t YN = Y_num[0];
	int_t YC = Y_num[1];
	int_t YD = Y_num[2]; // (D+2*padding[0]-KD)/stride[0] + 1
	int_t YH = Y_num[3]; // (H+2*padding[1]-KH)/stride[1] + 1
	int_t YW = Y_num[4]; // (W+2*padding[2]-KW)/stride[2] + 1

	// initial Y
	for(int_t i = YN*YC*YD*YH*YW - 1; i >= 0; i--)
		Y_data[i] = 0;

	for(int_t yn = 0; yn < YN; yn++)
		for(int_t yc = 0; yc < YC; yc++)
            for (int_t yd = 0; yd < YD; yd++)
                for (int_t yh = 0; yh < YH; yh++)
                	for (int_t yw = 0; yw < YW; yw++){
						// todo: data type
						int_t yPos = yn*YC*YD*YH*YW + yc*YD*YH*YW + yd*YH*YW + yh*YW + yw;
						int_t tmp_Y = 0;
						for(int_t xn = 0; xn < XN; xn++)
							for(int_t xc = 0; xc < XC; xc++)
								for(int_t kd = 0; kd < KD; kd++)
									for(int_t kh = 0; kh < KH; kh++)
										for(int_t kw = 0; kw < KW; kw++){
											int_t dPos = yd*stride[0]+kd-padding[0];
											int_t hPos = yh*stride[1]+kh-padding[1];
											int_t wPos = yw*stride[2]+kw-padding[2];

											if(dPos >= 0 && hPos >= 0 && wPos >= 0 && dPos < XD && hPos < XH && wPos < XW)
												tmp_Y += (X_data[xn*XC*XD*XH*XW + xc*XD*XH*XW + dPos*XH*XW + hPos*XW + wPos]- zp_in) * Kernel_data[yc*XC*KD*KH*KW + xc*KD*KH*KW + kd*KH*KW + kh*KW + kw];
										}
						Y_data[yPos] = round((double)tmp_Y*(scale_in*kernel_scale[yc]/scale_out) + zp_out);
					}
	return;
}