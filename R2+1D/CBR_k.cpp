#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void CBR_k(dtype* X_data, param_t* X_num, int_t XC, 
		dtype* Y_data, param_t* Y_num, int_t YC, 
		ktype* Kernel_data, param_t* Kernel_num,
		param_t* stride, param_t* padding, 
		dtype conv_in_zp, ftype conv_in_scale, dtype conv_out_zp, ftype conv_out_scale, dtype batch_zp, ftype batch_scale, 
		ftype* Kernel_scale, ftype* Mu, ftype* Var, ftype* Gamma, ftype* Bias)
{
    int_t YI = (Y_num[1]%YC) ? (Y_num[1]/YC+1) : (Y_num[1]/YC);
	int_t XI = (X_num[1]%XC) ? (X_num[1]/XC+1) : (X_num[1]/XC);
    for(int_t yi = 0; yi < YI; yi++){
        for(int_t k = 0; k < YC*Y_num[2]*Y_num[3]*Y_num[4]; k++)
            Y_bram[k] = 0; 
        
        for(int_t xi = 0; xi < XI; xi++){
            for(int_t k = 0; k < XC*X_num[2]*X_num[3]*X_num[4]; k++)
                X_bram[k] = X_data[xi*XC*X_num[2]*X_num[3]*X_num[4]+k];
            for(int_t yc = 0; yc < YC; yc++)
                for(int_t xc = 0; xc < XC && yi*YC+yc < Y_num[1]; xc++)
                    for(int_t j = 0; j < Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; j++){
                        Kernel_bram[yc*XC*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]+xc*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]+j] =  Kernel_data[(yi*YC + yc)*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2] + (xi*XC + xc)*Kernel_num[0]*Kernel_num[1]*Kernel_num[2] + j];
                    }
            Conv3d_k(X_bram, X_num, xi, XC, Y_bram, Y_num, yi, YC, Kernel_bram, Kernel_num, stride, padding, conv_in_zp);
        }
        
        for(int_t c = 0; c < YC; c++){
            int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
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