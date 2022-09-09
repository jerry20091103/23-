#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Linear(int* psum_range,Array_5D x, Array_5D weights, int* weightsBias, bool bias,Array_5D x_out){
   	int H = x.num[0];
	int W = x.num[1];
	int C = weights.num[0];


    for(int h = 0; h < H; h++){
        for(int c = 0; c < C; c++){
            for(int i = 0; i < W; i++)x_out.data[h*C+c] += weights.data[c*W+i] * x.data[h*W+i];
            if(bias)x_out.data[h*C+c] += weightsBias[c];
            if(x_out.data[h*C+c] > psum_range[1])x_out.data[h*C+c] = psum_range[1];
            if(x_out.data[h*C+c] < psum_range[0])x_out.data[h*C+c] = psum_range[0];
        }
    }
    return;
}
