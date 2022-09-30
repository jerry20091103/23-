#include "r2plus1d.h"
#include<iostream>
#include <math.h>
using namespace std;

#define _C 1152

void BatchNorm3d(float* X_data, int* X_num, float e, int r, int b){
	int N = X_num[0];
	int C = X_num[1];
	int D = X_num[2];
	int H = X_num[3];
	int W = X_num[4];

    // find channel mean
	float mu[_C];
    for(int c = 0; c < C; c++){
	    for(int n = 0; n < N; n++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						mu[c] += X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w];
			mu[c] /= D*H*W;
		}
	}

    // find channel variance
	float var[_C];
    for(int c = 0; c < C; c++){
	    for(int n = 0; n < N; n++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						var[c] += (X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w]-mu[c]) * (X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w]-mu[c]);
			var[c] /= D*H*W;
		}
	}

	for(int n = 0; n < N; n++)
		for(int c = 0; c < C; c++)
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] = ((X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] - mu[c]) / sqrt(var[c]+e)) * r + b;
}
