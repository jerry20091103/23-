#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Linear(int* psum_range,Array_2D x, Array_2D weights, int* weightsBias, bool bias,Array_2D x_out){
   	int H = x.num[0];
	int W = X.num[1];
	int C = weights.num[0];
	int W = weights.num[1];

    for(int h = 0; h < H; h++){
        for(int c = 0; c < C; c++){
            for(int i = 0; i < W; i++)x_out[h][c] += weights[c][i] * x[h][i];
            if(bias)x_out[h][c] += weightBias[c];
            if(x_out[h][c] > psum_range[1])x_out[h][c] = psum_range[1];
            if(x_out[h][c] < psum_range[0])x_out[h][c] = psum_range[0];
        }
    }
    return;
}
