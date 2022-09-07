#include<iostream>
using namespace std;

void conv3D(DATA_TYPE X_in(N1, C1, D1, H1, W1), DATA_TYPE X_out(N2, C2, D2, H2, W2), DATA_TYPE Weights(WN, WC, WD, WH, WW), int stride = 1, int padding = 0)
{
	for(int n = 0; n < N2; n++){
		for(int c = 0; c < C2; c++){
            for (int d = 0; d < ((D1+2*padding-FD)/stride + 1); d++){
                for (int h = 0; h < ((H1+2*padding-FH)/stride + 1); h++){
                	for (int w = 0; w < ((W1+2*padding-FW)/stride + 1); w++){
						for(int wc = 0; wc < WC; wc++){
							for(int wd = 0; wd < WD; wd++){
								for(int wh = 0; wh < WH; wh++){
									for(int ww = 0; ww < WW; ww++){
										X_out[n][c][d][h][w] += X_in[n][c][d*stride+wd][h*stride+wh][w*stride+ww] * Weights[c][wc][wd][wh][ww];
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