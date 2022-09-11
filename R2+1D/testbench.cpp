#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
using namespace std;

int validate(float* ourOutput, float* golden, int len);

float input[36963];
float Kernel_1[6615];
float Kernel_2[8640];
float X_out_data[200704];

int main()
{
    FILE         *fp;
    std::ifstream file;
    float data=0;

    // load input
    file.open("input.dat");
    for(int i = 0; i < 36963; i++){
        file >> data;
        input[i] = data;
    }
    file.close();

    // load kernel_1
    file.open("Conv3d1weight.dat");
    for(int i = 0; i < 6615; i++){
        file >> data;
        Kernel_1[i] = data;
    }
    file.close();

    // load kernel_2
    file.open("Conv3d2weight.dat");
    for(int i = 0; i < 8640; i++){
        file >> data;
        Kernel_2[i] = data;
    }
    file.close();

 // R2Plus1dStem
    float output[200704];
    int errors, total_errors = 0;

    r2plus1d(input, X_out_data, Kernel_1, Kernel_2);

    // load gloden result
    file.open("ReLU2output.dat");
    for(int i = 0; i < 200704; i++){
        file >> data;
        output[i] = data;
    }
    // calculate errors
    errors = validate(X_out_data, output, 200704);
    total_errors += errors;

    if (total_errors)
        printf("[FAIL] There are some errors QQ\n");
    else
        printf("[PASS] Congratulation! All results are correct\n");
    return 0;
}

int validate(float* ourOutput, float* golden, int len)
{
    int i;
    int errors = 0;

    for (i = 0; i < len; i++){
        if (ourOutput[i] != golden[i]){
             cout<<"[ERROR]: index "<<i<<", result: "<<ourOutput[i]<<", gold: "<<golden[i]<<endl;
            errors++;
        }
    }

    return errors;
}

