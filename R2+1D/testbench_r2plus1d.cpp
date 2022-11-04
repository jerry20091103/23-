#include "test_utility.h"

// modify these value to test different layers
// remember to use corresponding input.dat and output.dat in vitis/visual studio project
// and r2plus1d.cpp
#define INPUT_SIZE 602112
#define OUTPUT_SIZE 10
int_t OUTPUT_STRUCTURE[5] = { 1, 10, 1, 1, 1 };

ftype Kernel_stem_0_scale[45];
ftype Kernel_stem_3_scale[64];
ftype Mu_stem_1[45], Var_stem_1[45], Gamma_stem_1[45], Bias_stem_1[45];
ftype Mu_stem_4[64], Var_stem_4[64], Gamma_stem_4[64], Bias_stem_4[64];

ftype Kernel_seq1_0_conv1_0_0_scale[144];
ftype Kernel_seq1_0_conv2_0_0_scale[144];
ftype Kernel_seq1_1_conv1_0_0_scale[144];
ftype Kernel_seq1_1_conv2_0_0_scale[144];
ftype Kernel_seq1_0_conv1_0_3_scale[64];
ftype Kernel_seq1_0_conv2_0_3_scale[64];
ftype Kernel_seq1_1_conv1_0_3_scale[64];
ftype Kernel_seq1_1_conv2_0_3_scale[64];
ftype Mu_seq1_0_conv1_0_1[144], Mu_seq1_0_conv1_1[64], Mu_seq1_0_conv2_0_1[144], Mu_seq1_0_conv2_1[64], Mu_seq1_1_conv1_0_1[144], Mu_seq1_1_conv1_1[64], Mu_seq1_1_conv2_0_1[144], Mu_seq1_1_conv2_1[64];
ftype Var_seq1_0_conv1_0_1[144], Var_seq1_0_conv1_1[64], Var_seq1_0_conv2_0_1[144], Var_seq1_0_conv2_1[64], Var_seq1_1_conv1_0_1[144], Var_seq1_1_conv1_1[64], Var_seq1_1_conv2_0_1[144], Var_seq1_1_conv2_1[64];
ftype Gamma_seq1_0_conv1_0_1[144], Gamma_seq1_0_conv1_1[64], Gamma_seq1_0_conv2_0_1[144], Gamma_seq1_0_conv2_1[64], Gamma_seq1_1_conv1_0_1[144], Gamma_seq1_1_conv1_1[64], Gamma_seq1_1_conv2_0_1[144], Gamma_seq1_1_conv2_1[64];
ftype Bias_seq1_0_conv1_0_1[144], Bias_seq1_0_conv1_1[64], Bias_seq1_0_conv2_0_1[144], Bias_seq1_0_conv2_1[64], Bias_seq1_1_conv1_0_1[144], Bias_seq1_1_conv1_1[64], Bias_seq1_1_conv2_0_1[144], Bias_seq1_1_conv2_1[64];

ftype Kernel_seq2_0_conv1_0_0_scale[230];
ftype Kernel_seq2_0_conv1_0_3_scale[128];
ftype Kernel_seq2_0_conv2_0_0_scale[230];
ftype Kernel_seq2_0_conv2_0_3_scale[128];
ftype Kernel_seq2_0_downsample_0_scale[128];
ftype Kernel_seq2_1_conv1_0_0_scale[288];
ftype Kernel_seq2_1_conv1_0_3_scale[128];
ftype Kernel_seq2_1_conv2_0_0_scale[288];
ftype Kernel_seq2_1_conv2_0_3_scale[128];
ftype Mu_seq2_0_conv1_0_1[230], Mu_seq2_0_conv1_1[128], Mu_seq2_0_conv2_0_1[230], Mu_seq2_0_conv2_1[128], Mu_seq2_0_downsample_1[128], Mu_seq2_1_conv1_0_1[288], Mu_seq2_1_conv1_1[128], Mu_seq2_1_conv2_0_1[288], Mu_seq2_1_conv2_1[128];
ftype Var_seq2_0_conv1_0_1[230], Var_seq2_0_conv1_1[128], Var_seq2_0_conv2_0_1[230], Var_seq2_0_conv2_1[128], Var_seq2_0_downsample_1[128], Var_seq2_1_conv1_0_1[288], Var_seq2_1_conv1_1[128], Var_seq2_1_conv2_0_1[288], Var_seq2_1_conv2_1[128];
ftype Gamma_seq2_0_conv1_0_1[230], Gamma_seq2_0_conv1_1[128], Gamma_seq2_0_conv2_0_1[230], Gamma_seq2_0_conv2_1[128], Gamma_seq2_0_downsample_1[128], Gamma_seq2_1_conv1_0_1[288], Gamma_seq2_1_conv1_1[128], Gamma_seq2_1_conv2_0_1[288], Gamma_seq2_1_conv2_1[128];
ftype Bias_seq2_0_conv1_0_1[230], Bias_seq2_0_conv1_1[128], Bias_seq2_0_conv2_0_1[230], Bias_seq2_0_conv2_1[128], Bias_seq2_0_downsample_1[128], Bias_seq2_1_conv1_0_1[288], Bias_seq2_1_conv1_1[128], Bias_seq2_1_conv2_0_1[288], Bias_seq2_1_conv2_1[128];

ftype Kernel_seq3_0_conv1_0_0_scale[460];
ftype Kernel_seq3_0_conv1_0_3_scale[256];
ftype Kernel_seq3_0_conv2_0_0_scale[460];
ftype Kernel_seq3_0_conv2_0_3_scale[256];
ftype Kernel_seq3_0_downsample_0_scale[256];
ftype Kernel_seq3_1_conv1_0_0_scale[576];
ftype Kernel_seq3_1_conv1_0_3_scale[256];
ftype Kernel_seq3_1_conv2_0_0_scale[576];
ftype Kernel_seq3_1_conv2_0_3_scale[256];
ftype Mu_seq3_0_conv1_0_1[460], Mu_seq3_0_conv1_1[256], Mu_seq3_0_conv2_0_1[460], Mu_seq3_0_conv2_1[256], Mu_seq3_0_downsample_1[256], Mu_seq3_1_conv1_0_1[576], Mu_seq3_1_conv1_1[256], Mu_seq3_1_conv2_0_1[576], Mu_seq3_1_conv2_1[256];
ftype Var_seq3_0_conv1_0_1[460], Var_seq3_0_conv1_1[256], Var_seq3_0_conv2_0_1[460], Var_seq3_0_conv2_1[256], Var_seq3_0_downsample_1[256], Var_seq3_1_conv1_0_1[576], Var_seq3_1_conv1_1[256], Var_seq3_1_conv2_0_1[576], Var_seq3_1_conv2_1[256];
ftype Gamma_seq3_0_conv1_0_1[460], Gamma_seq3_0_conv1_1[256], Gamma_seq3_0_conv2_0_1[460], Gamma_seq3_0_conv2_1[256], Gamma_seq3_0_downsample_1[256], Gamma_seq3_1_conv1_0_1[576], Gamma_seq3_1_conv1_1[256], Gamma_seq3_1_conv2_0_1[576], Gamma_seq3_1_conv2_1[256];
ftype Bias_seq3_0_conv1_0_1[460], Bias_seq3_0_conv1_1[256], Bias_seq3_0_conv2_0_1[460], Bias_seq3_0_conv2_1[256], Bias_seq3_0_downsample_1[256], Bias_seq3_1_conv1_0_1[576], Bias_seq3_1_conv1_1[256], Bias_seq3_1_conv2_0_1[576], Bias_seq3_1_conv2_1[256];

