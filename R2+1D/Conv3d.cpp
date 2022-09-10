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

	int KD = Kernel_num[0];
	int KH = Kernel_num[1];
	int KW = Kernel_num[2];

	int N_out = Y_num[0];
	int C_out = Y_num[1];
	int D_out = Y_num[2]; // (N+2*padding[0]-KD)/stride[0] + 1
	int H_out = Y_num[3]; // (H+2*padding[1]-KH)/stride[1] + 1
	int W_out = Y_num[4]; // (W+2*padding[2]-KW)/stride[2] + 1

	for(int n = 0; n < N_out; n++)
		for(int c = 0; c < C_out; c++)
            for (int d = 0; d < D_out; d++)
                for (int h = 0; h < H_out; h++)
                	for (int w = 0; w < W_out; w++)

						for(int kn = 0; kn < N; kn++)

							for(int kc = 0; kc < C; kc++)
								for(int kd = 0; kd < KD; kd++)
									for(int kh = 0; kh < KH; kh++)
										for(int kw = 0; kw < KW; kw++){
											int Dpos = d*stride[0]+kd-padding[0];
											int Hpos = h*stride[1]+kh-padding[1];
											int Wpos = w*stride[2]+kw-padding[2];

											if(Dpos >= 0 && Hpos >= 0 && Wpos >= 0 && Dpos < D && Hpos < H && Wpos < W)
												Y_data[n*C_out*D_out*H_out*W_out + c*D_out*H_out*W_out + d*H_out*W_out + h*W_out + w] = X_data[(n*C*D*H*W) + (c*D*H*W) + (Dpos*H*W) + (Hpos*W) + (Wpos)] * Kernel_data[kn*C*KD*KH*KW + kc*KD*KH*KW + kd*KH*KW + kh*KW + kw];
										}
//										Y_data[n*C_out*D_out*H_out*W_out + c*D_out*H_out*W_out + d*H_out*W_out + h*W_out + w] += X_data[(n*C*D*H*W) + (c*D*H*W) + (d*stride[0]+kd)*H*W + (h*stride[1]+kh)*W + (w*stride[2]+kw)] * Kernel_data[c*KC*KD*KH*KW + kc*KD*KH*KW + kd*KH*KW + kh*KW + kw];
	return;
}

																																						{1, 3, 1, 111, 111};

																																						{1, 7, 7};	{1, 2, 2}, {0, 3, 3};

																																						{1, 45, 1, 56, 56};
