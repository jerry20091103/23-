#include "r2plus1d.h"
#include<iostream>
using namespace std;

void Sequential(dtype* X_data, dtype* Y_data, int_t* X_num, int_t* Y_num, int_t midplane,
                dtype* X_mid_data, dtype* X_batch_data, dtype* X_tmp_data, 
                dtype X_tile_num, dtype X_tile_size, dtype Y_tile_num, dtype Y_tile_size, dtype mid_tile_num, dtype mid_tile_size, 
                ftype X_scale, dtype X_zeropoint,
                ktype* Kernel_seq_0_conv1_0_0, ktype* Kernel_seq_0_conv1_0_3, ktype* Kernel_seq_0_conv2_0_0, ktype* Kernel_seq_0_conv2_0_3,
                ktype* Kernel_seq_0_downsample_0, 
                ktype* Kernel_seq_1_conv1_0_0, ktype* Kernel_seq_1_conv1_0_3, ktype* Kernel_seq_1_conv2_0_0, ktype* Kernel_seq_1_conv2_0_3,
                )
{
    // // ========================================================================================
    // int_t Kernel_num[3] = {1, 1, 1};
    // int_t stride[3] = {2, 2, 2};
    // int_t padding[3] = {0, 0, 0};

    // // layer 1
    // int_t X_num[5] = {1, 64, 16, 56, 56};

    // for(int_t i = 0; i < 3211264; i++)
    //     X_tmp_data[i] = X_data[i];

    // Conv2Plus1D(X_data, X_num, X_mid_data, X_batch_data, X_data, X_num, 144, 
    //             Kernel_1_1_data, Kernel_1_2_data, Kernel_seq1_0_conv1_0_0_scale, Kernel_seq1_0_conv1_0_3_scale, 1, 1, 
    //             X_scale, 8.706942945718765259e-02, 4.961582273244857788e-02 ,X_zeropoint, 64, 71,
    //             Mu_seq1_0_conv1_0_1, Var_seq1_0_conv1_0_1, Gamma_seq1_0_conv1_0_1, Bias_seq1_0_conv1_0_1, 4.489336907863616943e-02, 60); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    // BatchNorm3d(X_data, X_batch_data ,X_num, Mu_seq1_0_conv1_1, Var_seq1_0_conv1_1, Gamma_seq1_0_conv1_1, Bias_seq1_0_conv1_1,4.961582273244857788e-02 ,71, 5.436319485306739807e-02, 74);
    // ReLU(X_batch_data, X_data, X_num, 74);
    // Conv2Plus1D(X_data, X_num, X_mid_data, X_batch_data,X_data, X_num, 144, 
    //             Kernel_1_3_data, Kernel_1_4_data, Kernel_seq1_0_conv2_0_0_scale, Kernel_seq1_0_conv2_0_3_scale, 1, 1, 
    //             5.436319485306739807e-02,6.804036349058151245e-02, 3.850702568888664246e-02, 74, 60, 66,
    //             Mu_seq1_0_conv2_0_1,Var_seq1_0_conv2_0_1, Gamma_seq1_0_conv2_0_1, Bias_seq1_0_conv2_0_1, 4.303903132677078247e-02, 62); 
    // BatchNorm3d(X_data, X_batch_data,X_num, Mu_seq1_0_conv2_1, Var_seq1_0_conv2_1, Gamma_seq1_0_conv2_1, Bias_seq1_0_conv2_1, 3.850702568888664246e-02, 66 ,4.517441987991333008e-02, 68);
    // // layer1.0
    // Residual(X_batch_data, X_tmp_data, X_num, 4.517441987991333008e-02, X_scale, 7.029289007186889648e-02, 68, X_zeropoint, 46);
    // ReLU(X_batch_data, X_data, X_num, 46);

    // for(int_t i = 0; i < 3211264; i++)
    //     X_tmp_data[i] = X_data[i];
    // Conv2Plus1D(X_data, X_num, X_mid_data, X_batch_data, X_data, X_num, 144, 
    //             Kernel_1_5_data, Kernel_1_6_data, Kernel_seq1_1_conv1_0_0_scale, Kernel_seq1_1_conv1_0_3_scale, 1, 1, 
    //             7.029289007186889648e-02, 9.410868585109710693e-02, 3.386811539530754089e-02, 46, 72, 67,
    //             Mu_seq1_1_conv1_0_1,Var_seq1_1_conv1_0_1, Gamma_seq1_1_conv1_0_1, Bias_seq1_1_conv1_0_1, 3.406318649649620056e-02, 76); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    // BatchNorm3d(X_data, X_batch_data,X_num, Mu_seq1_1_conv1_1, Var_seq1_1_conv1_1, Gamma_seq1_1_conv1_1, Bias_seq1_1_conv1_1,3.386811539530754089e-02,67,4.148417711257934570e-02, 70);
    // ReLU(X_batch_data, X_data, X_num, 70);
    // Conv2Plus1D(X_data, X_num, X_mid_data, X_batch_data, X_data, X_num, 144, 
    //             Kernel_1_7_data, Kernel_1_8_data, Kernel_seq1_1_conv2_0_0_scale, Kernel_seq1_1_conv2_0_3_scale, 1, 1, 
    //             4.148417711257934570e-02, 3.422784805297851562e-02, 2.731916867196559906e-02, 70, 68, 71,
    //             Mu_seq1_1_conv2_0_1,Var_seq1_1_conv2_0_1, Gamma_seq1_1_conv2_0_1, Bias_seq1_1_conv2_0_1, 2.891838178038597107e-02,  61); // 144 = (inplanes * planes * 3 * 3) / (inplanes * 3 + planes)
    // BatchNorm3d(X_data, X_batch_data, X_num, Mu_seq1_1_conv2_1, Var_seq1_1_conv2_1, Gamma_seq1_1_conv2_1, Bias_seq1_1_conv2_1,2.731916867196559906e-02, 71, 5.917721241712570190e-02, 53);
    // // layer1.1
    // Residual(X_batch_data, X_tmp_data, X_num, 5.917721241712570190e-02, 7.029289007186889648e-02, 7.128605991601943970e-02, 53, 46, 49);
    // ReLU(X_batch_data, X_data, X_num, 49);

    // // =============================================================================
    // layer 2
    int_t X2_num[5] = {1, 128, 8, 28, 28};

    for(int_t i = 0; i < 3211264; i++)
        X_tmp_data[i] = X_data[i];
        
    Conv2Plus1D(X_data, X_num, X2_mid_data, X2_batch_data, X2_data, X2_num, 230, 
                Kernel_2_1_data, Kernel_2_2_data, Kernel_seq2_0_conv1_0_0_scale, Kernel_seq2_0_conv1_0_3_scale, 2, 1,
                7.128605991601943970e-02, 1.296460330486297607e-01, 3.311596438288688660e-02, 49, 76, 64,
                Mu_seq2_0_conv1_0_1,Var_seq2_0_conv1_0_1, Gamma_seq2_0_conv1_0_1, Bias_seq2_0_conv1_0_1, 3.834486752748489380e-02, 66); // 230 = (64 * 128 * 3 * 3) / (64 * 3 + 128)

    BatchNorm3d(X2_data, X2_batch_data, X2_num, Mu_seq2_0_conv1_1, Var_seq2_0_conv1_1, Gamma_seq2_0_conv1_1, Bias_seq2_0_conv1_1, 3.311596438288688660e-02, 64,3.730613738298416138e-02, 52);
    
    ReLU(X2_batch_data, X2_data, X2_num, 52);
    Conv2Plus1D(X2_data, X2_num, X2_mid_data, X2_batch_data, X2_data, X2_num, 230, 
                Kernel_2_3_data, Kernel_2_4_data, Kernel_seq2_0_conv2_0_0_scale, Kernel_seq2_0_conv2_0_3_scale, 1, 1,
                3.730613738298416138e-02,  6.581791490316390991e-02, 3.792280331254005432e-02, 52, 68, 70,
                Mu_seq2_0_conv2_0_1,Var_seq2_0_conv2_0_1, Gamma_seq2_0_conv2_0_1, Bias_seq2_0_conv2_0_1, 3.696846589446067810e-02, 75); // 230 = (64 * 128 * 3 * 3) / (64 * 3 + 128)
    BatchNorm3d(X2_data, X2_batch_data, X2_num, Mu_seq2_0_conv2_1, Var_seq2_0_conv2_1, Gamma_seq2_0_conv2_1, Bias_seq2_0_conv2_1, 3.792280331254005432e-02, 70, 5.221061781048774719e-02, 61);
    
    Conv3d(X_tmp_data, X_num, X2_tmp_data, X2_num, Kernel_2_5_data, Kernel_num, Kernel_seq2_0_downsample_0_scale, stride, padding, 7.128605991601943970e-02, 49, 5.711162462830543518e-02, 68);
    BatchNorm3d(X2_tmp_data, X2_tmp_data, X2_num, Mu_seq2_0_downsample_1, Var_seq2_0_downsample_1, Gamma_seq2_0_downsample_1, Bias_seq2_0_downsample_1, 5.711162462830543518e-02, 68, 5.571814253926277161e-02, 53);
   
    // layer2.0
    Residual(X2_batch_data, X2_tmp_data, X2_num, 5.221061781048774719e-02, 5.571814253926277161e-02, 5.941560864448547363e-02, 61, 53, 59);
    ReLU(X2_batch_data, X2_data, X2_num, 59);
    
    for(int_t i = 0; i < 802816; i++)
        X2_tmp_data[i] = X2_data[i];
    Conv2Plus1D(X2_data, X2_num, X2_mid_data, X2_batch_data, X2_data, X2_num, 288, 
                Kernel_2_6_data, Kernel_2_7_data, Kernel_seq2_1_conv1_0_0_scale, Kernel_seq2_1_conv1_0_3_scale, 1, 1,
                5.941560864448547363e-02, 1.044261455535888672e-01, 2.876071259379386902e-02, 59, 64, 63,
                Mu_seq2_1_conv1_0_1,Var_seq2_1_conv1_0_1, Gamma_seq2_1_conv1_0_1, Bias_seq2_1_conv1_0_1, 2.571923658251762390e-02, 74); // 288 = (128 * 128 * 3 * 3) / (128 * 3 + 128)
    BatchNorm3d(X2_data, X2_batch_data, X2_num, Mu_seq2_1_conv1_1, Var_seq2_1_conv1_1, Gamma_seq2_1_conv1_1, Bias_seq2_1_conv1_1,  2.876071259379386902e-02, 63, 4.108780622482299805e-02, 69);
    
    ReLU(X2_batch_data, X2_data, X2_num, 69);
    Conv2Plus1D(X2_data, X2_num, X2_mid_data, X2_batch_data, X2_data, X2_num, 288, 
                Kernel_2_8_data, Kernel_2_9_data, Kernel_seq2_1_conv2_0_0_scale, Kernel_seq2_1_conv2_0_3_scale, 1, 1,
                4.108780622482299805e-02, 4.689884185791015625e-02, 2.438377402722835541e-02, 69, 55, 66,
                Mu_seq2_1_conv2_0_1,Var_seq2_1_conv2_0_1, Gamma_seq2_1_conv2_0_1, Bias_seq2_1_conv2_0_1, 3.150121122598648071e-02, 69);
    BatchNorm3d(X2_data, X2_batch_data, X2_num, Mu_seq2_1_conv2_1, Var_seq2_1_conv2_1, Gamma_seq2_1_conv2_1, Bias_seq2_1_conv2_1, 2.438377402722835541e-02, 66, 6.300298124551773071e-02, 70);
    // layer2.1
    Residual(X2_batch_data, X2_tmp_data, X2_num, 6.300298124551773071e-02, 5.941560864448547363e-02, 7.469348609447479248e-02, 70, 59, 58);
    ReLU(X2_batch_data, X2_data, X2_num, 58);

    // // =============================================================================
    // // layer 3
    // int_t X3_num[5] = {1, 256, 4, 14, 14};

    // for(int_t i = 0; i< 802816; i++)
    //     X2_tmp_data[i] = X2_data[i];
    // Conv2Plus1D(X2_data, X2_num, X3_mid_data, X3_batch_data, X3_data, X3_num, 460, 
    //             Kernel_3_1_data, Kernel_3_2_data, Kernel_seq3_0_conv1_0_0_scale, Kernel_seq3_0_conv1_0_3_scale, 2, 1,
    //             7.469348609447479248e-02,  1.026936098933219910e-01, 3.513325005769729614e-02, 58, 66, 64,
    //             Mu_seq3_0_conv1_0_1, Var_seq3_0_conv1_0_1, Gamma_seq3_0_conv1_0_1, Bias_seq3_0_conv1_0_1, 3.207130357623100281e-02, 55); // 460 = (128 * 256 * 3 * 3) / (128 * 3 + 256)
    // BatchNorm3d(X3_data, X3_batch_data, X3_num, Mu_seq3_0_conv1_1, Var_seq3_0_conv1_1, Gamma_seq3_0_conv1_1, Bias_seq3_0_conv1_1, 3.513325005769729614e-02, 64, 3.827788308262825012e-02, 59);
    // ReLU(X3_batch_data, X3_data, X3_num, 59);
    Conv2Plus1D(X3_data, X3_num, X3_mid_data, X3_batch_data, X3_data, X3_num, 460, 
                Kernel_3_3_data, Kernel_3_4_data, Kernel_seq3_0_conv2_0_0_scale, Kernel_seq3_0_conv2_0_3_scale, 1, 1,
                3.827788308262825012e-02, 7.229902595281600952e-02, 3.355694189667701721e-02, 59, 74, 57,
                Mu_seq3_0_conv2_0_1, Var_seq3_0_conv2_0_1, Gamma_seq3_0_conv2_0_1, Bias_seq3_0_conv2_0_1, 2.794230915606021881e-02, 61);
    BatchNorm3d(X3_data, X3_batch_data, X3_num, Mu_seq3_0_conv2_1, Var_seq3_0_conv2_1, Gamma_seq3_0_conv2_1, Bias_seq3_0_conv2_1, 3.355694189667701721e-02, 57, 3.775262087583541870e-02, 63);

    Conv3d(X2_tmp_data, X2_num, X3_tmp_data, X3_num, Kernel_3_5_data, Kernel_num, Kernel_seq3_0_downsample_0_scale, stride, padding, 7.469348609447479248e-02, 58, 3.776641562581062317e-02, 72);
    BatchNorm3d(X3_tmp_data, X3_tmp_data, X3_num, Mu_seq3_0_downsample_1, Var_seq3_0_downsample_1, Gamma_seq3_0_downsample_1, Bias_seq3_0_downsample_1, 3.776641562581062317e-02, 72, 4.242179170250892639e-02, 52);
    
    // // layer3.0
    // Residual(X3_batch_data, X3_tmp_data, X3_num, 3.775262087583541870e-02, 4.242179170250892639e-02, 4.819526150822639465e-02, 63, 52, 56);
    // ReLU(X3_batch_data, X3_data, X3_num, 56);
    
    // for(int_t i = 0; i< 200704; i++)
    //     X3_tmp_data[i] = X3_data[i];
    // Conv2Plus1D(X3_data, X3_num, X3_mid_data, X3_batch_data, X3_data, X3_num, 576, 
    //             Kernel_3_6_data, Kernel_3_7_data, Kernel_seq3_1_conv1_0_0_scale, Kernel_seq3_1_conv1_0_3_scale, 1, 1,
    //             4.819526150822639465e-02, 9.108851104974746704e-02, 2.204562351107597351e-02, 56, 60, 64,
    //             Mu_seq3_1_conv1_0_1, Var_seq3_1_conv1_0_1, Gamma_seq3_1_conv1_0_1, Bias_seq3_1_conv1_0_1, 1.979854144155979156e-02, 64);
    // BatchNorm3d(X3_data, X3_batch_data, X3_num, Mu_seq3_1_conv1_1, Var_seq3_1_conv1_1, Gamma_seq3_1_conv1_1, Bias_seq3_1_conv1_1, 2.204562351107597351e-02, 64, 2.682571485638618469e-02, 55);
    // ReLU(X3_batch_data, X3_data, X3_num, 55);
    // Conv2Plus1D(X3_data, X3_num, X3_mid_data, X3_batch_data, X3_data, X3_num, 576, 
    //             Kernel_3_8_data, Kernel_3_9_data, Kernel_seq3_1_conv2_0_0_scale, Kernel_seq3_1_conv2_0_3_scale, 1, 1,
    //             2.682571485638618469e-02,4.488958418369293213e-02, 3.477662429213523865e-02, 55, 58, 82,
    //             Mu_seq3_1_conv2_0_1, Var_seq3_1_conv2_0_1, Gamma_seq3_1_conv2_0_1, Bias_seq3_1_conv2_0_1, 2.272782102227210999e-02, 74);
    // BatchNorm3d(X3_data, X3_batch_data, X3_num, Mu_seq3_1_conv2_1, Var_seq3_1_conv2_1, Gamma_seq3_1_conv2_1, Bias_seq3_1_conv2_1, 3.477662429213523865e-02, 82, 3.744378685951232910e-02, 78);
    // // layer3.1
    // Residual(X3_batch_data, X3_tmp_data, X3_num, 3.744378685951232910e-02, 4.819526150822639465e-02, 4.908789321780204773e-02, 78, 56, 58);
    // ReLU(X3_batch_data, X3_data, X3_num, 58);

    // // =============================================================================

    // // layer 4
    // int_t X4_num[5] = {1, 512, 2, 7, 7};

    // for(int_t i = 0; i< 200704; i++)
    //     X3_tmp_data[i] = X3_data[i];
    // Conv2Plus1D(X3_data, X3_num, X4_mid_data, X4_batch_data, X4_data, X4_num, 921, 
    //             Kernel_4_1_data, Kernel_4_2_data, Kernel_seq4_0_conv1_0_0_scale, Kernel_seq4_0_conv1_0_3_scale, 2, 1,
    //             4.908789321780204773e-02, 7.933901995420455933e-02, 4.174583032727241516e-02, 58, 64, 60,
    //             Mu_seq4_0_conv1_0_1, Var_seq4_0_conv1_0_1, Gamma_seq4_0_conv1_0_1, Bias_seq4_0_conv1_0_1, 2.300033532083034515e-02, 71); // 921 = (256 * 512 * 3 * 3) / (256 * 3 + 512)
    // BatchNorm3d(X4_data, X4_batch_data, X4_num, Mu_seq4_0_conv1_1, Var_seq4_0_conv1_1, Gamma_seq4_0_conv1_1, Bias_seq4_0_conv1_1, 4.174583032727241516e-02, 60,3.296769410371780396e-02, 49);
    // ReLU(X4_batch_data, X4_data, X4_num, 49);
    // Conv2Plus1D(X4_data, X4_num, X4_mid_data, X4_batch_data, X4_data, X4_num, 921, 
    //             Kernel_4_3_data, Kernel_4_4_data, Kernel_seq4_0_conv2_0_0_scale, Kernel_seq4_0_conv2_0_3_scale, 1, 1,
    //             3.296769410371780396e-02, 5.654629692435264587e-02, 3.702012076973915100e-02, 49, 61, 56,
    //             Mu_seq4_0_conv2_0_1, Var_seq4_0_conv2_0_1, Gamma_seq4_0_conv2_0_1, Bias_seq4_0_conv2_0_1, 2.629663422703742981e-02, 60);
    // BatchNorm3d(X4_data, X4_batch_data, X4_num,  Mu_seq4_0_conv2_1, Var_seq4_0_conv2_1, Gamma_seq4_0_conv2_1, Bias_seq4_0_conv2_1, 3.702012076973915100e-02,56 ,8.961183577775955200e-02, 57);

    // Conv3d(X3_tmp_data, X3_num, X4_tmp_data, X4_num, Kernel_4_5_data, Kernel_num, Kernel_seq4_0_downsample_0_scale, stride, padding, 4.908789321780204773e-02, 58, 2.351688779890537262e-02, 60);
    // BatchNorm3d(X4_tmp_data, X4_tmp_data, X4_num, Mu_seq4_0_downsample_1, Var_seq4_0_downsample_1, Gamma_seq4_0_downsample_1, Bias_seq4_0_downsample_1,2.351688779890537262e-02, 60, 5.310279503464698792e-02, 59);
    // // layer4.0
    // Residual(X4_batch_data, X4_tmp_data, X4_num, 8.961183577775955200e-02, 5.310279503464698792e-02, 1.033632829785346985e-01, 57, 59, 53);
    // ReLU(X4_batch_data, X4_data, X4_num, 53);
    
    // for(int_t i = 0; i< 50176; i++)
    //     X4_tmp_data[i] = X4_data[i];
    // Conv2Plus1D(X4_data, X4_num, X4_mid_data, X4_batch_data, X4_data, X4_num, 1152, 
    //             Kernel_4_6_data, Kernel_4_7_data, Kernel_seq4_1_conv1_0_0_scale, Kernel_seq4_1_conv1_0_3_scale, 1, 1,
    //             1.033632829785346985e-01,5.083529949188232422e-01, 3.209327906370162964e-02, 53, 59, 57, 
    //             Mu_seq4_1_conv1_0_1, Var_seq4_1_conv1_0_1, Gamma_seq4_1_conv1_0_1, Bias_seq4_1_conv1_0_1, 2.375184185802936554e-02, 66); // 1152 = (512 * 512 * 3 * 3) / (512 * 3 + 512)
    // BatchNorm3d(X4_data, X4_batch_data, X4_num, Mu_seq4_1_conv1_1, Var_seq4_1_conv1_1, Gamma_seq4_1_conv1_1, Bias_seq4_1_conv1_1, 3.209327906370162964e-02, 57, 2.595668099820613861e-02, 68);
    // ReLU(X4_batch_data, X4_data, X4_num, 68);
    // Conv2Plus1D(X4_data, X4_num, X4_mid_data, X4_batch_data, X4_data, X4_num, 1152, 
    //             Kernel_4_8_data, Kernel_4_9_data, Kernel_seq4_1_conv2_0_0_scale, Kernel_seq4_1_conv2_0_3_scale, 1, 1,
    //             2.595668099820613861e-02, 8.170315623283386230e-02, 2.505685016512870789e-02, 68, 67, 59,
    //             Mu_seq4_1_conv2_0_1, Var_seq4_1_conv2_0_1, Gamma_seq4_1_conv2_0_1, Bias_seq4_1_conv2_0_1, 2.590175159275531769e-02, 63);
    // BatchNorm3d(X4_data, X4_batch_data, X4_num, Mu_seq4_1_conv2_1, Var_seq4_1_conv2_1, Gamma_seq4_1_conv2_1, Bias_seq4_1_conv2_1, 2.505685016512870789e-02, 59, 1.026933342218399048e-01, 42);
    // // layer4.1
    // Residual(X4_batch_data, X4_tmp_data, X4_num, 1.026933342218399048e-01, 1.033632829785346985e-01, 1.290386915206909180e-01, 42, 53, 31);
    // ReLU(X4_batch_data, X4_data, X4_num, 31);

    return;
}