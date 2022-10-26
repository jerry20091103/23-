#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void Conv3d(int* X_data, int* X_num, int* Y_data, int* Y_num, int* Kernel_data, int* Kernel_num, int* stride, int* padding, double scale, int zeropoint)
{
	// get X(input) size
	int XN = X_num[0];
	int XC = X_num[1];
	int XD = X_num[2];
	int XH = X_num[3];
	int XW = X_num[4];

	// get Kernel size
	int KD = Kernel_num[0];
	int KH = Kernel_num[1];
	int KW = Kernel_num[2];

	// get Y(output) size
	int YN = Y_num[0];
	int YC = Y_num[1];
	int YD = Y_num[2]; // (D+2*padding[0]-KD)/stride[0] + 1
	int YH = Y_num[3]; // (H+2*padding[1]-KH)/stride[1] + 1
	int YW = Y_num[4]; // (W+2*padding[2]-KW)/stride[2] + 1

	// initial Y
	for(int i = YN*YC*YD*YH*YW - 1; i >= 0; i--)
		Y_data[i] = 0;

	for(int yn = 0; yn < YN; yn++)
		for(int yc = 0; yc < YC; yc++)
            for (int yd = 0; yd < YD; yd++)
                for (int yh = 0; yh < YH; yh++)
                	for (int yw = 0; yw < YW; yw++){
						int yPos = yn*YC*YD*YH*YW + yc*YD*YH*YW + yd*YH*YW + yh*YW + yw;
						for(int xc = 0; xc < XC; xc++)
							for(int kd = 0; kd < KD; kd++)
								for(int kh = 0; kh < KH; kh++)
									for(int kw = 0; kw < KW; kw++){
										int dPos = yd*stride[0]+kd-padding[0];
										int hPos = yh*stride[1]+kh-padding[1];
										int wPos = yw*stride[2]+kw-padding[2];

										if(dPos >= 0 && hPos >= 0 && wPos >= 0 && dPos < XD && hPos < XH && wPos < XW)
											Y_data[yPos] += X_data[yn*XC*XD*XH*XW + xc*XD*XH*XW + dPos*XH*XW + hPos*XW + wPos] * Kernel_data[yc*XC*KD*KH*KW + xc*KD*KH*KW + kd*KH*KW + kh*KW + kw];
											// Y_data[yn][yc][yd][yh][yw] += X_data[yn][xc][Dpos][Hpos][Wpos] * Kernel_data[yc][xc][kd][kh][kw];
									}
						Y_data[yPos] = round(Y_data[yPos]/scale + zeropoint);
					}
	return;
}