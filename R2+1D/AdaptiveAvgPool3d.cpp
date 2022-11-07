#include "r2plus1d.h"
#include <cmath>
void AdaptiveAvgPool3d(dtype* X_data, dtype* Y_data){
	for(int_t n = 0; n < 1; n++)
        for(int_t c = 0; c < 512; c++)
            for(int_t d = 0; d < 1; d++)
                for (int_t h = 0; h < 1; h++){
                    for (int_t w = 0; w < 1; w++){
                        int_t tmp_Y = 0;
                        for(int_t kd = 0; kd < 2; kd++)
                            for(int_t kh = 0; kh < 7; kh++)
                                for(int_t kw = 0; kw < 7; kw++)
                                    tmp_Y += X_data[(n*50176)+(c*98)+(d*2+kd)*49+(h*7+kh)*7+(w*7+kw)];
                        Y_data[n*512+c+d+h+w] = roundf((ftype)tmp_Y/98);
                    }
						
                }
		
}
