#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void CBRRAL(dtype* X_data, dtype* X_tmp_data, param_t* X_num, int_t XC, 
		dtype* Y_data, param_t* Y_num, int_t YC, 
		ktype* Kernel_data, param_t* Kernel_num, ktype* Kernel_linear_data,
		param_t* stride, param_t* padding, 
		dtype conv_in_zp, ftype conv_in_scale, dtype conv_out_zp, ftype conv_out_scale, dtype X_tmp_zp, ftype X_tmp_scale, dtype batch_zp, ftype batch_scale, dtype res_zp, ftype res_scale, 
		ftype* Kernel_scale, ftype* Mu, ftype* Var, ftype* Gamma, ftype* Bias, param_t* cnt)
{
    cnt[1] = 1;
    KERNEL_LOAD_LOOP:
	for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
        Kernel_bram[i] = Kernel_data[i];
    cnt[1] = 0;
    
    Y_ZERO_LOOP:
    for(int_t k = 0; k < YC*Y_num[2]*Y_num[3]*Y_num[4]; k++){
        #pragma HLS UNROLL factor=8
        Y_bram[k] = 0; 
    }
    
    cnt[1] = 2;
    X_LOAD_LOOP:
    for(int_t k = 0; k < XC*X_num[2]*X_num[3]*X_num[4]; k++)
        X_bram[k] = X_data[k];
    cnt[1] = 0;
    Conv3d(X_bram, X_num, 0, XC, Y_bram, Y_num, 0, YC, Kernel_bram, Kernel_num, stride, padding, conv_in_zp);
    
    Y_CHANNEL_LOOP:
    for(int_t c = 0; c < YC; c++){
        int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
        int_t tmp_Y = 0;
        BATCH_RES_RELU_ADAP_LOOP:
        for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
            int_t tmp = (int_t)roundf(Y_bram[offset+k]*conv_in_scale*Kernel_scale[c] / conv_out_scale) + conv_out_zp;
            tmp = (tmp > 255) ? 255 : (tmp < 0) ? 0 : tmp;
            tmp = (int_t)roundf(((((tmp-conv_out_zp)*conv_out_scale - Mu[c]) / sqrtf(Var[c]+0.00001f)) * Gamma[c] + Bias[c]) / batch_scale) + batch_zp;
            tmp = (tmp > 255) ? 255 : (tmp < 0) ? 0 : tmp;
            tmp = (int_t)roundf(((tmp-batch_zp)*batch_scale + ((X_tmp_data[offset+k]-X_tmp_zp)*X_tmp_scale)) / res_scale);
            tmp = (tmp+res_zp > 255) ? 255 : (tmp < 0) ? res_zp : tmp+res_zp;
            
            tmp_Y += tmp;
        }
        Y_bram[c] = roundf((ftype)tmp_Y/98);    
    }
    cnt[0]++;
    
    
    cnt[1] = 1;
	KERNEL_LINEAR_LOAD_LOOP:
    for(int_t i = 0; i < 5120; i++)
        Kernel_bram[i] = Kernel_linear_data[i];
    cnt[1] = 0;
    LINEAR_LOOP:
    for(int c = 0; c < 10; c++){
        int_t tmp_Y = 0;
        for(int i = 0; i < 512; i++)
            tmp_Y += Kernel_bram[c*512+i]*((int_t)Y_bram[i]-31);
        tmp_Y = (int_t)roundf((tmp_Y*1.290386915206909180e-01f*Kernel_linear_scale[c]+KernelBias[c]) / 3.984360396862030029e-02f) + 127;
        Y_data[c] = (tmp_Y > 255) ? 255 : (tmp_Y < 0) ? 0 : (dtype)tmp_Y;
    }
    cnt[0]++;

	return;
}
