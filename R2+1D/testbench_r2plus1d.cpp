#include "test_utility.h"

// modify these value to test different layers
// remember to use corresponding input.dat and output.dat in vitis/visual studio project
// and r2plus1d.cpp
#define INPUT_SIZE 602112
#define OUTPUT_SIZE 3211264
int_t OUTPUT_STRUCTURE[5] = {1, 64, 16, 56, 56};

string kernel_1_dat_name[8] = {"layer1.0.conv1.0.0.weight.dat", "layer1.0.conv1.0.3.weight.dat", "layer1.0.conv2.0.0.weight.dat", "layer1.0.conv2.0.3.weight.dat", "layer1.1.conv1.0.0.weight.dat", "layer1.1.conv1.0.3.weight.dat", "layer1.1.conv2.0.0.weight.dat", "layer1.1.conv2.0.3.weight.dat"};
string kernel_2_dat_name[9] = {"layer2.0.conv1.0.0.weight.dat", "layer2.0.conv1.0.3.weight.dat", "layer2.0.conv2.0.0.weight.dat", "layer2.0.conv2.0.3.weight.dat", "layer2.0.downsample.0.weight.dat", "layer2.1.conv1.0.0.weight.dat", "layer2.1.conv1.0.3.weight.dat", "layer2.1.conv2.0.0.weight.dat", "layer2.1.conv2.0.3.weight.dat"};
string kernel_3_dat_name[9] = {"layer3.0.conv1.0.0.weight.dat", "layer3.0.conv1.0.3.weight.dat", "layer3.0.conv2.0.0.weight.dat", "layer3.0.conv2.0.3.weight.dat", "layer3.0.downsample.0.weight.dat", "layer3.1.conv1.0.0.weight.dat", "layer3.1.conv1.0.3.weight.dat", "layer3.1.conv2.0.0.weight.dat", "layer3.1.conv2.0.3.weight.dat"};
string kernel_4_dat_name[9] = {"layer4.0.conv1.0.0.weight.dat", "layer4.0.conv1.0.3.weight.dat", "layer4.0.conv2.0.0.weight.dat", "layer4.0.conv2.0.3.weight.dat", "layer4.0.downsample.0.weight.dat", "layer4.1.conv1.0.0.weight.dat", "layer4.1.conv1.0.3.weight.dat", "layer4.1.conv2.0.0.weight.dat", "layer4.1.conv2.0.3.weight.dat"};
string fc_dat_name[1] = {"fc.1.weight.dat"};

