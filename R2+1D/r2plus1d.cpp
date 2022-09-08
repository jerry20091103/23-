#include "r2plus1d.h"
#include<iostream>
using namespace std;

void r2plus1d(Array_5D X_in, Array_5D Conv3d_Kernel_1, Array_5D Conv3d_Kernel_2)
{
	int stride[3] = {1,1,1};
	int padding[3] = {0,0,0};

    Conv3d(X_in, X_out, Kernel, stride, padding);
    BatchNorm3d(X, 0.00001, 1, 0);
    ReLU(X);

	// └─Conv3d: 2-1                            [1, 45, 1, 56, 56]        6,615
    // └─BatchNorm3d: 2-2                       [1, 45, 1, 56, 56]        90
    // └─ReLU: 2-3                              [1, 45, 1, 56, 56]        --
    // └─Conv3d: 2-4                            [1, 64, 1, 56, 56]        8,640
    // └─BatchNorm3d: 2-5                       [1, 64, 1, 56, 56]        128
    // └─ReLU: 2-6 

}