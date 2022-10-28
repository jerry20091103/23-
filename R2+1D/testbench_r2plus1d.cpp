#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
#include <string>
#include <iomanip>
using namespace std;

int_t validate(dtype* ourOutput, dtype* golden, int_t* size);
bool LoadFile(string filename, double* arr, int size);
bool LoadDouble(string filename, double* arr, int size);

string kernel_1_dat_name[8] = {"layer1.0.conv1.0.0.weight.dat", "layer1.0.conv1.0.3.weight.dat", "layer1.0.conv2.0.0.weight.dat", "layer1.0.conv2.0.3.weight.dat", "layer1.1.conv1.0.0.weight.dat", "layer1.1.conv1.0.3.weight.dat", "layer1.1.conv2.0.0.weight.dat", "layer1.1.conv2.0.3.weight.dat"};
string kernel_2_dat_name[9] = {"layer2.0.conv1.0.0.weight.dat", "layer2.0.conv1.0.3.weight.dat", "layer2.0.conv2.0.0.weight.dat", "layer2.0.conv2.0.3.weight.dat", "layer2.0.downsample.0.weight.dat", "layer2.1.conv1.0.0.weight.dat", "layer2.1.conv1.0.3.weight.dat", "layer2.1.conv2.0.0.weight.dat", "layer2.1.conv2.0.3.weight.dat"};
string kernel_3_dat_name[9] = {"layer3.0.conv1.0.0.weight.dat", "layer3.0.conv1.0.3.weight.dat", "layer3.0.conv2.0.0.weight.dat", "layer3.0.conv2.0.3.weight.dat", "layer3.0.downsample.0.weight.dat", "layer3.1.conv1.0.0.weight.dat", "layer3.1.conv1.0.3.weight.dat", "layer3.1.conv2.0.0.weight.dat", "layer3.1.conv2.0.3.weight.dat"};
string kernel_4_dat_name[9] = {"layer4.0.conv1.0.0.weight.dat", "layer4.0.conv1.0.3.weight.dat", "layer4.0.conv2.0.0.weight.dat", "layer4.0.conv2.0.3.weight.dat", "layer4.0.downsample.0.weight.dat", "layer4.1.conv1.0.0.weight.dat", "layer4.1.conv1.0.3.weight.dat", "layer4.1.conv2.0.0.weight.dat", "layer4.1.conv2.0.3.weight.dat"};

string stem_mu_dat_name[2] = {"stem.1.running_mean.dat", "stem.4.running_mean.dat"};
string layer_1_mu_dat_name[8] = {"layer1.0.conv1.0.1.running.mean.dat",  "layer1.0.conv1.1.running.mean.dat",  "layer1.0.conv2.0.1.running.mean.dat",  "layer1.0.conv2.1.running.mean.dat",  "layer1.1.conv1.0.1.running.mean.dat",  "layer1.1.conv1.1.running.mean.dat",  "layer1.1.conv2.0.1.running.mean.dat",  "layer1.1.conv2.1.running.mean.dat"};
string layer_2_mu_dat_name[9] = {"layer2.0.conv1.0.1.running.mean.dat",  "layer2.0.conv1.1.running.mean.dat",  "layer2.0.conv2.0.1.running.mean.dat",  "layer2.0.conv2.1.running.mean.dat",  "layer2.0.downsample.1.running.mean.dat",  "layer2.1.conv1.0.1.running.mean.dat",  "layer2.1.conv1.1.running.mean.dat",  "layer2.1.conv2.0.1.running.mean.dat",  "layer2.1.conv2.1.running.mean.dat"};
string layer_3_mu_dat_name[9] = {"layer3.0.conv1.0.1.running.mean.dat",  "layer3.0.conv1.1.running.mean.dat",  "layer3.0.conv2.0.1.running.mean.dat",  "layer3.0.conv2.1.running.mean.dat",  "layer3.0.downsample.1.running.mean.dat",  "layer3.1.conv1.0.1.running.mean.dat",  "layer3.1.conv1.1.running.mean.dat",  "layer3.1.conv2.0.1.running.mean.dat",  "layer3.1.conv2.1.running.mean.dat"};
string layer_4_mu_dat_name[9] = {"layer4.0.conv1.0.1.running.mean.dat",  "layer4.0.conv1.1.running.mean.dat",  "layer4.0.conv2.0.1.running.mean.dat",  "layer4.0.conv2.1.running.mean.dat",  "layer4.0.downsample.1.running.mean.dat",  "layer4.1.conv1.0.1.running.mean.dat",  "layer4.1.conv1.1.running.mean.dat",  "layer4.1.conv2.0.1.running.mean.dat",  "layer4.1.conv2.1.running.mean.dat"};

