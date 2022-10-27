#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void Linear(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num, dtype* Kernel, double scale, int_t zeropoint){
    int H = X_num[0];
    int W = X_num[1];
    int C = Y_num[0];

    for(int h = 0; h < H; h++)
        for(int c = 0; c < C; c++)
            for(int i = 0; i < W; i++)
                Y_data[h*C+c] += round( (Kernel[c*W+i]*X_data[h*W+i])/scale + zeropoint );
    return;
}

