#include "r2plus1d.h"
#include<iostream>
using namespace std;

void ReLU(float* X_data, int* X_num){
	int N = X_num[0];
	int C = X_num[1];
	int D = X_num[2];
	int H = X_num[3];
	int W = X_num[4];

	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++){
				for(int h = 0; h < H; h++){
					for(int w = 0; w < W; w++){
						int pos = n*C*D*H*W + c*D*H*W + d*H*W + h*W + w;
						X_data[pos] = (X_data[pos] > 0) ? X_data[pos] : 0;
					}
				}
			}
		}
	}
	return;
}
