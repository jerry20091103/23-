#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
#include <string>
#include <iomanip>
using namespace std;

int_t validate(dtype* ourOutput, dtype* golden, int_t* size);

int_t main()
{
	FILE         *fp;
	std::ifstream file;
	dtype data = 0;

	dtype *X_out_data = (dtype*)malloc(200704 * sizeof(dtype));
	dtype *output = (dtype*)malloc(200704 * sizeof(dtype));

	int_t errors, total_errors = 0;

	// ==========================================================
	// BatchNorm3d1
	int_t X_out_num_1[5] = { 1, 45, 1, 56, 56 };
	cout << "==> BatchNorm3d1\n";
	file.open("A.dat");
	if (!file.is_open()) {
		cout << "A.dat not found!" << endl;
		return 0;
	}
	for (int_t i = 0; i < 141120; i++) {
		file >> data;
		X_out_data[i] = data;
	}
	file.close();
	BatchNorm3d(X_out_data, X_out_num_1, 0.00001, 1, 0);

	file.open("B.dat");
	if (!file.is_open()) {
		cout << "B.dat not found!" << endl;
		return 0;
	}
	for (int_t i = 0; i < 141120; i++) {
		file >> data;
		output[i] = data;
	}
	file.close();
	errors = validate(X_out_data, output, X_out_num_1);
	total_errors += errors;

	// ==========================================================
	// BatchNorm3d2
	int_t X_out_num_2[5] = {1, 64, 1, 56, 56};
	cout << "==> BatchNorm3d2\n";
	file.open("Conv3d2output.dat");
	if (!file.is_open()) {
		cout << "Conv3d2output.dat not found!" << endl;
		return 0;
	}
	for(int_t i = 0; i < 200704; i++){
	    file >> data;
	    X_out_data[i] = data;
	}
	file.close();
	BatchNorm3d(X_out_data, X_out_num_2, 0.00001, 1, 0);

	file.open("BatchNorm3d2output.dat");
	if (!file.is_open()) {
		cout << "BatchNorm3d2output.dat not found!" << endl;
		return 0;
	}
	for(int_t i = 0; i < 200704; i++){
	    file >> data;
	    output[i] = data;
	}
	file.close();
	errors = validate(X_out_data, output, X_out_num_2);
	total_errors += errors;

	free(X_out_data);
	free(output);

	cout << "\n\n=======================================\n";
	cout << "==> Total\n";
	if (total_errors)
		printf("[FAIL] There are some errors QQ\n");
	else
		printf("[PASS] Congratulation! All results are correct\n");
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
						if (ourOutput[pos] != golden[pos] && ((ourOutput[pos] - golden[pos]) / golden[pos] >= 0.002 || (ourOutput[pos] - golden[pos]) / golden[pos] <= -0.002)) {
							cout << "[ERROR]  result[" << n << "][" << setw(2) << c << "][" << d << "][" << setw(2) << h << "][" << setw(2) << w << "]: " << setw(13) << ourOutput[pos] << ", gold: " << setw(10) << golden[pos] << ", error: " << 100 * (ourOutput[pos] - golden[pos]) / golden[pos] << "%" << endl;
							errors++;
						}
					}
	if (errors)
		printf("[FAIL] There are some errors QQ\n");
	else
		printf("[PASS] Congratulation! All results are correct\n");
	return errors;
}

