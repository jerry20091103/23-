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

double Mu_stem_1[45], Var_stem_1[45], Gamma_stem_1[45], Bias_stem_1[45];
double Mu_stem_4[64], Var_stem_4[64], Gamma_stem_4[64], Bias_stem_4[64];

double Mu_seq1_0_conv1_0_1[144], Mu_seq1_0_conv1_1[64], Mu_seq1_0_conv2_0_1[144], Mu_seq1_0_conv2_1[64], Mu_seq1_1_conv1_0_1[144], Mu_seq1_1_conv1_1[64], Mu_seq1_1_conv2_0_1[144], Mu_seq1_1_conv2_1[64];
double Var_seq1_0_conv1_0_1[144], Var_seq1_0_conv1_1[64], Var_seq1_0_conv2_0_1[144], Var_seq1_0_conv2_1[64], Var_seq1_1_conv1_0_1[144], Var_seq1_1_conv1_1[64], Var_seq1_1_conv2_0_1[144], Var_seq1_1_conv2_1[64];
double Gamma_seq1_0_conv1_0_1[144], Gamma_seq1_0_conv1_1[64], Gamma_seq1_0_conv2_0_1[144], Gamma_seq1_0_conv2_1[64], Gamma_seq1_1_conv1_0_1[144], Gamma_seq1_1_conv1_1[64], Gamma_seq1_1_conv2_0_1[144], Gamma_seq1_1_conv2_1[64];
double Bias_seq1_0_conv1_0_1[144], Bias_seq1_0_conv1_1[64], Bias_seq1_0_conv2_0_1[144], Bias_seq1_0_conv2_1[64], Bias_seq1_1_conv1_0_1[144], Bias_seq1_1_conv1_1[64], Bias_seq1_1_conv2_0_1[144], Bias_seq1_1_conv2_1[64];

double Mu_seq2_0_conv1_0_1[230], Mu_seq2_0_conv1_1[128], Mu_seq2_0_conv2_0_1[230], Mu_seq2_0_conv2_1[128], Mu_seq2_0_downsample_1[128], Mu_seq2_1_conv1_0_1[288], Mu_seq2_1_conv1_1[128], Mu_seq2_1_conv2_0_1[288], Mu_seq2_1_conv2_1[128];
double Var_seq2_0_conv1_0_1[230], Var_seq2_0_conv1_1[128], Var_seq2_0_conv2_0_1[230], Var_seq2_0_conv2_1[128], Var_seq2_0_downsample_1[128], Var_seq2_1_conv1_0_1[288], Var_seq2_1_conv1_1[128], Var_seq2_1_conv2_0_1[288], Var_seq2_1_conv2_1[128];
double Gamma_seq2_0_conv1_0_1[230], Gamma_seq2_0_conv1_1[128], Gamma_seq2_0_conv2_0_1[230], Gamma_seq2_0_conv2_1[128], Gamma_seq2_0_downsample_1[128], Gamma_seq2_1_conv1_0_1[288], Gamma_seq2_1_conv1_1[128], Gamma_seq2_1_conv2_0_1[288], Gamma_seq2_1_conv2_1[128];
double Bias_seq2_0_conv1_0_1[230], Bias_seq2_0_conv1_1[128], Bias_seq2_0_conv2_0_1[230], Bias_seq2_0_conv2_1[128], Bias_seq2_0_downsample_1[128], Bias_seq2_1_conv1_0_1[288], Bias_seq2_1_conv1_1[128], Bias_seq2_1_conv2_0_1[288], Bias_seq2_1_conv2_1[128];

double Mu_seq3_0_conv1_0_1[460], Mu_seq3_0_conv1_1[256], Mu_seq3_0_conv2_0_1[460], Mu_seq3_0_conv2_1[256], Mu_seq3_0_downsample_1[256], Mu_seq3_1_conv1_0_1[576], Mu_seq3_1_conv1_1[256], Mu_seq3_1_conv2_0_1[576], Mu_seq3_1_conv2_1[256];
double Var_seq3_0_conv1_0_1[460], Var_seq3_0_conv1_1[256], Var_seq3_0_conv2_0_1[460], Var_seq3_0_conv2_1[256], Var_seq3_0_downsample_1[256], Var_seq3_1_conv1_0_1[576], Var_seq3_1_conv1_1[256], Var_seq3_1_conv2_0_1[576], Var_seq3_1_conv2_1[256];
double Gamma_seq3_0_conv1_0_1[460], Gamma_seq3_0_conv1_1[256], Gamma_seq3_0_conv2_0_1[460], Gamma_seq3_0_conv2_1[256], Gamma_seq3_0_downsample_1[256], Gamma_seq3_1_conv1_0_1[576], Gamma_seq3_1_conv1_1[256], Gamma_seq3_1_conv2_0_1[576], Gamma_seq3_1_conv2_1[256];
double Bias_seq3_0_conv1_0_1[460], Bias_seq3_0_conv1_1[256], Bias_seq3_0_conv2_0_1[460], Bias_seq3_0_conv2_1[256], Bias_seq3_0_downsample_1[256], Bias_seq3_1_conv1_0_1[576], Bias_seq3_1_conv1_1[256], Bias_seq3_1_conv2_0_1[576], Bias_seq3_1_conv2_1[256];

double Mu_seq4_0_conv1_0_1[921], Mu_seq4_0_conv1_1[512], Mu_seq4_0_conv2_0_1[921], Mu_seq4_0_conv2_1[512], Mu_seq4_0_downsample_1[512], Mu_seq4_1_conv1_0_1[1152], Mu_seq4_1_conv1_1[512], Mu_seq4_1_conv2_0_1[1152], Mu_seq4_1_conv2_1[512];
double Var_seq4_0_conv1_0_1[921], Var_seq4_0_conv1_1[512], Var_seq4_0_conv2_0_1[921], Var_seq4_0_conv2_1[512], Var_seq4_0_downsample_1[512], Var_seq4_1_conv1_0_1[1152], Var_seq4_1_conv1_1[512], Var_seq4_1_conv2_0_1[1152], Var_seq4_1_conv2_1[512];
double Gamma_seq4_0_conv1_0_1[921], Gamma_seq4_0_conv1_1[512], Gamma_seq4_0_conv2_0_1[921], Gamma_seq4_0_conv2_1[512], Gamma_seq4_0_downsample_1[512], Gamma_seq4_1_conv1_0_1[1152], Gamma_seq4_1_conv1_1[512], Gamma_seq4_1_conv2_0_1[1152], Gamma_seq4_1_conv2_1[512];
double Bias_seq4_0_conv1_0_1[921], Bias_seq4_0_conv1_1[512], Bias_seq4_0_conv2_0_1[921], Bias_seq4_0_conv2_1[512], Bias_seq4_0_downsample_1[512], Bias_seq4_1_conv1_0_1[1152], Bias_seq4_1_conv1_1[512], Bias_seq4_1_conv2_0_1[1152], Bias_seq4_1_conv2_1[512];

