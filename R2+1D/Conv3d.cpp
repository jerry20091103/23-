#include<iostream>
using namespace std;

void Conv3d(DATA_TYPE X_in(N1, C1, D1, H1, W1), DATA_TYPE X_out(N2, C2, D2, H2, W2), DATA_TYPE Kernel(KN, KC, KD, KH, KW), TYPE stride = {1, 1, 1}, TYPE padding = {0, 0, 0})
{
	
	
	for(int n = 0; n < N2; n++){
		for(int c = 0; c < C2; c++){
            for (int d = 0; d < ((D1+2*padding[0]-FD)/stride[0] + 1); d++){
                for (int h = 0; h < ((H1+2*padding[1]-FH)/stride[1] + 1); h++){
                	for (int w = 0; w < ((W1+2*padding[2]-FW)/stride[2] + 1); w++){
						for(int kc = 0; kc < KC; kc++){
							for(int kd = 0; kd < KD; kd++){
								for(int kh = 0; kh < KH; kh++){
									for(int kw = 0; kw < KW; kw++){
										X_out[n][c][d][h][w] += X_in[n][c][d*stride[0]+kd][h*stride[1]+kh][w*stride[2]+kw] * Weights[c][kc][kd][kh][kw];
									}
								}
							}
						}
					}
				}
			}
		}
	}
}