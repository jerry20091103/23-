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

int_t main()
{
	dtype *input = (dtype*)malloc(50176 * sizeof(dtype));
	dtype *output = (dtype*)malloc(512 * sizeof(dtype));
	dtype *golden = (dtype*)malloc(512 * sizeof(dtype));

	// ==========================================================
	// Linear
	int_t X_adaptive_in_num[5] = { 1, 512, 2, 7, 7 };
	int_t X_adaptive_out_num[5] = { 1, 512, 1, 1, 1 };

    if(!LoadDTYPE("input.dat", input, 50176)) return 0;
	if(!LoadDTYPE("output.dat", golden, 512)) return 0;

	cout << "==> AdaptiveAvgPool3D\n";
    AdaptiveAvgPool3d(input, X_adaptive_in_num, output, X_adaptive_out_num);

	ftype errors;
	errors = 100 * ftype(validate(output, golden, X_adaptive_out_num)) / 512;

	if (errors != 0)
		printf("[FAIL] There are some errors QQ, error rate: %f%\n", errors);
	else
		printf("[PASS] Congratulation! All results are correct\n");

	// ==========================================================

	free(input);
	free(output);
	free(golden);

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
                            cout<<"[ERROR]  result["<<n+1<<"]["<<setw(2)<<c+1<<"]["<<setw(2)<<d+1<<"]["<<setw(2)<<h+1<<"]["<<setw(2)<<w+1<<"]: "<<setw(8)<<ourOutput[pos]<<", gold: "<<setw(8)<<golden[pos]<<", error: "<< 100*(ftype)(ourOutput[pos] - golden[pos]) / ourOutput[pos]<<"%"<<endl;
                            errors++;
                        }
                        else if(ourOutput[pos] != golden[pos] && (ftype)(ourOutput[pos] - golden[pos]) / golden[pos] >= 0.002 || (ftype)(ourOutput[pos] - golden[pos]) / golden[pos] <= -0.002){
                            cout<<"[ERROR]  result["<<n+1<<"]["<<setw(2)<<c+1<<"]["<<setw(2)<<d+1<<"]["<<setw(2)<<h+1<<"]["<<setw(2)<<w+1<<"]: "<<setw(8)<<ourOutput[pos]<<", gold: "<<setw(8)<<golden[pos]<<", error: "<< 100*(ftype)(ourOutput[pos] - golden[pos]) / golden[pos]<<"%"<<endl;
                            errors++;
                        }
					}
	return errors;
}

bool LoadDTYPE(string filename, dtype* arr, int size){
	std::ifstream file;
	ftype data = 0;

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