string stem_var_dat_name[2] = {"stem.1.running_var.dat", "stem.4.running_var.dat"};
string layer_1_var_dat_name[8] = {"layer1.0.conv1.0.1.running_var.dat",  "layer1.0.conv1.1.running_var.dat",  "layer1.0.conv2.0.1.running_var.dat",  "layer1.0.conv2.1.running_var.dat",  "layer1.1.conv1.0.1.running_var.dat",  "layer1.1.conv1.1.running_var.dat",  "layer1.1.conv2.0.1.running_var.dat",  "layer1.1.conv2.1.running_var.dat"};
string layer_2_var_dat_name[9] = {"layer2.0.conv1.0.1.running_var.dat",  "layer2.0.conv1.1.running_var.dat",  "layer2.0.conv2.0.1.running_var.dat",  "layer2.0.conv2.1.running_var.dat",  "layer2.0.downsample.1.running_var.dat",  "layer2.1.conv1.0.1.running_var.dat",  "layer2.1.conv1.1.running_var.dat",  "layer2.1.conv2.0.1.running_var.dat",  "layer2.1.conv2.1.running_var.dat"};
string layer_3_var_dat_name[9] = {"layer3.0.conv1.0.1.running_var.dat",  "layer3.0.conv1.1.running_var.dat",  "layer3.0.conv2.0.1.running_var.dat",  "layer3.0.conv2.1.running_var.dat",  "layer3.0.downsample.1.running_var.dat",  "layer3.1.conv1.0.1.running_var.dat",  "layer3.1.conv1.1.running_var.dat",  "layer3.1.conv2.0.1.running_var.dat",  "layer3.1.conv2.1.running_var.dat"};
string layer_4_var_dat_name[9] = {"layer4.0.conv1.0.1.running_var.dat",  "layer4.0.conv1.1.running_var.dat",  "layer4.0.conv2.0.1.running_var.dat",  "layer4.0.conv2.1.running_var.dat",  "layer4.0.downsample.1.running_var.dat",  "layer4.1.conv1.0.1.running_var.dat",  "layer4.1.conv1.1.running_var.dat",  "layer4.1.conv2.0.1.running_var.dat",  "layer4.1.conv2.1.running_var.dat"};

string stem_gamma_dat_name[2] = {"stem.1.weight.dat", "stem.4.weight.dat"};
string layer_1_gamma_dat_name[8] = {"layer1.0.conv1.0.1.weight.dat", "layer1.0.conv1.1.weight.dat", "layer1.0.conv2.0.1.weight.dat", "layer1.0.conv2.1.weight.dat", "layer1.1.conv1.0.1.weight.dat", "layer1.1.conv1.1.weight.dat", "layer1.1.conv2.0.1.weight.dat", "layer1.1.conv2.1.weight.dat"};
string layer_2_gamma_dat_name[9] = {"layer2.0.conv1.0.1.weight.dat",  "layer2.0.conv1.1.weight.dat",  "layer2.0.conv2.0.1.weight.dat",  "layer2.0.conv2.1.weight.dat",  "layer2.0.downsample.1.weight.dat",  "layer2.1.conv1.0.1.weight.dat",  "layer2.1.conv1.1.weight.dat",  "layer2.1.conv2.0.1.weight.dat",  "layer2.1.conv2.1.weight.dat"};
string layer_3_gamma_dat_name[9] = {"layer3.0.conv1.0.1.weight.dat",  "layer3.0.conv1.1.weight.dat",  "layer3.0.conv2.0.1.weight.dat",  "layer3.0.conv2.1.weight.dat",  "layer3.0.downsample.1.weight.dat",  "layer3.1.conv1.0.1.weight.dat",  "layer3.1.conv1.1.weight.dat",  "layer3.1.conv2.0.1.weight.dat",  "layer3.1.conv2.1.weight.dat"};
string layer_4_gamma_dat_name[9] = {"layer4.0.conv1.0.1.weight.dat",  "layer4.0.conv1.1.weight.dat",  "layer4.0.conv2.0.1.weight.dat",  "layer4.0.conv2.1.weight.dat",  "layer4.0.downsample.1.weight.dat",  "layer4.1.conv1.0.1.weight.dat",  "layer4.1.conv1.1.weight.dat",  "layer4.1.conv2.0.1.weight.dat",  "layer4.1.conv2.1.weight.dat"};

