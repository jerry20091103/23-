#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void Residual(dtype* X, dtype* X_tmp, int_t* size, ftype X_scale, ftype X_tmp_scale, ftype out_scale, dtype X_zeropoint, dtype X_tmp_zeropoint, dtype out_zeropoint){
    int_t tmp;
    for(int_t i = size[4]*size[3]*size[2]*size[1]*size[0] - 1; i >= 0; i--)
    {
        tmp = roundf((((int_t)X[i]-X_zeropoint)*X_scale + ((int_t)X_tmp[i]-X_tmp_zeropoint)*X_tmp_scale) / out_scale + out_zeropoint);
        X[i] = (tmp > 255) ? 255 : (tmp < 0) ? 0 : (dtype)tmp;
    }

    return;
}