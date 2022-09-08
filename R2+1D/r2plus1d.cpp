#include<iostream>
using namespace std;

void r2plus1d(Array_5D X_in, Array_5D Conv3d_Kernel_1, Array_5D Conv3d_Kernel_2)
{
	
    Conv3d(Array_5D X_in, Array_5D X_out, Array_5D Kernel, int* stride, int* padding);
    BatchNorm3d(Array_5D X, int e = 0.00001, int r = 1, int b = 0);
    ReLU(Array_5D X);

	// └─Conv3d: 2-1                            [1, 45, 1, 56, 56]        6,615
    // └─BatchNorm3d: 2-2                       [1, 45, 1, 56, 56]        90
    // └─ReLU: 2-3                              [1, 45, 1, 56, 56]        --
    // └─Conv3d: 2-4                            [1, 64, 1, 56, 56]        8,640
    // └─BatchNorm3d: 2-5                       [1, 64, 1, 56, 56]        128
    // └─ReLU: 2-6 

}