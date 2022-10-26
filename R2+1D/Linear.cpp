#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Linear(int_t* psum_range,dtype* x,int_t* x_num, dtype* weights, int_t* weights_num , int_t* weightsBias, bool bias,dtype* x_out){
       int_t H = x_num[0];
    int_t W = x_num[1];
    int_t C = weights_num[0];


    for(int_t h = 0; h < H; h++){
        for(int_t c = 0; c < C; c++){
            for(int_t i = 0; i < W; i++)x_out[h*C+c] += weights[c*W+i] * x[h*W+i];
            if(bias)x_out[h*C+c] += weightsBias[c];
            if(x_out[h*C+c] > psum_range[1])x_out[h*C+c] = psum_range[1];
            if(x_out[h*C+c] < psum_range[0])x_out[h*C+c] = psum_range[0];
        }
    }
    return;
}

