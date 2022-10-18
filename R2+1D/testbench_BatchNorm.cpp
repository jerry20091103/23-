#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
#include <string>
#include <iomanip>
using namespace std;

int validate(float* ourOutput, float* golden, int* size);

int main()
{
    FILE         *fp;
    std::ifstream file;
    float data=0;

    float *X_out_data = (float*)malloc(141120*sizeof(float));
    float *output = (float*)malloc(141120*sizeof(float));

    int errors, total_errors = 0;

    // ==========================================================
    // BatchNorm3d1
    int X_out_num_1[5] = {1, 45, 1, 56, 56};
    cout << "==> BatchNorm3d1\n";
    file.open("Conv3d1output.dat");
    for(int i = 0; i < 141120; i++){
        file >> data;
        X_out_data[i] = data;
    }
    file.close();
    BatchNorm3d(X_out_data, X_out_num_1, 0.00001, 1, 0);

    file.open("BatchNorm3d1output.dat");
    for(int i = 0; i < 141120; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    errors = validate(X_out_data, output, X_out_num_1);
    total_errors += errors;
    
    // // ==========================================================
    // // BatchNorm3d2
    // int X_out_num_2[5] = {1, 64, 1, 56, 56};
    // cout << "==> BatchNorm3d2\n";
    // file.open("Conv3d2output.dat");
    // for(int i = 0; i < 200704; i++){
    //     file >> data;
    //     X_out_data[i] = data;
    // }
    // file.close();
    // BatchNorm3d(X_out_data, X_out_num_2, 0.00001, 1, 0);

    // file.open("BatchNorm3d2output.dat");
    // for(int i = 0; i < 200704; i++){
    //     file >> data;
    //     output[i] = data;
    // }
    // file.close();
    // errors = validate(X_out_data, output, X_out_num_2);
    // total_errors += errors;

    free(X_out_data);
    free(output);

    cout << "\n\n=======================================\n";
    cout << "==> Total\n";
    if (total_errors)
        printf("[FAIL] There are some errors QQ\n");
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
    if (errors)
        printf("[FAIL] There are some errors QQ\n");
    else
        printf("[PASS] Congratulation! All results are correct\n");
    return errors;
}

