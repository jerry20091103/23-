#include "test.h"
#include<iostream>
using namespace std;

void Trans(Array_5D X, Array_5D X_out);

void test(float* X, float* Xout)
{
	int X_in_num[5] = {1, 3, 1, 111, 111};
    Array_5D X_in = {.data = X, .num = X_in_num};

	int X_out_num[5] = {1, 3, 1, 111, 111};
    float X_out_data[36963];
    Array_5D X_out = {.data = X_out_data, .num = X_out_num};

    Trans(X_in, X_out);
    
    Xout = X_out.data;
    return;
}

void Trans(Array_5D X, Array_5D X_out){
	int N = X.num[0];
	int C = X.num[1];
	int D = X.num[2];
	int H = X.num[3];
	int W = X.num[4];

	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++){
				for(int h = 0; h < H; h++){
					for(int w = 0; w < W; w++){
						int pos = n*C*D*H*W + c*D*H*W + d*H*W + h*W + w;
						X_out.data[pos] = X.data[pos];
					}
				}
			}
		}
	}
	return;
}