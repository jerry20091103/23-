#include "test_utility.h"

int_t main()
{
	dtype *input = (dtype*)malloc(50176 * sizeof(dtype));
	dtype *output = (dtype*)malloc(512 * sizeof(dtype));
	dtype *golden = (dtype*)malloc(512 * sizeof(dtype));

	// ==========================================================
	// Linear
	int_t X_adaptive_in_num[5] = { 1, 512, 2, 7, 7 };
	int_t X_adaptive_out_num[5] = { 1, 512, 1, 1, 1 };

    if(!LoadArr<dtype>("input.dat", input, 50176)) return 0;
	if(!LoadArr<dtype>("output.dat", golden, 512)) return 0;

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