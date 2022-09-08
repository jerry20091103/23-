#include "r2plus1d.h"
#include<iostream>
using namespace std;

#define _N 1
#define _C 64
#define _D 1
#define _H 56
#define _W 56

void Conv3d(Array_5D X_in, Array_5D X_out, Array_5D Kernel, int* stride, int* padding)
{
	float X_data[_N][_C][_D][_H][_W];

	int N = X_in.num[0];
	int C = X_in.num[1];
	int D = X_in.num[2];
	int H = X_in.num[3];
	int W = X_in.num[4];

	int KC = Kernel.num[1];
	int KD = Kernel.num[2];
	int KH = Kernel.num[3];
	int KW = Kernel.num[4];

	int C_out = X_in.num[1];
	int D_out = X_in.num[2]; // N+2*padding[0]-KD)/stride[0] + 1
	int H_out = X_in.num[3]; // H+2*padding[1]-KH)/stride[1] + 1
	int W_out = X_in.num[4]; // W+2*padding[2]-KW)/stride[2] + 1

	for(int n = 0; n < N; n++)
		for(int c = 0; c < C; c++)
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						X_data[n][c][d][h][w] = X_in.data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w];	

	for(int n = 0; n < N; n++)
		for(int c = 0; c < C_out; c++)
            for (int d = 0; d < D_out; d++)
                for (int h = 0; h < H_out; h++)
                	for (int w = 0; w < W_out; w++)
						for(int kc = 0; kc < KC; kc++)
							for(int kd = 0; kd < KD; kd++)
								for(int kh = 0; kh < KH; kh++)
									for(int kw = 0; kw < KW; kw++)
										X_out.data[n*C_out*D_out*H_out*W_out + c*D_out*H_out*W_out + d*H_out*W_out + h*W_out + w] += X_data[n][c][d*stride[0]+kd][h*stride[1]+kh][w*stride[2]+kw] * Kernel[c][kc][kd][kh][kw];
	return;
}
