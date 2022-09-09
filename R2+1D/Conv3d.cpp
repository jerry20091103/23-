#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Conv3d(float* X_data, int* X_num, float* Y_data, int* Y_num, float* Kernel_data, int* Kernel_num, int* stride, int* padding)
{
	int N = X_num[0];
	int C = X_num[1];
	int D = X_num[2];
	int H = X_num[3];
	int W = X_num[4];

	int KN = Kernel_num[0];
	int KC = Kernel_num[1];
	int KD = Kernel_num[2];
	int KH = Kernel_num[3];
	int KW = Kernel_num[4];

	int C_out = Y_num[1];
	int D_out = Y_num[2]; // N+2*padding[0]-KD)/stride[0] + 1
	int H_out = Y_num[3]; // H+2*padding[1]-KH)/stride[1] + 1
	int W_out = Y_num[4]; // W+2*padding[2]-KW)/stride[2] + 1

	for(int n = 0; n < N; n++)
		for(int c = 0; c < C_out; c++)
            for (int d = 0; d < D_out; d++)
                for (int h = 0; h < H_out; h++)
                	for (int w = 0; w < W_out; w++)
						for(int kc = 0; kc < KC; kc++)
							for(int kd = 0; kd < KD; kd++)
								for(int kh = 0; kh < KH; kh++)
									for(int kw = 0; kw < KW; kw++)
										Y_data[n*C_out*D_out*H_out*W_out + c*D_out*H_out*W_out + d*H_out*W_out + h*W_out + w] += X_data[(n*C*D*H*W)+(c*D*H*W) + (d*stride[0]+kd)*H*W + (h*stride[1]+kh)*W + (w*stride[2]+kw)] * Kernel_data[c*KC*KD*KH*KW + kc*KD*KH*KW + kd*KH*KW + kh*KW + kw];
	return;
}