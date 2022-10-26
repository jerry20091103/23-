#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Linear(int* psum_range, double* x, int* x_num, double* weights, int* weights_num , int* weightsBias, bool bias, double* x_out){
    int H = x_num[0];
    int W = x_num[1];
    int C = weights_num[0];


    for(int h = 0; h < H; h++){
        for(int c = 0; c < C; c++){
            for(int i = 0; i < W; i++)
                x_out[h*C+c] += weights[c*W+i] * x[h*W+i];
            if(bias)x_out[h*C+c] += weightsBias[c];
            if(x_out[h*C+c] > psum_range[1])x_out[h*C+c] = psum_range[1];
            if(x_out[h*C+c] < psum_range[0])x_out[h*C+c] = psum_range[0];
        }
    }
    return;
}

