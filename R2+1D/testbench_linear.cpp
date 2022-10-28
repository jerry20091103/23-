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

	dtype *input = (dtype*)malloc(512 * sizeof(dtype));
	dtype *output = (dtype*)malloc(400 * sizeof(dtype));
	dtype *golden = (dtype*)malloc(400 * sizeof(dtype));
	dtype *kernel = (dtype*)malloc(204800 * sizeof(dtype));

	int_t errors, total_errors = 0;

	// ==========================================================
	// Linear
	int_t X_linear_in_num[5] = { 1, 512, 1, 1, 1 };
	int_t X_linear_out_num[5] = { 1, 400, 1, 1, 1 };
	cout << "==> Linear\n";
	file.open("output_avg.dat");
	if (!file.is_open()) {
		cout << "output_avg.dat not found!" << endl;
		return 0;
	}
	for (int_t i = 0; i < 512; i++) {
		file >> data;
		input[i] = data;
	}
	file.close();

	file.open("weight_6.dat");
	if (!file.is_open()) {
		cout << "weight_6.dat not found!" << endl;
		return 0;
	}
	for (int_t i = 0; i < 204800; i++) {
		file >> data;
		kernel[i] = data;
	}
	file.close();

	Linear(input, X_linear_in_num, output, X_linear_out_num, kernel);

	file.open("output_fc.dat");
	if (!file.is_open()) {
		cout << "output_fc.dat not found!" << endl;
		return 0;
	}
	for (int_t i = 0; i < 400; i++) {
		file >> data;
		golden[i] = data;
	}
	file.close();
	errors = validate(output, golden, X_linear_out_num);
	total_errors += errors;

	// ==========================================================

	free(input);
	free(output);
	free(golden);
	free(kernel);

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

