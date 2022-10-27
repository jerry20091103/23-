#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

#define _C 1152

void BatchNorm3d(dtype* X_data, int_t* X_num, double* _mu, double* _var, double* r, double* b, double scale, int_t zeropoint){
	int_t N = X_num[0];
	int_t C = X_num[1];
	int_t D = X_num[2];
	int_t H = X_num[3];
	int_t W = X_num[4];

    // find channel mean
	double mu[_C];
    for(int_t c = 0; c < C; c++){
	    for(int_t n = 0; n < N; n++){
			mu[c] = 0;
			for(int_t d = 0; d < D; d++)
				for(int_t h = 0; h < H; h++)
					for(int_t w = 0; w < W; w++)
						mu[c] += X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w];
			mu[c] /= D*H*W;
		}
	}

    // find channel variance
	double var[_C];
    for(int_t c = 0; c < C; c++){
	    for(int_t n = 0; n < N; n++){
			var[c] = 0;
			for(int_t d = 0; d < D; d++)
				for(int_t h = 0; h < H; h++)
					for(int_t w = 0; w < W; w++)
						var[c] += (X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w]-mu[c]) * (X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w]-mu[c]);
			var[c] /= D*H*W;
		}
	}

	for(int_t n = 0; n < N; n++)
		for(int_t c = 0; c < C; c++)
			for(int_t d = 0; d < D; d++)
				for(int_t h = 0; h < H; h++)
					for(int_t w = 0; w < W; w++)
						X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] = round((((X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] - mu[c]) / sqrt(var[c]+0.00001)) * r[c] + b[c])/scale + zeropoint);
}
