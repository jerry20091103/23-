#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Linear(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num, dtype* Kernel){
    int H = X_num[0];
    int W = X_num[1];
    int C = Y_num[1];

    // initialize Y_data
    for(int c = 0; c < C; c++){
        for(int h = 0; h < H; h++){
            Y_data[h*c] = 0;
        }
    }

    for(int h = 0; h < H; h++)
        for(int c = 0; c < C; c++)
            for(int i = 0; i < W; i++)
                Y_data[h*C+c] += Kernel[c*W+i] * X_data[h*W+i];
        
    return;
}

