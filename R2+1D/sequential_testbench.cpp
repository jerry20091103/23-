#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "r2plus1d.h"
#include <string>
using namespace std;

int validate(float* ourOutput, float* golden, int len);

float input[200704];
float Kernel_1[36864], Kernel_3[36864], Kernel_5[36864], Kernel_7[36864], Kernel_9[36864], Kernel_11[36864];
float Kernel_2[12288], Kernel_4[12288], Kernel_6[12288], Kernel_8[12288], Kernel_10[12288], Kernel_12[12288];
// todo
string kernel_dat_name[12] = {}; 
float X_out_data[200704];


//kernel_size=(64, 64, 1, 3, 3),  kernel_size=(64, 64, 3, 1, 1)
int main()
{
    FILE         *fp;
    std::ifstream file;
    float data=0;

    // load input
    file.open("input.dat");
    for(int i = 0; i < 200704; i++){
        file >> data;
        input[i] = data;
    }
    file.close();

    // load kernel
    for(int j = 0; j < 12; j+=2){
        file.open(kernel_dat_name[j]);
        for(int i = 0; i < 36864; i++){
            file >> data;
            if(j == 0) Kernel_1[i] = data;
            else if(j == 2) Kernel_3[i] = data;
            else if(j == 4) Kernel_5[i] = data;
            else if(j == 6) Kernel_7[i] = data;
            else if(j == 8) Kernel_9[i] = data;
            else if(j == 10) Kernel_11[i] = data;
        }
        file.close();
    }
    for(int j = 1; j < 12; j+=2){
        file.open(kernel_dat_name[j]);
        for(int i = 0; i < 12288; i++){
            file >> data;
            else if(j == 1) Kernel_2[i] = data;
            else if(j == 3) Kernel_4[i] = data;
            else if(j == 5) Kernel_6[i] = data;
            else if(j == 7) Kernel_8[i] = data;
            else if(j == 9) Kernel_10[i] = data;
            else if(j == 11) Kernel_12[i] = data;
        }
        file.close();
    }
        

 // Sequential_1 layer 1
    // load gloden result
    float output[200704];
    file.open("ReLU.dat");  // todo
    for(int i = 0; i < 200704; i++){
        file >> data;
        output[i] = data;
    }
    file.close();

    Sequential_1(input, X_out_data, Kernel_1, Kernel_2, Kernel_3, Kernel_4, Kernel_5, Kernel_6, Kernel_7, Kernel_8, Kernel_9, Kernel_10, Kernel_11, Kernel_12);

    // calculate errors
    int errors, total_errors = 0;
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

