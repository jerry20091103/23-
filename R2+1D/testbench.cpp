#include "test_utility.h"

// !defines: switch between different testing modes.
#define separate_test 0
#define full_test 1
// modify this:
#define TEST_MODE separate_test

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

string stem_mu_dat_name[2] = {"stem.1.running_mean.dat", "stem.4.running_mean.dat"};
string stem_var_dat_name[2] = {"stem.1.running_var.dat", "stem.4.running_var.dat"};
string stem_gamma_dat_name[2] = {"stem.1.weight.dat", "stem.4.weight.dat"};
string stem_bias_dat_name[2] = {"stem.1.bias.dat", "stem.4.bias.dat"};

int_t main()
{
	// create a output txt file
	ofstream outfile;
	outfile.open("results.txt");

    ftype errors = 0;

    dtype *input = (dtype*)malloc(602112 * sizeof(dtype));
    dtype *output = (dtype*)malloc(3211264 * sizeof(dtype));
    dtype *golden = (dtype*)malloc(3211264 * sizeof(dtype));

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

	// load input
	if(!LoadArr<dtype>("input.dat", input, 602112))
		return 0;

	// load stem kernel
	if(!LoadArr<ftype>("stem.0.weight.scale.dat", Kernel_stem_0_scale, 45)) return 0;
	if(!LoadArr<ftype>("stem.3.weight.scale.dat", Kernel_stem_3_scale, 64)) return 0;
	if(!LoadArr<ktype>("stem.0.weight.dat", Kernel_stem_0, 6615)) return 0;
	if(!LoadArr<ktype>("stem.3.weight.dat", Kernel_stem_3, 8640)) return 0;

    // load stem batch
	if(!LoadArr<ftype>(stem_mu_dat_name[0], Mu_stem_1, 45)) return 0;
	if(!LoadArr<ftype>(stem_var_dat_name[0], Var_stem_1, 45)) return 0;
	if(!LoadArr<ftype>(stem_gamma_dat_name[0], Gamma_stem_1, 45)) return 0;
	if(!LoadArr<ftype>(stem_bias_dat_name[0], Bias_stem_1, 45)) return 0;

	if(!LoadArr<ftype>(stem_mu_dat_name[1], Mu_stem_4, 64)) return 0;
	if(!LoadArr<ftype>(stem_var_dat_name[1], Var_stem_4, 64)) return 0;
	if(!LoadArr<ftype>(stem_gamma_dat_name[1], Gamma_stem_4, 64)) return 0;
	if(!LoadArr<ftype>(stem_bias_dat_name[1], Bias_stem_4, 64)) return 0;

#if TEST_MODE == separate_test
    // ==========================================================
    // Conv3d1
    cout << "==> Conv3d1\n";
	outfile << "==> Conv3d1\n";
    int_t X_num[5] = {1, 3, D_, 112, 112};
    int_t X_mid_num[5] = {1, 45, D_, 56, 56};
    int_t Kernel_num_1[3] = {1, 7, 7};
    int_t stride_1[3] = {1, 2, 2};
    int_t padding_1[3] = {0, 3, 3};
    Conv3d(input, X_num, output, X_mid_num, Kernel_stem_0, Kernel_num_1, Kernel_stem_0_scale, stride_1, padding_1, 3.756307810544967651e-02 ,56 , 0.4609071612358093262, 60);
	

    if(!LoadArr<dtype>("Conv3d1output.dat", golden, 2257920)) return 0;
    errors += 100 * ftype(validate_file(output, golden, X_mid_num, outfile)) / 2257920;

    // BatchNorm3d1
    cout << "==> BatchNorm3d1\n";
	outfile << "==> BatchNorm3d1\n";
    if(!LoadArr<dtype>("Conv3d1output.dat", output, 2257920)) return 0;
    BatchNorm3d(output, X_mid_num, Mu_stem_1, Var_stem_1, Gamma_stem_1, Bias_stem_1, 0.4609071612358093262, 60, 0.07323520630598068237, 55);	
	if(!LoadArr<dtype>("BatchNorm3d1output.dat", golden, 2257920)) return 0;
    errors += 100 * ftype(validate_file(output, golden, X_mid_num, outfile)) / 2257920;

    // ReLU1
    cout << "==> ReLU1\n";
	outfile << "==> ReLU1\n";
    if(!LoadArr<dtype>("BatchNorm3d1output.dat", output, 2257920)) return 0;
    ReLU(output, X_mid_num, 55);
    if(!LoadArr<dtype>("ReLU1output.dat", golden, 2257920)) return 0;
    errors += 100 * ftype(validate_file(output, golden, X_mid_num, outfile)) / 2257920;

    // ==========================================================

    // Conv3d2
    cout << "==> Conv3d2\n";
	outfile << "==> Conv3d2\n";
    int_t X_out_num[5] = {1, 64, D_, 56, 56};
    int_t Kernel_num_2[3] = {3, 1, 1};
    int_t stride_2[3] = {1, 1, 1};
    int_t padding_2[3] = {1, 0, 0};
    if(!LoadArr<dtype>("ReLU1output.dat", golden, 2257920)) return 0;
    Conv3d(golden, X_mid_num, output, X_out_num, Kernel_stem_3, Kernel_num_2, Kernel_stem_3_scale, stride_2, padding_2, 0.07323520630598068237, 55, 0.09311912953853607178, 70);	
	if(!LoadArr<dtype>("Conv3d2output.dat", golden, 3211264)) return 0;
    errors += 100 * ftype(validate_file(output, golden, X_out_num, outfile)) / 3211264;

    // BatchNorm3d2
    cout << "==> BatchNorm3d2\n";
	outfile << "==> BatchNorm3d2\n";
    if(!LoadArr<dtype>("Conv3d2output.dat", output, 3211264)) return 0;
    BatchNorm3d(output, X_out_num, Mu_stem_4, Var_stem_4, Gamma_stem_4, Bias_stem_4, 0.09311912953853607178, 70, 0.07423608750104904175, 65);
    if(!LoadArr<dtype>("BatchNorm3d2output.dat", golden, 3211264)) return 0;
    errors += 100 * ftype(validate_file(output, golden, X_out_num, outfile)) / 3211264;
    
    // ReLU2
    cout << "==> ReLU2\n";
	outfile << "==> ReLU2\n";
    if(!LoadArr<dtype>("BatchNorm3d2output.dat", output, 3211264)) return 0;
    ReLU(output, X_out_num, 65);
    
	if(!LoadArr<dtype>("ReLu2output.dat", golden, 3211264)) return 0;
	errors += 100 * ftype(validate_file(output, golden, X_out_num, outfile)) / 3211264;
    // ==========================================================
#endif

#if TEST_MODE == full_test
    // R2Plus1dStem
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
            Kernel_linear, Kernel_linear_scale);

    // calculate errors
    if(!LoadArr<dtype>("output.dat", golden, 3211264)) return 0;
	int_t X_num_cal[5] = {1, 64, D_, 56, 56};
	errors = 100 * ftype(validate_file(output, golden, X_num_cal, outfile)) / 3211264;
#endif


	if (errors != 0)
	{
		printf("[FAIL] There are some errors QQ, error rate: %f%\n", errors);
		outfile<<"[FAIL] There are some errors QQ, error rate: "<<errors<<"%\n";
	}
	else
	{
		printf("[PASS] Congratulation! All results are correct\n");
		outfile<<"[PASS] Congratulation! All results are correct\n";
	}

	outfile.close();

    free(input);
    free(output);
    free(golden);

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