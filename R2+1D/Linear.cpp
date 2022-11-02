#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std; 

#define out_features 10  // Y_num(out_features) = 10

#define scale_in  1.290386915206909180e-01
#define zp_in 31
#define scale_out 3.984360396862030029e-02
#define zp_out 127



void Linear(dtype* X_data, int_t* X_num, dtype* Y_data, dtype* Kernel, double* kernel_scale){
    int H = X_num[0];
    int W = X_num[1];
    
    // dequan X
	for(int_t i = H*W-1; i >= 0; i--)
		X_data[i] -= zp_in;

    // initial Y
    for(int i = 0; i < out_features*H; i++)
        Y_data[i] = 0;

    for(int h = 0; h < H; h++)
        for(int c = 0; c < out_features; c++){
            int yPos = h*out_features+c;
            for(int i = 0; i < W; i++)
                Y_data[yPos] += Kernel[c*W+i]*X_data[h*W+i];
            Y_data[yPos] = round(Y_data[yPos]*scale_in*kernel_scale[c]/scale_out + zp_out);
        }

    return;
}

