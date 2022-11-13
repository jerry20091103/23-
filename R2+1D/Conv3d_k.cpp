#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void Conv3d_k(dtype* X_data, param_t* X_num, int_t xi, int_t XC, ytype* Y_data, param_t* Y_num, int_t yi, int_t YC, ktype* Kernel_data, param_t* Kernel_num, param_t* stride, param_t* padding, dtype zp_in)
{
	// // get X(input) size
	// int_t X_num[1] = X_num[1];
	// int_t X_num[2] = X_num[2];
	// int_t X_num[3] = X_num[3];
	// int_t X_num[4] = X_num[4];

	// // get Kernel size
	// int_t Kernel_num[0] = Kernel_num[0];
	// int_t Kernel_num[1] = Kernel_num[1];
	// int_t Kernel_num[2] = Kernel_num[2];

	// // get Y(output) size
	// int_t Y_num[2] = Y_num[2]; // (D+2*padding[0]-Kernel_num[0])/stride[0] + 1
	// int_t Y_num[3] = Y_num[3]; // (H+2*padding[1]-Kernel_num[1])/stride[1] + 1
	// int_t Y_num[4] = Y_num[4]; // (W+2*padding[2]-Kernel_num[2])/stride[2] + 1
	YC_LOOP:
	for(int_t yc = 0; yc < YC && yi*YC+yc < Y_num[1]; yc++){
		YD_LOOP:
		for (int_t yd = 0; yd < Y_num[2]; yd++){
			YH_LOOP:
			for (int_t yh = 0; yh < Y_num[3]; yh++){
				YW_LOOP:
				for (int_t yw = 0; yw < Y_num[4]; yw++){
					#pragma HLS UNROLL factor=4
					int_t yPos = yc*Y_num[2]*Y_num[3]*Y_num[4] + yd*Y_num[3]*Y_num[4] + yh*Y_num[4] + yw;
					int_t tmp_Y = 0;
					XC_LOOP:
					for(int_t xc = 0; xc < XC && xi*XC+xc < X_num[1]; xc++){
						KD_LOOP:
						for(int_t kd = 0; kd < Kernel_num[0]; kd++){
							KH_LOOP:
							for(int_t kh = 0; kh < Kernel_num[1]; kh++){
								KW_LOOP:
								for(int_t kw = 0; kw < Kernel_num[2]; kw++){
									int_t dPos = yd*stride[0]+kd-padding[0];
									int_t hPos = yh*stride[1]+kh-padding[1];
									int_t wPos = yw*stride[2]+kw-padding[2];

									if(dPos >= 0 && hPos >= 0 && wPos >= 0 && dPos < X_num[2] && hPos < X_num[3] && wPos < X_num[4])
										tmp_Y += ((int_t)X_data[xc*X_num[2]*X_num[3]*X_num[4] + dPos*X_num[3]*X_num[4] + hPos*X_num[4] + wPos]- zp_in) * Kernel_data[(yc)*XC*Kernel_num[0]*Kernel_num[1]*Kernel_num[2] + (xc)*Kernel_num[0]*Kernel_num[1]*Kernel_num[2] + kd*Kernel_num[1]*Kernel_num[2] + kh*Kernel_num[2] + kw];
								}
							}
						}
					}
					Y_data[yPos] += tmp_Y;
				}
			}
		}
	}
	return;
}