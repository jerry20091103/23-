#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void CBR(dtype* X_data, param_t* X_num, int_t XC, 
		dtype* Y_data, param_t* Y_num, int_t YC, 
		ktype* Kernel_data, param_t* Kernel_num,
		param_t* stride, param_t* padding, 
		dtype conv_in_zp, ftype conv_in_scale, dtype conv_out_zp, ftype conv_out_scale, dtype batch_zp, ftype batch_scale, 
		ftype* Kernel_scale, ftype* Mu, ftype* Var, ftype* Gamma, ftype* Bias)
{
    #pragma HLS ARRAY_PARTITION variable= Y_bram factor=16 type=cyclic
    KERNEL_LOAD_LOOP:
	for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
        Kernel_bram[i] = Kernel_data[i];
	int_t YI = (Y_num[1]%YC) ? (Y_num[1]/YC+1) : (Y_num[1]/YC);
	int_t XI = (X_num[1]%XC) ? (X_num[1]/XC+1) : (X_num[1]/XC);
    Y_TILE_LOOP:
    for(int_t yi = 0; yi < YI; yi++){
        Y_ZERO_LOOP:
        for(int_t k = 0; k < YC*Y_num[2]*Y_num[3]*Y_num[4]; k++){
            #pragma HLS UNROLL factor = 16
            Y_bram[k] = 0; 
        }
        X_TILE_LOOP:
        for(int_t xi = 0; xi < XI; xi++){
            X_LOAD_LOOP:
            for(int_t k = 0; k < XC*X_num[2]*X_num[3]*X_num[4]; k++)
                X_bram[k] = X_data[xi*XC*X_num[2]*X_num[3]*X_num[4]+k];
			Conv3d(X_bram, X_num, xi, XC, Y_bram, Y_num, yi, YC, Kernel_bram, Kernel_num, stride, padding, conv_in_zp);
        }
        Y_CHANNEL_LOOP:
        for(int_t c = 0; c < YC; c++){
            int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
            BATCH_RELU_LOOP:
            for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
                int_t tmp = (int_t)roundf(Y_bram[offset+k]*conv_in_scale*Kernel_scale[yi*YC+c] / conv_out_scale) + conv_out_zp;
                tmp = (tmp > 255) ? 255 : (tmp < 0) ? 0 : tmp;
                tmp = (int_t)roundf(((((tmp-conv_out_zp)*conv_out_scale - Mu[yi*YC+c]) / sqrtf(Var[yi*YC+c]+0.00001f)) * Gamma[yi*YC+c] + Bias[yi*YC+c]) / batch_scale);
                Y_data[yi*YC*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = (tmp+batch_zp > 255) ? 255 : (tmp < 0) ? batch_zp : tmp+batch_zp;
            }
        }
    }
	return;
}


