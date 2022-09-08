#include "r2plus1d.h"
#include<iostream>
using namespace std;

#define _N 1
#define _C 64
#define _D 1
#define _H 56
#define _W 56

void BatchNorm3d(Array_5D X, int e = 0.00001, int r = 1, int b = 0){

	float X_data[_N][_C][_D][_H][_W];

	int N = X.num[0];
	int C = X.num[1];
	int D = X.num[2];
	int H = X.num[3];
	int W = X.num[4];

	int mu[_N][_C];
	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						mu[n][c]  += X_data[n][c][d][h][w];
			mu[n][c] /= N*C;
		}
	}

	int var[_N][_C];
	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						var[n][c]  += (X_data[n][c][d][h][w]-mu[n][c]) * (X_data[n][c][d][h][w]-mu[n][c]);
			var[n][c] /= N*C;
		}
	}

	for(int n = 0; n < N; n++)
		for(int c = 0; c < C; c++)
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						X_data[n][c][d][h][w] = ((X_data[n][c][d][h][w] - mu[n][c]) / sqrt(var[n][c]+e)) * r + b;
}