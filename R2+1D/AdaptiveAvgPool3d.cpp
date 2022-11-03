#include "r2plus1d.h"
#include <cmath>
void AdaptiveAvgPool3d(dtype* X_data, int_t* X_num, dtype* Y_data, int_t* Y_num){
    int_t N = X_num[0];
	int_t C = X_num[1];
	int_t D = X_num[2];
	int_t H = X_num[3];
	int_t W = X_num[4];
    
    int_t D_out = Y_num[2]; // N+2*padding[0]-dilation[0]*(KD-1)-1)/stride[0] + 1
	int_t H_out = Y_num[3]; // H+2*padding[1]--dilation[0]*(KH-1)-1)/stride[1] + 1
	int_t W_out = Y_num[4]; // W+2*padding[2]--dilation[0]*(KW-1)-1)/stride[2] + 1

    int_t stride_D = D/D_out;
    int_t stride_H = H/H_out;
    int_t stride_W = W/W_out;

    int_t kernel_D = D - (D_out-1) * stride_D;
    int_t kernel_H = H - (H_out-1) * stride_H;
    int_t kernel_W = W - (W_out-1) * stride_W;
    int_t padding = 0;
    
	for(int_t n = 0; n < N; n++){
        for(int_t c = 0; c < C; c++){
            for(int_t d = 0; d < D_out; d++){
                for (int_t h = 0; h < H_out; h++){
                    for (int_t w = 0; w < W_out; w++){
                        int_t tmp_Y = 0;
                        for(int_t kd = 0; kd < kernel_D; kd++){
                            for(int_t kh = 0; kh < kernel_H; kh++){
                                for(int_t kw = 0; kw < kernel_W; kw++){
                                    tmp_Y += X_data[(n*C*D*H*W)+(c*D*H*W) + (d*stride_D+kd)*H*W + (h*stride_H+kh)*W + (w*stride_W+kw)];
                                }
                            }
                        }
                        
                        Y_data[n*C*D_out*H_out*W_out + c*D_out*H_out*W_out + d*H_out*W_out + h*W_out + w] = round((ftype)tmp_Y/(kernel_D*kernel_W*kernel_H));
                    }
						
                }
            }
        }
    }
		
}
