void AdaptiveAvgPool3d(float* X_data,float* X_num, int* out_size, float* Y_data, float* Y_num ){
    int N = X_num[0];
	int C = X_num[1];
	int D = X_num[2];
	int H = X_num[3];
	int W = X_num[4];
    
    int D_out = Y_num[2]; // N+2*padding[0]-dilation[0]*(KD-1)-1)/stride[0] + 1
	int H_out = Y_num[3]; // H+2*padding[1]--dilation[0]*(KH-1)-1)/stride[1] + 1
	int W_out = Y_num[4]; // W+2*padding[2]--dilation[0]*(KW-1)-1)/stride[2] + 1

    int stride_D = D/D_out;
    int stride_H = H/H_out;
    int stride_W = W/W_out;

    int kernel_D = D - (D_out-1) * stride_D;
    int kernel_H = H - (H_out-1) * stride_H;
    int kernel_W = W - (W_out-1) * stride_W;
    int padding = 0;
    
	for(int n = 0; n < N; n++){
        for(int c = 0; c < C; c++){
            for(int d = 0; d < D_out; d++){
                for (int h = 0; h < H_out; h++){
                    for (int w = 0; w < W_out; w++){
                        for(int kd = 0; kd < kernel_D; kd++){
                            for(int kh = 0; kh < kernel_H; kh++){
                                for(int kw = 0; kw < kernel_W; kw++){
                                    Y_data[n*C*D_out*H_out*W_out + c*D_out*H_out*W_out + d*H_out*W_out + h*W_out + w] += X_data[(n*C*D*H*W)+(c*D*H*W) + (d*stride_D+kd)*H*W + (h*stride_H+kh)*W + (w*stride_W+kw)];
                                }
                            }
                        }
                        Y_data[n*C*D_out*H_out*W_out + c*D_out*H_out*W_out + d*H_out*W_out + h*W_out + w] = Y_data[n*C*D_out*H_out*W_out + c*D_out*H_out*W_out + d*H_out*W_out + h*W_out + w]/(kernel_D*kernel_W*kernel_H);
                    }
						
                }
            }
        }
    }
		
}
