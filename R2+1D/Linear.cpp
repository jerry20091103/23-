#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std; 

#define out_features 10  // Y_num(out_features) = 10
#define scale 3.984360396862030029e-02
#define zeropoint 127

void Linear(dtype* X_data, int_t* X_num, dtype* Y_data, dtype* Kernel){
    int H = X_num[0];
    int W = X_num[1];
    
    for(int i = 0; i < out_features*H; i++)
        Y_data[i] = 0;

    for(int h = 0; h < H; h++)
        for(int c = 0; c < out_features; c++)
            for(int i = 0; i < W; i++)
                Y_data[h*out_features+c] += round( (Kernel[c*W+i]*X_data[h*W+i])/scale + zeropoint );
    
    return;
}

