#include <iostream>
#include "imageIO.h"
using namespace std;
int main(int argc, char* argv[]){
	int pass = 1;
	packet_t image[112*112*3/128];
	packet_t output[112*112*3/128];
	for(int i=0; i<112; i++)
	{
		for(int j=0; j<112; j++)
		{
			((uint8_t*)image)[i*112*3 + j*3] = 1;
			((uint8_t*)image)[i*112*3 + j*3 + 1] = 2;
			((uint8_t*)image)[i*112*3 + j*3 + 2] = 3;
		}
	}
	imageIO_test(image, output);
	for(int i=0; i<112; i++)
	{
		for(int j=0; j<112; j++)
		{
			if(((uint8_t*)output)[i*112*3 + j*3] != 1)
			{
				pass = 0;
				cout << i << " x " << j << ": red is   " <<  (int)((uint8_t*)output)[i*112*3 + j*3] << endl;
			}
			if(((uint8_t*)output)[i*112*3 + j*3 + 1] != 2)
			{
				pass = 0;
				cout << i << " x " << j << ": green is " <<  (int)((uint8_t*)output)[i*112*3 + j*3 + 1] << endl;
			}
			if(((uint8_t*)output)[i*112*3 + j*3 + 2] != 0)
			{
				pass = 0;
				cout << i << " x " << j << ": blue is  " <<  (int)((uint8_t*)output)[i*112*3 + j*3 + 2] << endl;
			}
		}
	}
	if(!pass) {
		cout << ">> Test failed!" << endl;
		return 1;
	}
	cout << ">> Test passed!" << endl;
	return 0;
}
