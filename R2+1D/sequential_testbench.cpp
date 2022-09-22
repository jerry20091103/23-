#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
#include <string>
#include <iomanip>
using namespace std;

int validate(float* ourOutput, float* golden, int* size);

float input[200704], X_out_data[200704];
float output[451584];

float Kernel_1[82944], Kernel_3[82944], Kernel_5[82944], Kernel_7[82944], Kernel_9[82944], Kernel_11[82944];
float Kernel_2[27648], Kernel_4[27648], Kernel_6[27648], Kernel_8[27648], Kernel_10[27648], Kernel_12[27648];
// kernel_size=(64, 144, 1, 3, 3),  kernel_size=(64, 144, 3, 1, 1)
string kernel_dat_name[12] = {"layer1_1_weight.dat", "layer1_2_weight.dat", "layer1_3_weight.dat","layer1_4_weight.dat","layer1_5_weight.dat", "layer1_6_weight.dat","layer1_7_weight.dat", "layer1_8_weight.dat", "layer1_9_weight.dat", "layer1_10_weight.dat", "layer1_11_weight.dat", "layer1_12_weight.dat"};

int main() {
    FILE         *fp;
    std::ifstream file;
    float data = 0;

    // load input
    file.open("layer1_input.dat");
    for(int i = 0; i < 200704; i++){
        file >> data;
        input[i] = data;
    }
    file.close();

    // load kernel
    for(int j = 1; j < 12; j += 2){
        file.open(kernel_dat_name[j-1]);
        for(int i = 0; i < 82944; i++){
            file >> data;
            if(j == 1) Kernel_1[i] = data;
            else if(j == 3) Kernel_3[i] = data;
            else if(j == 5) Kernel_5[i] = data;
            else if(j == 7) Kernel_7[i] = data;
            else if(j == 9) Kernel_9[i] = data;
            else if(j == 11) Kernel_11[i] = data;
        }
        file.close();
    }
    for(int j = 2; j <= 12; j += 2){
        file.open(kernel_dat_name[j-1]);
        for(int i = 0; i < 27648; i++){
            file >> data;
            if(j == 2) Kernel_2[i] = data;
            else if(j == 4) Kernel_4[i] = data;
            else if(j == 6) Kernel_6[i] = data;
            else if(j == 8) Kernel_8[i] = data;
            else if(j == 10) Kernel_10[i] = data;
            else if(j == 12) Kernel_12[i] = data;
        }
        file.close();
    }

    // load output
    file.open("layer1_output.dat");
    for(int i = 0; i < 200704; i++){
        file >> data;
        output[i] = data;
    }
    file.close();
    
    // ====================================
    Sequential(input, X_out_data, Kernel_1, Kernel_2, Kernel_3, Kernel_4, Kernel_5, Kernel_6, Kernel_7, Kernel_8, Kernel_9, Kernel_10, Kernel_11, Kernel_12);
    
    // calculate errors
    float errors;
    int X_num[5] = {1, 64, 1, 56, 56};
    errors = 100*float(validate(X_out_data, output, X_num)) / 200704;

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

