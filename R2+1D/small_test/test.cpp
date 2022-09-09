#include "test.h"
#include<iostream>
using namespace std;

void test(float* X, float* Xout)
{
	int X_in_num[5] = {1, 3, 1, 111, 111};
    Array_5D X_in = {.data = X, .num = X_in_num};

	int X_out_num[5] = {1, 3, 1, 111, 111};
    float X_out_data[36963];
    Array_5D X_out = {.data = X_out_data, .num = X_out_num};

    Trans(X_in, X_out);
    
    Xout = X_out.data;
    return;
}