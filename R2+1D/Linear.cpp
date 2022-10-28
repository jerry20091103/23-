#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std; 

#define _C 10  // Y_num(out_features) = 10
#define scale 3.984360396862030029e-02
#define zeropoint 127

void Linear(dtype* X_data, int_t* X_num, dtype* Y_data, dtype* Kernel){
    int H = X_num[0];
    int W = X_num[1];
    int C = Y_num[0];

    for(int h = 0; h < H; h++)
        for(int c = 0; c < _C; c++)
            for(int i = 0; i < W; i++)
                Y_data[h*_C+c] += round( (Kernel[c*W+i]*X_data[h*W+i])/scale + zeropoint );
    
    return;
}