ftype Kernel_seq4_0_conv1_0_0_scale[921];
ftype Kernel_seq4_0_conv1_0_3_scale[512];
ftype Kernel_seq4_0_conv2_0_0_scale[921];
ftype Kernel_seq4_0_conv2_0_3_scale[512];
ftype Kernel_seq4_0_downsample_0_scale[512];
ftype Kernel_seq4_1_conv1_0_0_scale[1152];
ftype Kernel_seq4_1_conv1_0_3_scale[512];
ftype Kernel_seq4_1_conv2_0_0_scale[1152];
ftype Kernel_seq4_1_conv2_0_3_scale[512];
ftype Mu_seq4_0_conv1_0_1[921], Mu_seq4_0_conv1_1[512], Mu_seq4_0_conv2_0_1[921], Mu_seq4_0_conv2_1[512], Mu_seq4_0_downsample_1[512], Mu_seq4_1_conv1_0_1[1152], Mu_seq4_1_conv1_1[512], Mu_seq4_1_conv2_0_1[1152], Mu_seq4_1_conv2_1[512];
ftype Var_seq4_0_conv1_0_1[921], Var_seq4_0_conv1_1[512], Var_seq4_0_conv2_0_1[921], Var_seq4_0_conv2_1[512], Var_seq4_0_downsample_1[512], Var_seq4_1_conv1_0_1[1152], Var_seq4_1_conv1_1[512], Var_seq4_1_conv2_0_1[1152], Var_seq4_1_conv2_1[512];
ftype Gamma_seq4_0_conv1_0_1[921], Gamma_seq4_0_conv1_1[512], Gamma_seq4_0_conv2_0_1[921], Gamma_seq4_0_conv2_1[512], Gamma_seq4_0_downsample_1[512], Gamma_seq4_1_conv1_0_1[1152], Gamma_seq4_1_conv1_1[512], Gamma_seq4_1_conv2_0_1[1152], Gamma_seq4_1_conv2_1[512];
ftype Bias_seq4_0_conv1_0_1[921], Bias_seq4_0_conv1_1[512], Bias_seq4_0_conv2_0_1[921], Bias_seq4_0_conv2_1[512], Bias_seq4_0_downsample_1[512], Bias_seq4_1_conv1_0_1[1152], Bias_seq4_1_conv1_1[512], Bias_seq4_1_conv2_0_1[1152], Bias_seq4_1_conv2_1[512];

