#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void CBR(dtype* X_data, int_t* X_num, int_t XC, 
		dtype* Y_data, int_t* Y_num, int_t YC, 
		ktype* Kernel_data, int_t* Kernel_num, 
		int_t* stride, int_t* padding, 
		dtype conv_zp, ftype conv_scale, dtype batch_zp, ftype batch_scale, int_t flag) // 0 for conv3d, 1 for conv3d_k
{
    if(flag == 0){
		for(int_t i = 0; i < Y_num[1]*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; i++)
        Kernel_bram[i] = Kernel_data[i];
	}
    for(int_t yi = 0; yi < (Y_num[1]/YC); yi++){
        for(int_t k = 0; k < YC*Y_num[2]*Y_num[3]*Y_num[4]; k++)
            Y_bram[k] = 0; 
        
        for(int_t xi = 0; xi < (X_num[1]/XC); xi++){
            for(int_t k = 0; k < XC*X_num[2]*X_num[3]*X_num[4]; k++)
                X_bram[k] = X_data[xi*XC*X_num[2]*X_num[3]*X_num[4]+k];

            if(flag == 0)
				Conv3d(X_bram, X_num, xi, XC, Y_bram, Y_num, yi, YC, Kernel_bram, Kernel_num, stride, padding, conv_zp);
            else if(flag == 1){
				int_t i = 0;
				for(int_t yc = 0; yc < YC; yc++)
					for(int_t xc = 0; xc < XC; xc++)
						for(int_t j = 0; j < Kernel_num[0]*Kernel_num[1]*Kernel_num[2]; j++){
							Kernel_bram[i++] =  Kernel_data[(yi*YC + yc)*X_num[1]*Kernel_num[0]*Kernel_num[1]*Kernel_num[2] + (xi*XC + xc)*Kernel_num[0]*Kernel_num[1]*Kernel_num[2] + j];
						}
				Conv3d_k(X_bram, X_num, xi, XC, Y_bram, Y_num, yi, YC, Kernel_bram, Kernel_num, stride, padding, conv_zp);
			}
        }
        
        for(int_t c = 0; c < YC; c++){
            int_t offset = c*Y_num[2]*Y_num[3]*Y_num[4];
            for(int_t k = 0; k < Y_num[2]*Y_num[3]*Y_num[4]; k++){
                int_t tmp = (int_t)roundf((((Y_bram[offset+k]*conv_scale*Kernel_stem_0_scale[yi*YC+c] - Mu_stem_1[yi*YC+c]) / sqrtf(Var_stem_1[yi*YC+c]+0.00001)) * Gamma_stem_1[yi*YC+c] + Bias_stem_1[yi*YC+c])/batch_scale);
                Y_bram[offset+k] = (tmp+batch_zp > 255) ? 255 : (tmp < 0) ? batch_zp : tmp+batch_zp;
                Y_data[yi*YC*Y_num[2]*Y_num[3]*Y_num[4]+offset+k] = Y_bram[offset+k];
            }
        }
    }
	return;
}