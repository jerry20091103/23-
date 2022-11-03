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
    double KernelBias[out_features] = {-2.027071081101894379e-02, 
                                        -2.052653767168521881e-02,
                                        7.522165542468428612e-04,
                                        -1.116470154374837875e-02,
                                        -7.982283830642700195e-03,
                                        9.041070006787776947e-03,
                                        -1.629139482975006104e-02,
                                        -4.765422269701957703e-02,
                                        4.082637373358011246e-03,
                                        5.861985497176647186e-03};
    // dequan X
	// for(int_t i = H*W-1; i >= 0; i--)
	// 	X_data[i] -= zp_in;

    // initial Y
    // for(int i = 0; i < out_features*H; i++)
    //     Y_data[i] = 0;

    for(int h = 0; h < H; h++)
        for(int c = 0; c < out_features; c++){
            int yPos = h*out_features+c;
            int_t tmp_Y = 0;
            for(int i = 0; i < W; i++)
                tmp_Y += Kernel[c*W+i]*((int_t)X_data[h*W+i]-zp_in);
            Y_data[yPos] = round((tmp_Y*scale_in*kernel_scale[c]+KernelBias[c])/scale_out + zp_out);
            // clamp to 0~255
            if(Y_data[yPos] > 255) Y_data[yPos] = 255;
            else if(Y_data[yPos] < 0) Y_data[yPos] = 0;
        }

    return;
}

