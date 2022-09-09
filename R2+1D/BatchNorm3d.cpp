#include "r2plus1d.h"
#include<iostream>
using namespace std;

#define _N 1
#define _C 16

// https://www.codeproject.com/Articles/570700/SquareplusRootplusalgorithmplusforplusC
double powerOfTen(int num){
    double rst = 1.0;
    if(num >= 0){
        for(int i = 0; i < num ; i++){
            rst *= 10.0;
        }
    }else{
        for(int i = 0; i < (0 - num ); i++){
           rst *= 0.1;
       }
   }
   return rst;
}

double sqrt(double a)
{
    /*
          find more detail of this method on wiki methods_of_computing_square_roots

          *** Babylonian method cannot get exact zero but approximately value of the square_root

     */
    double z = a; 
    double rst = 0.0;
    int max = 8;     // to define maximum digit 
    int i;
    double j = 1.0;
    for(i = max ; i > 0 ; i--){
        // value must be bigger then 0
        if(z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0){
            while( z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0){
                j++;
                if(j >= 10) break;
            }
            j--; //correct the extra value by minus one to j
            z -= (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)); //find value of z

            rst += j * powerOfTen(i);     // find sum of a
            j = 1.0;
          }
     }

     for(i = 0 ; i >= 0 - max ; i--){
         if(z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0){
             while( z - (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)) >= 0)
                 j++;
             j--;
             z -= (( 2 * rst ) + ( j * powerOfTen(i)))*( j * powerOfTen(i)); //find value of z
             rst += j * powerOfTen(i); // find sum of a
             j = 1.0;
          }
     }
     // find the number on each digit
     return rst;
}

void BatchNorm3d(float* X_data, int* X_num, float e, int r, int b){
	int N = X_num[0];
	int C = X_num[1];
	int D = X_num[2];
	int H = X_num[3];
	int W = X_num[4];

	float mu[_N*_C];
	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						mu[n*C + c]  += X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w];
			mu[n*C + c] /= N*C;
		}
	}

	float var[_N*_C];
	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						var[n*C + c]  += (X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w]-mu[n*C + c]) * (X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w]-mu[n*C + c]);
			var[n*C + c] /= N*C;
		}
	}

	for(int n = 0; n < N; n++)
		for(int c = 0; c < C; c++)
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] = ((X_data[n*C*D*H*W + c*D*H*W + d*H*W + h*W + w] - mu[n*C + c]) / sqrt(var[n*C + c]+e)) * r + b;
}