string stem_bias_dat_name[2] = {"stem.1.bias.dat", "stem.4.bias.dat"};
string layer_1_bias_dat_name[8] = {"layer1.0.conv1.0.1.bias.dat", "layer1.0.conv1.1.bias.dat", "layer1.0.conv2.0.1.bias.dat", "layer1.0.conv2.1.bias.dat", "layer1.1.conv1.0.1.bias.dat", "layer1.1.conv1.1.bias.dat", "layer1.1.conv2.0.1.bias.dat", "layer1.1.conv2.1.bias.dat"};
string layer_2_bias_dat_name[9] = {"layer2.0.conv1.0.1.bias.dat",  "layer2.0.conv1.1.bias.dat",  "layer2.0.conv2.0.1.bias.dat",  "layer2.0.conv2.1.bias.dat",  "layer2.0.downsample.1.bias.dat",  "layer2.1.conv1.0.1.bias.dat",  "layer2.1.conv1.1.bias.dat",  "layer2.1.conv2.0.1.bias.dat",  "layer2.1.conv2.1.bias.dat"};
string layer_3_bias_dat_name[9] = {"layer3.0.conv1.0.1.bias.dat",  "layer3.0.conv1.1.bias.dat",  "layer3.0.conv2.0.1.bias.dat",  "layer3.0.conv2.1.bias.dat",  "layer3.0.downsample.1.bias.dat",  "layer3.1.conv1.0.1.bias.dat",  "layer3.1.conv1.1.bias.dat",  "layer3.1.conv2.0.1.bias.dat",  "layer3.1.conv2.1.bias.dat"};
string layer_4_bias_dat_name[9] = {"layer4.0.conv1.0.1.bias.dat",  "layer4.0.conv1.1.bias.dat",  "layer4.0.conv2.0.1.bias.dat",  "layer4.0.conv2.1.bias.dat",  "layer4.0.downsample.1.bias.dat",  "layer4.1.conv1.0.1.bias.dat",  "layer4.1.conv1.1.bias.dat",  "layer4.1.conv2.0.1.bias.dat",  "layer4.1.conv2.1.bias.dat"};

string fc_dat_name[1] = {"fc.1.weight.dat"};
	



