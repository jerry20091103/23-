#include "r2plus1d.h"
#include<iostream>
#include <cmath>
using namespace std;

void Residual(dtype* X, dtype* X_tmp, int_t* size, ftype X_scale, ftype X_tmp_scale, ftype out_scale, int_t X_zeropoint, int_t X_tmp_zeropoint, int_t out_zeropoint){
    for(int_t i = size[4]*size[3]*size[2]*size[1]*size[0] - 1; i >= 0; i--)
        X[i] = round((((int_t)X[i]-X_zeropoint)*X_scale + ((int_t)X_tmp[i]-X_tmp_zeropoint)*X_tmp_scale) / out_scale + out_zeropoint);

    return;
}