#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
#include <string>
#include <iomanip>
using namespace std;

int validate(float* ourOutput, float* golden, int* size);

float input[36963];
float Kernel_1[6615];
float Kernel_2[8640];
float X_out_data[200704];

// // for detail debug
// float X_out_data_1[141120];
// int X_out_num_1[5] = {1, 45, 1, 56, 56};
// float X_out_data_2[200704];

int main()
{
    FILE         *fp;
    std::ifstream file;
    float data=0;

    float output[200704];

    // load input
    file.open("input.dat");
    if(!file.is_open()){
        cout << "input.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 36963; i++){
        file >> data;
        input[i] = data;
    }
    file.close();

    // load kernel_1
    file.open("Conv3d1weight.dat");
    if(!file.is_open()){
        cout << "Conv3d1weight.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 6615; i++){
        file >> data;
        Kernel_1[i] = data;
    }
    file.close();

    // load kernel_2
    file.open("Conv3d2weight.dat");
    if(!file.is_open()){
        cout << "Conv3d2weight.dat not found!" << endl;
        return 0;
    }
    for(int i = 0; i < 8640; i++){
        file >> data;
        Kernel_2[i] = data;
    }
    file.close();

    // // ==========================================================
    // // Conv3d1
    // cout << "==> Conv3d1\n";
    // int X_num[5] = {1, 3, 1, 111, 111};
    // int Kernel_num_1[3] = {1, 7, 7};
    // int stride_1[3] = {1, 2, 2};
    // int padding_1[3] = {0, 3, 3};
    // Conv3d(input, X_num, X_out_data_1, X_out_num_1, Kernel_1, Kernel_num_1, stride_1, padding_1);

    // file.open("Conv3d1output.dat");
    // for(int i = 0; i < 141120; i++){
    //     file >> data;
    //     output[i] = data;
    // }
    // file.close();
    // errors = validate(X_out_data_1, output, X_out_num_1);
    // total_errors += errors;

    // // BatchNorm3d1
    // cout << "==> BatchNorm3d1\n";
    // file.open("Conv3d1output.dat");
    // for(int i = 0; i < 141120; i++){
    //     file >> data;
    //     X_out_data_1[i] = data;
    // }
    // file.close();
    // BatchNorm3d(X_out_data_1, X_out_num_1, 0.00001, 1, 0);

    // file.open("BatchNorm3d1output.dat");
    // for(int i = 0; i < 141120; i++){
    //     file >> data;
    //     output[i] = data;
    // }
    // file.close();
    // errors = validate(X_out_data_1, output, X_out_num_1);
    // total_errors += errors;
    

    // // ReLU1
    // cout << "==> ReLU1\n";
    // file.open("BatchNorm3d1output.dat");
    // for(int i = 0; i < 141120; i++){
    //     file >> data;
    //     X_out_data_1[i] = data;
    // }
    // file.close();
    // ReLU(X_out_data_1, X_out_num_1);

    // file.open("ReLU1output.dat");
    // for(int i = 0; i < 141120; i++){
    //     file >> data;
    //     output[i] = data;
    // }
    // file.close();
    // errors = validate(X_out_data_1, output, X_out_num_1);
    // total_errors += errors;
    

    // // ==========================================================

    // // Conv3d2
    // cout << "==> Conv3d2\n";
    // int X_out_num_2[5] = {1, 64, 1, 56, 56};
    // int Kernel_num_2[3] = {3, 1, 1};
    // int stride_2[3] = {1, 1, 1};
    // int padding_2[3] = {1, 0, 0};
    // file.open("ReLU1output.dat");
    // for(int i = 0; i < 141120; i++){
    //     file >> data;
    //     X_out_data_1[i] = data;
    // }
    // file.close();
    // Conv3d(X_out_data_1, X_out_num_1, X_out_data_2, X_out_num_2, Kernel_2, Kernel_num_2, stride_2, padding_2);

    // file.open("Conv3d2output.dat");
    // for(int i = 0; i < 200704; i++){
    //     file >> data;
    //     output[i] = data;
    // }
    // file.close();
    // errors = validate(X_out_data_2, output, X_out_num_2);
    // total_errors += errors;
    

    // // BatchNorm3d2
    // cout << "==> BatchNorm3d2\n";
    // file.open("Conv3d2output.dat");
    // for(int i = 0; i < 200704; i++){
    //     file >> data;
    //     X_out_data_2[i] = data;
    // }
    // file.close();
    // BatchNorm3d(X_out_data_2, X_out_num_2, 0.00001, 1, 0);

    // file.open("BatchNorm3d2output.dat");
    // for(int i = 0; i < 200704; i++){
    //     file >> data;
    //     output[i] = data;
    // }
    // file.close();
    // errors = validate(X_out_data_2, output, X_out_num_2);
    // total_errors += errors;
    

    // // ReLU2
    // cout << "==> ReLU2\n";
    // file.open("BatchNorm3d2output.dat");
    // for(int i = 0; i < 200704; i++){
    //     file >> data;
    //     X_out_data_2[i] = data;
    // }
    // file.close();
    // ReLU(X_out_data_2, X_out_num_2);

    // file.open("ReLU1output.dat");
    // for(int i = 0; i < 200704; i++){
    //     file >> data;
    //     output[i] = data;
    // }
    // file.close();
    // errors = validate(X_out_data_1, output, X_out_num_1);
    // total_errors += errors;
    
    // // ==========================================================


    // R2Plus1dStem
    r2plus1d(input, X_out_data, Kernel_1, Kernel_2);

    // load gloden result
    // file.open("Conv3d1output.dat");
    // for(int i = 0; i < 141120; i++){
    //     file >> data;
    //     output[i] = data;
    // }
    // file.close();
    file.open("ReLU2output.dat");
    if(!file.is_open()){
        cout << "ReLU2output.dat not found!\n";
        return 0;
    }
    for(int i = 0; i < 200704; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    
    // calculate errors
    float errors;
    // int X_num[5] = {1, 45, 1, 56, 56};
    int X_num[5] = {1, 64, 1, 56, 56};
    errors = 100*(float)validate(X_out_data, output, X_num)/200704;
    
    cout << "\n\n=======================================\n";
    cout << "==> Total\n";
    if (errors != 0)
        printf("[FAIL] There are some errors QQ, error rate: %f%\n", errors);
    else
        printf("[PASS] Congratulation! All results are correct\n");
    return 0;
}

int validate(float* ourOutput, float* golden, int* size)
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
                        if (ourOutput[pos] != golden[pos] && ((ourOutput[pos] - golden[pos]) / golden[pos] >= 0.005 || (ourOutput[pos] - golden[pos]) / golden[pos] <= -0.005)){
                            cout<<"[ERROR]  result["<<n<<"]["<<setw(2)<<c<<"]["<<d<<"]["<<setw(2)<<h<<"]["<<setw(2)<<w<<"]: "<<setw(13)<<ourOutput[pos]<<", gold: "<<setw(10)<<golden[pos]<<", error: "<< 100*(ourOutput[pos] - golden[pos]) / golden[pos]<<"%"<<endl;
                            errors++;
                        }
                    }
    return errors;
}
