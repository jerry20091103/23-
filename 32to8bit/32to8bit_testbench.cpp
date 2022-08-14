#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include "32to8bit.h"
using namespace std;

#define inputNum 2

int32_t out[inputNum*4];
int im[inputNum*4] = {
74,
1,
-91,
-128,
127,
-57,
45,
-105
};

int g[] = {
148,
2, 
-182,
-256,
254,
-114,
90,
-210
};






static int sw_validate()
{
    int i, j;
    int errors = 0;
    int total_errors = 0;

   // image
   for(i = 0 ; i < inputNum*4 ; i++){
       if(out[i] != g[i]){
           printf("[ERROR]: index %d, result:%d, gold:%d\n", i, out[i], g[i]);
           errors++;
       }
       else{
           printf("[CORRECT]: index %d, result:%d, gold:%d\n", i, out[i], g[i]);
       }
   }
   if(errors == 0)
       printf("===> Image pass!\n");
   else
       printf("===> Image fail!\n");
   total_errors += errors;

    return total_errors;
}


stream32u_t strm_im;
stream32_t strm_out;
value32u_t valDataCtrl;


int main(){
    for(int i = 0; i < inputNum*4; i++)
       printf("%d, ", im[i]);
    cout << "\n";
    
    unsigned errors = 0;
    // init valDataCtrl
    valDataCtrl.data = 0;
    valDataCtrl.keep = 0xF;
    valDataCtrl.strb = 0;
    valDataCtrl.user = 0;
    valDataCtrl.last = 0;
    valDataCtrl.id = 0;
    valDataCtrl.dest = 0;

    // write im stream
    for (int i = 0; i < inputNum; i++) {
        uint32_t ui32 = (uint8_t(im[3 + i*4]) << 24) | (uint8_t(im[2 + i*4]) << 16) | (uint8_t(im[1 + i*4]) << 8) | uint8_t(im[0 + i*4]);
        valDataCtrl.data = ui32;
        if (i >= (inputNum-1)) valDataCtrl.last = 1;
        strm_im.write(valDataCtrl);
    }
    // compute
    sw_compute(&strm_im, &strm_out);
    // read out stream
    for (int i = 0; i < inputNum*4; i++) {
        out[i] = strm_out.read().data;
    }
    errors = sw_validate();
    if (errors)
        printf("[FAIL] There are some errors QQ\n");
    else
        printf("[PASS] Congratulation! All results are correct\n");
    return 0;
}




