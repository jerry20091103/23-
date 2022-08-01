#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "iris.h"
using namespace std;

#define inputNum 8
const int32_t scale_FC1 = 402;
const int32_t scale_FC2 = 288;

int out[inputNum*16];
short int im[inputNum*16] = {
74,
1,
-91,
-128,
127,
-57,
45,
-105,
64,
-23,
-100,
-128,
69,
-18,
-95,
-128,
127,
-13,
108,
-57,
127,
-18,
69,
-95,
127,
-33,
64,
-100,
64,
-23,
-100,
-128
};

int g[] = {
74,
1,
-91,
-128,
127,
-57,
45,
-105,
64,
-23,
-100,
-128,
69,
-18,
-95,
-128,
127,
-13,
108,
-57,
127,
-18,
69,
-95,
127,
-33,
64,
-100,
64,
-23,
-100,
-128,
127,
127,
0,
0,
0,
75,
79,
0,
38,
42,
127,
120,
50,
31,
36,
0,
127,
127,
0,
0,
0,
79,
85,
0,
127,
127,
0,
0,
0,
77,
83,
0,
0,
0,
127,
127,
81,
0,
0,
0,
29,
29,
127,
114,
56,
19,
21,
0,
30,
32,
127,
119,
56,
23,
26,
0,
127,
127,
0,
0,
0,
79,
85,
0,
23980,
12850,
-25055,
-30277,
4156,
-2923,
24354,
13176,
-25523,
24204,
13048,
-25337,
-43561,
-1122,
6951,
-32898,
2466,
-43,
-32915,
2888,
-646,
24354,
13176,
-25523
};






static int sw_validate()
{
    int i, j;
    int errors = 0;
    int total_errors = 0;

    // image
    for(i = 0 ; i < inputNum*4 ; i++){
        if(out[i] != g[i]){
            printf("[ERROR]: index %d, result:%lld, gold:%lld\n", i, out[i], g[i]);
            errors++;
        }
        else{
            //printf("[CORRECT]: index %d, result:%lld, gold:%lld\n", i, im[i], g[i]);
        }
    }
    if(errors == 0)
        printf("===> Image pass!\n");
    else
        printf("===> Image fail!\n");
    total_errors += errors;
    errors = 0;
    // FC1
    for(i = inputNum*4 ; i < inputNum*12 ; i++){
        if(out[i] != g[i]){
            printf("[ERROR]: index %d, result:%lld, gold:%lld\n", i-32, out[i], g[i]);
            errors++;
        }
        else{
            //printf("[CORRECT]: index %d, result:%lld, gold:%lld\n", i, im[i], g[i]);
        }
    }
    if(errors == 0)
        printf("===> FC1 pass!\n");
    else
        printf("===> FC1 fail!\n");
    total_errors += errors;
    errors = 0;
    // FC2
    for(i = inputNum*12 ; i < inputNum*15 ; i++){
        if(out[i] != g[i]){
            printf("[ERROR]: index %d, result:%lld, gold:%lld\n", i-96, out[i], g[i]);
            errors++;
        }
        else{
            //printf("[CORRECT]: index %d, result:%lld, gold:%lld\n", i, im[20000+i], g[i]);
        }
    }
    if(errors == 0)
        printf("===> FC2 pass!\n");
    else
        printf("===> FC2 fail!\n");
    total_errors += errors;

    return total_errors;
}


int main(){
    unsigned errors = 0;
    sw_compute(im,out);
    errors = sw_validate();
    if (errors)
        printf("[FAIL] There are some errors QQ\n");
    else
        printf("[PASS] Congratulation! All results are correct\n");
    return 0;
}




