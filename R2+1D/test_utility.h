#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// template load function
template <typename T>
bool LoadArr(string filename, T* arr, int size)
{
	std::ifstream file;
	double data;
	file.open(filename);
	if (!file.is_open()) {
		cout << "Error: " << filename << " not found!" << endl;
		return false;
	}
	for (int_t i = 0; i < size; i++) {
		file >> data;
		arr[i] = (T)data;
	}	
	file.close();
	return true;
}


int_t validate(dtype* ourOutput, dtype* golden, int_t* size)
{
	int_t errors = 0;
	int_t N = size[0];
	int_t C = size[1];
	int_t D = size[2];
	int_t H = size[3];
	int_t W = size[4];
	for (int_t n = 0; n < N; n++)
		for (int_t c = 0; c < C; c++)
			for (int_t d = 0; d < D; d++)
				for (int_t h = 0; h < H; h++)
					for (int_t w = 0; w < W; w++) {
						int_t pos = n * C*D*H*W + c * D*H*W + d * H*W + h * W + w;
                        if( ourOutput[pos] != golden[pos]  && abs(ourOutput[pos] - golden[pos]) > 2 ) {
                            cout<<"[ERROR]  result["<<n+1<<"]["<<setw(2)<<c+1<<"]["<<setw(2)<<d+1<<"]["<<setw(2)<<h+1<<"]["<<setw(2)<<w+1<<"]: "<<setw(8)<<(float)ourOutput[pos]<<", gold: "<<setw(8)<<(float)golden[pos]<<", error: "<< 100*(ftype)(ourOutput[pos] - golden[pos]) / golden[pos]<<"%"<<endl;
							errors++;
                        }
					}
	return errors;
}


int_t validate_file(dtype* ourOutput, dtype* golden, int_t* size, ofstream &outfile)
{
	int_t errors = 0;
	int_t N = size[0];
	int_t C = size[1];
	int_t D = size[2];
	int_t H = size[3];
	int_t W = size[4];
	for (int_t n = 0; n < N; n++)
		for (int_t c = 0; c < C; c++)
			for (int_t d = 0; d < D; d++)
				for (int_t h = 0; h < H; h++)
					for (int_t w = 0; w < W; w++) {
						int_t pos = n * C*D*H*W + c * D*H*W + d * H*W + h * W + w;
                        if( ourOutput[pos] != golden[pos]/* && abs(ourOutput[pos] - golden[pos]) > 2 */) {
                            outfile << "[ERROR]  result["<<n+1<<"]["<<setw(2)<<c+1<<"]["<<setw(2)<<d+1<<"]["<<setw(2)<<h+1<<"]["<<setw(2)<<w+1<<"]: "<<setw(8)<<(int)ourOutput[pos]<<", gold: "<<setw(8)<<(int)golden[pos]<<", error: "<< 100*(ftype)(ourOutput[pos] - golden[pos]) / golden[pos]<<"%"<<endl;
							errors++;
                        }
					}
	return errors;
}