int_t main() {
	// create a output txt file
	ofstream outfile;
	outfile.open("results.dat");
	if (!outfile.is_open()) {
		cout << "Error opening file" << endl;
		return 0;
	}

	dtype *input = (dtype*)malloc(INPUT_SIZE * sizeof(dtype));
	dtype *output = (dtype*)malloc(OUTPUT_SIZE * sizeof(dtype));
	dtype *output_golden = (dtype*)malloc(OUTPUT_SIZE * sizeof(dtype));

	// malloc buffer
	dtype *X_stem_1 = (dtype*)malloc(2257920 * sizeof(dtype));
	dtype *X_stem_2 = (dtype*)malloc(3211264 * sizeof(dtype));
	dtype *X_data = (dtype*)malloc(3211264 * sizeof(dtype));
	dtype *X2_data = (dtype*)malloc(802816 * sizeof(dtype));
	dtype *X3_data = (dtype*)malloc(200704 * sizeof(dtype));
	dtype *X_seq = (dtype*)malloc(50176 * sizeof(dtype));
	dtype *X_adap = (dtype*)malloc(512 * sizeof(dtype));
	dtype *X_tmp_data = (dtype*)malloc(3211264 * sizeof(dtype));
	dtype *X_batch_data = (dtype*)malloc(7225344 * sizeof(dtype));
	dtype *X_mid_data = (dtype*)malloc(7225344 * sizeof(dtype));

	// load kernel
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

	ktype *Kernel_seq2_0_conv1_0_0 = (ktype*)malloc(132480 * sizeof(ktype));
	ktype *Kernel_seq2_0_conv1_0_3 = (ktype*)malloc(88320 * sizeof(ktype));
	ktype *Kernel_seq2_0_conv2_0_0 = (ktype*)malloc(264960 * sizeof(ktype));
	ktype *Kernel_seq2_0_conv2_0_3 = (ktype*)malloc(88320 * sizeof(ktype));
	ktype *Kernel_seq2_0_downsample_0 = (ktype*)malloc(8192 * sizeof(ktype));
	ktype *Kernel_seq2_1_conv1_0_0 = (ktype*)malloc(331776 * sizeof(ktype));
	ktype *Kernel_seq2_1_conv1_0_3 = (ktype*)malloc(110592 * sizeof(ktype));
	ktype *Kernel_seq2_1_conv2_0_0 = (ktype*)malloc(331776 * sizeof(ktype));
	ktype *Kernel_seq2_1_conv2_0_3 = (ktype*)malloc(110592 * sizeof(ktype));

	ktype *Kernel_seq3_0_conv1_0_0 = (ktype*)malloc(529920 * sizeof(ktype));
	ktype *Kernel_seq3_0_conv1_0_3 = (ktype*)malloc(353280 * sizeof(ktype));
	ktype *Kernel_seq3_0_conv2_0_0 = (ktype*)malloc(1059840 * sizeof(ktype));
	ktype *Kernel_seq3_0_conv2_0_3 = (ktype*)malloc(353280 * sizeof(ktype));
	ktype *Kernel_seq3_0_downsample_0 = (ktype*)malloc(32768 * sizeof(ktype));
	ktype *Kernel_seq3_1_conv1_0_0 = (ktype*)malloc(1327104 * sizeof(ktype));
	ktype *Kernel_seq3_1_conv1_0_3 = (ktype*)malloc(442368 * sizeof(ktype));
	ktype *Kernel_seq3_1_conv2_0_0 = (ktype*)malloc(1327104 * sizeof(ktype));
	ktype *Kernel_seq3_1_conv2_0_3 = (ktype*)malloc(442368 * sizeof(ktype));

	ktype *Kernel_seq4_0_conv1_0_0 = (ktype*)malloc(2121984 * sizeof(ktype));
	ktype *Kernel_seq4_0_conv1_0_3 = (ktype*)malloc(1414656 * sizeof(ktype));
	ktype *Kernel_seq4_0_conv2_0_0 = (ktype*)malloc(4243968 * sizeof(ktype));
	ktype *Kernel_seq4_0_conv2_0_3 = (ktype*)malloc(1414656 * sizeof(ktype));
	ktype *Kernel_seq4_0_downsample_0 = (ktype*)malloc(131072 * sizeof(ktype));
	ktype *Kernel_seq4_1_conv1_0_0 = (ktype*)malloc(5308416 * sizeof(ktype));
	ktype *Kernel_seq4_1_conv1_0_3 = (ktype*)malloc(1769472 * sizeof(ktype));
	ktype *Kernel_seq4_1_conv2_0_0 = (ktype*)malloc(5308416 * sizeof(ktype));
	ktype *Kernel_seq4_1_conv2_0_3 = (ktype*)malloc(1769472 * sizeof(ktype));

	ktype *Kernel_linear = (ktype*)malloc(5120 * sizeof(ktype));

	// load stem kernel
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

	// // load layer2 kernel
	// if(!LoadArr<ktype>(kernel_2_dat_name[0], Kernel_seq2_0_conv1_0_0, 132480)) return 0;
	// if(!LoadArr<ktype>(kernel_2_dat_name[1], Kernel_seq2_0_conv1_0_3, 88320)) return 0;
	// if(!LoadArr<ktype>(kernel_2_dat_name[2], Kernel_seq2_0_conv2_0_0, 264960)) return 0;
	// if(!LoadArr<ktype>(kernel_2_dat_name[3], Kernel_seq2_0_conv2_0_3, 88320)) return 0;
	// if(!LoadArr<ktype>(kernel_2_dat_name[4], Kernel_seq2_0_downsample_0, 8192)) return 0;
	// if(!LoadArr<ktype>(kernel_2_dat_name[5], Kernel_seq2_1_conv1_0_0, 331776)) return 0;
	// if(!LoadArr<ktype>(kernel_2_dat_name[6], Kernel_seq2_1_conv1_0_3, 110592)) return 0;
	// if(!LoadArr<ktype>(kernel_2_dat_name[7], Kernel_seq2_1_conv2_0_0, 331776)) return 0;
	// if(!LoadArr<ktype>(kernel_2_dat_name[8], Kernel_seq2_1_conv2_0_3, 110592)) return 0;

	// // load layer3 kernel
	// if(!LoadArr<ktype>(kernel_3_dat_name[0], Kernel_seq3_0_conv1_0_0, 529920)) return 0;
	// if(!LoadArr<ktype>(kernel_3_dat_name[1], Kernel_seq3_0_conv1_0_3, 353280)) return 0;
	// if(!LoadArr<ktype>(kernel_3_dat_name[2], Kernel_seq3_0_conv2_0_0, 1059840)) return 0;
	// if(!LoadArr<ktype>(kernel_3_dat_name[3], Kernel_seq3_0_conv2_0_3, 353280)) return 0;
	// if(!LoadArr<ktype>(kernel_3_dat_name[4], Kernel_seq3_0_downsample_0, 32768)) return 0;
	// if(!LoadArr<ktype>(kernel_3_dat_name[5], Kernel_seq3_1_conv1_0_0, 1327104)) return 0;
	// if(!LoadArr<ktype>(kernel_3_dat_name[6], Kernel_seq3_1_conv1_0_3, 442368)) return 0;
	// if(!LoadArr<ktype>(kernel_3_dat_name[7], Kernel_seq3_1_conv2_0_0, 1327104)) return 0;
	// if(!LoadArr<ktype>(kernel_3_dat_name[8], Kernel_seq3_1_conv2_0_3, 442368)) return 0;

	// // load layer4 kernel
	// if(!LoadArr<ktype>(kernel_4_dat_name[0], Kernel_seq4_0_conv1_0_0, 2121984)) return 0;
	// if(!LoadArr<ktype>(kernel_4_dat_name[1], Kernel_seq4_0_conv1_0_3, 1414656)) return 0;
	// if(!LoadArr<ktype>(kernel_4_dat_name[2], Kernel_seq4_0_conv2_0_0, 4243968)) return 0;
	// if(!LoadArr<ktype>(kernel_4_dat_name[3], Kernel_seq4_0_conv2_0_3, 1414656)) return 0;
	// if(!LoadArr<ktype>(kernel_4_dat_name[4], Kernel_seq4_0_downsample_0, 131072)) return 0;
	// if(!LoadArr<ktype>(kernel_4_dat_name[5], Kernel_seq4_1_conv1_0_0, 5308416)) return 0;
	// if(!LoadArr<ktype>(kernel_4_dat_name[6], Kernel_seq4_1_conv1_0_3, 1769472)) return 0;
	// if(!LoadArr<ktype>(kernel_4_dat_name[7], Kernel_seq4_1_conv2_0_0, 5308416)) return 0;
	// if(!LoadArr<ktype>(kernel_4_dat_name[8], Kernel_seq4_1_conv2_0_3, 1769472)) return 0;

	// // load linear kernel
	// if(!LoadArr<ktype>(fc_dat_name[0], Kernel_linear, 5120)) return 0;

	// load input / output
	if(!LoadArr<dtype>("input.dat", 					input, 			INPUT_SIZE)) return 0;
	if(!LoadArr<dtype>("output.dat", 			 output_golden, 	  OUTPUT_SIZE)) return 0;

	// ====================================
	// Function to test here:

	r2plus1d(input, Kernel_stem_0, Kernel_stem_3, 
            Kernel_seq1_0_conv1_0_0, Kernel_seq1_0_conv1_0_3, Kernel_seq1_0_conv2_0_0, Kernel_seq1_0_conv2_0_3, Kernel_seq1_1_conv1_0_0, Kernel_seq1_1_conv1_0_3, Kernel_seq1_1_conv2_0_0, Kernel_seq1_1_conv2_0_3,
            Kernel_seq2_0_conv1_0_0, Kernel_seq2_0_conv1_0_3, Kernel_seq2_0_conv2_0_0, Kernel_seq2_0_conv2_0_3, Kernel_seq2_0_downsample_0, Kernel_seq2_1_conv1_0_0, Kernel_seq2_1_conv1_0_3, Kernel_seq2_1_conv2_0_0, Kernel_seq2_1_conv2_0_3,
            Kernel_seq3_0_conv1_0_0, Kernel_seq3_0_conv1_0_3, Kernel_seq3_0_conv2_0_0, Kernel_seq3_0_conv2_0_3, Kernel_seq3_0_downsample_0, Kernel_seq3_1_conv1_0_0, Kernel_seq3_1_conv1_0_3, Kernel_seq3_1_conv2_0_0, Kernel_seq3_1_conv2_0_3,
            Kernel_seq4_0_conv1_0_0, Kernel_seq4_0_conv1_0_3, Kernel_seq4_0_conv2_0_0, Kernel_seq4_0_conv2_0_3, Kernel_seq4_0_downsample_0, Kernel_seq4_1_conv1_0_0, Kernel_seq4_1_conv1_0_3, Kernel_seq4_1_conv2_0_0, Kernel_seq4_1_conv2_0_3,
            Kernel_linear, 
			X_stem_1, X_stem_2, X_data, X2_data, X3_data, X_seq, X_adap, output,
			X_tmp_data, X_batch_data, X_mid_data);

	// calculate errors
	ftype errors;
	errors = 100 * ftype(validate_file(X_data, output_golden, OUTPUT_STRUCTURE, outfile)) / OUTPUT_SIZE;
	
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
	free(X_data);
	free(X2_data);
	free(X3_data);
	free(X_seq);
	free(X_adap);
	free(X_tmp_data);
	free(X_batch_data);
	free(X_mid_data);

	return 0;
}
