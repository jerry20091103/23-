#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
#include <string>
#include <iomanip>
using namespace std;

int_t validate(dtype* ourOutput, dtype* golden, int_t* size);


//string kernel_dat_name[12] = {"layer1_1_weight.dat", "layer1_2_weight.dat", "layer1_3_weight.dat","layer1_4_weight.dat","layer1_5_weight.dat", "layer1_6_weight.dat","layer1_7_weight.dat", "layer1_8_weight.dat", "layer1_9_weight.dat", "layer1_10_weight.dat", "layer1_11_weight.dat", "layer1_12_weight.dat"};
string kernel_1_dat_name[8] = { "weight_1_1.dat", "weight_1_2.dat", "weight_1_3.dat","weight_1_4.dat","weight_1_5.dat", "weight_1_6.dat","weight_1_7.dat", "weight_1_8.dat" };
string kernel_2_dat_name[9] = { "weight_2_1.dat", "weight_2_2.dat", "weight_2_3.dat","weight_2_4.dat","weight_2_5.dat", "weight_2_6.dat","weight_2_7.dat", "weight_2_8.dat", "weight_2_9.dat" };
string kernel_3_dat_name[9] = { "weight_3_1.dat", "weight_3_2.dat", "weight_3_3.dat","weight_3_4.dat","weight_3_5.dat", "weight_3_6.dat","weight_3_7.dat", "weight_3_8.dat", "weight_3_9.dat" };
string kernel_4_dat_name[9] = { "weight_4_1.dat", "weight_4_2.dat", "weight_4_3.dat","weight_4_4.dat","weight_4_5.dat", "weight_4_6.dat","weight_4_7.dat", "weight_4_8.dat", "weight_4_9.dat" };

