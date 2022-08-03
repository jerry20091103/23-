#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "iris.h"
using namespace std;

#define inputNum 30
const int32_t scale_FC1 = 402;
const int32_t scale_FC2 = 288;

int out[inputNum*16];
ap_int<8> im[inputNum*16] = {
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
-23,
112,
-62,
127,
-13,
88,
-57,
108,
-42,
1,
-120,
79,
1,
-100,
-128,
88,
11,
-95,
-128,
127,
16,
127,
-62,
59,
-13,
-105,
-128,
83,
-4,
-100,
-128,
69,
-18,
-95,
-128,
127,
-42,
127,
-57,
108,
-23,
35,
-110,
74,
1,
-105,
-128,
127,
-8,
122,
-47,
103,
-37,
35,
-105,
122,
-23,
64,
-81,
127,
-18,
98,
-81,
74,
6,
-100,
-128,
122,
-62,
25,
-120,
103,
-23,
50,
-95,
74,
-23,
-91,
-128,
69,
-52,
-8,
-120,
98,
-57,
25,
-105
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
-23,
112,
-62,
127,
-13,
88,
-57,
108,
-42,
1,
-120,
79,
1,
-100,
-128,
88,
11,
-95,
-128,
127,
16,
127,
-62,
59,
-13,
-105,
-128,
83,
-4,
-100,
-128,
69,
-18,
-95,
-128,
127,
-42,
127,
-57,
108,
-23,
35,
-110,
74,
1,
-105,
-128,
127,
-8,
122,
-47,
103,
-37,
35,
-105,
122,
-23,
64,
-81,
127,
-18,
98,
-81,
74,
6,
-100,
-128,
122,
-62,
25,
-120,
103,
-23,
50,
-95,
74,
-23,
-91,
-128,
69,
-52,
-8,
-120,
98,
-57,
25,
-105,
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
0,
0,
127,
127,
86,
0,
0,
0,
0,
0,
127,
120,
69,
0,
0,
0,
73,
74,
96,
76,
16,
49,
53,
0,
127,
127,
0,
0,
0,
77,
82,
0,
127,
127,
0,
0,
0,
75,
80,
0,
0,
0,
127,
127,
85,
0,
0,
0,
127,
127,
0,
0,
0,
80,
85,
0,
127,
127,
0,
0,
0,
78,
83,
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
100,
0,
0,
0,
52,
52,
106,
88,
33,
35,
37,
0,
127,
127,
0,
0,
0,
79,
84,
0,
0,
0,
127,
127,
89,
0,
0,
0,
45,
47,
114,
93,
36,
33,
37,
0,
22,
23,
127,
110,
55,
15,
17,
0,
3,
5,
127,
127,
75,
5,
6,
0,
127,
127,
0,
0,
0,
77,
82,
0,
56,
60,
127,
109,
37,
43,
49,
0,
34,
35,
113,
95,
42,
24,
27,
0,
127,
126,
0,
0,
0,
76,
82,
0,
68,
71,
82,
61,
7,
52,
57,
0,
44,
49,
120,
96,
34,
37,
42,
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
-25523,
-44191,
-1217,
7081,
-41153,
-894,
6506,
-10034,
7898,
-11615,
24167,
13013,
-25289,
24017,
12885,
-25103,
-44065,
-1198,
7055,
24392,
13205,
-25568,
24242,
13077,
-25382,
24204,
13048,
-25337,
-45955,
-1483,
7445,
-19334,
5292,
-6275,
24317,
13141,
-25475,
-44569,
-1274,
7159,
-22366,
4836,
-5010,
-33542,
1822,
1183,
-41807,
-396,
5712,
24167,
13013,
-25289,
-23594,
6340,
-7262,
-25680,
3380,
-2273,
24061,
12950,
-25178,
-5540,
7993,
-12059,
-22875,
5228,
-5393,
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




