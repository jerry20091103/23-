#include <iostream>
#include "iris.h"
using namespace std;

const int32_t scale_FC1 = 402;
const int32_t scale_FC2 = 288;

int32_t weight[] = {
31,
46,
-99,
-89,
26,
20,
-91,
-85,
62,
-125,
127,
-31,
60,
-92,
112,
-17,
24,
-40,
98,
14,
-2,
-9,
-44,
-66,
2,
-17,
-49,
-66,
-8,
-16,
3,
13,
82,
68,
-128,
-128,
-126,
38,
37,
1,
29,
34,
4,
0,
-19,
29,
35,
-4,
-80,
-66,
14,
19,
26,
-45,
-48,
-3,
-843,
-91,
654
};


int32_t act[125] = {
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

int32_t g[] = {
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

static int validate()
{
	int i, j;
	int errors = 0;
    int total_errors = 0;

	// actage
	for(i = 0 ; i < 32 ; i++){
		if(act[i] != g[i]){
			printf("[ERROR]: index %d, result:%lld, gold:%lld\n", i, act[i], g[i]);
			errors++;
		}
		else{
			//printf("[CORRECT]: index %d, result:%lld, gold:%lld\n", i, act[i], g[i]);
		}
	}
	if(errors == 0)
		printf("===> image pass!\n");
	else
		printf("===> image fail!\n");
    total_errors += errors;
	errors = 0;
	// FC1
	for(i = 32 ; i < 96 ; i++){
		if(act[i] != g[i]){
			printf("[ERROR]: index %d, result:%lld, gold:%lld\n", i-32, act[i], g[i]);
			errors++;
		}
		else{
			//printf("[CORRECT]: index %d, result:%lld, gold:%lld\n", i, act[i], g[i]);
		}
	}
	if(errors == 0)
		printf("===> FC1 pass!\n");
	else
		printf("===> FC1 fail!\n");
    total_errors += errors;
	errors = 0;
	// FC2
	for(i = 96 ; i < 120 ; i++){
		if(act[i] != g[i]){
			printf("[ERROR]: index %d, result:%lld, gold:%lld\n", i-96, act[i], g[i]);
			errors++;
		}
		else{
			//printf("[CORRECT]: index %d, result:%lld, gold:%lld\n", i, act[20000+i], g[i]);
		}
	}
	if(errors == 0)
		printf("===> FC2 pass!\n");
	else
		printf("===> FC2 fail!\n");
    total_errors += errors;

	return total_errors;
}

int main()
{
    unsigned errors = 0;
    iris_module(act, weight, scale_FC1, scale_FC2);
    errors = validate();
    if (errors)
        printf("[FAIL] There are some errors QQ\n");
    else
        printf("[PASS] Congratulation! All results are correct\n");
    return 0;
}