int_t main() {

	dtype *input = (dtype*)malloc(200704*sizeof(dtype));
	dtype *X_out_data = (dtype*)malloc(200704*sizeof(dtype));
	dtype *output = (dtype*)malloc(451584*sizeof(dtype));
	
	dtype *Kernel_1_1 = (dtype*)malloc(82944*sizeof(dtype));
	dtype *Kernel_1_3 = (dtype*)malloc(82944*sizeof(dtype));
	dtype *Kernel_1_5 = (dtype*)malloc(82944*sizeof(dtype));
	dtype *Kernel_1_7 = (dtype*)malloc(82944*sizeof(dtype));
	
	dtype *Kernel_1_2 = (dtype*)malloc(27648*sizeof(dtype));
	dtype *Kernel_1_4 = (dtype*)malloc(27648*sizeof(dtype));
	dtype *Kernel_1_6 = (dtype*)malloc(27648*sizeof(dtype));
	dtype *Kernel_1_8 = (dtype*)malloc(27648*sizeof(dtype));
	// kernel_size=(64, 144, 1, 3, 3),  kernel_size=(64, 144, 3, 1, 1)
	
	dtype *Kernel_2_1 = (dtype*)malloc(132480*sizeof(dtype));
	dtype *Kernel_2_2 = (dtype*)malloc(88320*sizeof(dtype));
	// kernel_size=(64, 230, 1, 3, 3), kernel_size=(128, 230, 3, 1, 1)
	dtype *Kernel_2_3 = (dtype*)malloc(264960*sizeof(dtype));
	dtype *Kernel_2_4 = (dtype*)malloc(88320*sizeof(dtype));
	// kernel_size=(128, 230, 1, 3, 3), kernel_size=(128, 230, 3, 1, 1)
	dtype *Kernel_2_5 = (dtype*)malloc(8192*sizeof(dtype));
	// kernel_size=(64, 128, 1, 1, 1)
	dtype *Kernel_2_6 = (dtype*)malloc(331776*sizeof(dtype));
	dtype *Kernel_2_8 = (dtype*)malloc(331776*sizeof(dtype));
	dtype *Kernel_2_7 = (dtype*)malloc(110592*sizeof(dtype));
	dtype *Kernel_2_9 = (dtype*)malloc(110592*sizeof(dtype));
	// kernel_size=(128, 288, 1, 3, 3),  kernel_size=(128, 288, 3, 1, 1)
	
	dtype *Kernel_3_1 = (dtype*)malloc(529920*sizeof(dtype));
	dtype *Kernel_3_2 = (dtype*)malloc(353280*sizeof(dtype));
	// kernel_size=(128, 460, 1, 3, 3), kernel_size=(256, 460, 3, 1, 1)
	dtype *Kernel_3_3 = (dtype*)malloc(1059840*sizeof(dtype));
	dtype *Kernel_3_4 = (dtype*)malloc(353280*sizeof(dtype));
	// kernel_size=(256, 460, 1, 3, 3), kernel_size=(256, 460, 3, 1, 1)
	dtype *Kernel_3_5 = (dtype*)malloc(32768*sizeof(dtype));
	// kernel_size=(128, 256, 1, 1, 1)
	dtype *Kernel_3_6 = (dtype*)malloc(1327104*sizeof(dtype));
	dtype *Kernel_3_8 = (dtype*)malloc(1327104*sizeof(dtype));
	dtype *Kernel_3_7 = (dtype*)malloc(442368*sizeof(dtype));
	dtype *Kernel_3_9 = (dtype*)malloc(442368*sizeof(dtype));
	// kernel_size=(256, 576, 1, 3, 3),  kernel_size=(256, 576, 3, 1, 1)
	
	dtype *Kernel_4_1 = (dtype*)malloc(2121984*sizeof(dtype));
	dtype *Kernel_4_2 = (dtype*)malloc(1414656*sizeof(dtype));
	// kernel_size=(256, 921, 1, 3, 3), kernel_size=(512, 921, 3, 1, 1)
	dtype *Kernel_4_3 = (dtype*)malloc(4243968*sizeof(dtype));
	dtype *Kernel_4_4 = (dtype*)malloc(1414656*sizeof(dtype));
	// kernel_size=(512, 921, 1, 3, 3), kernel_size=(512, 921, 3, 1, 1)
	dtype *Kernel_4_5 = (dtype*)malloc(131072*sizeof(dtype));
	// kernel4size=(256, 512, 1, 1, 1)
	dtype *Kernel_4_6 = (dtype*)malloc(5308416*sizeof(dtype));
	dtype *Kernel_4_8 = (dtype*)malloc(5308416*sizeof(dtype));
	dtype *Kernel_4_7 = (dtype*)malloc(1769472*sizeof(dtype));
	dtype *Kernel_4_9 = (dtype*)malloc(1769472*sizeof(dtype));
	// kernel_size=(512, 1152, 1, 3, 3),  kernel_size=(512, 1152, 3, 1, 1)

	FILE         *fp;
	std::ifstream file;
	dtype data = 0;

	// load input
	file.open("output_0.dat");
	for (int_t i = 0; i < 200704; i++) {
		file >> data;
		input[i] = data;
	}
	file.close();

	// load layer1 kernel
	for (int_t j = 1; j < 8; j += 2) {
		file.open(kernel_1_dat_name[j - 1]);
		for (int_t i = 0; i < 82944; i++) {
			file >> data;
			if (j == 1) Kernel_1_1[i] = data;
			else if (j == 3) Kernel_1_3[i] = data;
			else if (j == 5) Kernel_1_5[i] = data;
			else if (j == 7) Kernel_1_7[i] = data;
		}
		file.close();
	}
	for (int_t j = 2; j <= 8; j += 2) {
		file.open(kernel_1_dat_name[j - 1]);
		for (int_t i = 0; i < 27648; i++) {
			file >> data;
			if (j == 2) Kernel_1_2[i] = data;
			else if (j == 4) Kernel_1_4[i] = data;
			else if (j == 6) Kernel_1_6[i] = data;
			else if (j == 8) Kernel_1_8[i] = data;
		}
		file.close();
	}

	//// load layer2 kernel
	file.open(kernel_2_dat_name[0]);
	for (int_t i = 0; i < 132480; i++) {
		file >> data;
		Kernel_2_1[i] = data;
	}
	file.close();
	file.open(kernel_2_dat_name[1]);
	for (int_t i = 0; i < 88320; i++) {
		file >> data;
		Kernel_2_2[i] = data;
	}
	file.close();
	file.open(kernel_2_dat_name[2]);
	for (int_t i = 0; i < 264960; i++) {
		file >> data;
		Kernel_2_3[i] = data;
	}
	file.close();
	file.open(kernel_2_dat_name[3]);
	for (int_t i = 0; i < 88320; i++) {
		file >> data;
		Kernel_2_4[i] = data;
	}
	file.close();
	file.open(kernel_2_dat_name[4]);
	for (int_t i = 0; i < 8192; i++) {
		file >> data;
		Kernel_2_5[i] = data;
	}
	file.close();
	file.open(kernel_2_dat_name[5]);
	for (int_t i = 0; i < 331776; i++) {
		file >> data;
		Kernel_2_6[i] = data;
	}
	file.close();
	file.open(kernel_2_dat_name[6]);
	for (int_t i = 0; i < 110592; i++) {
		file >> data;
		Kernel_2_7[i] = data;
	}
	file.close();
	file.open(kernel_2_dat_name[7]);
	for (int_t i = 0; i < 331776; i++) {
		file >> data;
		Kernel_2_8[i] = data;
	}
	file.close();
	file.open(kernel_2_dat_name[8]);
	for (int_t i = 0; i < 110592; i++) {
		file >> data;
		Kernel_2_9[i] = data;
	}
	file.close();

	//// load layer3 kernel
	file.open(kernel_3_dat_name[0]);
	for (int_t i = 0; i < 529920; i++) {
		file >> data;
		Kernel_3_1[i] = data;
	}
	file.close();
	file.open(kernel_3_dat_name[1]);
	for (int_t i = 0; i < 353280; i++) {
		file >> data;
		Kernel_3_2[i] = data;
	}
	file.close();
	file.open(kernel_3_dat_name[2]);
	for (int_t i = 0; i < 1059840; i++) {
		file >> data;
		Kernel_3_3[i] = data;
	}
	file.close();
	file.open(kernel_3_dat_name[3]);
	for (int_t i = 0; i < 353280; i++) {
		file >> data;
		Kernel_3_4[i] = data;
	}
	file.close();
	file.open(kernel_3_dat_name[4]);
	for (int_t i = 0; i < 32768; i++) {
		file >> data;
		Kernel_3_5[i] = data;
	}
	file.close();
	file.open(kernel_3_dat_name[5]);
	for (int_t i = 0; i < 1327104; i++) {
		file >> data;
		Kernel_3_6[i] = data;
	}
	file.close();
	file.open(kernel_3_dat_name[6]);
	for (int_t i = 0; i < 442368; i++) {
		file >> data;
		Kernel_3_7[i] = data;
	}
	file.close();
	file.open(kernel_3_dat_name[7]);
	for (int_t i = 0; i < 1327104; i++) {
		file >> data;
		Kernel_3_8[i] = data;
	}
	file.close();
	file.open(kernel_3_dat_name[8]);
	for (int_t i = 0; i < 442368; i++) {
		file >> data;
		Kernel_3_9[i] = data;
	}
	file.close();

	//// load layer4 kernel
	file.open(kernel_4_dat_name[0]);
	for (int_t i = 0; i < 2121984; i++) {
		file >> data;
		Kernel_4_1[i] = data;
	}
	file.close();
	file.open(kernel_4_dat_name[1]);
	for (int_t i = 0; i < 1414656; i++) {
		file >> data;
		Kernel_4_2[i] = data;
	}
	file.close();
	file.open(kernel_4_dat_name[2]);
	for (int_t i = 0; i < 4243968; i++) {
		file >> data;
		Kernel_4_3[i] = data;
	}
	file.close();
	file.open(kernel_4_dat_name[3]);
	for (int_t i = 0; i < 1414656; i++) {
		file >> data;
		Kernel_4_4[i] = data;
	}
	file.close();
	file.open(kernel_4_dat_name[4]);
	for (int_t i = 0; i < 131072; i++) {
		file >> data;
		Kernel_4_5[i] = data;
	}
	file.close();
	file.open(kernel_4_dat_name[5]);
	for (int_t i = 0; i < 5308416; i++) {
		file >> data;
		Kernel_4_6[i] = data;
	}
	file.close();
	file.open(kernel_4_dat_name[6]);
	for (int_t i = 0; i < 1769472; i++) {
		file >> data;
		Kernel_4_7[i] = data;
	}
	file.close();
	file.open(kernel_4_dat_name[7]);
	for (int_t i = 0; i < 5308416; i++) {
		file >> data;
		Kernel_4_8[i] = data;
	}
	file.close();
	file.open(kernel_4_dat_name[8]);
	for (int_t i = 0; i < 1769472; i++) {
		file >> data;
		Kernel_4_9[i] = data;
	}
	file.close();

	// load output
	file.open("output_4.dat");
	for (int_t i = 0; i < 25088; i++) {
		file >> data;
		output[i] = data;
	}
	file.close();

	// ====================================

	Sequential(input, X_out_data, Kernel_1_1, Kernel_1_2, Kernel_1_3, Kernel_1_4, Kernel_1_5, Kernel_1_6, Kernel_1_7, Kernel_1_8,
		Kernel_2_1, Kernel_2_2, Kernel_2_3, Kernel_2_4, Kernel_2_5, Kernel_2_6, Kernel_2_7, Kernel_2_8, Kernel_2_9,
		Kernel_3_1, Kernel_3_2, Kernel_3_3, Kernel_3_4, Kernel_3_5, Kernel_3_6, Kernel_3_7, Kernel_3_8, Kernel_3_9,
		Kernel_4_1, Kernel_4_2, Kernel_4_3, Kernel_4_4, Kernel_4_5, Kernel_4_6, Kernel_4_7, Kernel_4_8, Kernel_4_9);

	// calculate errors
	dtype errors;
	int_t X_num[5] = { 1, 512, 1, 7, 7 };
	errors = 100 * dtype(validate(X_out_data, output, X_num)) / 25088;

	if (errors != 0)
		printf("[FAIL] There are some errors QQ, error rate: %f%\n", errors);
	else
		printf("[PASS] Congratulation! All results are correct\n");

	free(input);
	free(X_out_data);
	free(output);

	free(Kernel_1_1);
	free(Kernel_1_3);
	free(Kernel_1_5);
	free(Kernel_1_7);
	free(Kernel_1_2);
	free(Kernel_1_4);
	free(Kernel_1_6);
	free(Kernel_1_8);

	free(Kernel_2_1);
	free(Kernel_2_2);
	free(Kernel_2_3);
	free(Kernel_2_4);
	free(Kernel_2_5);
	free(Kernel_2_6);
	free(Kernel_2_8);
	free(Kernel_2_7);
	free(Kernel_2_9);

	free(Kernel_3_1);
	free(Kernel_3_2);
	free(Kernel_3_3);
	free(Kernel_3_4);
	free(Kernel_3_5);
	free(Kernel_3_6);
	free(Kernel_3_8);
	free(Kernel_3_7);
	free(Kernel_3_9);
	
	free(Kernel_4_1);
	free(Kernel_4_2);
	free(Kernel_4_3);
	free(Kernel_4_4);
	free(Kernel_4_5);
	free(Kernel_4_6);
	free(Kernel_4_8);
	free(Kernel_4_7);
	free(Kernel_4_9);

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
						if (ourOutput[pos] != golden[pos] && ((ourOutput[pos] - golden[pos]) / golden[pos] >= 0.005 || (ourOutput[pos] - golden[pos]) / golden[pos] <= -0.005)) {
							cout << "[ERROR]  result[" << n << "][" << setw(2) << c << "][" << d << "][" << setw(2) << h << "][" << setw(2) << w << "]: " << setw(13) << ourOutput[pos] << ", gold: " << setw(10) << golden[pos] << ", error: " << 100 * (ourOutput[pos] - golden[pos]) / golden[pos] << "%" << endl;
							errors++;
						}
					}
	return errors;
}
