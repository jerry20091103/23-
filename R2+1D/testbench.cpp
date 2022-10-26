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
#define TEST_MODE separate_test

int_t validate(dtype* ourOutput, dtype* golden, int_t* size);

dtype Kernel_1[6615];
dtype Kernel_2[8640];

// dtype X_out_data_2[200704];
// dtype output[200704];
// dtype input[36963];



int_t main()
{
    FILE         *fp;
    std::ifstream file;
    dtype data=0;

    int_t errors, total_errors = 0;

    dtype *X_out_data_2 = (dtype*)malloc(200704 * sizeof(dtype));
    dtype *output = (dtype*)malloc(200704 * sizeof(dtype));
    dtype *input = (dtype*)malloc(36963 * sizeof(dtype));

    // load input
    file.open("input.dat");
    if (!file.is_open()) {
        cout << "input.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 36963; i++){
        file >> data;
        input[i] = data;
    }
    file.close();

    // load kernel_1
    file.open("Conv3d1weight.dat");
    if (!file.is_open()) {
        cout << "Conv3d1weight.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 6615; i++){
        file >> data;
        Kernel_1[i] = data;
    }
    file.close();

    // load kernel_2
    file.open("Conv3d2weight.dat");
    if (!file.is_open()) {
        cout << "Conv3d2weight.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 8640; i++){
        file >> data;
        Kernel_2[i] = data;
    }
    file.close();
#if TEST_MODE == separate_test
    // ==========================================================
    // Conv3d1
    cout << "==> Conv3d1\n";
    int_t X_num[5] = {1, 3, 1, 111, 111};
    int_t X_out_num_1[5] = {1, 45, 1, 56, 56};
    int_t Kernel_num_1[3] = {1, 7, 7};
    int_t stride_1[3] = {1, 2, 2};
    int_t padding_1[3] = {0, 3, 3};
    Conv3d(input, X_num, X_out_data_2, X_out_num_1, Kernel_1, Kernel_num_1, stride_1, padding_1);

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
    errors = validate(X_out_data_2, output, X_out_num_1);
    total_errors += errors;

    // BatchNorm3d1
    cout << "==> BatchNorm3d1\n";
    file.open("Conv3d1output.dat");
    if (!file.is_open()) {
        cout << "Conv3d1output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 141120; i++){
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
    for(int_t i = 0; i < 141120; i++){
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
    for(int_t i = 0; i < 141120; i++){
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
    for(int_t i = 0; i < 141120; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    errors = validate(X_out_data_2, output, X_out_num_1);
    total_errors += errors;
    

    // ==========================================================

    // Conv3d2
    cout << "==> Conv3d2\n";
    int_t X_out_num_2[5] = {1, 64, 1, 56, 56};
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
        output[i] = data;
    }
    file.close();
    Conv3d(output, X_out_num_1, X_out_data_2, X_out_num_2, Kernel_2, Kernel_num_2, stride_2, padding_2);

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
    errors = validate(X_out_data_2, output, X_out_num_2);
    total_errors += errors;
    

    // BatchNorm3d2
    cout << "==> BatchNorm3d2\n";
    file.open("Conv3d2output.dat");
    if (!file.is_open()) {
        cout << "Conv3d2output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 200704; i++){
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
    for(int_t i = 0; i < 200704; i++){
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
    for(int_t i = 0; i < 200704; i++){
        file >> data;
        X_out_data_2[i] = data;
    }
    file.close();
    ReLU(X_out_data_2, X_out_num_2);
    
    // ==========================================================
#endif

#if TEST_MODE == full_test
    // R2Plus1dStem
    r2plus1d(input, X_out_data_2, Kernel_1, Kernel_2);
#endif

     file.open("ReLU2output.dat");
    if (!file.is_open()) {
        cout << "ReLU2output.dat not found!" << endl;
        return 0;
    }
    for(int_t i = 0; i < 200704; i++){
        file >> data;
        output[i] = data;
    }
    file.close();

    // calculate errors
    int_t X_num_2[5] = {1, 64, 1, 56, 56};
    errors = validate(X_out_data_2, output, X_num_2);
    total_errors += errors;

    free(X_out_data_2);
    free(output);
    free(input);

    cout << "\n\n=======================================\n";
    cout << "==> Total\n";
    if (total_errors)
        printf("[FAIL] There are some errors QQ\n");
    else
        printf("[PASS] Congratulation! All results are correct\n");
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
    for(int_t n = 0; n < N; n++)
        for(int_t c = 0; c < C; c++)
            for(int_t d = 0; d < D; d++)
                for(int_t h = 0; h < H; h++)
                    for(int_t w = 0; w < W; w++){
                        int_t pos = n*C*D*H*W + c*D*H*W + d*H*W + h*W +w;
                        if (ourOutput[pos] != golden[pos] && ((ourOutput[pos] - golden[pos]) / golden[pos] >= 0.002 || (ourOutput[pos] - golden[pos]) / golden[pos] <= -0.002)){
                            cout<<"[ERROR]  result["<<n<<"]["<<setw(2)<<c<<"]["<<d<<"]["<<setw(2)<<h<<"]["<<setw(2)<<w<<"]: "<<setw(13)<<ourOutput[pos]<<", gold: "<<setw(10)<<golden[pos]<<", error: "<< 100*(ourOutput[pos] - golden[pos]) / golden[pos]<<"%"<<endl;
                            errors++;
                        }
                    }
    if (errors)
        printf("[FAIL] There are some errors QQ\n");
    else
        printf("[PASS] Congratulation! All results are correct\n");
    return errors;
}