string kernel_1_dat_name[8] = {"layer1.0.conv1.0.0.weight.dat", "layer1.0.conv1.0.3.weight.dat", "layer1.0.conv2.0.0.weight.dat", "layer1.0.conv2.0.3.weight.dat", "layer1.1.conv1.0.0.weight.dat", "layer1.1.conv1.0.3.weight.dat", "layer1.1.conv2.0.0.weight.dat", "layer1.1.conv2.0.3.weight.dat"};
string kernel_2_dat_name[9] = {"layer2.0.conv1.0.0.weight.dat", "layer2.0.conv1.0.3.weight.dat", "layer2.0.conv2.0.0.weight.dat", "layer2.0.conv2.0.3.weight.dat", "layer2.0.downsample.0.weight.dat", "layer2.1.conv1.0.0.weight.dat", "layer2.1.conv1.0.3.weight.dat", "layer2.1.conv2.0.0.weight.dat", "layer2.1.conv2.0.3.weight.dat"};
string kernel_3_dat_name[9] = {"layer3.0.conv1.0.0.weight.dat", "layer3.0.conv1.0.3.weight.dat", "layer3.0.conv2.0.0.weight.dat", "layer3.0.conv2.0.3.weight.dat", "layer3.0.downsample.0.weight.dat", "layer3.1.conv1.0.0.weight.dat", "layer3.1.conv1.0.3.weight.dat", "layer3.1.conv2.0.0.weight.dat", "layer3.1.conv2.0.3.weight.dat"};
string kernel_4_dat_name[9] = {"layer4.0.conv1.0.0.weight.dat", "layer4.0.conv1.0.3.weight.dat", "layer4.0.conv2.0.0.weight.dat", "layer4.0.conv2.0.3.weight.dat", "layer4.0.downsample.0.weight.dat", "layer4.1.conv1.0.0.weight.dat", "layer4.1.conv1.0.3.weight.dat", "layer4.1.conv2.0.0.weight.dat", "layer4.1.conv2.0.3.weight.dat"};