ftype Kernel_linear_scale[10];

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
	// create a output txt file
	ofstream outfile;
	outfile.open("results.txt");
	if (!outfile.is_open()) {
		cout << "Error opening file" << endl;
		return 0;
	}

	dtype *input = (dtype*)malloc(INPUT_SIZE * sizeof(dtype));
	dtype *output = (dtype*)malloc(OUTPUT_SIZE * sizeof(dtype));
	dtype *output_golden = (dtype*)malloc(OUTPUT_SIZE * sizeof(dtype));

	ktype *Kernel_stem_0 = (ktype*)malloc(6615 * sizeof(ktype));
	ktype *Kernel_stem_3 = (ktype*)malloc(8640 * sizeof(ktype));

	ktype *Kernel_seq1_0_conv1_0_0 = (ktype*)malloc(82944 * sizeof(ktype));
	ktype *Kernel_seq1_0_conv2_0_0 = (ktype*)malloc(82944 * sizeof(ktype));
	ktype *Kernel_seq1_1_conv1_0_0 = (ktype*)malloc(82944 * sizeof(ktype));
	ktype *Kernel_seq1_1_conv2_0_0 = (ktype*)malloc(82944 * sizeof(ktype));
	ktype *Kernel_seq1_0_conv1_0_3 = (ktype*)malloc(27648 * sizeof(ktype));
	ktype *Kernel_seq1_0_conv2_0_3 = (ktype*)malloc(27648 * sizeof(ktype));
	ktype *Kernel_seq1_1_conv1_0_3 = (ktype*)malloc(27648 * sizeof(ktype));
	ktype *Kernel_seq1_1_conv2_0_3 = (ktype*)malloc(27648 * sizeof(ktype));
	// kernel_size=(64, 144, 1, 3, 3),  kernel_size=(64, 144, 3, 1, 1)

	ktype *Kernel_seq2_0_conv1_0_0 = (ktype*)malloc(132480 * sizeof(ktype));
	ktype *Kernel_seq2_0_conv1_0_3 = (ktype*)malloc(88320 * sizeof(ktype));
	// kernel_size=(64, 230, 1, 3, 3), kernel_size=(128, 230, 3, 1, 1)
	ktype *Kernel_seq2_0_conv2_0_0 = (ktype*)malloc(264960 * sizeof(ktype));
	ktype *Kernel_seq2_0_conv2_0_3 = (ktype*)malloc(88320 * sizeof(ktype));
	// kernel_size=(128, 230, 1, 3, 3), kernel_size=(128, 230, 3, 1, 1)
	ktype *Kernel_seq2_0_downsample_0 = (ktype*)malloc(8192 * sizeof(ktype));
	// kernel_size=(64, 128, 1, 1, 1)
	ktype *Kernel_seq2_1_conv1_0_0 = (ktype*)malloc(331776 * sizeof(ktype));
	ktype *Kernel_seq2_1_conv1_0_3 = (ktype*)malloc(110592 * sizeof(ktype));
	ktype *Kernel_seq2_1_conv2_0_0 = (ktype*)malloc(331776 * sizeof(ktype));
	ktype *Kernel_seq2_1_conv2_0_3 = (ktype*)malloc(110592 * sizeof(ktype));
	// kernel_size=(128, 288, 1, 3, 3),  kernel_size=(128, 288, 3, 1, 1)

	ktype *Kernel_seq3_0_conv1_0_0 = (ktype*)malloc(529920 * sizeof(ktype));
	ktype *Kernel_seq3_0_conv1_0_3 = (ktype*)malloc(353280 * sizeof(ktype));
	// kernel_size=(128, 460, 1, 3, 3), kernel_size=(256, 460, 3, 1, 1)
	ktype *Kernel_seq3_0_conv2_0_0 = (ktype*)malloc(1059840 * sizeof(ktype));
	ktype *Kernel_seq3_0_conv2_0_3 = (ktype*)malloc(353280 * sizeof(ktype));
	// kernel_size=(256, 460, 1, 3, 3), kernel_size=(256, 460, 3, 1, 1)
	ktype *Kernel_seq3_0_downsample_0 = (ktype*)malloc(32768 * sizeof(ktype));
	// kernel_size=(128, 256, 1, 1, 1)
	ktype *Kernel_seq3_1_conv1_0_0 = (ktype*)malloc(1327104 * sizeof(ktype));
	ktype *Kernel_seq3_1_conv1_0_3 = (ktype*)malloc(442368 * sizeof(ktype));
	ktype *Kernel_seq3_1_conv2_0_0 = (ktype*)malloc(1327104 * sizeof(ktype));
	ktype *Kernel_seq3_1_conv2_0_3 = (ktype*)malloc(442368 * sizeof(ktype));
	// kernel_size=(256, 576, 1, 3, 3),  kernel_size=(256, 576, 3, 1, 1)

	ktype *Kernel_seq4_0_conv1_0_0 = (ktype*)malloc(2121984 * sizeof(ktype));
	ktype *Kernel_seq4_0_conv1_0_3 = (ktype*)malloc(1414656 * sizeof(ktype));
	// kernel_size=(256, 921, 1, 3, 3), kernel_size=(512, 921, 3, 1, 1)
	ktype *Kernel_seq4_0_conv2_0_0 = (ktype*)malloc(4243968 * sizeof(ktype));
	ktype *Kernel_seq4_0_conv2_0_3 = (ktype*)malloc(1414656 * sizeof(ktype));
	// kernel_size=(512, 921, 1, 3, 3), kernel_size=(512, 921, 3, 1, 1)
	ktype *Kernel_seq4_0_downsample_0 = (ktype*)malloc(131072 * sizeof(ktype));
	// kernel4size=(256, 512, 1, 1, 1)
	ktype *Kernel_seq4_1_conv1_0_0 = (ktype*)malloc(5308416 * sizeof(ktype));
	ktype *Kernel_seq4_1_conv1_0_3 = (ktype*)malloc(1769472 * sizeof(ktype));
	ktype *Kernel_seq4_1_conv2_0_0 = (ktype*)malloc(5308416 * sizeof(ktype));
	ktype *Kernel_seq4_1_conv2_0_3 = (ktype*)malloc(1769472 * sizeof(ktype));
	// kernel_size=(512, 1152, 1, 3, 3),  kernel_size=(512, 1152, 3, 1, 1)
	// kernel_size=5120
	ktype *Kernel_linear = (ktype*)malloc(5120 * sizeof(ktype));

	// malloc buffer
	dtype *X_stem_1 = (dtype*)malloc(2257920 * sizeof(dtype));
	dtype *X_stem_2 = (dtype*)malloc(3211264 * sizeof(dtype));
	dtype *X_seq = (dtype*)malloc(50176 * sizeof(dtype));
	dtype *X_adap = (dtype*)malloc(512 * sizeof(dtype));
	dtype *X_tmp_data = (dtype*)malloc(3211264 * sizeof(dtype));
	dtype *X2_data = (dtype*)malloc(802816 * sizeof(dtype));
	dtype *X2_tmp_data = (dtype*)malloc(802816 * sizeof(dtype));
	dtype *X_mid_data = (dtype*)malloc(7225344 * sizeof(dtype));
	dtype *X_batch_data = (dtype*)malloc(7225344 * sizeof(dtype));

	// load input
	if(!LoadArr<dtype>("input.dat", input, INPUT_SIZE))
		return 0;

	// load stem kernel
	if(!LoadArr<ftype>("stem.0.weight.scale.dat", Kernel_stem_0_scale, 45)) return 0;
	if(!LoadArr<ftype>("stem.3.weight.scale.dat", Kernel_stem_3_scale, 64)) return 0;
	if(!LoadArr<ktype>("stem.0.weight.dat", Kernel_stem_0, 6615)) return 0;
	if(!LoadArr<ktype>("stem.3.weight.dat", Kernel_stem_3, 8640)) return 0;

	// load layer1 kernel
	if(!LoadArr<ktype>(kernel_1_dat_name[0], Kernel_seq1_0_conv1_0_0, 82944)) return 0;
	if(!LoadArr<ktype>(kernel_1_dat_name[1], Kernel_seq1_0_conv1_0_3, 27648)) return 0;
	if(!LoadArr<ktype>(kernel_1_dat_name[2], Kernel_seq1_0_conv2_0_0, 82944)) return 0;
	if(!LoadArr<ktype>(kernel_1_dat_name[3], Kernel_seq1_0_conv2_0_3, 27648)) return 0;
	if(!LoadArr<ktype>(kernel_1_dat_name[4], Kernel_seq1_1_conv1_0_0, 82944)) return 0;
	if(!LoadArr<ktype>(kernel_1_dat_name[5], Kernel_seq1_1_conv1_0_3, 27648)) return 0;
	if(!LoadArr<ktype>(kernel_1_dat_name[6], Kernel_seq1_1_conv2_0_0, 82944)) return 0;
	if(!LoadArr<ktype>(kernel_1_dat_name[7], Kernel_seq1_1_conv2_0_3, 27648)) return 0;
	// load layer kernel scale
	if(!LoadArr<ftype>("layer1.0.conv1.0.0.weight.scale.dat", Kernel_seq1_0_conv1_0_0_scale, 144)) return 0;
	if(!LoadArr<ftype>("layer1.0.conv1.0.3.weight.scale.dat", Kernel_seq1_0_conv1_0_3_scale, 64)) return 0;
	if(!LoadArr<ftype>("layer1.0.conv2.0.0.weight.scale.dat", Kernel_seq1_0_conv2_0_0_scale, 144)) return 0;
	if(!LoadArr<ftype>("layer1.0.conv2.0.3.weight.scale.dat", Kernel_seq1_0_conv2_0_3_scale, 64)) return 0;
	if(!LoadArr<ftype>("layer1.1.conv1.0.0.weight.scale.dat", Kernel_seq1_1_conv1_0_0_scale, 144)) return 0;
	if(!LoadArr<ftype>("layer1.1.conv1.0.3.weight.scale.dat", Kernel_seq1_1_conv1_0_3_scale, 64)) return 0;
	if(!LoadArr<ftype>("layer1.1.conv2.0.0.weight.scale.dat", Kernel_seq1_1_conv2_0_0_scale, 144)) return 0;
	if(!LoadArr<ftype>("layer1.1.conv2.0.3.weight.scale.dat", Kernel_seq1_1_conv2_0_3_scale, 64)) return 0;

	// load layer2 kernel
	if(!LoadArr<ktype>(kernel_2_dat_name[0], Kernel_seq2_0_conv1_0_0, 132480)) return 0;
	if(!LoadArr<ktype>(kernel_2_dat_name[1], Kernel_seq2_0_conv1_0_3, 88320)) return 0;
	if(!LoadArr<ktype>(kernel_2_dat_name[2], Kernel_seq2_0_conv2_0_0, 264960)) return 0;
	if(!LoadArr<ktype>(kernel_2_dat_name[3], Kernel_seq2_0_conv2_0_3, 88320)) return 0;
	if(!LoadArr<ktype>(kernel_2_dat_name[4], Kernel_seq2_0_downsample_0, 8192)) return 0;
	if(!LoadArr<ktype>(kernel_2_dat_name[5], Kernel_seq2_1_conv1_0_0, 331776)) return 0;
	if(!LoadArr<ktype>(kernel_2_dat_name[6], Kernel_seq2_1_conv1_0_3, 110592)) return 0;
	if(!LoadArr<ktype>(kernel_2_dat_name[7], Kernel_seq2_1_conv2_0_0, 331776)) return 0;
	if(!LoadArr<ktype>(kernel_2_dat_name[8], Kernel_seq2_1_conv2_0_3, 110592)) return 0;
	// load layer2 scale
	if(!LoadArr<ftype>("layer2.0.conv1.0.0.weight.scale.dat", Kernel_seq2_0_conv1_0_0_scale, 230)) return 0;
	if(!LoadArr<ftype>("layer2.0.conv1.0.3.weight.scale.dat", Kernel_seq2_0_conv1_0_3_scale, 128)) return 0;
	if(!LoadArr<ftype>("layer2.0.conv2.0.0.weight.scale.dat", Kernel_seq2_0_conv2_0_0_scale, 230)) return 0;
	if(!LoadArr<ftype>("layer2.0.conv2.0.3.weight.scale.dat", Kernel_seq2_0_conv2_0_3_scale, 128)) return 0;
	if(!LoadArr<ftype>("layer2.0.downsample.0.weight.scale.dat", Kernel_seq2_0_downsample_0_scale, 128)) return 0;
	if(!LoadArr<ftype>("layer2.1.conv1.0.0.weight.scale.dat", Kernel_seq2_1_conv1_0_0_scale, 288)) return 0;
	if(!LoadArr<ftype>("layer2.1.conv1.0.3.weight.scale.dat", Kernel_seq2_1_conv1_0_3_scale, 128)) return 0;
	if(!LoadArr<ftype>("layer2.1.conv2.0.0.weight.scale.dat", Kernel_seq2_1_conv2_0_0_scale, 288)) return 0;
	if(!LoadArr<ftype>("layer2.1.conv2.0.3.weight.scale.dat", Kernel_seq2_1_conv2_0_3_scale, 128)) return 0;

	// load layer3 kernel
	if(!LoadArr<ktype>(kernel_3_dat_name[0], Kernel_seq3_0_conv1_0_0, 529920)) return 0;
	if(!LoadArr<ktype>(kernel_3_dat_name[1], Kernel_seq3_0_conv1_0_3, 353280)) return 0;
	if(!LoadArr<ktype>(kernel_3_dat_name[2], Kernel_seq3_0_conv2_0_0, 1059840)) return 0;
	if(!LoadArr<ktype>(kernel_3_dat_name[3], Kernel_seq3_0_conv2_0_3, 353280)) return 0;
	if(!LoadArr<ktype>(kernel_3_dat_name[4], Kernel_seq3_0_downsample_0, 32768)) return 0;
	if(!LoadArr<ktype>(kernel_3_dat_name[5], Kernel_seq3_1_conv1_0_0, 1327104)) return 0;
	if(!LoadArr<ktype>(kernel_3_dat_name[6], Kernel_seq3_1_conv1_0_3, 442368)) return 0;
	if(!LoadArr<ktype>(kernel_3_dat_name[7], Kernel_seq3_1_conv2_0_0, 1327104)) return 0;
	if(!LoadArr<ktype>(kernel_3_dat_name[8], Kernel_seq3_1_conv2_0_3, 442368)) return 0;
	// load layer3 scale
	if(!LoadArr<ftype>("layer3.0.conv1.0.0.weight.scale.dat", Kernel_seq3_0_conv1_0_0_scale, 460)) return 0;
	if(!LoadArr<ftype>("layer3.0.conv1.0.3.weight.scale.dat", Kernel_seq3_0_conv1_0_3_scale, 256)) return 0;
	if(!LoadArr<ftype>("layer3.0.conv2.0.0.weight.scale.dat", Kernel_seq3_0_conv2_0_0_scale, 460)) return 0;
	if(!LoadArr<ftype>("layer3.0.conv2.0.3.weight.scale.dat", Kernel_seq3_0_conv2_0_3_scale, 256)) return 0;
	if(!LoadArr<ftype>("layer3.0.downsample.0.weight.scale.dat", Kernel_seq3_0_downsample_0_scale, 256)) return 0;
	if(!LoadArr<ftype>("layer3.1.conv1.0.0.weight.scale.dat", Kernel_seq3_1_conv1_0_0_scale, 576)) return 0;
	if(!LoadArr<ftype>("layer3.1.conv1.0.3.weight.scale.dat", Kernel_seq3_1_conv1_0_3_scale, 256)) return 0;
	if(!LoadArr<ftype>("layer3.1.conv2.0.0.weight.scale.dat", Kernel_seq3_1_conv2_0_0_scale, 576)) return 0;
	if(!LoadArr<ftype>("layer3.1.conv2.0.3.weight.scale.dat", Kernel_seq3_1_conv2_0_3_scale, 256)) return 0;

	// load layer4 kernel
	if(!LoadArr<ktype>(kernel_4_dat_name[0], Kernel_seq4_0_conv1_0_0, 2121984)) return 0;
	if(!LoadArr<ktype>(kernel_4_dat_name[1], Kernel_seq4_0_conv1_0_3, 1414656)) return 0;
	if(!LoadArr<ktype>(kernel_4_dat_name[2], Kernel_seq4_0_conv2_0_0, 4243968)) return 0;
	if(!LoadArr<ktype>(kernel_4_dat_name[3], Kernel_seq4_0_conv2_0_3, 1414656)) return 0;
	if(!LoadArr<ktype>(kernel_4_dat_name[4], Kernel_seq4_0_downsample_0, 131072)) return 0;
	if(!LoadArr<ktype>(kernel_4_dat_name[5], Kernel_seq4_1_conv1_0_0, 5308416)) return 0;
	if(!LoadArr<ktype>(kernel_4_dat_name[6], Kernel_seq4_1_conv1_0_3, 1769472)) return 0;
	if(!LoadArr<ktype>(kernel_4_dat_name[7], Kernel_seq4_1_conv2_0_0, 5308416)) return 0;
	if(!LoadArr<ktype>(kernel_4_dat_name[8], Kernel_seq4_1_conv2_0_3, 1769472)) return 0;
	// load layer4 scale
	if(!LoadArr<ftype>("layer4.0.conv1.0.0.weight.scale.dat", Kernel_seq4_0_conv1_0_0_scale, 921)) return 0;
	if(!LoadArr<ftype>("layer4.0.conv1.0.3.weight.scale.dat", Kernel_seq4_0_conv1_0_3_scale, 512)) return 0;
	if(!LoadArr<ftype>("layer4.0.conv2.0.0.weight.scale.dat", Kernel_seq4_0_conv2_0_0_scale, 921)) return 0;
	if(!LoadArr<ftype>("layer4.0.conv2.0.3.weight.scale.dat", Kernel_seq4_0_conv2_0_3_scale, 512)) return 0;
	if(!LoadArr<ftype>("layer4.0.downsample.0.weight.scale.dat", Kernel_seq4_0_downsample_0_scale, 512)) return 0;
	if(!LoadArr<ftype>("layer4.1.conv1.0.0.weight.scale.dat", Kernel_seq4_1_conv1_0_0_scale, 1152)) return 0;
	if(!LoadArr<ftype>("layer4.1.conv1.0.3.weight.scale.dat", Kernel_seq4_1_conv1_0_3_scale, 512)) return 0;
	if(!LoadArr<ftype>("layer4.1.conv2.0.0.weight.scale.dat", Kernel_seq4_1_conv2_0_0_scale, 1152)) return 0;
	if(!LoadArr<ftype>("layer4.1.conv2.0.3.weight.scale.dat", Kernel_seq4_1_conv2_0_3_scale, 512)) return 0;
	
	// load linear kernel
	if(!LoadArr<ktype>(fc_dat_name[0], Kernel_linear, 5120)) return 0;
	// load linear kernel scale
	if(!LoadArr<ftype>("fc.1.weight.scale.dat", Kernel_linear_scale, 10)) return 0;

	// load stem batch
	if(!LoadArr<ftype>(stem_mu_dat_name[0], Mu_stem_1, 45)) return 0;
	if(!LoadArr<ftype>(stem_var_dat_name[0], Var_stem_1, 45)) return 0;
	if(!LoadArr<ftype>(stem_gamma_dat_name[0], Gamma_stem_1, 45)) return 0;
	if(!LoadArr<ftype>(stem_bias_dat_name[0], Bias_stem_1, 45)) return 0;

	if(!LoadArr<ftype>(stem_mu_dat_name[1], Mu_stem_4, 64)) return 0;
	if(!LoadArr<ftype>(stem_var_dat_name[1], Var_stem_4, 64)) return 0;
	if(!LoadArr<ftype>(stem_gamma_dat_name[1], Gamma_stem_4, 64)) return 0;
	if(!LoadArr<ftype>(stem_bias_dat_name[1], Bias_stem_4, 64)) return 0;
	
	if(!LoadArr<ftype>(layer_1_mu_dat_name[0], Mu_seq1_0_conv1_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_mu_dat_name[1], Mu_seq1_0_conv1_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_mu_dat_name[2], Mu_seq1_0_conv2_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_mu_dat_name[3], Mu_seq1_0_conv2_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_mu_dat_name[4], Mu_seq1_1_conv1_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_mu_dat_name[5], Mu_seq1_1_conv1_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_mu_dat_name[6], Mu_seq1_1_conv2_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_mu_dat_name[7], Mu_seq1_1_conv2_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_var_dat_name[0], Var_seq1_0_conv1_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_var_dat_name[1], Var_seq1_0_conv1_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_var_dat_name[2], Var_seq1_0_conv2_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_var_dat_name[3], Var_seq1_0_conv2_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_var_dat_name[4], Var_seq1_1_conv1_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_var_dat_name[5], Var_seq1_1_conv1_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_var_dat_name[6], Var_seq1_1_conv2_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_var_dat_name[7], Var_seq1_1_conv2_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_gamma_dat_name[0], Gamma_seq1_0_conv1_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_gamma_dat_name[1], Gamma_seq1_0_conv1_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_gamma_dat_name[2], Gamma_seq1_0_conv2_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_gamma_dat_name[3], Gamma_seq1_0_conv2_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_gamma_dat_name[4], Gamma_seq1_1_conv1_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_gamma_dat_name[5], Gamma_seq1_1_conv1_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_gamma_dat_name[6], Gamma_seq1_1_conv2_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_gamma_dat_name[7], Gamma_seq1_1_conv2_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_bias_dat_name[0], Bias_seq1_0_conv1_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_bias_dat_name[1], Bias_seq1_0_conv1_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_bias_dat_name[2], Bias_seq1_0_conv2_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_bias_dat_name[3], Bias_seq1_0_conv2_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_bias_dat_name[4], Bias_seq1_1_conv1_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_bias_dat_name[5], Bias_seq1_1_conv1_1, 64)) return 0;
	if(!LoadArr<ftype>(layer_1_bias_dat_name[6], Bias_seq1_1_conv2_0_1, 144)) return 0;
	if(!LoadArr<ftype>(layer_1_bias_dat_name[7], Bias_seq1_1_conv2_1, 64)) return 0;

	if(!LoadArr<ftype>(layer_2_mu_dat_name[0], Mu_seq2_0_conv1_0_1, 230)) return 0;
	if(!LoadArr<ftype>(layer_2_mu_dat_name[1], Mu_seq2_0_conv1_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_mu_dat_name[2], Mu_seq2_0_conv2_0_1, 230)) return 0;
	if(!LoadArr<ftype>(layer_2_mu_dat_name[3], Mu_seq2_0_conv2_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_mu_dat_name[4], Mu_seq2_0_downsample_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_mu_dat_name[5], Mu_seq2_1_conv1_0_1, 288)) return 0;
	if(!LoadArr<ftype>(layer_2_mu_dat_name[6], Mu_seq2_1_conv1_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_mu_dat_name[7], Mu_seq2_1_conv2_0_1, 288)) return 0;
	if(!LoadArr<ftype>(layer_2_mu_dat_name[8], Mu_seq2_1_conv2_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_var_dat_name[0], Var_seq2_0_conv1_0_1, 230)) return 0;
	if(!LoadArr<ftype>(layer_2_var_dat_name[1], Var_seq2_0_conv1_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_var_dat_name[2], Var_seq2_0_conv2_0_1, 230)) return 0;
	if(!LoadArr<ftype>(layer_2_var_dat_name[3], Var_seq2_0_conv2_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_var_dat_name[4], Var_seq2_0_downsample_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_var_dat_name[5], Var_seq2_1_conv1_0_1, 288)) return 0;
	if(!LoadArr<ftype>(layer_2_var_dat_name[6], Var_seq2_1_conv1_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_var_dat_name[7], Var_seq2_1_conv2_0_1, 288)) return 0;
	if(!LoadArr<ftype>(layer_2_var_dat_name[8], Var_seq2_1_conv2_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_gamma_dat_name[0], Gamma_seq2_0_conv1_0_1, 230)) return 0;
	if(!LoadArr<ftype>(layer_2_gamma_dat_name[1], Gamma_seq2_0_conv1_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_gamma_dat_name[2], Gamma_seq2_0_conv2_0_1, 230)) return 0;
	if(!LoadArr<ftype>(layer_2_gamma_dat_name[3], Gamma_seq2_0_conv2_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_gamma_dat_name[4], Gamma_seq2_0_downsample_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_gamma_dat_name[5], Gamma_seq2_1_conv1_0_1, 288)) return 0;
	if(!LoadArr<ftype>(layer_2_gamma_dat_name[6], Gamma_seq2_1_conv1_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_gamma_dat_name[7], Gamma_seq2_1_conv2_0_1, 288)) return 0;
	if(!LoadArr<ftype>(layer_2_gamma_dat_name[8], Gamma_seq2_1_conv2_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_bias_dat_name[0], Bias_seq2_0_conv1_0_1, 230)) return 0;
	if(!LoadArr<ftype>(layer_2_bias_dat_name[1], Bias_seq2_0_conv1_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_bias_dat_name[2], Bias_seq2_0_conv2_0_1, 230)) return 0;
	if(!LoadArr<ftype>(layer_2_bias_dat_name[3], Bias_seq2_0_conv2_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_bias_dat_name[4], Bias_seq2_0_downsample_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_bias_dat_name[5], Bias_seq2_1_conv1_0_1, 288)) return 0;
	if(!LoadArr<ftype>(layer_2_bias_dat_name[6], Bias_seq2_1_conv1_1, 128)) return 0;
	if(!LoadArr<ftype>(layer_2_bias_dat_name[7], Bias_seq2_1_conv2_0_1, 288)) return 0;
	if(!LoadArr<ftype>(layer_2_bias_dat_name[8], Bias_seq2_1_conv2_1, 128)) return 0;

	if(!LoadArr<ftype>(layer_3_mu_dat_name[0], Mu_seq3_0_conv1_0_1, 460)) return 0;
	if(!LoadArr<ftype>(layer_3_mu_dat_name[1], Mu_seq3_0_conv1_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_mu_dat_name[2], Mu_seq3_0_conv2_0_1, 460)) return 0;
	if(!LoadArr<ftype>(layer_3_mu_dat_name[3], Mu_seq3_0_conv2_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_mu_dat_name[4], Mu_seq3_0_downsample_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_mu_dat_name[5], Mu_seq3_1_conv1_0_1, 576)) return 0;
	if(!LoadArr<ftype>(layer_3_mu_dat_name[6], Mu_seq3_1_conv1_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_mu_dat_name[7], Mu_seq3_1_conv2_0_1, 576)) return 0;
	if(!LoadArr<ftype>(layer_3_mu_dat_name[8], Mu_seq3_1_conv2_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_var_dat_name[0], Var_seq3_0_conv1_0_1, 460)) return 0;
	if(!LoadArr<ftype>(layer_3_var_dat_name[1], Var_seq3_0_conv1_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_var_dat_name[2], Var_seq3_0_conv2_0_1, 460)) return 0;
	if(!LoadArr<ftype>(layer_3_var_dat_name[3], Var_seq3_0_conv2_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_var_dat_name[4], Var_seq3_0_downsample_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_var_dat_name[5], Var_seq3_1_conv1_0_1, 576)) return 0;
	if(!LoadArr<ftype>(layer_3_var_dat_name[6], Var_seq3_1_conv1_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_var_dat_name[7], Var_seq3_1_conv2_0_1, 576)) return 0;
	if(!LoadArr<ftype>(layer_3_var_dat_name[8], Var_seq3_1_conv2_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_gamma_dat_name[0], Gamma_seq3_0_conv1_0_1, 460)) return 0;
	if(!LoadArr<ftype>(layer_3_gamma_dat_name[1], Gamma_seq3_0_conv1_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_gamma_dat_name[2], Gamma_seq3_0_conv2_0_1, 460)) return 0;
	if(!LoadArr<ftype>(layer_3_gamma_dat_name[3], Gamma_seq3_0_conv2_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_gamma_dat_name[4], Gamma_seq3_0_downsample_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_gamma_dat_name[5], Gamma_seq3_1_conv1_0_1, 576)) return 0;
	if(!LoadArr<ftype>(layer_3_gamma_dat_name[6], Gamma_seq3_1_conv1_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_gamma_dat_name[7], Gamma_seq3_1_conv2_0_1, 576)) return 0;
	if(!LoadArr<ftype>(layer_3_gamma_dat_name[8], Gamma_seq3_1_conv2_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_bias_dat_name[0], Bias_seq3_0_conv1_0_1, 460)) return 0;
	if(!LoadArr<ftype>(layer_3_bias_dat_name[1], Bias_seq3_0_conv1_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_bias_dat_name[2], Bias_seq3_0_conv2_0_1, 460)) return 0;
	if(!LoadArr<ftype>(layer_3_bias_dat_name[3], Bias_seq3_0_conv2_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_bias_dat_name[4], Bias_seq3_0_downsample_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_bias_dat_name[5], Bias_seq3_1_conv1_0_1, 576)) return 0;
	if(!LoadArr<ftype>(layer_3_bias_dat_name[6], Bias_seq3_1_conv1_1, 256)) return 0;
	if(!LoadArr<ftype>(layer_3_bias_dat_name[7], Bias_seq3_1_conv2_0_1, 576)) return 0;
	if(!LoadArr<ftype>(layer_3_bias_dat_name[8], Bias_seq3_1_conv2_1, 256)) return 0;

	if(!LoadArr<ftype>(layer_4_mu_dat_name[0], Mu_seq4_0_conv1_0_1, 921)) return 0;
	if(!LoadArr<ftype>(layer_4_mu_dat_name[1], Mu_seq4_0_conv1_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_mu_dat_name[2], Mu_seq4_0_conv2_0_1, 921)) return 0;
	if(!LoadArr<ftype>(layer_4_mu_dat_name[3], Mu_seq4_0_conv2_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_mu_dat_name[4], Mu_seq4_0_downsample_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_mu_dat_name[5], Mu_seq4_1_conv1_0_1, 1152)) return 0;
	if(!LoadArr<ftype>(layer_4_mu_dat_name[6], Mu_seq4_1_conv1_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_mu_dat_name[7], Mu_seq4_1_conv2_0_1, 1152)) return 0;
	if(!LoadArr<ftype>(layer_4_mu_dat_name[8], Mu_seq4_1_conv2_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_var_dat_name[0], Var_seq4_0_conv1_0_1, 921)) return 0;
	if(!LoadArr<ftype>(layer_4_var_dat_name[1], Var_seq4_0_conv1_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_var_dat_name[2], Var_seq4_0_conv2_0_1, 921)) return 0;
	if(!LoadArr<ftype>(layer_4_var_dat_name[3], Var_seq4_0_conv2_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_var_dat_name[4], Var_seq4_0_downsample_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_var_dat_name[5], Var_seq4_1_conv1_0_1, 1152)) return 0;
	if(!LoadArr<ftype>(layer_4_var_dat_name[6], Var_seq4_1_conv1_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_var_dat_name[7], Var_seq4_1_conv2_0_1, 1152)) return 0;
	if(!LoadArr<ftype>(layer_4_var_dat_name[8], Var_seq4_1_conv2_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_gamma_dat_name[0], Gamma_seq4_0_conv1_0_1, 921)) return 0;
	if(!LoadArr<ftype>(layer_4_gamma_dat_name[1], Gamma_seq4_0_conv1_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_gamma_dat_name[2], Gamma_seq4_0_conv2_0_1, 921)) return 0;
	if(!LoadArr<ftype>(layer_4_gamma_dat_name[3], Gamma_seq4_0_conv2_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_gamma_dat_name[4], Gamma_seq4_0_downsample_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_gamma_dat_name[5], Gamma_seq4_1_conv1_0_1, 1152)) return 0;
	if(!LoadArr<ftype>(layer_4_gamma_dat_name[6], Gamma_seq4_1_conv1_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_gamma_dat_name[7], Gamma_seq4_1_conv2_0_1, 1152)) return 0;
	if(!LoadArr<ftype>(layer_4_gamma_dat_name[8], Gamma_seq4_1_conv2_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_bias_dat_name[0], Bias_seq4_0_conv1_0_1, 921)) return 0;
	if(!LoadArr<ftype>(layer_4_bias_dat_name[1], Bias_seq4_0_conv1_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_bias_dat_name[2], Bias_seq4_0_conv2_0_1, 921)) return 0;
	if(!LoadArr<ftype>(layer_4_bias_dat_name[3], Bias_seq4_0_conv2_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_bias_dat_name[4], Bias_seq4_0_downsample_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_bias_dat_name[5], Bias_seq4_1_conv1_0_1, 1152)) return 0;
	if(!LoadArr<ftype>(layer_4_bias_dat_name[6], Bias_seq4_1_conv1_1, 512)) return 0;
	if(!LoadArr<ftype>(layer_4_bias_dat_name[7], Bias_seq4_1_conv2_0_1, 1152)) return 0;
	if(!LoadArr<ftype>(layer_4_bias_dat_name[8], Bias_seq4_1_conv2_1, 512)) return 0;

	if(!LoadArr<dtype>("output.dat", 			 output_golden, 	  OUTPUT_SIZE)) return 0;

	// ====================================
	// Function to test here:

	r2plus1d(input, output, Kernel_stem_0, Kernel_stem_3, Kernel_stem_0_scale, Kernel_stem_3_scale,
                Mu_stem_1, Mu_stem_4, Var_stem_1, Var_stem_4, Gamma_stem_1, Gamma_stem_4, Bias_stem_1, Bias_stem_4,
            Kernel_seq1_0_conv1_0_0, Kernel_seq1_0_conv1_0_3, Kernel_seq1_0_conv2_0_0, Kernel_seq1_0_conv2_0_3, Kernel_seq1_1_conv1_0_0, Kernel_seq1_1_conv1_0_3, Kernel_seq1_1_conv2_0_0, Kernel_seq1_1_conv2_0_3,
            Kernel_seq1_0_conv1_0_0_scale, Kernel_seq1_0_conv1_0_3_scale, Kernel_seq1_0_conv2_0_0_scale, Kernel_seq1_0_conv2_0_3_scale, Kernel_seq1_1_conv1_0_0_scale, Kernel_seq1_1_conv1_0_3_scale, Kernel_seq1_1_conv2_0_0_scale, Kernel_seq1_1_conv2_0_3_scale,
                Mu_seq1_0_conv1_0_1, Mu_seq1_0_conv1_1, Mu_seq1_0_conv2_0_1, Mu_seq1_0_conv2_1, Mu_seq1_1_conv1_0_1, Mu_seq1_1_conv1_1, Mu_seq1_1_conv2_0_1, Mu_seq1_1_conv2_1,
                Var_seq1_0_conv1_0_1, Var_seq1_0_conv1_1, Var_seq1_0_conv2_0_1, Var_seq1_0_conv2_1, Var_seq1_1_conv1_0_1, Var_seq1_1_conv1_1, Var_seq1_1_conv2_0_1, Var_seq1_1_conv2_1,
                Gamma_seq1_0_conv1_0_1, Gamma_seq1_0_conv1_1, Gamma_seq1_0_conv2_0_1, Gamma_seq1_0_conv2_1, Gamma_seq1_1_conv1_0_1, Gamma_seq1_1_conv1_1, Gamma_seq1_1_conv2_0_1, Gamma_seq1_1_conv2_1,
                Bias_seq1_0_conv1_0_1, Bias_seq1_0_conv1_1, Bias_seq1_0_conv2_0_1, Bias_seq1_0_conv2_1, Bias_seq1_1_conv1_0_1, Bias_seq1_1_conv1_1, Bias_seq1_1_conv2_0_1, Bias_seq1_1_conv2_1,
            Kernel_seq2_0_conv1_0_0, Kernel_seq2_0_conv1_0_3, Kernel_seq2_0_conv2_0_0, Kernel_seq2_0_conv2_0_3, Kernel_seq2_0_downsample_0, Kernel_seq2_1_conv1_0_0, Kernel_seq2_1_conv1_0_3, Kernel_seq2_1_conv2_0_0, Kernel_seq2_1_conv2_0_3,
            Kernel_seq2_0_conv1_0_0_scale, Kernel_seq2_0_conv1_0_3_scale, Kernel_seq2_0_conv2_0_0_scale, Kernel_seq2_0_conv2_0_3_scale, Kernel_seq2_0_downsample_0_scale, Kernel_seq2_1_conv1_0_0_scale, Kernel_seq2_1_conv1_0_3_scale, Kernel_seq2_1_conv2_0_0_scale, Kernel_seq2_1_conv2_0_3_scale,
                Mu_seq2_0_conv1_0_1, Mu_seq2_0_conv1_1, Mu_seq2_0_conv2_0_1, Mu_seq2_0_conv2_1, Mu_seq2_0_downsample_1, Mu_seq2_1_conv1_0_1, Mu_seq2_1_conv1_1, Mu_seq2_1_conv2_0_1, Mu_seq2_1_conv2_1,
                Var_seq2_0_conv1_0_1, Var_seq2_0_conv1_1, Var_seq2_0_conv2_0_1, Var_seq2_0_conv2_1, Var_seq2_0_downsample_1, Var_seq2_1_conv1_0_1, Var_seq2_1_conv1_1, Var_seq2_1_conv2_0_1, Var_seq2_1_conv2_1,
                Gamma_seq2_0_conv1_0_1, Gamma_seq2_0_conv1_1, Gamma_seq2_0_conv2_0_1, Gamma_seq2_0_conv2_1, Gamma_seq2_0_downsample_1, Gamma_seq2_1_conv1_0_1, Gamma_seq2_1_conv1_1, Gamma_seq2_1_conv2_0_1, Gamma_seq2_1_conv2_1,
                Bias_seq2_0_conv1_0_1, Bias_seq2_0_conv1_1, Bias_seq2_0_conv2_0_1, Bias_seq2_0_conv2_1, Bias_seq2_0_downsample_1, Bias_seq2_1_conv1_0_1, Bias_seq2_1_conv1_1, Bias_seq2_1_conv2_0_1, Bias_seq2_1_conv2_1,
            Kernel_seq3_0_conv1_0_0, Kernel_seq3_0_conv1_0_3, Kernel_seq3_0_conv2_0_0, Kernel_seq3_0_conv2_0_3, Kernel_seq3_0_downsample_0, Kernel_seq3_1_conv1_0_0, Kernel_seq3_1_conv1_0_3, Kernel_seq3_1_conv2_0_0, Kernel_seq3_1_conv2_0_3,
            Kernel_seq3_0_conv1_0_0_scale, Kernel_seq3_0_conv1_0_3_scale, Kernel_seq3_0_conv2_0_0_scale, Kernel_seq3_0_conv2_0_3_scale, Kernel_seq3_0_downsample_0_scale, Kernel_seq3_1_conv1_0_0_scale, Kernel_seq3_1_conv1_0_3_scale, Kernel_seq3_1_conv2_0_0_scale, Kernel_seq3_1_conv2_0_3_scale,
                Mu_seq3_0_conv1_0_1, Mu_seq3_0_conv1_1, Mu_seq3_0_conv2_0_1, Mu_seq3_0_conv2_1, Mu_seq3_0_downsample_1, Mu_seq3_1_conv1_0_1, Mu_seq3_1_conv1_1, Mu_seq3_1_conv2_0_1, Mu_seq3_1_conv2_1,
                Var_seq3_0_conv1_0_1, Var_seq3_0_conv1_1, Var_seq3_0_conv2_0_1, Var_seq3_0_conv2_1, Var_seq3_0_downsample_1, Var_seq3_1_conv1_0_1, Var_seq3_1_conv1_1, Var_seq3_1_conv2_0_1, Var_seq3_1_conv2_1,
                Gamma_seq3_0_conv1_0_1, Gamma_seq3_0_conv1_1, Gamma_seq3_0_conv2_0_1, Gamma_seq3_0_conv2_1, Gamma_seq3_0_downsample_1, Gamma_seq3_1_conv1_0_1, Gamma_seq3_1_conv1_1, Gamma_seq3_1_conv2_0_1, Gamma_seq3_1_conv2_1,
                Bias_seq3_0_conv1_0_1, Bias_seq3_0_conv1_1, Bias_seq3_0_conv2_0_1, Bias_seq3_0_conv2_1, Bias_seq3_0_downsample_1, Bias_seq3_1_conv1_0_1, Bias_seq3_1_conv1_1, Bias_seq3_1_conv2_0_1, Bias_seq3_1_conv2_1,
            Kernel_seq4_0_conv1_0_0, Kernel_seq4_0_conv1_0_3, Kernel_seq4_0_conv2_0_0, Kernel_seq4_0_conv2_0_3, Kernel_seq4_0_downsample_0, Kernel_seq4_1_conv1_0_0, Kernel_seq4_1_conv1_0_3, Kernel_seq4_1_conv2_0_0, Kernel_seq4_1_conv2_0_3,
            Kernel_seq4_0_conv1_0_0_scale, Kernel_seq4_0_conv1_0_3_scale, Kernel_seq4_0_conv2_0_0_scale, Kernel_seq4_0_conv2_0_3_scale, Kernel_seq4_0_downsample_0_scale, Kernel_seq4_1_conv1_0_0_scale, Kernel_seq4_1_conv1_0_3_scale, Kernel_seq4_1_conv2_0_0_scale, Kernel_seq4_1_conv2_0_3_scale,
                Mu_seq4_0_conv1_0_1, Mu_seq4_0_conv1_1, Mu_seq4_0_conv2_0_1, Mu_seq4_0_conv2_1, Mu_seq4_0_downsample_1, Mu_seq4_1_conv1_0_1, Mu_seq4_1_conv1_1, Mu_seq4_1_conv2_0_1, Mu_seq4_1_conv2_1,
                Var_seq4_0_conv1_0_1, Var_seq4_0_conv1_1, Var_seq4_0_conv2_0_1, Var_seq4_0_conv2_1, Var_seq4_0_downsample_1, Var_seq4_1_conv1_0_1, Var_seq4_1_conv1_1, Var_seq4_1_conv2_0_1, Var_seq4_1_conv2_1,
                Gamma_seq4_0_conv1_0_1, Gamma_seq4_0_conv1_1, Gamma_seq4_0_conv2_0_1, Gamma_seq4_0_conv2_1, Gamma_seq4_0_downsample_1, Gamma_seq4_1_conv1_0_1, Gamma_seq4_1_conv1_1, Gamma_seq4_1_conv2_0_1, Gamma_seq4_1_conv2_1,
                Bias_seq4_0_conv1_0_1, Bias_seq4_0_conv1_1, Bias_seq4_0_conv2_0_1, Bias_seq4_0_conv2_1, Bias_seq4_0_downsample_1, Bias_seq4_1_conv1_0_1, Bias_seq4_1_conv1_1, Bias_seq4_1_conv2_0_1, Bias_seq4_1_conv2_1,
            Kernel_linear, Kernel_linear_scale,
			X_stem_1, X_stem_2, X_seq, X_adap, X_tmp_data, X2_data, X2_tmp_data, X_mid_data, X_batch_data);

	// calculate errors
	ftype errors;
	errors = 100 * ftype(validate_file(output, output_golden, OUTPUT_STRUCTURE, outfile)) / OUTPUT_SIZE;
	
	if (errors != 0) {
		printf("[FAIL] There are some errors QQ, error rate: %f%\n", errors);
		outfile << "[FAIL] There are some errors QQ, error rate: "<<errors<<"%\n";
	}
	else {
		printf("[PASS] Congratulation! All results are correct\n");
		outfile<<"[PASS] Congratulation! All results are correct\n";
	}

	outfile.close();

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
	free(X_stem_1);
	free(X_stem_2);
	free(X_seq);
	free(X_adap);
	free(X_tmp_data);
	free(X2_data);
	free(X2_tmp_data);
	free(X_mid_data);
	free(X_batch_data);

	return 0;
}