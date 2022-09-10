#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
using namespace std;

static int validate(float* ourOutput, float* golden, int len);

float input[36963];
float Kernel_1[6615];
float X_out_data_1[141120];
float BatchNorm3d1output[141120];
float Kernel_2[8640];
int main()
{
    int errors, total_errors = 0;

    FILE         *fp;
    std::ifstream file;
    float data=0;

    file.open("input.dat");
    for(int i = 0; i < 36963; i++){
        file >> data;
        input[i] = data;
    }
    file.close();

    file.open("Conv3d1weight.dat");
    for(int i = 0; i < 6615; i++){
        file >> data;
        Kernel_1[i] = data;
    }
    file.close();

    // Conv3d1
    int X_num[5] = {1, 3, 1, 111, 111};
    float Conv3d1output[141120];
    file.open("Conv3d1output.dat");
    for(int i = 0; i < 141120; i++){
        file >> data;
        Conv3d1output[i] = data;
    }
    file.close();

    int X_out_num_1[5] = {1, 45, 1, 56, 56};

    int Kernel_num_1[3] = {1, 7, 7};

    int stride_1[3] = {1, 2, 2};
    int padding_1[3] = {0, 3, 3};

    Conv3d(input, X_num, X_out_data_1, X_out_num_1, Kernel_1, Kernel_num_1, stride_1, padding_1);
    errors = validate(X_out_data_1, Conv3d1output, 141120);
    total_errors += errors;
//
//    // BatchNorm3d1
//    BatchNorm3d(X_out_data_1, X_out_num_1, 0.00001, 1, 0);
//
//    file.open("BatchNorm3d1output.dat");
//    for(int i = 0; i < 141120; i++){
//        file >> data;
//        BatchNorm3d1output[i] = data;
//    }
//    file.close();
//    errors = validate(X_out_data_1, BatchNorm3d1output, 141120);
//    total_errors += errors;
//
//    // ReLU1
//    ReLU(X_out_data_1, X_out_num_1);
//    float ReLU1output[141120];
//    file.open("ReLU1output.dat");
//    for(int i = 0; i < 141120; i++){
//        file >> data;
//        ReLU1output[i] = data;
//    }
//    file.close();
//
//    errors = validate(X_out_data_1, ReLU1output, 141120);
//    total_errors += errors;
//
//    // ==========================================================
//
//    // Conv3d2
//    float X_out_data_2[200704];
//    int X_out_num_2[5] = {1, 64, 1, 56, 56};
//
//    int Kernel_num_2[5] = {45, 64, 3, 1, 1};
//
//    int stride_2[3] = {1, 1, 1};
//    int padding_2[3] = {1, 0, 0};
//
//    file.open("Conv3d2weight.dat");
//
//    for(int i = 0; i < 8640; i++){
//        file >> data;
//        Kernel_2[i] = data;
//    }
//    file.close();
//
//    Conv3d(X_out_data_1, X_out_num_1, X_out_data_2, X_out_num_2, Kernel_2, Kernel_num_2, stride_2, padding_2);
//
//    float Conv3d2output[200704];
//    file.open("Conv3d2output.dat");
//    for(int i = 0; i < 200704; i++){
//        file >> data;
//        Conv3d2output[i] = data;
//    }
//    file.close();
//
//    errors = validate(X_out_data_2, Conv3d2output, 200704);
//    total_errors += errors;
//
//    // BatchNorm3d2
//    BatchNorm3d(X_out_data_2, X_out_num_2, 0.00001, 1, 0);
//    float BatchNorm3d2output[200704];
//    file.open("BatchNorm3d2output.dat");
//    for(int i = 0; i < 200704; i++){
//        file >> data;
//        BatchNorm3d2output[i] = data;
//    }
//    file.close();
//    errors = validate(X_out_data_2, BatchNorm3d2output, 200704);
//    total_errors += errors;
//
//    // ReLU2
//    ReLU(X_out_data_2, X_out_num_2);
//    float ReLU2output[200704];
//    file.open("ReLU2output.dat");
//    for(int i = 0; i < 200704; i++){
//        file >> data;
//        ReLU2output[i] = data;
//    }
//    file.close();
//    errors = validate(X_out_data_2, ReLU2output, 200704);
//    total_errors += errors;

    if (total_errors)
        printf("[FAIL] There are some errors QQ\n");
    else
        printf("[PASS] Congratulation! All results are correct\n");
    return 0;
}

static int validate(float* ourOutput, float* golden, int len)
{
    int i;
    int errors = 0;

    for (i = 0; i < len; i++){
        if (ourOutput[i] != golden[i]){
            printf("[ERROR]: index %d, result:%f, gold:%f\n", i, ourOutput[i], golden[i]);
            errors++;
        }
    }

    return errors;
}