string stem_mu_dat_name[2] = {"stem.1.running_mean.dat", "stem.4.running_mean.dat"};
string layer_1_mu_dat_name[8] = {"layer1.0.conv1.0.1.running_mean.dat",  "layer1.0.conv1.1.running_mean.dat",  "layer1.0.conv2.0.1.running_mean.dat",  "layer1.0.conv2.1.running_mean.dat",  "layer1.1.conv1.0.1.running_mean.dat",  "layer1.1.conv1.1.running_mean.dat",  "layer1.1.conv2.0.1.running_mean.dat",  "layer1.1.conv2.1.running_mean.dat"};
string layer_2_mu_dat_name[9] = {"layer2.0.conv1.0.1.running_mean.dat",  "layer2.0.conv1.1.running_mean.dat",  "layer2.0.conv2.0.1.running_mean.dat",  "layer2.0.conv2.1.running_mean.dat",  "layer2.0.downsample.1.running_mean.dat",  "layer2.1.conv1.0.1.running_mean.dat",  "layer2.1.conv1.1.running_mean.dat",  "layer2.1.conv2.0.1.running_mean.dat",  "layer2.1.conv2.1.running_mean.dat"};
string layer_3_mu_dat_name[9] = {"layer3.0.conv1.0.1.running_mean.dat",  "layer3.0.conv1.1.running_mean.dat",  "layer3.0.conv2.0.1.running_mean.dat",  "layer3.0.conv2.1.running_mean.dat",  "layer3.0.downsample.1.running_mean.dat",  "layer3.1.conv1.0.1.running_mean.dat",  "layer3.1.conv1.1.running_mean.dat",  "layer3.1.conv2.0.1.running_mean.dat",  "layer3.1.conv2.1.running_mean.dat"};
string layer_4_mu_dat_name[9] = {"layer4.0.conv1.0.1.running_mean.dat",  "layer4.0.conv1.1.running_mean.dat",  "layer4.0.conv2.0.1.running_mean.dat",  "layer4.0.conv2.1.running_mean.dat",  "layer4.0.downsample.1.running_mean.dat",  "layer4.1.conv1.0.1.running_mean.dat",  "layer4.1.conv1.1.running_mean.dat",  "layer4.1.conv2.0.1.running_mean.dat",  "layer4.1.conv2.1.running_mean.dat"};

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
	dtype *input = (dtype*)malloc(602112 * sizeof(dtype));
	dtype *output = (dtype*)malloc(10 * sizeof(dtype));
	dtype *output_golden = (dtype*)malloc(10 * sizeof(dtype));

	dtype *Kernel_stem_0 = (dtype*)malloc(6615 * sizeof(dtype));
	dtype *Kernel_stem_3 = (dtype*)malloc(8640 * sizeof(dtype));

	dtype *Kernel_seq1_0_conv1_0_0 = (dtype*)malloc(82944 * sizeof(dtype));
	dtype *Kernel_seq1_0_conv2_0_0 = (dtype*)malloc(82944 * sizeof(dtype));
	dtype *Kernel_seq1_1_conv1_0_0 = (dtype*)malloc(82944 * sizeof(dtype));
	dtype *Kernel_seq1_1_conv2_0_0 = (dtype*)malloc(82944 * sizeof(dtype));
	dtype *Kernel_seq1_0_conv1_0_3 = (dtype*)malloc(27648 * sizeof(dtype));
	dtype *Kernel_seq1_0_conv2_0_3 = (dtype*)malloc(27648 * sizeof(dtype));
	dtype *Kernel_seq1_1_conv1_0_3 = (dtype*)malloc(27648 * sizeof(dtype));
	dtype *Kernel_seq1_1_conv2_0_3 = (dtype*)malloc(27648 * sizeof(dtype));
	// kernel_size=(64, 144, 1, 3, 3),  kernel_size=(64, 144, 3, 1, 1)

	dtype *Kernel_seq2_0_conv1_0_0 = (dtype*)malloc(132480 * sizeof(dtype));
	dtype *Kernel_seq2_0_conv1_0_3 = (dtype*)malloc(88320 * sizeof(dtype));
	// kernel_size=(64, 230, 1, 3, 3), kernel_size=(128, 230, 3, 1, 1)
	dtype *Kernel_seq2_0_conv2_0_0 = (dtype*)malloc(264960 * sizeof(dtype));
	dtype *Kernel_seq2_0_conv2_0_3 = (dtype*)malloc(88320 * sizeof(dtype));
	// kernel_size=(128, 230, 1, 3, 3), kernel_size=(128, 230, 3, 1, 1)
	dtype *Kernel_seq2_0_downsample_0 = (dtype*)malloc(8192 * sizeof(dtype));
	// kernel_size=(64, 128, 1, 1, 1)
	dtype *Kernel_seq2_1_conv1_0_0 = (dtype*)malloc(331776 * sizeof(dtype));
	dtype *Kernel_seq2_1_conv1_0_3 = (dtype*)malloc(110592 * sizeof(dtype));
	dtype *Kernel_seq2_1_conv2_0_0 = (dtype*)malloc(331776 * sizeof(dtype));
	dtype *Kernel_seq2_1_conv2_0_3 = (dtype*)malloc(110592 * sizeof(dtype));
	// kernel_size=(128, 288, 1, 3, 3),  kernel_size=(128, 288, 3, 1, 1)

	dtype *Kernel_seq3_0_conv1_0_0 = (dtype*)malloc(529920 * sizeof(dtype));
	dtype *Kernel_seq3_0_conv1_0_3 = (dtype*)malloc(353280 * sizeof(dtype));
	// kernel_size=(128, 460, 1, 3, 3), kernel_size=(256, 460, 3, 1, 1)
	dtype *Kernel_seq3_0_conv2_0_0 = (dtype*)malloc(1059840 * sizeof(dtype));
	dtype *Kernel_seq3_0_conv2_0_3 = (dtype*)malloc(353280 * sizeof(dtype));
	// kernel_size=(256, 460, 1, 3, 3), kernel_size=(256, 460, 3, 1, 1)
	dtype *Kernel_seq3_0_downsample_0 = (dtype*)malloc(32768 * sizeof(dtype));
	// kernel_size=(128, 256, 1, 1, 1)
	dtype *Kernel_seq3_1_conv1_0_0 = (dtype*)malloc(1327104 * sizeof(dtype));
	dtype *Kernel_seq3_1_conv1_0_3 = (dtype*)malloc(442368 * sizeof(dtype));
	dtype *Kernel_seq3_1_conv2_0_0 = (dtype*)malloc(1327104 * sizeof(dtype));
	dtype *Kernel_seq3_1_conv2_0_3 = (dtype*)malloc(442368 * sizeof(dtype));
	// kernel_size=(256, 576, 1, 3, 3),  kernel_size=(256, 576, 3, 1, 1)

	dtype *Kernel_seq4_0_conv1_0_0 = (dtype*)malloc(2121984 * sizeof(dtype));
	dtype *Kernel_seq4_0_conv1_0_3 = (dtype*)malloc(1414656 * sizeof(dtype));
	// kernel_size=(256, 921, 1, 3, 3), kernel_size=(512, 921, 3, 1, 1)
	dtype *Kernel_seq4_0_conv2_0_0 = (dtype*)malloc(4243968 * sizeof(dtype));
	dtype *Kernel_seq4_0_conv2_0_3 = (dtype*)malloc(1414656 * sizeof(dtype));
	// kernel_size=(512, 921, 1, 3, 3), kernel_size=(512, 921, 3, 1, 1)
	dtype *Kernel_seq4_0_downsample_0 = (dtype*)malloc(131072 * sizeof(dtype));
	// kernel4size=(256, 512, 1, 1, 1)
	dtype *Kernel_seq4_1_conv1_0_0 = (dtype*)malloc(5308416 * sizeof(dtype));
	dtype *Kernel_seq4_1_conv1_0_3 = (dtype*)malloc(1769472 * sizeof(dtype));
	dtype *Kernel_seq4_1_conv2_0_0 = (dtype*)malloc(5308416 * sizeof(dtype));
	dtype *Kernel_seq4_1_conv2_0_3 = (dtype*)malloc(1769472 * sizeof(dtype));
	// kernel_size=(512, 1152, 1, 3, 3),  kernel_size=(512, 1152, 3, 1, 1)
	// kernel_size=5120
	dtype *Kernel_linear = (dtype*)malloc(5120 * sizeof(dtype));

	// load input
	if(!LoadDTYPE("input.dat", input, 602112))
		return 0;

	// load stem kernel
	if(!LoadDTYPE("stem.0.weight.dat", Kernel_stem_0, 6615)) return 0;
	if(!LoadDTYPE("stem.3.weight.dat", Kernel_stem_3, 8640)) return 0;

	// load layer1 kernel
	if(!LoadDTYPE(kernel_1_dat_name[0], Kernel_seq1_0_conv1_0_0, 82944)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[1], Kernel_seq1_0_conv1_0_3, 27648)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[2], Kernel_seq1_0_conv2_0_0, 82944)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[3], Kernel_seq1_0_conv2_0_3, 27648)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[4], Kernel_seq1_1_conv1_0_0, 82944)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[5], Kernel_seq1_1_conv1_0_3, 27648)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[6], Kernel_seq1_1_conv2_0_0, 82944)) return 0;
	if(!LoadDTYPE(kernel_1_dat_name[7], Kernel_seq1_1_conv2_0_3, 27648)) return 0;

	// load layer2 kernel
	if(!LoadDTYPE(kernel_2_dat_name[0], Kernel_seq2_0_conv1_0_0, 132480)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[1], Kernel_seq2_0_conv1_0_3, 88320)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[2], Kernel_seq2_0_conv2_0_0, 264960)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[3], Kernel_seq2_0_conv2_0_3, 88320)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[4], Kernel_seq2_0_downsample_0, 8192)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[5], Kernel_seq2_1_conv1_0_0, 331776)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[6], Kernel_seq2_1_conv1_0_3, 110592)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[7], Kernel_seq2_1_conv2_0_0, 331776)) return 0;
	if(!LoadDTYPE(kernel_2_dat_name[8], Kernel_seq2_1_conv2_0_3, 110592)) return 0;

	// load layer3 kernel
	if(!LoadDTYPE(kernel_3_dat_name[0], Kernel_seq3_0_conv1_0_0, 529920)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[1], Kernel_seq3_0_conv1_0_3, 353280)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[2], Kernel_seq3_0_conv2_0_0, 1059840)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[3], Kernel_seq3_0_conv2_0_3, 353280)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[4], Kernel_seq3_0_downsample_0, 32768)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[5], Kernel_seq3_1_conv1_0_0, 1327104)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[6], Kernel_seq3_1_conv1_0_3, 442368)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[7], Kernel_seq3_1_conv2_0_0, 1327104)) return 0;
	if(!LoadDTYPE(kernel_3_dat_name[8], Kernel_seq3_1_conv2_0_3, 442368)) return 0;

	// load layer4 kernel
	if(!LoadDTYPE(kernel_4_dat_name[0], Kernel_seq4_0_conv1_0_0, 2121984)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[1], Kernel_seq4_0_conv1_0_3, 1414656)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[2], Kernel_seq4_0_conv2_0_0, 4243968)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[3], Kernel_seq4_0_conv2_0_3, 1414656)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[4], Kernel_seq4_0_downsample_0, 131072)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[5], Kernel_seq4_1_conv1_0_0, 5308416)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[6], Kernel_seq4_1_conv1_0_3, 1769472)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[7], Kernel_seq4_1_conv2_0_0, 5308416)) return 0;
	if(!LoadDTYPE(kernel_4_dat_name[8], Kernel_seq4_1_conv2_0_3, 1769472)) return 0;
	
	// load linear kernel
	if(!LoadDTYPE(kernel_4_dat_name[8], Kernel_linear, 5120)) return 0;

	// load stem batch
	if(!LoadDouble(stem_mu_dat_name[0], Mu_stem_1, 45)) return 0;
	if(!LoadDouble(stem_var_dat_name[0], Var_stem_1, 45)) return 0;
	if(!LoadDouble(stem_gamma_dat_name[0], Gamma_stem_1, 45)) return 0;
	if(!LoadDouble(stem_bias_dat_name[0], Bias_stem_1, 45)) return 0;

	if(!LoadDouble(stem_mu_dat_name[1], Mu_stem_4, 64)) return 0;
	if(!LoadDouble(stem_var_dat_name[1], Var_stem_4, 64)) return 0;
	if(!LoadDouble(stem_gamma_dat_name[1], Gamma_stem_4, 64)) return 0;
	if(!LoadDouble(stem_bias_dat_name[1], Bias_stem_4, 64)) return 0;
	
	if(!LoadDouble(layer_1_mu_dat_name[0], Mu_seq1_0_conv1_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_mu_dat_name[1], Mu_seq1_0_conv1_1, 64)) return 0;
	if(!LoadDouble(layer_1_mu_dat_name[2], Mu_seq1_0_conv2_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_mu_dat_name[3], Mu_seq1_0_conv2_1, 64)) return 0;
	if(!LoadDouble(layer_1_mu_dat_name[4], Mu_seq1_1_conv1_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_mu_dat_name[5], Mu_seq1_1_conv1_1, 64)) return 0;
	if(!LoadDouble(layer_1_mu_dat_name[6], Mu_seq1_1_conv2_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_mu_dat_name[7], Mu_seq1_1_conv2_1, 64)) return 0;
	if(!LoadDouble(layer_1_var_dat_name[0], Var_seq1_0_conv1_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_var_dat_name[1], Var_seq1_0_conv1_1, 64)) return 0;
	if(!LoadDouble(layer_1_var_dat_name[2], Var_seq1_0_conv2_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_var_dat_name[3], Var_seq1_0_conv2_1, 64)) return 0;
	if(!LoadDouble(layer_1_var_dat_name[4], Var_seq1_1_conv1_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_var_dat_name[5], Var_seq1_1_conv1_1, 64)) return 0;
	if(!LoadDouble(layer_1_var_dat_name[6], Var_seq1_1_conv2_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_var_dat_name[7], Var_seq1_1_conv2_1, 64)) return 0;
	if(!LoadDouble(layer_1_gamma_dat_name[0], Gamma_seq1_0_conv1_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_gamma_dat_name[1], Gamma_seq1_0_conv1_1, 64)) return 0;
	if(!LoadDouble(layer_1_gamma_dat_name[2], Gamma_seq1_0_conv2_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_gamma_dat_name[3], Gamma_seq1_0_conv2_1, 64)) return 0;
	if(!LoadDouble(layer_1_gamma_dat_name[4], Gamma_seq1_1_conv1_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_gamma_dat_name[5], Gamma_seq1_1_conv1_1, 64)) return 0;
	if(!LoadDouble(layer_1_gamma_dat_name[6], Gamma_seq1_1_conv2_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_gamma_dat_name[7], Gamma_seq1_1_conv2_1, 64)) return 0;
	if(!LoadDouble(layer_1_bias_dat_name[0], Bias_seq1_0_conv1_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_bias_dat_name[1], Bias_seq1_0_conv1_1, 64)) return 0;
	if(!LoadDouble(layer_1_bias_dat_name[2], Bias_seq1_0_conv2_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_bias_dat_name[3], Bias_seq1_0_conv2_1, 64)) return 0;
	if(!LoadDouble(layer_1_bias_dat_name[4], Bias_seq1_1_conv1_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_bias_dat_name[5], Bias_seq1_1_conv1_1, 64)) return 0;
	if(!LoadDouble(layer_1_bias_dat_name[6], Bias_seq1_1_conv2_0_1, 144)) return 0;
	if(!LoadDouble(layer_1_bias_dat_name[7], Bias_seq1_1_conv2_1, 64)) return 0;

	if(!LoadDouble(layer_2_mu_dat_name[0], Mu_seq2_0_conv1_0_1, 230)) return 0;
	if(!LoadDouble(layer_2_mu_dat_name[1], Mu_seq2_0_conv1_1, 128)) return 0;
	if(!LoadDouble(layer_2_mu_dat_name[2], Mu_seq2_0_conv2_0_1, 230)) return 0;
	if(!LoadDouble(layer_2_mu_dat_name[3], Mu_seq2_0_conv2_1, 128)) return 0;
	if(!LoadDouble(layer_2_mu_dat_name[4], Mu_seq2_0_downsample_1, 128)) return 0;
	if(!LoadDouble(layer_2_mu_dat_name[5], Mu_seq2_1_conv1_0_1, 288)) return 0;
	if(!LoadDouble(layer_2_mu_dat_name[6], Mu_seq2_1_conv1_1, 128)) return 0;
	if(!LoadDouble(layer_2_mu_dat_name[7], Mu_seq2_1_conv2_0_1, 288)) return 0;
	if(!LoadDouble(layer_2_mu_dat_name[8], Mu_seq2_1_conv2_1, 128)) return 0;
	if(!LoadDouble(layer_2_var_dat_name[0], Var_seq2_0_conv1_0_1, 230)) return 0;
	if(!LoadDouble(layer_2_var_dat_name[1], Var_seq2_0_conv1_1, 128)) return 0;
	if(!LoadDouble(layer_2_var_dat_name[2], Var_seq2_0_conv2_0_1, 230)) return 0;
	if(!LoadDouble(layer_2_var_dat_name[3], Var_seq2_0_conv2_1, 128)) return 0;
	if(!LoadDouble(layer_2_var_dat_name[4], Var_seq2_0_downsample_1, 128)) return 0;
	if(!LoadDouble(layer_2_var_dat_name[5], Var_seq2_1_conv1_0_1, 288)) return 0;
	if(!LoadDouble(layer_2_var_dat_name[6], Var_seq2_1_conv1_1, 128)) return 0;
	if(!LoadDouble(layer_2_var_dat_name[7], Var_seq2_1_conv2_0_1, 288)) return 0;
	if(!LoadDouble(layer_2_var_dat_name[8], Var_seq2_1_conv2_1, 128)) return 0;
	if(!LoadDouble(layer_2_gamma_dat_name[0], Gamma_seq2_0_conv1_0_1, 230)) return 0;
	if(!LoadDouble(layer_2_gamma_dat_name[1], Gamma_seq2_0_conv1_1, 128)) return 0;
	if(!LoadDouble(layer_2_gamma_dat_name[2], Gamma_seq2_0_conv2_0_1, 230)) return 0;
	if(!LoadDouble(layer_2_gamma_dat_name[3], Gamma_seq2_0_conv2_1, 128)) return 0;
	if(!LoadDouble(layer_2_gamma_dat_name[4], Gamma_seq2_0_downsample_1, 128)) return 0;
	if(!LoadDouble(layer_2_gamma_dat_name[5], Gamma_seq2_1_conv1_0_1, 288)) return 0;
	if(!LoadDouble(layer_2_gamma_dat_name[6], Gamma_seq2_1_conv1_1, 128)) return 0;
	if(!LoadDouble(layer_2_gamma_dat_name[7], Gamma_seq2_1_conv2_0_1, 288)) return 0;
	if(!LoadDouble(layer_2_gamma_dat_name[8], Gamma_seq2_1_conv2_1, 128)) return 0;
	if(!LoadDouble(layer_2_bias_dat_name[0], Bias_seq2_0_conv1_0_1, 230)) return 0;
	if(!LoadDouble(layer_2_bias_dat_name[1], Bias_seq2_0_conv1_1, 128)) return 0;
	if(!LoadDouble(layer_2_bias_dat_name[2], Bias_seq2_0_conv2_0_1, 230)) return 0;
	if(!LoadDouble(layer_2_bias_dat_name[3], Bias_seq2_0_conv2_1, 128)) return 0;
	if(!LoadDouble(layer_2_bias_dat_name[4], Bias_seq2_0_downsample_1, 128)) return 0;
	if(!LoadDouble(layer_2_bias_dat_name[5], Bias_seq2_1_conv1_0_1, 288)) return 0;
	if(!LoadDouble(layer_2_bias_dat_name[6], Bias_seq2_1_conv1_1, 128)) return 0;
	if(!LoadDouble(layer_2_bias_dat_name[7], Bias_seq2_1_conv2_0_1, 288)) return 0;
	if(!LoadDouble(layer_2_bias_dat_name[8], Bias_seq2_1_conv2_1, 128)) return 0;

	if(!LoadDouble(layer_3_mu_dat_name[0], Mu_seq3_0_conv1_0_1, 460)) return 0;
	if(!LoadDouble(layer_3_mu_dat_name[1], Mu_seq3_0_conv1_1, 256)) return 0;
	if(!LoadDouble(layer_3_mu_dat_name[2], Mu_seq3_0_conv2_0_1, 460)) return 0;
	if(!LoadDouble(layer_3_mu_dat_name[3], Mu_seq3_0_conv2_1, 256)) return 0;
	if(!LoadDouble(layer_3_mu_dat_name[4], Mu_seq3_0_downsample_1, 256)) return 0;
	if(!LoadDouble(layer_3_mu_dat_name[5], Mu_seq3_1_conv1_0_1, 576)) return 0;
	if(!LoadDouble(layer_3_mu_dat_name[6], Mu_seq3_1_conv1_1, 256)) return 0;
	if(!LoadDouble(layer_3_mu_dat_name[7], Mu_seq3_1_conv2_0_1, 576)) return 0;
	if(!LoadDouble(layer_3_mu_dat_name[8], Mu_seq3_1_conv2_1, 256)) return 0;
	if(!LoadDouble(layer_3_var_dat_name[0], Var_seq3_0_conv1_0_1, 460)) return 0;
	if(!LoadDouble(layer_3_var_dat_name[1], Var_seq3_0_conv1_1, 256)) return 0;
	if(!LoadDouble(layer_3_var_dat_name[2], Var_seq3_0_conv2_0_1, 460)) return 0;
	if(!LoadDouble(layer_3_var_dat_name[3], Var_seq3_0_conv2_1, 256)) return 0;
	if(!LoadDouble(layer_3_var_dat_name[4], Var_seq3_0_downsample_1, 256)) return 0;
	if(!LoadDouble(layer_3_var_dat_name[5], Var_seq3_1_conv1_0_1, 576)) return 0;
	if(!LoadDouble(layer_3_var_dat_name[6], Var_seq3_1_conv1_1, 256)) return 0;
	if(!LoadDouble(layer_3_var_dat_name[7], Var_seq3_1_conv2_0_1, 576)) return 0;
	if(!LoadDouble(layer_3_var_dat_name[8], Var_seq3_1_conv2_1, 256)) return 0;
	if(!LoadDouble(layer_3_gamma_dat_name[0], Gamma_seq3_0_conv1_0_1, 460)) return 0;
	if(!LoadDouble(layer_3_gamma_dat_name[1], Gamma_seq3_0_conv1_1, 256)) return 0;
	if(!LoadDouble(layer_3_gamma_dat_name[2], Gamma_seq3_0_conv2_0_1, 460)) return 0;
	if(!LoadDouble(layer_3_gamma_dat_name[3], Gamma_seq3_0_conv2_1, 256)) return 0;
	if(!LoadDouble(layer_3_gamma_dat_name[4], Gamma_seq3_0_downsample_1, 256)) return 0;
	if(!LoadDouble(layer_3_gamma_dat_name[5], Gamma_seq3_1_conv1_0_1, 576)) return 0;
	if(!LoadDouble(layer_3_gamma_dat_name[6], Gamma_seq3_1_conv1_1, 256)) return 0;
	if(!LoadDouble(layer_3_gamma_dat_name[7], Gamma_seq3_1_conv2_0_1, 576)) return 0;
	if(!LoadDouble(layer_3_gamma_dat_name[8], Gamma_seq3_1_conv2_1, 256)) return 0;
	if(!LoadDouble(layer_3_bias_dat_name[0], Bias_seq3_0_conv1_0_1, 460)) return 0;
	if(!LoadDouble(layer_3_bias_dat_name[1], Bias_seq3_0_conv1_1, 256)) return 0;
	if(!LoadDouble(layer_3_bias_dat_name[2], Bias_seq3_0_conv2_0_1, 460)) return 0;
	if(!LoadDouble(layer_3_bias_dat_name[3], Bias_seq3_0_conv2_1, 256)) return 0;
	if(!LoadDouble(layer_3_bias_dat_name[4], Bias_seq3_0_downsample_1, 256)) return 0;
	if(!LoadDouble(layer_3_bias_dat_name[5], Bias_seq3_1_conv1_0_1, 576)) return 0;
	if(!LoadDouble(layer_3_bias_dat_name[6], Bias_seq3_1_conv1_1, 256)) return 0;
	if(!LoadDouble(layer_3_bias_dat_name[7], Bias_seq3_1_conv2_0_1, 576)) return 0;
	if(!LoadDouble(layer_3_bias_dat_name[8], Bias_seq3_1_conv2_1, 256)) return 0;

	if(!LoadDouble(layer_4_mu_dat_name[0], Mu_seq4_0_conv1_0_1, 921)) return 0;
	if(!LoadDouble(layer_4_mu_dat_name[1], Mu_seq4_0_conv1_1, 512)) return 0;
	if(!LoadDouble(layer_4_mu_dat_name[2], Mu_seq4_0_conv2_0_1, 921)) return 0;
	if(!LoadDouble(layer_4_mu_dat_name[3], Mu_seq4_0_conv2_1, 512)) return 0;
	if(!LoadDouble(layer_4_mu_dat_name[4], Mu_seq4_0_downsample_1, 512)) return 0;
	if(!LoadDouble(layer_4_mu_dat_name[5], Mu_seq4_1_conv1_0_1, 1152)) return 0;
	if(!LoadDouble(layer_4_mu_dat_name[6], Mu_seq4_1_conv1_1, 512)) return 0;
	if(!LoadDouble(layer_4_mu_dat_name[7], Mu_seq4_1_conv2_0_1, 1152)) return 0;
	if(!LoadDouble(layer_4_mu_dat_name[8], Mu_seq4_1_conv2_1, 512)) return 0;
	if(!LoadDouble(layer_4_var_dat_name[0], Var_seq4_0_conv1_0_1, 921)) return 0;
	if(!LoadDouble(layer_4_var_dat_name[1], Var_seq4_0_conv1_1, 512)) return 0;
	if(!LoadDouble(layer_4_var_dat_name[2], Var_seq4_0_conv2_0_1, 921)) return 0;
	if(!LoadDouble(layer_4_var_dat_name[3], Var_seq4_0_conv2_1, 512)) return 0;
	if(!LoadDouble(layer_4_var_dat_name[4], Var_seq4_0_downsample_1, 512)) return 0;
	if(!LoadDouble(layer_4_var_dat_name[5], Var_seq4_1_conv1_0_1, 1152)) return 0;
	if(!LoadDouble(layer_4_var_dat_name[6], Var_seq4_1_conv1_1, 512)) return 0;
	if(!LoadDouble(layer_4_var_dat_name[7], Var_seq4_1_conv2_0_1, 1152)) return 0;
	if(!LoadDouble(layer_4_var_dat_name[8], Var_seq4_1_conv2_1, 512)) return 0;
	if(!LoadDouble(layer_4_gamma_dat_name[0], Gamma_seq4_0_conv1_0_1, 921)) return 0;
	if(!LoadDouble(layer_4_gamma_dat_name[1], Gamma_seq4_0_conv1_1, 512)) return 0;
	if(!LoadDouble(layer_4_gamma_dat_name[2], Gamma_seq4_0_conv2_0_1, 921)) return 0;
	if(!LoadDouble(layer_4_gamma_dat_name[3], Gamma_seq4_0_conv2_1, 512)) return 0;
	if(!LoadDouble(layer_4_gamma_dat_name[4], Gamma_seq4_0_downsample_1, 512)) return 0;
	if(!LoadDouble(layer_4_gamma_dat_name[5], Gamma_seq4_1_conv1_0_1, 1152)) return 0;
	if(!LoadDouble(layer_4_gamma_dat_name[6], Gamma_seq4_1_conv1_1, 512)) return 0;
	if(!LoadDouble(layer_4_gamma_dat_name[7], Gamma_seq4_1_conv2_0_1, 1152)) return 0;
	if(!LoadDouble(layer_4_gamma_dat_name[8], Gamma_seq4_1_conv2_1, 512)) return 0;
	if(!LoadDouble(layer_4_bias_dat_name[0], Bias_seq4_0_conv1_0_1, 921)) return 0;
	if(!LoadDouble(layer_4_bias_dat_name[1], Bias_seq4_0_conv1_1, 512)) return 0;
	if(!LoadDouble(layer_4_bias_dat_name[2], Bias_seq4_0_conv2_0_1, 921)) return 0;
	if(!LoadDouble(layer_4_bias_dat_name[3], Bias_seq4_0_conv2_1, 512)) return 0;
	if(!LoadDouble(layer_4_bias_dat_name[4], Bias_seq4_0_downsample_1, 512)) return 0;
	if(!LoadDouble(layer_4_bias_dat_name[5], Bias_seq4_1_conv1_0_1, 1152)) return 0;
	if(!LoadDouble(layer_4_bias_dat_name[6], Bias_seq4_1_conv1_1, 512)) return 0;
	if(!LoadDouble(layer_4_bias_dat_name[7], Bias_seq4_1_conv2_0_1, 1152)) return 0;
	if(!LoadDouble(layer_4_bias_dat_name[8], Bias_seq4_1_conv2_1, 512)) return 0;

	if(!LoadDTYPE("output.dat", 			 output_golden, 	  10)) return 0;

	// ====================================
	// Function to test here:

	r2plus1d(input, output, Kernel_stem_0, Kernel_stem_3, Mu_stem_1, Mu_stem_4, Var_stem_1, Var_stem_4, Gamma_stem_1, Gamma_stem_4, Bias_stem_1, Bias_stem_4,
            Kernel_seq1_0_conv1_0_0, Kernel_seq1_0_conv1_0_3, Kernel_seq1_0_conv2_0_0, Kernel_seq1_0_conv2_0_3, Kernel_seq1_1_conv1_0_0, Kernel_seq1_1_conv1_0_3, Kernel_seq1_1_conv2_0_0, Kernel_seq1_1_conv2_0_3,
                Mu_seq1_0_conv1_0_1, Mu_seq1_0_conv1_1, Mu_seq1_0_conv2_0_1, Mu_seq1_0_conv2_1, Mu_seq1_1_conv1_0_1, Mu_seq1_1_conv1_1, Mu_seq1_1_conv2_0_1, Mu_seq1_1_conv2_1,
                Var_seq1_0_conv1_0_1, Var_seq1_0_conv1_1, Var_seq1_0_conv2_0_1, Var_seq1_0_conv2_1, Var_seq1_1_conv1_0_1, Var_seq1_1_conv1_1, Var_seq1_1_conv2_0_1, Var_seq1_1_conv2_1,
                Gamma_seq1_0_conv1_0_1, Gamma_seq1_0_conv1_1, Gamma_seq1_0_conv2_0_1, Gamma_seq1_0_conv2_1, Gamma_seq1_1_conv1_0_1, Gamma_seq1_1_conv1_1, Gamma_seq1_1_conv2_0_1, Gamma_seq1_1_conv2_1,
                Bias_seq1_0_conv1_0_1, Bias_seq1_0_conv1_1, Bias_seq1_0_conv2_0_1, Bias_seq1_0_conv2_1, Bias_seq1_1_conv1_0_1, Bias_seq1_1_conv1_1, Bias_seq1_1_conv2_0_1, Bias_seq1_1_conv2_1,
            Kernel_seq2_0_conv1_0_0, Kernel_seq2_0_conv1_0_3, Kernel_seq2_0_conv2_0_0, Kernel_seq2_0_conv2_0_3, Kernel_seq2_0_downsample_0, Kernel_seq2_1_conv1_0_0, Kernel_seq2_1_conv1_0_3, Kernel_seq2_1_conv2_0_0, Kernel_seq2_1_conv2_0_3,
                Mu_seq2_0_conv1_0_1, Mu_seq2_0_conv1_1, Mu_seq2_0_conv2_0_1, Mu_seq2_0_conv2_1, Mu_seq2_0_downsample_1, Mu_seq2_1_conv1_0_1, Mu_seq2_1_conv1_1, Mu_seq2_1_conv2_0_1, Mu_seq2_1_conv2_1,
                Var_seq2_0_conv1_0_1, Var_seq2_0_conv1_1, Var_seq2_0_conv2_0_1, Var_seq2_0_conv2_1, Var_seq2_0_downsample_1, Var_seq2_1_conv1_0_1, Var_seq2_1_conv1_1, Var_seq2_1_conv2_0_1, Var_seq2_1_conv2_1,
                Gamma_seq2_0_conv1_0_1, Gamma_seq2_0_conv1_1, Gamma_seq2_0_conv2_0_1, Gamma_seq2_0_conv2_1, Gamma_seq2_0_downsample_1, Gamma_seq2_1_conv1_0_1, Gamma_seq2_1_conv1_1, Gamma_seq2_1_conv2_0_1, Gamma_seq2_1_conv2_1,
                Bias_seq2_0_conv1_0_1, Bias_seq2_0_conv1_1, Bias_seq2_0_conv2_0_1, Bias_seq2_0_conv2_1, Bias_seq2_0_downsample_1, Bias_seq2_1_conv1_0_1, Bias_seq2_1_conv1_1, Bias_seq2_1_conv2_0_1, Bias_seq2_1_conv2_1,
            Kernel_seq3_0_conv1_0_0, Kernel_seq3_0_conv1_0_3, Kernel_seq3_0_conv2_0_0, Kernel_seq3_0_conv2_0_3, Kernel_seq3_0_downsample_0, Kernel_seq3_1_conv1_0_0, Kernel_seq3_1_conv1_0_3, Kernel_seq3_1_conv2_0_0, Kernel_seq3_1_conv2_0_3,
                Mu_seq3_0_conv1_0_1, Mu_seq3_0_conv1_1, Mu_seq3_0_conv2_0_1, Mu_seq3_0_conv2_1, Mu_seq3_0_downsample_1, Mu_seq3_1_conv1_0_1, Mu_seq3_1_conv1_1, Mu_seq3_1_conv2_0_1, Mu_seq3_1_conv2_1,
                Var_seq3_0_conv1_0_1, Var_seq3_0_conv1_1, Var_seq3_0_conv2_0_1, Var_seq3_0_conv2_1, Var_seq3_0_downsample_1, Var_seq3_1_conv1_0_1, Var_seq3_1_conv1_1, Var_seq3_1_conv2_0_1, Var_seq3_1_conv2_1,
                Gamma_seq3_0_conv1_0_1, Gamma_seq3_0_conv1_1, Gamma_seq3_0_conv2_0_1, Gamma_seq3_0_conv2_1, Gamma_seq3_0_downsample_1, Gamma_seq3_1_conv1_0_1, Gamma_seq3_1_conv1_1, Gamma_seq3_1_conv2_0_1, Gamma_seq3_1_conv2_1,
                Bias_seq3_0_conv1_0_1, Bias_seq3_0_conv1_1, Bias_seq3_0_conv2_0_1, Bias_seq3_0_conv2_1, Bias_seq3_0_downsample_1, Bias_seq3_1_conv1_0_1, Bias_seq3_1_conv1_1, Bias_seq3_1_conv2_0_1, Bias_seq3_1_conv2_1,
            Kernel_seq4_0_conv1_0_0, Kernel_seq4_0_conv1_0_3, Kernel_seq4_0_conv2_0_0, Kernel_seq4_0_conv2_0_3, Kernel_seq4_0_downsample_0, Kernel_seq4_1_conv1_0_0, Kernel_seq4_1_conv1_0_3, Kernel_seq4_1_conv2_0_0, Kernel_seq4_1_conv2_0_3,
                Mu_seq4_0_conv1_0_1, Mu_seq4_0_conv1_1, Mu_seq4_0_conv2_0_1, Mu_seq4_0_conv2_1, Mu_seq4_0_downsample_1, Mu_seq4_1_conv1_0_1, Mu_seq4_1_conv1_1, Mu_seq4_1_conv2_0_1, Mu_seq4_1_conv2_1,
                Var_seq4_0_conv1_0_1, Var_seq4_0_conv1_1, Var_seq4_0_conv2_0_1, Var_seq4_0_conv2_1, Var_seq4_0_downsample_1, Var_seq4_1_conv1_0_1, Var_seq4_1_conv1_1, Var_seq4_1_conv2_0_1, Var_seq4_1_conv2_1,
                Gamma_seq4_0_conv1_0_1, Gamma_seq4_0_conv1_1, Gamma_seq4_0_conv2_0_1, Gamma_seq4_0_conv2_1, Gamma_seq4_0_downsample_1, Gamma_seq4_1_conv1_0_1, Gamma_seq4_1_conv1_1, Gamma_seq4_1_conv2_0_1, Gamma_seq4_1_conv2_1,
                Bias_seq4_0_conv1_0_1, Bias_seq4_0_conv1_1, Bias_seq4_0_conv2_0_1, Bias_seq4_0_conv2_1, Bias_seq4_0_downsample_1, Bias_seq4_1_conv1_0_1, Bias_seq4_1_conv1_1, Bias_seq4_1_conv2_0_1, Bias_seq4_1_conv2_1,
            Kernel_linear);

	// calculate errors
	float errors;
	int_t X_num[5] = { 1, 10, 1, 1, 1 };
	errors = 100 * float(validate(output, output_golden, X_num)) / 10;

	if (errors != 0)
		printf("[FAIL] There are some errors QQ, error rate: %f%\n", errors);
	else
		printf("[PASS] Congratulation! All results are correct\n");

	free(input);
	free(output_golden);
	free(output);

	free(Kernel_stem_0);
	free(Kernel_stem_3);

	free(Kernel_seq1_0_conv1_0_0);
	free(Kernel_seq1_0_conv2_0_0);
	free(Kernel_seq1_1_conv1_0_0);
	free(Kernel_seq1_1_conv2_0_0);
	free(Kernel_seq1_0_conv1_0_3);
	free(Kernel_seq1_0_conv2_0_3);
	free(Kernel_seq1_1_conv1_0_3);
	free(Kernel_seq1_1_conv2_0_3);


	free(Kernel_seq2_0_conv1_0_0);
	free(Kernel_seq2_0_conv1_0_3);

	free(Kernel_seq2_0_conv2_0_0);
	free(Kernel_seq2_0_conv2_0_3);

	free(Kernel_seq2_0_downsample_0);

	free(Kernel_seq2_1_conv1_0_0);
	free(Kernel_seq2_1_conv1_0_3);
	free(Kernel_seq2_1_conv2_0_0);
	free(Kernel_seq2_1_conv2_0_3);


	free(Kernel_seq3_0_conv1_0_0);
	free(Kernel_seq3_0_conv1_0_3);

	free(Kernel_seq3_0_conv2_0_0);
	free(Kernel_seq3_0_conv2_0_3);

	free(Kernel_seq3_0_downsample_0);

	free(Kernel_seq3_1_conv1_0_0);
	free(Kernel_seq3_1_conv1_0_3);
	free(Kernel_seq3_1_conv2_0_0);
	free(Kernel_seq3_1_conv2_0_3);


	free(Kernel_seq4_0_conv1_0_0);
	free(Kernel_seq4_0_conv1_0_3);

	free(Kernel_seq4_0_conv2_0_0);
	free(Kernel_seq4_0_conv2_0_3);

	free(Kernel_seq4_0_downsample_0);

	free(Kernel_seq4_1_conv1_0_0);
	free(Kernel_seq4_1_conv1_0_3);
	free(Kernel_seq4_1_conv2_0_0);
	free(Kernel_seq4_1_conv2_0_3);


	free(Kernel_linear);

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
                        else if(ourOutput[pos] != golden[pos] && (ourOutput[pos] - golden[pos]) / golden[pos] >= 0.002 || (ourOutput[pos] - golden[pos]) / golden[pos] <= -0.002){
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
