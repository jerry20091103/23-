#include "r2plus1d.h"
#include<iostream>
#include <cmath>

using namespace std;

void BatchNorm3d(dtype* X_data, int_t* X_num, ftype* mu_, ftype* var_, ftype* r, ftype* b, ftype scale_in, int_t zp_in, ftype scale_out, int_t zp_out){
	int_t N = X_num[0];
	int_t C = X_num[1];
	int_t D = X_num[2];
	int_t H = X_num[3];
	int_t W = X_num[4];

	for(int_t n = 0; n < N; n++)
		for(int_t c = 0; c < C; c++)
			for(int_t d = 0; d < D; d++)
				for(int_t h = 0; h < H; h++)
					for(int_t w = 0; w < W; w++){
						int_t tmp_X = round((((ftype((int_t)X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w]-zp_in)*scale_in - mu_[c]) / sqrtf(var_[c]+0.00001)) * r[c] + b[c])/scale_out + zp_out);
						X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] = (tmp_X > 255) ? 255 : (tmp_X < 0) ? 0 : (dtype)tmp_X;
					}
}