int_t main() {

	dtype *input = (dtype*)malloc(36963 * sizeof(dtype));
	dtype *output = (dtype*)malloc(25088 * sizeof(dtype));
	dtype *output_golden = (dtype*)malloc(25088 * sizeof(dtype));

	dtype *kernel_stem_1 = (dtype*)malloc(6615 * sizeof(dtype));
	dtype *kernel_stem_2 = (dtype*)malloc(8640 * sizeof(dtype));

	dtype *Kernel_1_1 = (dtype*)malloc(82944 * sizeof(dtype));
	dtype *Kernel_1_3 = (dtype*)malloc(82944 * sizeof(dtype));
	dtype *Kernel_1_5 = (dtype*)malloc(82944 * sizeof(dtype));
	dtype *Kernel_1_7 = (dtype*)malloc(82944 * sizeof(dtype));

	dtype *Kernel_1_2 = (dtype*)malloc(27648 * sizeof(dtype));
	dtype *Kernel_1_4 = (dtype*)malloc(27648 * sizeof(dtype));
	dtype *Kernel_1_6 = (dtype*)malloc(27648 * sizeof(dtype));
	dtype *Kernel_1_8 = (dtype*)malloc(27648 * sizeof(dtype));
	// kernel_size=(64, 144, 1, 3, 3),  kernel_size=(64, 144, 3, 1, 1)

	dtype *Kernel_2_1 = (dtype*)malloc(132480 * sizeof(dtype));
	dtype *Kernel_2_2 = (dtype*)malloc(88320 * sizeof(dtype));
	// kernel_size=(64, 230, 1, 3, 3), kernel_size=(128, 230, 3, 1, 1)
	dtype *Kernel_2_3 = (dtype*)malloc(264960 * sizeof(dtype));
	dtype *Kernel_2_4 = (dtype*)malloc(88320 * sizeof(dtype));
	// kernel_size=(128, 230, 1, 3, 3), kernel_size=(128, 230, 3, 1, 1)
	dtype *Kernel_2_5 = (dtype*)malloc(8192 * sizeof(dtype));
	// kernel_size=(64, 128, 1, 1, 1)
	dtype *Kernel_2_6 = (dtype*)malloc(331776 * sizeof(dtype));
	dtype *Kernel_2_8 = (dtype*)malloc(331776 * sizeof(dtype));
	dtype *Kernel_2_7 = (dtype*)malloc(110592 * sizeof(dtype));
	dtype *Kernel_2_9 = (dtype*)malloc(110592 * sizeof(dtype));
	// kernel_size=(128, 288, 1, 3, 3),  kernel_size=(128, 288, 3, 1, 1)

	dtype *Kernel_3_1 = (dtype*)malloc(529920 * sizeof(dtype));
	dtype *Kernel_3_2 = (dtype*)malloc(353280 * sizeof(dtype));
	// kernel_size=(128, 460, 1, 3, 3), kernel_size=(256, 460, 3, 1, 1)
	dtype *Kernel_3_3 = (dtype*)malloc(1059840 * sizeof(dtype));
	dtype *Kernel_3_4 = (dtype*)malloc(353280 * sizeof(dtype));
	// kernel_size=(256, 460, 1, 3, 3), kernel_size=(256, 460, 3, 1, 1)
	dtype *Kernel_3_5 = (dtype*)malloc(32768 * sizeof(dtype));
	// kernel_size=(128, 256, 1, 1, 1)
	dtype *Kernel_3_6 = (dtype*)malloc(1327104 * sizeof(dtype));
	dtype *Kernel_3_8 = (dtype*)malloc(1327104 * sizeof(dtype));
	dtype *Kernel_3_7 = (dtype*)malloc(442368 * sizeof(dtype));
	dtype *Kernel_3_9 = (dtype*)malloc(442368 * sizeof(dtype));
	// kernel_size=(256, 576, 1, 3, 3),  kernel_size=(256, 576, 3, 1, 1)

	dtype *Kernel_4_1 = (dtype*)malloc(2121984 * sizeof(dtype));
	dtype *Kernel_4_2 = (dtype*)malloc(1414656 * sizeof(dtype));
	// kernel_size=(256, 921, 1, 3, 3), kernel_size=(512, 921, 3, 1, 1)
	dtype *Kernel_4_3 = (dtype*)malloc(4243968 * sizeof(dtype));
	dtype *Kernel_4_4 = (dtype*)malloc(1414656 * sizeof(dtype));
	// kernel_size=(512, 921, 1, 3, 3), kernel_size=(512, 921, 3, 1, 1)
	dtype *Kernel_4_5 = (dtype*)malloc(131072 * sizeof(dtype));
	// kernel4size=(256, 512, 1, 1, 1)
	dtype *Kernel_4_6 = (dtype*)malloc(5308416 * sizeof(dtype));
	dtype *Kernel_4_8 = (dtype*)malloc(5308416 * sizeof(dtype));
	dtype *Kernel_4_7 = (dtype*)malloc(1769472 * sizeof(dtype));
	dtype *Kernel_4_9 = (dtype*)malloc(1769472 * sizeof(dtype));
	// kernel_size=(512, 1152, 1, 3, 3),  kernel_size=(512, 1152, 3, 1, 1)

	// load input
	if(!LoadDTYPE("input.dat", input, 602112))
		return 0;

	// load stem kernel
	if(!LoadDTYPE("stem.0.weight.dat", kernel_stem_1, 6615)) return 0;
	if(!LoadDTYPE("stem.3.weight.dat", kernel_stem_2, 8640)) return 0;

	// load layer1 kernel
	if(!LoadDTYPE(kernel_1_dat_name[0], Kernel_1_1, 82944)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[2], Kernel_1_3, 82944)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[4], Kernel_1_5, 82944)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[6], Kernel_1_7, 82944)) return 0;

	if(!LoadDTYPE(kernel_1_dat_name[1], Kernel_1_2, 27648)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[3], Kernel_1_4, 27648)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[5], Kernel_1_6, 27648)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[7], Kernel_1_8, 27648)) return 0;

	// load layer2 kernel
	if(!LoadDTYPE(kernel_2_dat_name[0], Kernel_2_1, 132480)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[1], Kernel_2_2, 88320)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[2], Kernel_2_3, 264960)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[3], Kernel_2_4, 88320)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[4], Kernel_2_5, 8192)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[5], Kernel_2_6, 331776)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[6], Kernel_2_7, 110592)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[7], Kernel_2_8, 331776)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[8], Kernel_2_9, 110592)) return 0;

	// load layer3 kernel
	if(!LoadDTYPE(kernel_3_dat_name[0], Kernel_3_1, 529920)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[1], Kernel_3_2, 353280)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[2], Kernel_3_3, 1059840)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[3], Kernel_3_4, 353280)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[4], Kernel_3_5, 32768)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[5], Kernel_3_6, 1327104)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[6], Kernel_3_7, 442368)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[7], Kernel_3_8, 1327104)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[8], Kernel_3_9, 442368)) return 0;

	// load layer4 kernel
	if(!LoadDTYPE(kernel_4_dat_name[0], Kernel_4_1, 2121984)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[1], Kernel_4_2, 1414656)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[2], Kernel_4_3, 4243968)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[3], Kernel_4_4, 1414656)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[4], Kernel_4_5, 131072)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[5], Kernel_4_6, 5308416)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[6], Kernel_4_7, 1769472)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[7], Kernel_4_8, 5308416)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[8], Kernel_4_9, 1769472)) return 0;
	
	// load output
	file.open("output_4.dat");
	for (int_t i = 0; i < 25088; i++) {
		file >> data;
		output_golden[i] = data;
	}
	file.close();

	// ====================================
	// Function to test here:

	r2plus1d(input, output, kernel_stem_1, kernel_stem_2,
		Kernel_1_1, Kernel_1_2, Kernel_1_3, Kernel_1_4, Kernel_1_5, Kernel_1_6, Kernel_1_7, Kernel_1_8,
		Kernel_2_1, Kernel_2_2, Kernel_2_3, Kernel_2_4, Kernel_2_5, Kernel_2_6, Kernel_2_7, Kernel_2_8, Kernel_2_9,
		Kernel_3_1, Kernel_3_2, Kernel_3_3, Kernel_3_4, Kernel_3_5, Kernel_3_6, Kernel_3_7, Kernel_3_8, Kernel_3_9,
		Kernel_4_1, Kernel_4_2, Kernel_4_3, Kernel_4_4, Kernel_4_5, Kernel_4_6, Kernel_4_7, Kernel_4_8, Kernel_4_9);

	// calculate errors
	float errors;
	int_t X_num[5] = { 1, 512, 1, 7, 7 };
	errors = 100 * float(validate(output, output_golden, X_num)) / 25088;

	if (errors != 0)
		printf("[FAIL] There are some errors QQ, error rate: %f%\n", errors);
	else
		printf("[PASS] Congratulation! All results are correct\n");

	free(input);
	free(output_golden);
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