#include "r2plus1d.h"
#include<iostream>
using namespace std;

#define _N 1
#define _C 64
#define _D 1
#define _H 56
#define _W 56

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

void BatchNorm3d(Array_5D X, int e = 0.00001, int r = 1, int b = 0){

	float X_data[_N][_C][_D][_H][_W];

	int N = X.num[0];
	int C = X.num[1];
	int D = X.num[2];
	int H = X.num[3];
	int W = X.num[4];

	int mu[_N][_C];
	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						mu[n][c]  += X_data[n][c][d][h][w];
			mu[n][c] /= N*C;
		}
	}

	int var[_N][_C];
	for(int n = 0; n < N; n++){
		for(int c = 0; c < C; c++){
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						var[n][c]  += (X_data[n][c][d][h][w]-mu[n][c]) * (X_data[n][c][d][h][w]-mu[n][c]);
			var[n][c] /= N*C;
		}
	}

	for(int n = 0; n < N; n++)
		for(int c = 0; c < C; c++)
			for(int d = 0; d < D; d++)
				for(int h = 0; h < H; h++)
					for(int w = 0; w < W; w++)
						X_data[n][c][d][h][w] = ((X_data[n][c][d][h][w] - mu[n][c]) / sqrt(var[n][c]+e)) * r + b;
}