#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
#include <string>
#include <iomanip>
using namespace std;

// !defines: switch between different testing modes.
#define separate_test 0
#define full_test 1
// modify this:
#define TEST_MODE full_test

int validate(int* ourOutput, int* golden, int* size);


int main()
{
    FILE         *fp;
    std::ifstream file;
    double data=0;

    int errors, total_errors = 0;

    int *Kernel_1 = (int*)malloc(6615 * sizeof(int));
    int *Kernel_2 = (int*)malloc(8640 * sizeof(int));
    double *Batch_mu1 = (double*)malloc(45 * sizeof(double));
    double *Batch_mu2 = (double*)malloc(64 * sizeof(double));
    double *Batch_var1 = (double*)malloc(45 * sizeof(double));
    double *Batch_var2 = (double*)malloc(64 * sizeof(double));
    double *Batch_r1 = (double*)malloc(45 * sizeof(double));
    double *Batch_r2 = (double*)malloc(64 * sizeof(double));
    double *Batch_b1 = (double*)malloc(45 * sizeof(double));
    double *Batch_b2 = (double*)malloc(64 * sizeof(double));

    int *X_out_data_2 = (int*)malloc(200704 * sizeof(int));
    int *output = (int*)malloc(200704 * sizeof(int));
    int *input = (int*)malloc(37632 * sizeof(int));

    // load input
    file.open("input.dat");
    if (!file.is_open()) {
        cout << "input.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 37632; i++){
        file >> data;
        input[i] = (int)data;
    }
    file.close();

    // load kernel_1
    file.open("Conv3d1weight.dat");
    if (!file.is_open()) {
        cout << "Conv3d1weight.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 6615; i++){
        file >> data;
        Kernel_1[i] = (int)data;
    }
    file.close();

    // load kernel_2
    file.open("Conv3d2weight.dat");
    if (!file.is_open()) {
        cout << "Conv3d2weight.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 8640; i++){
        file >> data;
        Kernel_2[i] = (int)data;
    }
    file.close();

    // load Batch_mu1
    file.open("Batch1Mu.dat");
    if (!file.is_open()) {
        cout << "Batch1Mu.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 45; i++){
        file >> data;
        Batch_mu1[i] = data;
    }
    file.close();

    // load Batch_mu2
    file.open("Batch2Mu.dat");
    if (!file.is_open()) {
        cout << "Batch2Mu.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 64; i++){
        file >> data;
        Batch_mu2[i] = data;
    }
    file.close();

    // load Batch_var1
    file.open("Batch1Var.dat");
    if (!file.is_open()) {
        cout << "Batch1Var.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 45; i++){
        file >> data;
        Batch_var1[i] = data;
    }
    file.close();

    // load Batch_var2
    file.open("Batch2Var.dat");
    if (!file.is_open()) {
        cout << "Batch2Var.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 64; i++){
        file >> data;
        Batch_var2[i] = data;
    }
    file.close();

    // load Batch_r1
    file.open("Batch1Gamma.dat");
    if (!file.is_open()) {
        cout << "Batch1Gamma.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 45; i++){
        file >> data;
        Batch_r1[i] = data;
    }
    file.close();

    // load Batch_r2
    file.open("Batch2Gamma.dat");
    if (!file.is_open()) {
        cout << "Batch2Gamma.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 64; i++){
        file >> data;
        Batch_r2[i] = data;
    }
    file.close();

    // load Batch_b1
    file.open("Batch1Beta.dat");
    if (!file.is_open()) {
        cout << "Batch1Beta.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 45; i++){
        file >> data;
        Batch_b1[i] = data;
    }
    file.close();

    // load Batch_b2
    file.open("Batch2Beta.dat");
    if (!file.is_open()) {
        cout << "Batch2Beta.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 64; i++){
        file >> data;
        Batch_b2[i] = data;
    }
    file.close();

#if TEST_MODE == separate_test
    // ==========================================================
    // Conv3d1
    cout << "==> Conv3d1\n";
    int X_num[5] = {1, 3, 1, 111, 111};
    int X_out_num_1[5] = {1, 45, 1, 56, 56};
    int Kernel_num_1[3] = {1, 7, 7};
    int stride_1[3] = {1, 2, 2};
    int padding_1[3] = {0, 3, 3};
    Conv3d(input, X_num, X_out_data_2, X_out_num_1, Kernel_1, Kernel_num_1, stride_1, padding_1);

    file.open("Conv3d1output.dat");
    if (!file.is_open()) {
        cout << "Conv3d1output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 141120; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    errors = validate(X_out_data_2, output, X_out_num_1);
    total_errors += errors;

    // BatchNorm3d1
    cout << "==> BatchNorm3d1\n";
    file.open("Conv3d1output.dat");
    if (!file.is_open()) {
        cout << "Conv3d1output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 141120; i++){
        file >> data;
        X_out_data_2[i] = data;
    }
    file.close();
    BatchNorm3d(X_out_data_2, X_out_num_1, 0.00001, 1, 0);

    file.open("BatchNorm3d1output.dat");
    if (!file.is_open()) {
        cout << "BatchNorm3d1output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 141120; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    errors = validate(X_out_data_2, output, X_out_num_1);
    total_errors += errors;
    

    // ReLU1
    cout << "==> ReLU1\n";
    file.open("BatchNorm3d1output.dat");
    if (!file.is_open()) {
        cout << "BatchNorm3d1output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 141120; i++){
        file >> data;
        X_out_data_2[i] = data;
    }
    file.close();
    ReLU(X_out_data_2, X_out_num_1);

    file.open("ReLU1output.dat");
    if (!file.is_open()) {
        cout << "ReLU1output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 141120; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    errors = validate(X_out_data_2, output, X_out_num_1);
    total_errors += errors;
    

    // ==========================================================

    // Conv3d2
    cout << "==> Conv3d2\n";
    int X_out_num_2[5] = {1, 64, 1, 56, 56};
    int Kernel_num_2[3] = {3, 1, 1};
    int stride_2[3] = {1, 1, 1};
    int padding_2[3] = {1, 0, 0};
    file.open("ReLU1output.dat");
    if (!file.is_open()) {
        cout << "ReLU1output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 141120; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    Conv3d(output, X_out_num_1, X_out_data_2, X_out_num_2, Kernel_2, Kernel_num_2, stride_2, padding_2);

    file.open("Conv3d2output.dat");
    if (!file.is_open()) {
        cout << "Conv3d2output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 200704; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    errors = validate(X_out_data_2, output, X_out_num_2);
    total_errors += errors;
    

    // BatchNorm3d2
    cout << "==> BatchNorm3d2\n";
    file.open("Conv3d2output.dat");
    if (!file.is_open()) {
        cout << "Conv3d2output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 200704; i++){
        file >> data;
        X_out_data_2[i] = data;
    }
    file.close();
    BatchNorm3d(X_out_data_2, X_out_num_2, 0.00001, 1, 0);

    file.open("BatchNorm3d2output.dat");
    if (!file.is_open()) {
        cout << "BatchNorm3d2output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 200704; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    errors = validate(X_out_data_2, output, X_out_num_2);
    total_errors += errors;
    

    // ReLU2
    cout << "==> ReLU2\n";
    file.open("BatchNorm3d2output.dat");
    if (!file.is_open()) {
        cout << "BatchNorm3d2output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 200704; i++){
        file >> data;
        X_out_data_2[i] = data;
    }
    file.close();
    ReLU(X_out_data_2, X_out_num_2);
    
    // ==========================================================
#endif

#if TEST_MODE == full_test
    // R2Plus1dStem
    r2plus1d(input, X_out_data_2, Kernel_1, Kernel_2, Batch_mu1, Batch_mu2, Batch_var1, Batch_var2, Batch_r1, Batch_r2, Batch_b1, Batch_b2);
#endif

    file.open("ReLU2output.dat");
    if (!file.is_open()) {
        cout << "ReLU2output.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 200704; i++){
        file >> data;
        output[i] = (int)data;
    }
    file.close();

    // calculate errors
    double error;
    int X_num_2[5] = {1, 64, 1, 56, 56};
    error = 100 * double(validate(X_out_data_2, output, X_num_2)) / 200704;
    total_errors += error;
	if (error != 0)
		printf("[FAIL] There are some errors QQ, error rate: %f%\n", error);

    free(X_out_data_2);
    free(output);
    free(input);
    free(Kernel_1);
    free(Kernel_2);
    free(Batch_mu1);
    free(Batch_mu2);
    free(Batch_var1);
    free(Batch_var2);
    free(Batch_r1);
    free(Batch_r2);
    free(Batch_b1);
    free(Batch_b2);

    cout << "\n\n=======================================\n";
    cout << "==> Total\n";
    if (total_errors)
        printf("[FAIL] There are some errors QQ\n");
    else
        printf("[PASS] Congratulation! All results are correct\n");
    return 0;
}

int validate(int* ourOutput, int* golden, int* size)
{
    int errors = 0;
    int N = size[0];
    int C = size[1];
    int D = size[2];
    int H = size[3];
    int W = size[4];
    for(int n = 0; n < N; n++)
        for(int c = 0; c < C; c++)
            for(int d = 0; d < D; d++)
                for(int h = 0; h < H; h++)
                    for(int w = 0; w < W; w++){
                        int pos = n*C*D*H*W + c*D*H*W + d*H*W + h*W +w;
                        if(golden[pos] == 0)
                            continue;
                        if (ourOutput[pos] != golden[pos] && ((ourOutput[pos] - golden[pos]) / golden[pos] >= 0.002 || (ourOutput[pos] - golden[pos]) / golden[pos] <= -0.002)){
                            cout<<"[ERROR]  result["<<n+1<<"]["<<c+1<<"]["<<d+1<<"]["<<h+1<<"]["<<w+1<<"]: "<<ourOutput[pos]<<", gold: "<<golden[pos]<<", error: "<< 100*(ourOutput[pos] - golden[pos]) / golden[pos]<<"%"<<endl;
                            errors++;
                        }
                    }
    if (errors)
        printf("[FAIL] There are some errors QQ\n");
    else
        printf("[PASS] Congratulation! All results are correct\n");
    return errors;
}

