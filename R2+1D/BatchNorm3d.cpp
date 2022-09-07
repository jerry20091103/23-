#include<iostream>
using namespace std;

void BatchNorm3d(DATA_TYPE X(N, C, D, H, W), int e = 0.00001, int r = 1, int b = 0){

	int mu[N][C];
	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						mu[n][c]  += X[n][c][d][h][w];
			mu[n][c] /= N*C;
		}
	}

	int var[N][C];
	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						var[n][c]  += (X[n][c][d][h][w]-mu[n][c]) * (X[n][c][d][h][w]-mu[n][c]);
			var[n][c] /= N*C;
		}
	}

	for(int n = 0; n < N; n++)
		for(int c = 0; c < C; c++)
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						X[n][c][d][h][w] = ((X[n][c][d][h][w] - mu[n][c]) / sqrt(var[n][c]+e)) * r + b;
}