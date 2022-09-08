#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef signed char   ap_int;
typedef unsigned char ap_uint;



void Sequential(psum_range, x, weights, out_channels, kernel_size=5, stride=1, bias=False, psum_record=False){
    psum_record_list = [np.complex64(x) for x in range(0)];
    N, C, H, W = x.shape;
    x_out = np.zeros((N, out_channels, int(((H-kernel_size)/stride)+1), int((W-kernel_size)/stride + 1)), dtype='int32');
    
    for(int n = 0; n < N; n++){
        for (int m = 0; m < out_channels; m++){
            for (int p = 0; p < ((H-kernel_size)/stride + 1); p++){
                for (int q = 0; q < ((W-kernel_size)/stride + 1); q++){
                    for (int r = 0; r < kernel_size; r++){
                        for (int s = 0; s < kernel_size; s++){
                            for (int c = 0; c < C; c++){
                                int h = p * stride + r;
                                int w = q * stride + s;
                                x_out[n,m,p,q] += x[n,c,h,w] * weights[m,c,r,s];
                                if(x_out[n,m,p,q] < psum_range[0]){
                                    x_out[n,m,p,q]=psum_range[0];
                                }
                                elif(x_out[n,m,p,q] > psum_range[1]){
                                    x_out[n,m,p,q]=psum_range[1];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
                  
    psum_record_list = x_out;
      
    
    return x_out, psum_record_list;
}



