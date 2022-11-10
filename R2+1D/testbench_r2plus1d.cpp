#include "test_utility.h"

// modify these value to test different layers
// remember to use corresponding input.dat and output.dat in vitis/visual studio project
// and r2plus1d.cpp
#define INPUT_SIZE 602112
#define OUTPUT_SIZE 10
int_t OUTPUT_STRUCTURE[5] = { 1, 10, 1, 1, 1 };

string kernel_1_dat_name[8] = {"layer1.0.conv1.0.0.weight.dat", "layer1.0.conv1.0.3.weight.dat", "layer1.0.conv2.0.0.weight.dat", "layer1.0.conv2.0.3.weight.dat", "layer1.1.conv1.0.0.weight.dat", "layer1.1.conv1.0.3.weight.dat", "layer1.1.conv2.0.0.weight.dat", "layer1.1.conv2.0.3.weight.dat"};
string kernel_2_dat_name[9] = {"layer2.0.conv1.0.0.weight.dat", "layer2.0.conv1.0.3.weight.dat", "layer2.0.conv2.0.0.weight.dat", "layer2.0.conv2.0.3.weight.dat", "layer2.0.downsample.0.weight.dat", "layer2.1.conv1.0.0.weight.dat", "layer2.1.conv1.0.3.weight.dat", "layer2.1.conv2.0.0.weight.dat", "layer2.1.conv2.0.3.weight.dat"};
string kernel_3_dat_name[9] = {"layer3.0.conv1.0.0.weight.dat", "layer3.0.conv1.0.3.weight.dat", "layer3.0.conv2.0.0.weight.dat", "layer3.0.conv2.0.3.weight.dat", "layer3.0.downsample.0.weight.dat", "layer3.1.conv1.0.0.weight.dat", "layer3.1.conv1.0.3.weight.dat", "layer3.1.conv2.0.0.weight.dat", "layer3.1.conv2.0.3.weight.dat"};
string kernel_4_dat_name[9] = {"layer4.0.conv1.0.0.weight.dat", "layer4.0.conv1.0.3.weight.dat", "layer4.0.conv2.0.0.weight.dat", "layer4.0.conv2.0.3.weight.dat", "layer4.0.downsample.0.weight.dat", "layer4.1.conv1.0.0.weight.dat", "layer4.1.conv1.0.3.weight.dat", "layer4.1.conv2.0.0.weight.dat", "layer4.1.conv2.0.3.weight.dat"};
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
	dtype *X2_data = (dtype*)malloc(802816 * sizeof(dtype));
	dtype *X3_data = (dtype*)malloc(200704 * sizeof(dtype));
	dtype *X_seq = (dtype*)malloc(50176 * sizeof(dtype));
	dtype *X_adap = (dtype*)malloc(512 * sizeof(dtype));
	dtype *X_tmp_data = (dtype*)malloc(3211264 * sizeof(dtype));
	dtype *X2_tmp_data = (dtype*)malloc(802816 * sizeof(dtype));
	dtype *X3_tmp_data = (dtype*)malloc(200704 * sizeof(dtype));
	dtype *X4_tmp_data = (dtype*)malloc(50176 * sizeof(dtype));
	dtype *X_batch_data = (dtype*)malloc(7225344 * sizeof(dtype));
	dtype *X2_batch_data = (dtype*)malloc(2885120 * sizeof(dtype));
	dtype *X3_batch_data = (dtype*)malloc(721280 * sizeof(dtype));
	dtype *X4_batch_data = (dtype*)malloc(180516 * sizeof(dtype));
	dtype *X_mid_data = (dtype*)malloc(7225344 * sizeof(dtype));
	dtype *X2_mid_data = (dtype*)malloc(2885120 * sizeof(dtype));
	dtype *X3_mid_data = (dtype*)malloc(721280 * sizeof(dtype));
	dtype *X4_mid_data = (dtype*)malloc(180516 * sizeof(dtype));

	// load input
	if(!LoadArr<dtype>("input.dat", input, INPUT_SIZE))
		return 0;

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
	
	// load linear kernel
	if(!LoadArr<ktype>(fc_dat_name[0], Kernel_linear, 5120)) return 0;

	if(!LoadArr<dtype>("output.dat", 			 output_golden, 	  OUTPUT_SIZE)) return 0;

	// ====================================
	// Function to test here:

	r2plus1d(input, Kernel_stem_0, Kernel_stem_3, 
            Kernel_seq1_0_conv1_0_0, Kernel_seq1_0_conv1_0_3, Kernel_seq1_0_conv2_0_0, Kernel_seq1_0_conv2_0_3, Kernel_seq1_1_conv1_0_0, Kernel_seq1_1_conv1_0_3, Kernel_seq1_1_conv2_0_0, Kernel_seq1_1_conv2_0_3,
            Kernel_seq2_0_conv1_0_0, Kernel_seq2_0_conv1_0_3, Kernel_seq2_0_conv2_0_0, Kernel_seq2_0_conv2_0_3, Kernel_seq2_0_downsample_0, Kernel_seq2_1_conv1_0_0, Kernel_seq2_1_conv1_0_3, Kernel_seq2_1_conv2_0_0, Kernel_seq2_1_conv2_0_3,
            Kernel_seq3_0_conv1_0_0, Kernel_seq3_0_conv1_0_3, Kernel_seq3_0_conv2_0_0, Kernel_seq3_0_conv2_0_3, Kernel_seq3_0_downsample_0, Kernel_seq3_1_conv1_0_0, Kernel_seq3_1_conv1_0_3, Kernel_seq3_1_conv2_0_0, Kernel_seq3_1_conv2_0_3,
            Kernel_seq4_0_conv1_0_0, Kernel_seq4_0_conv1_0_3, Kernel_seq4_0_conv2_0_0, Kernel_seq4_0_conv2_0_3, Kernel_seq4_0_downsample_0, Kernel_seq4_1_conv1_0_0, Kernel_seq4_1_conv1_0_3, Kernel_seq4_1_conv2_0_0, Kernel_seq4_1_conv2_0_3,
            Kernel_linear, 
			X_stem_1, X_stem_2, X2_data, X3_data, X_seq, X_adap, output,
			X_tmp_data, X2_tmp_data, X3_tmp_data, X4_tmp_data, 
			X_batch_data, X2_batch_data, X3_batch_data, X4_batch_data,
			X_mid_data, X2_mid_data, X3_mid_data, X4_mid_data);

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

	dtype *X_batch_data_golden = (dtype*)malloc(7225344 * sizeof(dtype));
	LoadArr("X_batch_data_golden.dat", X_batch_data_golden, 3211264);
	int X_batch_data_structure[5] = { 1, 64, 16, 56, 56 };
	outfile << "X_batch_data: " << endl;
	outfile << "error rate: " << validate_file(X_batch_data, X_batch_data_golden, X_batch_data_structure, outfile) / 3211264.0f * 100 << endl;
	outfile << "X_batch_data end" << endl << endl;

	dtype *X2_mid_data_golden = (dtype*)malloc(1806336 * sizeof(dtype));
	LoadArr("X2_mid_data_golden.dat", X2_mid_data_golden, 1806336);
	int X2_mid_data_structure[5] = { 1, 1, 1, 1, 1806336 };
	outfile << "X2_mid_data: " << endl;
	outfile << "error rate: " << validate_file(X2_mid_data, X2_mid_data_golden, X2_mid_data_structure, outfile) / 1806336.0f * 100 << endl;
	outfile << "X2_mid_data end" << endl << endl;

	dtype *X2_batch_data_golden = (dtype*)malloc(2885120 * sizeof(dtype));
	LoadArr("X2_batch_data_golden.dat", X2_batch_data_golden, 802816);
	int X2_batch_data_structure[5] = { 1, 128, 8, 28, 28 };
	outfile << "X2_batch_data: " << endl;
	outfile << "error rate: " << validate_file(X2_batch_data, X2_batch_data_golden, X2_batch_data_structure, outfile) / 802816.0f * 100 << endl;
	outfile << "X2_batch_data end" << endl << endl;

	dtype *X2_data_golden = (dtype*)malloc(802816 * sizeof(dtype));
	LoadArr("X2_data_golden.dat", X2_data_golden, 802816);
	int X2_data_structure[5] = { 1, 128, 8, 28, 28 };
	outfile << "X2_data: " << endl;
	outfile << "error rate: " << validate_file(X2_data, X2_data_golden, X2_data_structure, outfile) / 802816.0f * 100 << endl;
	outfile << "X2_data end" << endl << endl;

	dtype *X3_mid_data_golden = (dtype*)malloc(451584 * sizeof(dtype));
	LoadArr("X3_mid_data_golden.dat", X3_mid_data_golden, 451584);
	int X3_mid_data_structure[5] = { 1, 1, 1, 1, 451584 };
	outfile << "X3_mid_data: " << endl;
	outfile << "error rate: " << validate_file(X3_mid_data, X3_mid_data_golden, X3_mid_data_structure, outfile) / 451584.0f * 100 << endl;
	outfile << "X3_mid_data end" << endl << endl;

	dtype *X3_batch_data_golden = (dtype*)malloc(721280 * sizeof(dtype));
	LoadArr("X3_batch_data_golden.dat", X3_batch_data_golden, 200704);
	int X3_batch_data_structure[5] = { 1, 256, 4, 14, 14 };
	outfile << "X3_batch_data: " << endl;
	outfile << "error rate: " << validate_file(X3_batch_data, X3_batch_data_golden, X3_batch_data_structure, outfile) / 200704.0f * 100 << endl;
	outfile << "X3_batch_data end" << endl << endl;

	dtype *X3_data_golden = (dtype*)malloc(200704 * sizeof(dtype));
	LoadArr("X3_data_golden.dat", X3_data_golden, 200704);
	int X3_data_structure[5] = { 1, 256, 4, 14, 14 };
	outfile << "X3_data: " << endl;
	outfile << "error rate: " << validate_file(X3_data, X3_data_golden, X3_data_structure, outfile) / 200704.0f * 100 << endl;
	outfile << "X3_data end" << endl << endl;

	dtype *X4_tmp_data_golden = (dtype*)malloc(50176 * sizeof(dtype));
	LoadArr("X4_tmp_data_golden.dat", X4_tmp_data_golden, 50176);
	int X4_tmp_data_structure[5] = { 1, 512, 2, 2, 7 };
	outfile << "X4_tmp_data: " << endl;
	outfile << "error rate: " << validate_file(X4_tmp_data, X4_tmp_data_golden, X4_tmp_data_structure, outfile) / 50176.0f * 100 << endl;
	outfile << "X4_tmp_data end" << endl << endl;

	dtype *X4_mid_data_golden = (dtype*)malloc(112896 * sizeof(dtype));
	LoadArr("X4_mid_data_golden.dat", X4_mid_data_golden, 112896);
	int X4_mid_data_structure[5] = { 1, 1, 1, 1, 112896 };
	outfile << "X4_mid_data: " << endl;
	outfile << "error rate: " << validate_file(X4_mid_data, X4_mid_data_golden, X4_mid_data_structure, outfile) / 112896.0f * 100 << endl;
	outfile << "X4_mid_data end" << endl << endl;

	dtype *X4_batch_data_golden = (dtype*)malloc(180480 * sizeof(dtype));
	LoadArr("X4_batch_data_golden.dat", X4_batch_data_golden, 50176);
	int X4_batch_data_structure[5] = { 1, 512, 2, 7, 7 };
	outfile << "X4_batch_data: " << endl;
	outfile << "error rate: " << validate_file(X4_batch_data, X4_batch_data_golden, X4_batch_data_structure, outfile) / 50176.0f * 100 << endl;
	outfile << "X4_batch_data end" << endl << endl;

	dtype *X_seq_golden = (dtype*)malloc(50176 * sizeof(dtype));
	LoadArr("X_seq_golden.dat", X_seq_golden, 50176);
	int X_seq_structure[5] = { 1, 512, 2, 7, 7 };
	outfile << "X_seq: " << endl;
	outfile << "error rate: " << validate_file(X_seq, X_seq_golden, X_seq_structure, outfile) / 50176.0f * 100 << endl;
	outfile << "X_seq end" << endl << endl;

	dtype *X_adap_golden = (dtype*)malloc(512 * sizeof(dtype));
	LoadArr("X_adap_golden.dat", X_adap_golden, 512);
	int X_adap_structure[5] = { 1, 512, 1, 1, 1 };
	outfile << "X_adap: " << endl;
	outfile << "error rate: " << validate_file(X_adap, X_adap_golden, X_adap_structure, outfile) / 512.0f * 100 << endl;
	outfile << "X_adap end" << endl << endl;


	outfile.close();

	free(X_batch_data_golden);
	free(X2_mid_data_golden);
	free(X2_batch_data_golden);
	free(X2_data_golden);
	free(X3_mid_data_golden);
	free(X3_batch_data_golden);
	free(X3_data_golden);
	free(X4_tmp_data_golden);
	free(X4_mid_data_golden);
	free(X4_batch_data_golden);
	free(X_seq_golden);
	free(X_adap_golden);

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
	free(X2_data);
	free(X3_data);
	free(X_seq);
	free(X_adap);
	free(X_tmp_data);
	free(X2_tmp_data);
	free(X3_tmp_data);
	free(X4_tmp_data);
	free(X_batch_data);
	free(X2_batch_data);
	free(X3_batch_data);
	free(X4_batch_data);
	free(X_mid_data);
	free(X2_mid_data);
	free(X3_mid_data);
	free(X4_mid_data);

	return 0;
}