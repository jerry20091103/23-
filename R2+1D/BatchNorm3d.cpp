#include "r2plus1d.h"
#include<iostream>
#include <cmath>

using namespace std;

void BatchNorm3d(dtype* X_data, int_t* X_num, double* mu_, double* var_, double* r, double* b, double scale_in, int_t zp_in, double scale_out, int_t zp_out){
	int_t N = X_num[0];
	int_t C = X_num[1];
	int_t D = X_num[2];
	int_t H = X_num[3];
	int_t W = X_num[4];

    // dequan X_data
	for(int_t i = N*C*D*H*W-1; i >= 0; i--)
		X_data[i] -= zp_in;

	for(int_t n = 0; n < N; n++)
		for(int_t c = 0; c < C; c++)
			for(int_t d = 0; d < D; d++)
				for(int_t h = 0; h < H; h++)
					for(int_t w = 0; w < W; w++)
						X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] = round((((float(X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w])*scale_in - mu_[c]) / sqrt(var_[c]+0.00001)) * r[c] + b[c])/scale_out + zp_out);
						// X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] = round((((float(X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w])*scale_in - (0.1*mu[c]*scale_in+0.9*mu_[c])) / sqrt((0.1*var[c]*pow(scale_in, 2)+0.9*var_[c])+0.00001)) * r[c] + b[c])/scale_out + zp_out);
}
