#include<iostream>
using namespace std;

void r2plus1d(DATA_TYPE X_in(N1, C1, D1, H1, W1))
{
	
	└─Conv3d: 2-1                            [1, 45, 1, 56, 56]        6,615
    └─BatchNorm3d: 2-2                       [1, 45, 1, 56, 56]        90
    └─ReLU: 2-3                              [1, 45, 1, 56, 56]        --
    └─Conv3d: 2-4                            [1, 64, 1, 56, 56]        8,640
    └─BatchNorm3d: 2-5                       [1, 64, 1, 56, 56]        128
    └─ReLU: 2-6 

}