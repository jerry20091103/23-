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

void validate(dtype* ourOutput, dtype* golden, int_t* size);

dtype Kernel_1[6615];
dtype Kernel_2[8640];
double Mu_1[45], Var_1[45], Gamma_1[45], Bias_1[45];
double Mu_2[64], Var_2[64], Gamma_2[64], Bias_2[64];
double Scale_1, Scale_2, Scale_3, Scale_4;
int_t Zeropoint_1, Zeropoint_2, Zeropoint_3, Zeropoint_4;

int_t main()
{
    FILE         *fp;
    std::ifstream file;
    double data = 0;

    double errors = 0;

    dtype *input = (dtype*)malloc(37632 * sizeof(dtype));
    dtype *output = (dtype*)malloc(200704 * sizeof(dtype));
    dtype *golden = (dtype*)malloc(200704 * sizeof(dtype));

    // load input
    file.open("input.dat");
    if (!file.is_open()) {
        cout << "input.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 37632; i++){
        file >> data;
        input[i] = (dtype)data;
    }
    file.close();

    // load kernel_1
    file.open("stem.0.weight.dat");
    if (!file.is_open()) {
        cout << "stem.0.weight.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 6615; i++){
        file >> data;
        Kernel_1[i] = (dtype)data;
    }
    file.close();

    // load kernel_2
    file.open("stem.3.weight.dat");
    if (!file.is_open()) {
        cout << "stem.3.weight.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 8640; i++){
        file >> data;
        Kernel_2[i] = (dtype)data;
    }
    file.close();

    // load Mu_1
    file.open("stem.1.running_mean.dat");
    if (!file.is_open()) {
        cout << "stem.1.running_mean.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 45; i++){
        file >> data;
        Mu_1[i] = data;
    }
    file.close();

    // load Mu_2
    file.open("stem.4.running_mean.dat");
    if (!file.is_open()) {
        cout << "stem.4.running_mean.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 64; i++){
        file >> data;
        Mu_2[i] = data;
    }
    file.close();

    // load Var_1
    file.open("stem.1.running_var.dat");
    if (!file.is_open()) {
        cout << "stem.1.running_var.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 45; i++){
        file >> data;
        Var_1[i] = data;
    }
    file.close();

    // load Var_2
    file.open("stem.4.running_var.dat");
    if (!file.is_open()) {
        cout << "stem.4.running_var.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 64; i++){
        file >> data;
        Var_2[i] = data;
    }
    file.close();

    // load Gamma_1
    file.open("stem.1.weight.dat");
    if (!file.is_open()) {
        cout << "stem.1.weight.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 45; i++){
        file >> data;
        Gamma_1[i] = data;
    }
    file.close();

    // load Gamma_2
    file.open("stem.4.weight.dat");
    if (!file.is_open()) {
        cout << "stem.4.weight.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 64; i++){
        file >> data;
        Gamma_2[i] = data;
    }
    file.close();

    // load Bias_1
    file.open("stem.1.bias.dat");
    if (!file.is_open()) {
        cout << "stem.1.bias.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 45; i++){
        file >> data;
        Bias_1[i] = data;
    }
    file.close();

    // load Bias_2
    file.open("stem.4.bias.dat");
    if (!file.is_open()) {
        cout << "stem.4.bias.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 64; i++){
        file >> data;
        Bias_2[i] = data;
    }
    file.close();

    Scale_1 = 0.460907161235809;
    Scale_2 = 0.0732352063059806;
    Scale_3 = 0.093119129538536;
    Scale_4 = 0.074236087501049;

    Zeropoint_1 = 60;
    Zeropoint_2 = 55;
    Zeropoint_3 = 70;
    Zeropoint_4 = 65;

#if TEST_MODE == separate_test
    // ==========================================================
    // Conv3d1
    cout << "==> Conv3d1\n";
    int_t X_num[5] = {1, 3, 1, 111, 111};
    int_t X_mid_num[5] = {1, 45, 1, 56, 56};
    int_t Kernel_num_1[3] = {1, 7, 7};
    int_t stride_1[3] = {1, 2, 2};
    int_t padding_1[3] = {0, 3, 3};
    Conv3d(input, X_num, output, X_mid_num, Kernel_1, Kernel_num_1, stride_1, padding_1);

    file.open("Conv3d1output.dat");
    if (!file.is_open()) {
        cout << "Conv3d1output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 141120; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    errors += 100 * double(validate(output, golden, X_mid_num)) / 141120;

    // BatchNorm3d1
    cout << "==> BatchNorm3d1\n";
    file.open("Conv3d1output.dat");
    if (!file.is_open()) {
        cout << "Conv3d1output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 141120; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    BatchNorm3d(output, X_mid_num, 0.00001, 1, 0);
    
    file.open("BatchNorm3d1output.dat");
    if (!file.is_open()) {
        cout << "BatchNorm3d1output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 141120; i++){
        file >> data;
        golden[i] = data;
    }
    file.close();
    errors += 100 * double(validate(output, golden, X_mid_num)) / 141120;

    // ReLU1
    cout << "==> ReLU1\n";
    file.open("BatchNorm3d1output.dat");
    if (!file.is_open()) {
        cout << "BatchNorm3d1output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 141120; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    ReLU(output, X_mid_num);

    file.open("ReLU1output.dat");
    if (!file.is_open()) {
        cout << "ReLU1output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 141120; i++){
        file >> data;
        golden[i] = data;
    }
    file.close();
    errors += 100 * double(validate(output, golden, X_mid_num)) / 141120;

    // ==========================================================

    // Conv3d2
    cout << "==> Conv3d2\n";
    int_t X_out_num[5] = {1, 64, 1, 56, 56};
    int_t Kernel_num_2[3] = {3, 1, 1};
    int_t stride_2[3] = {1, 1, 1};
    int_t padding_2[3] = {1, 0, 0};
    file.open("ReLU1output.dat");
    if (!file.is_open()) {
        cout << "ReLU1output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 141120; i++){
        file >> data;
        golden[i] = data;
    }
    file.close();
    Conv3d(golden, X_mid_num, output, X_out_num, Kernel_2, Kernel_num_2, stride_2, padding_2);

    file.open("Conv3d2output.dat");
    if (!file.is_open()) {
        cout << "Conv3d2output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 200704; i++){
        file >> data;
        golden[i] = data;
    }
    file.close();
    errors += 100 * double(validate(output, golden, X_out_num)) / 200704;

    // BatchNorm3d2
    cout << "==> BatchNorm3d2\n";
    file.open("Conv3d2output.dat");
    if (!file.is_open()) {
        cout << "Conv3d2output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 200704; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    BatchNorm3d(output, X_out_num, 0.00001, 1, 0);

    file.open("BatchNorm3d2output.dat");
    if (!file.is_open()) {
        cout << "BatchNorm3d2output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 200704; i++){
        file >> data;
        golden[i] = data;
    }
    file.close();
    errors += 100 * double(validate(output, golden, X_out_num)) / 200704;
    
    // ReLU2
    cout << "==> ReLU2\n";
    file.open("BatchNorm3d2output.dat");
    if (!file.is_open()) {
        cout << "BatchNorm3d2output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 200704; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    ReLU(output, X_out_num);
    
    // ==========================================================
#endif

#if TEST_MODE == full_test
    // R2Plus1dStem
    r2plus1d(input, output, Kernel_1, Kernel_2,
                Mu_1, Mu_2, Var_1, Var_2, Gamma_1, Gamma_2, Bias_1, Bias_2,
                Scale_1, Scale_2, Scale_3, Scale_4, 
                Zeropoint_1, Zeropoint_2, Zeropoint_3, Zeropoint_4);
#endif

    file.open("output.dat");
    if (!file.is_open()) {
        cout << "output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 200704; i++){
        file >> data;
        golden[i] = data;
    }
    file.close();

    // for(int_t c = 0; c < 64; c++)
    //     for(int_t h = 0; h < 56; h++)
    //         for(int_t w = 0; w < 56; w++)
    //             cout<<"[1]["<<c+1<<"][1]["<<h+1<<"]["<<w+1<<"]: "<<output[c*3136 + h*56 +w]<<endl;
                
    // calculate errors
    int_t X_out_num[5] = {1, 64, 1, 56, 56};
    validate(output, golden, X_out_num);

    free(input);
    free(output);
    free(golden);

    return 0;
}

void validate(dtype* ourOutput, dtype* golden, int_t* size)
{
    int_t errors = 0;
    int_t N = size[0];
    int_t C = size[1];
    int_t D = size[2];
    int_t H = size[3];
    int_t W = size[4];

    for(int_t n = 0; n < N; n++)
        for(int_t c = 0; c < C; c++)
            for(int_t d = 0; d < D; d++)
                for(int_t h = 0; h < H; h++)
                    for(int_t w = 0; w < W; w++){
                        int_t pos = n*C*D*H*W + c*D*H*W + d*H*W + h*W +w;
                        if(golden[pos] == 0 && ourOutput[pos] != golden[pos]){
                            cout<<"[ERROR]  result["<<n+1<<"]["<<setw(2)<<c+1<<"]["<<d+1<<"]["<<setw(2)<<h+1<<"]["<<setw(2)<<w+1<<"]: "<<setw(8)<<ourOutput[pos]<<", gold: "<<setw(8)<<golden[pos]<<", error: "<< 100*(ourOutput[pos] - golden[pos]) / ourOutput[pos]<<"%"<<endl;
                            errors++;
                        }
                        else if(ourOutput[pos] != golden[pos] && (ourOutput[pos] - golden[pos]) / golden[pos] >= 0.002 || (ourOutput[pos] - golden[pos]) / golden[pos] <= -0.002){
                            cout<<"[ERROR]  result["<<n+1<<"]["<<setw(2)<<c+1<<"]["<<d+1<<"]["<<setw(2)<<h+1<<"]["<<setw(2)<<w+1<<"]: "<<setw(8)<<ourOutput[pos]<<", gold: "<<setw(8)<<golden[pos]<<", error: "<< 100*(ourOutput[pos] - golden[pos]) / golden[pos]<<"%"<<endl;
                            errors++;
                        }
                    }

    cout << "\n\n=======================================\n";
    cout << "==> Total\n";
    if (errors != 0)
		printf("[FAIL] There are some errors QQ, error rate: %f%\n", 100 * (double)errors / 200704);
    else
        printf("[PASS] Congratulation! All results are correct\n");

    return;
}

