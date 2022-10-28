#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Sequential(dtype* X_data, dtype* Y_data, 
                dtype* Kernel_1_1_data, dtype* Kernel_1_2_data, dtype* Kernel_1_3_data, dtype* Kernel_1_4_data, dtype* Kernel_1_5_data, dtype* Kernel_1_6_data, dtype* Kernel_1_7_data, dtype* Kernel_1_8_data, 
                dtype* Kernel_2_1_data, dtype* Kernel_2_2_data, dtype* Kernel_2_3_data, dtype* Kernel_2_4_data, dtype* Kernel_2_5_data, dtype* Kernel_2_6_data, dtype* Kernel_2_7_data, dtype* Kernel_2_8_data, dtype* Kernel_2_9_data, 
                dtype* Kernel_3_1_data, dtype* Kernel_3_2_data, dtype* Kernel_3_3_data, dtype* Kernel_3_4_data, dtype* Kernel_3_5_data, dtype* Kernel_3_6_data, dtype* Kernel_3_7_data, dtype* Kernel_3_8_data, dtype* Kernel_3_9_data, 
                dtype* Kernel_4_1_data, dtype* Kernel_4_2_data, dtype* Kernel_4_3_data, dtype* Kernel_4_4_data, dtype* Kernel_4_5_data, dtype* Kernel_4_6_data, dtype* Kernel_4_7_data, dtype* Kernel_4_8_data, dtype* Kernel_4_9_data,
                double* Mu_seq_1_1, double* Mu_seq_1_2, double* Mu_seq_1_3, double* Mu_seq_1_4, double* Mu_seq_1_5, double* Mu_seq_1_6, double* Mu_seq_1_7, double* Mu_seq_1_8,
                double* Mu_seq_2_1, double* Mu_seq_2_2, double* Mu_seq_2_3, double* Mu_seq_2_4, double* Mu_seq_2_5, double* Mu_seq_2_6, double* Mu_seq_2_7, double* Mu_seq_2_8,double* Mu_seq_2_9,
                double* Mu_seq_3_1, double* Mu_seq_3_2, double* Mu_seq_3_3, double* Mu_seq_3_4, double* Mu_seq_3_5, double* Mu_seq_3_6, double* Mu_seq_3_7, double* Mu_seq_3_8,double* Mu_seq_3_9,
                double* Mu_seq_4_1, double* Mu_seq_4_2, double* Mu_seq_4_3, double* Mu_seq_4_4, double* Mu_seq_4_5, double* Mu_seq_4_6, double* Mu_seq_4_7, double* Mu_seq_4_8,double* Mu_seq_4_9,
                double* Var_seq_1_1, double* Var_seq_1_2, double* Var_seq_1_3, double* Var_seq_1_4, double* Var_seq_1_5, double* Var_seq_1_6, double* Var_seq_1_7, double* Var_seq_1_8,
                double* Var_seq_2_1, double* Var_seq_2_2, double* Var_seq_2_3, double* Var_seq_2_4, double* Var_seq_2_5, double* Var_seq_2_6, double* Var_seq_2_7, double* Var_seq_2_8,double* Var_seq_2_9,
                double* Var_seq_3_1, double* Var_seq_3_2, double* Var_seq_3_3, double* Var_seq_3_4, double* Var_seq_3_5, double* Var_seq_3_6, double* Var_seq_3_7, double* Var_seq_3_8,double* Var_seq_3_9,
                double* Var_seq_4_1, double* Var_seq_4_2, double* Var_seq_4_3, double* Var_seq_4_4, double* Var_seq_4_5, double* Var_seq_4_6, double* Var_seq_4_7, double* Var_seq_4_8,double* Var_seq_4_9,
                double* Gamma_seq_1_1, double* Gamma_seq_1_2, double* Gamma_seq_1_3, double* Gamma_seq_1_4, double* Gamma_seq_1_5, double* Gamma_seq_1_6, double* Gamma_seq_1_7, double* Gamma_seq_1_8,
                double* Gamma_seq_2_1, double* Gamma_seq_2_2, double* Gamma_seq_2_3, double* Gamma_seq_2_4, double* Gamma_seq_2_5, double* Gamma_seq_2_6, double* Gamma_seq_2_7, double* Gamma_seq_2_8,double* Gamma_seq_2_9,
                double* Gamma_seq_3_1, double* Gamma_seq_3_2, double* Gamma_seq_3_3, double* Gamma_seq_3_4, double* Gamma_seq_3_5, double* Gamma_seq_3_6, double* Gamma_seq_3_7, double* Gamma_seq_3_8,double* Gamma_seq_3_9,
                double* Gamma_seq_4_1, double* Gamma_seq_4_2, double* Gamma_seq_4_3, double* Gamma_seq_4_4, double* Gamma_seq_4_5, double* Gamma_seq_4_6, double* Gamma_seq_4_7, double* Gamma_seq_4_8,double* Gamma_seq_4_9,
                double* bias_seq_1_1, double* bias_seq_1_2, double* bias_seq_1_3, double* bias_seq_1_4, double* bias_seq_1_5, double* bias_seq_1_6, double* bias_seq_1_7, double* bias_seq_1_8,
                double* bias_seq_2_1, double* bias_seq_2_2, double* bias_seq_2_3, double* bias_seq_2_4, double* bias_seq_2_5, double* bias_seq_2_6, double* bias_seq_2_7, double* bias_seq_2_8,double* bias_seq_2_9,
                double* bias_seq_3_1, double* bias_seq_3_2, double* bias_seq_3_3, double* bias_seq_3_4, double* bias_seq_3_5, double* bias_seq_3_6, double* bias_seq_3_7, double* bias_seq_3_8,double* bias_seq_3_9,
                double* bias_seq_4_1, double* bias_seq_4_2, double* bias_seq_4_3, double* bias_seq_4_4, double* bias_seq_4_5, double* bias_seq_4_6, double* bias_seq_4_7, double* bias_seq_4_8,double* bias_seq_4_9)
{
 #ifdef __SYNTHESIS__
    dtype X_tmp_data[200704];
    dtype X2_data[100352];
    dtype X2_tmp_data[100352];
    dtype X3_data[50176];
    dtype X3_tmp_data[50176];
    dtype X4_data[25088];
    dtype X4_tmp_data[25088];
 #else
    dtype* X_tmp_data = (dtype*)malloc(3211264*sizeof(dtype));
    dtype* X2_data = (dtype*)malloc(802816*sizeof(dtype));
    dtype* X2_tmp_data = (dtype*)malloc(802816*sizeof(dtype));
    dtype* X3_data = (dtype*)malloc(200704*sizeof(dtype));
    dtype* X3_tmp_data = (dtype*)malloc(200704*sizeof(dtype));
    dtype* X4_data = (dtype*)malloc(50176*sizeof(dtype));
    dtype* X4_tmp_data = (dtype*)malloc(50176*sizeof(dtype));
 #endif

    int_t Kernel_num[3] = {1, 1, 1};
    int_t stride[3] = {2, 2, 2};
    int_t padding[3] = {0, 0, 0};

    // layer 1
    int_t X_num[5] = {1, 64, _D, 56, 56};

    for(int_t i = 0; i < 200704; i++)
        X_tmp_data[i] = X_data[i];

    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_1_data, Kernel_1_2_data, 1, 1, 
                8.706942945718765259e-02, 4.961582273244857788e-02, 64, 71,
                Mu_seq_1_1, Var_seq_1_1, Gamma_seq_1_1, bias_seq_1_1, 4.489336907863616943e-02, 60); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    BatchNorm3d(X_data, X_num, Mu_seq_1_2, Var_seq_1_2, Gamma_seq_1_2, bias_seq_1_2, 5.436319485306739807e-02, 74);
    ReLU(X_data, X_num);
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_3_data, Kernel_1_4_data, 1, 1, 
                6.804036349058151245e-02, 3.850702568888664246e-02, 60, 66,
                Mu_seq_1_3,Var_seq_1_3, Gamma_seq_1_3, bias_seq_1_3, 4.303903132677078247e-02, 62); 
    BatchNorm3d(X_data, X_num, Mu_seq_1_4, Var_seq_1_4, Gamma_seq_1_4, bias_seq_1_4, 4.517441987991333008e-02, 68);
    for(int_t i = 0; i < 200704; i++)
        X_data[i] += X_tmp_data[i];
    ReLU(X_data, X_num);

    for(int_t i = 0; i < 200704; i++)
        X_tmp_data[i] = X_data[i];
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_5_data, Kernel_1_6_data, 1, 1, 
                9.410868585109710693e-02, 3.386811539530754089e-02, 72, 67,
                Mu_seq_1_5,Var_seq_1_5, Gamma_seq_1_5, bias_seq_1_5, 3.406318649649620056e-02, 76); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    BatchNorm3d(X_data, X_num, Mu_seq_1_6, Var_seq_1_6, Gamma_seq_1_6, bias_seq_1_6, 4.148417711257934570e-02, 70);
    ReLU(X_data, X_num);
    Conv2Plus1D(X_data, X_num, X_data, X_num, 144, Kernel_1_7_data, Kernel_1_8_data, 1, 1, 
                3.422784805297851562e-02, 2.731916867196559906e-02, 68, 71,
                Mu_seq_1_7,Var_seq_1_7, Gamma_seq_1_7, bias_seq_1_7, 2.891838178038597107e-02,  61); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
  
    BatchNorm3d(X_data, X_num, Mu_seq_1_8, Var_seq_1_8, Gamma_seq_1_8, bias_seq_1_8, 5.917721241712570190e-02, 53);
    for(int_t i = 0; i < 200704; i++)
        X_data[i] += X_tmp_data[i];
    ReLU(X_data, X_num);

    // // =============================================================================
    // // layer 2
    int_t X2_num[5] = {1, 128, 8, 28, 28};

    for(int_t i = 0; i < 200704; i++)
        X_tmp_data[i] = X_data[i];
        
    Conv2Plus1D(X_data, X_num, X2_data, X2_num, 230, Kernel_2_1_data, Kernel_2_2_data, 2, 1,
                1.296460330486297607e-01, 3.311596438288688660e-02, 76, 64,
                Mu_seq_2_1,Var_seq_2_1, Gamma_seq_2_1, bias_seq_2_1, 3.834486752748489380e-02, 66); // 230 = (64 * 128 * 3 * 3) / (64 * 3 + 128)

    BatchNorm3d(X2_data, X2_num, Mu_seq_2_2, Var_seq_2_2, Gamma_seq_2_2, bias_seq_2_2, 3.730613738298416138e-02, 52);
    
    ReLU(X2_data, X2_num);
    Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 230, Kernel_2_3_data, Kernel_2_4_data, 1, 1,
                6.581791490316390991e-02, 3.792280331254005432e-02, 68, 70,
                Mu_seq_2_3,Var_seq_2_3, Gamma_seq_2_3, bias_seq_2_3, 3.696846589446067810e-02, 75); // 230 = (64 * 128 * 3 * 3) / (64 * 3 + 128)
    BatchNorm3d(X2_data, X2_num, Mu_seq_2_4, Var_seq_2_4, Gamma_seq_2_4, bias_seq_2_4, 5.221061781048774719e-02, 61);
    
    Conv3d(X_tmp_data, X_num, X2_tmp_data, X2_num, Kernel_2_5_data, Kernel_num, stride, padding,5.711162462830543518e-02, 68);
    BatchNorm3d(X2_tmp_data, X2_num, Mu_seq_2_5, Var_seq_2_5, Gamma_seq_2_5, bias_seq_2_5, 5.571814253926277161e-02, 53);
   
    for(int_t i = 0; i< 100352; i++)
        X2_data[i] += X2_tmp_data[i];
    ReLU(X2_data, X2_num);
    
    for(int_t i = 0; i < 100352; i++)
        X2_tmp_data[i] = X2_data[i];
    Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 288, Kernel_2_6_data, Kernel_2_7_data, 1, 1,
                1.044261455535888672e-01, 2.876071259379386902e-02, 64, 63,
                Mu_seq_2_6,Var_seq_2_6, Gamma_seq_2_6, bias_seq_2_6, 2.571923658251762390e-02, 74); // 288 = (128 * 128 * 3 * 3) / (128 * 3 + 128)
    BatchNorm3d(X2_data, X2_num, Mu_seq_2_7, Var_seq_2_7, Gamma_seq_2_7, bias_seq_2_7, 4.108780622482299805e-02, 69);
    
    ReLU(X2_data, X2_num);
    Conv2Plus1D(X2_data, X2_num, X2_data, X2_num, 288, Kernel_2_8_data, Kernel_2_9_data, 1, 1,
                4.689884185791015625e-02, 2.438377402722835541e-02, 55, 66,
                Mu_seq_2_8,Var_seq_2_8, Gamma_seq_2_8, bias_seq_2_8, 3.150121122598648071e-02, 69);
    BatchNorm3d(X2_data, X2_num, Mu_seq_2_9, Var_seq_2_9, Gamma_seq_2_9, bias_seq_2_9, 6.300298124551773071e-02, 70);
    for(int_t i = 0; i < 100352; i++)
        X2_data[i] += X2_tmp_data[i];
    ReLU(X2_data, X2_num);

    // // =============================================================================
    // // layer 3
    int_t X3_num[5] = {1, 256, 4, 14, 14};

    for(int_t i = 0; i< 100352; i++)
        X2_tmp_data[i] = X2_data[i];
    Conv2Plus1D(X2_data, X2_num, X3_data, X3_num, 460, Kernel_3_1_data, Kernel_3_2_data, 2, 1,
                1.026936098933219910e-01, 3.513325005769729614e-02, 66, 64,
                Mu_seq_3_1, Var_seq_3_1, Gamma_seq_3_1, bias_seq_3_1, 3.207130357623100281e-02, 55); // 460 = (128 * 256 * 3 * 3) / (128 * 3 + 256)
    BatchNorm3d(X3_data, X3_num, Mu_seq_3_2, Var_seq_3_2, Gamma_seq_3_2, bias_seq_3_2, 3.827788308262825012e-02, 59);
    ReLU(X3_data, X3_num);
    Conv2Plus1D(X3_data, X3_num, X3_data, X3_num, 460, Kernel_3_3_data, Kernel_3_4_data, 1, 1,
                7.229902595281600952e-02, 3.355694189667701721e-02, 74, 57,
                Mu_seq_3_3, Var_seq_3_3, Gamma_seq_3_3, bias_seq_3_3, 2.794230915606021881e-02, 61);
    BatchNorm3d(X3_data, X3_num, Mu_seq_3_4, Var_seq_3_4, Gamma_seq_3_4, bias_seq_3_4, 3.775262087583541870e-02, 63);

    Conv3d(X2_tmp_data, X2_num, X3_tmp_data, X3_num, Kernel_3_5_data, Kernel_num, stride, padding, 3.776641562581062317e-02, 72);
    BatchNorm3d(X3_tmp_data, X3_num, Mu_seq_3_5, Var_seq_3_5, Gamma_seq_3_5, bias_seq_3_5, 4.242179170250892639e-02, 52);
    for(int_t i = 0; i< 50176; i++)
        X3_data[i] += X3_tmp_data[i];
    ReLU(X3_data, X3_num);
    
    for(int_t i = 0; i< 50176; i++)
        X3_tmp_data[i] = X3_data[i];
    Conv2Plus1D(X3_data, X3_num, X3_data, X3_num, 576, Kernel_3_6_data, Kernel_3_7_data, 1, 1,
                9.108851104974746704e-02, 2.204562351107597351e-02, 60, 64,
                Mu_seq_3_6, Var_seq_3_6, Gamma_seq_3_6, bias_seq_3_6, 1.979854144155979156e-02, 64);
    BatchNorm3d(X3_data, X3_num, Mu_seq_3_7, Var_seq_3_7, Gamma_seq_3_7, bias_seq_3_7, 2.682571485638618469e-02, 55);
    ReLU(X3_data, X3_num);
    Conv2Plus1D(X3_data, X3_num, X3_data, X3_num, 576, Kernel_3_8_data, Kernel_3_9_data, 1, 1,
                4.488958418369293213e-02, 3.477662429213523865e-02, 58, 82,
                Mu_seq_3_8, Var_seq_3_8, Gamma_seq_3_8, bias_seq_3_8, 2.272782102227210999e-02, 74);
    BatchNorm3d(X3_data, X3_num, Mu_seq_3_9, Var_seq_3_9, Gamma_seq_3_9, bias_seq_3_9, 3.744378685951232910e-02, 78);
    for(int_t i = 0; i< 50176; i++)
        X3_data[i] += X3_tmp_data[i];
    ReLU(X3_data, X3_num);

    // // =============================================================================

    // // layer 4
    int_t X4_num[5] = {1, 512, 2, 7, 7};

    for(int_t i = 0; i< 50176; i++)
        X3_tmp_data[i] = X3_data[i];
    Conv2Plus1D(X3_data, X3_num, X4_data, X4_num, 921, Kernel_4_1_data, Kernel_4_2_data, 2, 1,
                7.933901995420455933e-02, 4.174583032727241516e-02, 64, 60,
                Mu_seq_4_1, Var_seq_4_1, Gamma_seq_4_1, bias_seq_4_1, 2.300033532083034515e-02, 71); // 921 = (256 * 512 * 3 * 3) / (256 * 3 + 512)
    BatchNorm3d(X4_data, X4_num, Mu_seq_4_2, Var_seq_4_2, Gamma_seq_4_2, bias_seq_4_2, 3.296769410371780396e-02, 49);
    ReLU(X4_data, X4_num);
    Conv2Plus1D(X4_data, X4_num, X4_data, X4_num, 921, Kernel_4_3_data, Kernel_4_4_data, 1, 1,
                5.654629692435264587e-02, 3.702012076973915100e-02, 61, 56,
                Mu_seq_4_3, Var_seq_4_3, Gamma_seq_4_3, bias_seq_4_3, 2.629663422703742981e-02, 60);
    BatchNorm3d(X4_data, X4_num,  Mu_seq_4_4, Var_seq_4_4, Gamma_seq_4_4, bias_seq_4_4, 8.961183577775955200e-02, 57);

    Conv3d(X3_tmp_data, X3_num, X4_tmp_data, X4_num, Kernel_4_5_data, Kernel_num, stride, padding, 2.351688779890537262e-02, 60);
    BatchNorm3d(X4_tmp_data, X4_num, Mu_seq_4_5, Var_seq_4_5, Gamma_seq_4_5, bias_seq_4_5, 5.310279503464698792e-02, 59);
    for(int_t i = 0; i< 25088; i++)
        X4_data[i] += X4_tmp_data[i];
    ReLU(X4_data, X4_num);
    
    for(int_t i = 0; i< 25088; i++)
        X4_tmp_data[i] = X4_data[i];
    Conv2Plus1D(X4_data, X4_num, X4_data, X4_num, 1152, Kernel_4_6_data, Kernel_4_7_data, 1, 1,
                5.083529949188232422e-01, 3.209327906370162964e-02, 57, 59,
                Mu_seq_4_6, Var_seq_4_6, Gamma_seq_4_6, bias_seq_4_6, 2.375184185802936554e-02, 66); // 1152 = (512 * 512 * 3 * 3) / (512 * 3 + 512)
    BatchNorm3d(X4_data, X4_num, Mu_seq_4_7, Var_seq_4_7, Gamma_seq_4_7, bias_seq_4_7, 2.595668099820613861e-02, 68);
    ReLU(X4_data, X4_num);
    Conv2Plus1D(X4_data, X4_num, X4_data, X4_num, 1152, Kernel_4_8_data, Kernel_4_9_data, 1, 1,
                8.170315623283386230e-02, 2.505685016512870789e-02, 67, 59,
                Mu_seq_4_8, Var_seq_4_8, Gamma_seq_4_8, bias_seq_4_8, 2.590175159275531769e-02, 63);
    BatchNorm3d(X4_data, X4_num, Mu_seq_4_9, Var_seq_4_9, Gamma_seq_4_9, bias_seq_4_9, 1.026933342218399048e-01, 42);
    for(int_t i = 0; i< 25088; i++)
        X4_data[i] += X4_tmp_data[i];
    ReLU(X4_data, X4_num);

    // =============================================================================

    for(int_t i = 0; i < 25088; i++)  //for test
        Y_data[i] = X4_data[i];
    
#ifndef __SYNTHESIS__
    free(X_tmp_data);
    free(X2_data);
    free(X2_tmp_data);
    free(X3_data);
    free(X3_tmp_data);
    free(X4_data);
    free(X4_tmp_data);
#endif
    
    return;
}