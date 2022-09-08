#include<iostream>
using namespace std;

void ReLU(Array_5D X){
	int N = X_in.num[0];
	int C = X_in.num[1];
	int D = X_in.num[2];
	int H = X_in.num[3];
	int W = X_in.num[4];

	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++){
				for(int h = 0; h < H; h++){
					for(int w = 0; w < W; w++){
						int pos = n*C*D*H*W + c*D*H*W + d*H*W + h*W + w;
						X[pos] = (X[pos] > 0) ? X[pos] : 0;
					}
				}
			}
		}
	}
}