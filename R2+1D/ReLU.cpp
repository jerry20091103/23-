#include "r2plus1d.h"
#include<iostream>
using namespace std;

void ReLU(float* X_data, int* X_num){
	
	for(int i = X_num[0] * X_num[1] * X_num[2] * X_num[3] * X_num[4]; i >= 0; i--)
		X_data[i] = (X_data[i] > 0) ? X_data[i] : 0;
	
	return;
}
