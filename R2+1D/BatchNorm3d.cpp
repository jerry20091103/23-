#include "r2plus1d.h"
#include<iostream>
using namespace std;

#define _C 512

// source: https://www.codeproject.com/Articles/570700/SquareplusRootplusalgorithmplusforplusC
double powerOfTen(int num){
    double rst = 1.0;
    if(num >= 0)
        for(int i = 0; i < num ; i++)
            rst *= 10.0;
    else
        for(int i = 0; i < (0 - num ); i++)
           rst *= 0.1;
   return rst;
}

double sqrt(double a)
{
    double z = a; 
    double rst = 0.0;
    int max = 8;     // to define maximum digit
    double j = 1.0;

    for(int i = max ; i > 0 ; i--){
        // value must be bigger then 0
        double pow_i = powerOfTen(i);
        if(z - (2*rst + j*pow_i) * j * pow_i >= 0){
            while(z - (2*rst + j*pow_i) * j * pow_i >= 0)
                if(++j >= 10)
                    break;
            j--; //correct the extra value by minus one to j
            z -= (2*rst + j*pow_i) * j * pow_i; //find value of z
            rst += j * pow_i;     // find sum of a
            j = 1.0;
        }
    }

    for(int i = 0 ; i >= 0 - max ; i--){
        double pow_i = powerOfTen(i);
        if(z - (2*rst + j*pow_i) * j * pow_i >= 0){
            while(z - (2*rst + j*pow_i) * j * pow_i >= 0)
                j++;
            j--;
            z -= (2*rst + j*pow_i) * j * pow_i; //find value of z
            rst += j * pow_i; // find sum of a
            j = 1.0;
        }
    }
    // find the number on each digit
    return rst;
}

void BatchNorm3d(float* X_data, int* X_num, float e, int r, int b){
	int N = X_num[0];
	int C = X_num[1];
	int D = X_num[2];
	int H = X_num[3];
	int W = X_num[4];

    // find channel mean
	float mu[_C];
    for(int c = 0; c < C; c++){
	    for(int n = 0; n < N; n++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						mu[c] += X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w];
			mu[c] /= D*H*W;
		}
	}

    // find channel variance
	float var[_C];
    for(int c = 0; c < C; c++){
	    for(int n = 0; n < N; n++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						var[c] += (X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w]-mu[c]) * (X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w]-mu[c]);
			var[c] /= D*H*W;
		}
	}

	for(int n = 0; n < N; n++)
		for(int c = 0; c < C; c++)
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] = ((X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] - mu[c]) / sqrt(var[c]+e)) * r + b;
}
