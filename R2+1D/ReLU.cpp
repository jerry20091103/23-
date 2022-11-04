#include "r2plus1d.h"
#include<iostream>
using namespace std;

void ReLU(dtype* X_data, int_t* X_num, int_t zp){
	
	for(int_t i = X_num[0] * X_num[1] * X_num[2] * X_num[3] * X_num[4]-1; i >= 0; i--) // traverse all data
		X_data[i] = (X_data[i] > zp) ? X_data[i] : zp;
	
	return;
}
