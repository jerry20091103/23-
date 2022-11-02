#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
#include <string>
#include <iomanip>
using namespace std;

int_t validate(dtype* ourOutput, dtype* golden, int_t* size);
bool LoadDTYPE(string filename, dtype* arr, int size);
bool LoadDouble(string filename, double* arr, int size);

int_t main()
{
	dtype *input = (dtype*)malloc(512 * sizeof(dtype));
	dtype *output = (dtype*)malloc(10 * sizeof(dtype));
	dtype *golden = (dtype*)malloc(10 * sizeof(dtype));

	dtype *Kernel = (dtype*)malloc(5120 * sizeof(dtype));
	double *Kernel_linear_scale = (double*)malloc(10 * sizeof(double));

	// ==========================================================
	// Linear
	int_t X_linear_in_num[2] = { N_, 512 };
	int_t X_linear_out_num[5] = { 1, 10, 1, 1, 1 };

    if(!LoadDTYPE("input.dat", input, 512)) return 0;
	if(!LoadDTYPE("fc.1.weight.dat", Kernel, 5120)) return 0;
	if(!LoadDouble("fc.1.weight.scale.dat", Kernel_linear_scale, 10)) return 0;
	if(!LoadDTYPE("output.dat", golden, 10)) return 0;

	cout << "==> Linear\n";
    Linear(input, X_linear_in_num, output, Kernel, Kernel_linear_scale);

	float errors;
	errors = 100 * float(validate(output, golden, X_linear_out_num)) / 10;

	if (errors != 0)
		printf("[FAIL] There are some errors QQ, error rate: %f%\n", errors);
	else
		printf("[PASS] Congratulation! All results are correct\n");

	// ==========================================================

	free(input);
	free(output);
	free(golden);
	free(Kernel);

	free(Kernel_linear_scale);

	return 0;
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
                        if(golden[pos] == 0 && ourOutput[pos] != golden[pos]){
                            cout<<"[ERROR]  result["<<n+1<<"]["<<setw(2)<<c+1<<"]["<<setw(2)<<d+1<<"]["<<setw(2)<<h+1<<"]["<<setw(2)<<w+1<<"]: "<<setw(8)<<ourOutput[pos]<<", gold: "<<setw(8)<<golden[pos]<<", error: "<< 100*(double)(ourOutput[pos] - golden[pos]) / ourOutput[pos]<<"%"<<endl;
                            errors++;
                        }
                        else if(ourOutput[pos] != golden[pos] && (double)(ourOutput[pos] - golden[pos]) / golden[pos] >= 0.002 || (double)(ourOutput[pos] - golden[pos]) / golden[pos] <= -0.002){
                            cout<<"[ERROR]  result["<<n+1<<"]["<<setw(2)<<c+1<<"]["<<setw(2)<<d+1<<"]["<<setw(2)<<h+1<<"]["<<setw(2)<<w+1<<"]: "<<setw(8)<<ourOutput[pos]<<", gold: "<<setw(8)<<golden[pos]<<", error: "<< 100*(double)(ourOutput[pos] - golden[pos]) / golden[pos]<<"%"<<endl;
                            errors++;
                        }
					}
	return errors;
}

bool LoadDTYPE(string filename, dtype* arr, int size){
	FILE         *fp;
	std::ifstream file;
	double data = 0;

	file.open(filename);
	if (!file.is_open()) {
		cout << filename << " not found!" << endl;
		return false;
	}
	for (int_t i = 0; i < size; i++) {
		file >> data;
		arr[i] = (dtype)data;
	}
	file.close();
	return true;
}

bool LoadDouble(string filename, double* arr, int size){
	FILE         *fp;
	std::ifstream file;
	double data = 0;

	file.open(filename);
	if (!file.is_open()) {
		cout << filename << " not found!" << endl;
		return false;
	}
	for (int_t i = 0; i < size; i++) {
		file >> data;
		arr[i] = data;
	}
	file.close();
	return true;
}
