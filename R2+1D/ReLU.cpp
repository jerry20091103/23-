#include<iostream>
using namespace std;

void ReLU(DATA_TYPE X(N, C, D, H, W)){
	
    for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++){
				for(int h = 0; h < H; h++){
					for(int w = 0; w < W; w++){
						X[n][c][d][h][w] = (X[n][c][d][h][w] > 0) ? X[n][c][d][h][w] : 0;
					}
				}
			}
		}
	}
}
