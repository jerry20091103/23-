// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xiris_module.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XIris_module_CfgInitialize(XIris_module *InstancePtr, XIris_module_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XIris_module_Start(XIris_module *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_AP_CTRL) & 0x80;
    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XIris_module_IsDone(XIris_module *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XIris_module_IsIdle(XIris_module *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XIris_module_IsReady(XIris_module *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XIris_module_EnableAutoRestart(XIris_module *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XIris_module_DisableAutoRestart(XIris_module *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_AP_CTRL, 0);
}

void XIris_module_Set_input_features(XIris_module *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_INPUT_FEATURES_DATA, (u32)(Data));
    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_INPUT_FEATURES_DATA + 4, (u32)(Data >> 32));
}

u64 XIris_module_Get_input_features(XIris_module *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_INPUT_FEATURES_DATA);
    Data += (u64)XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_INPUT_FEATURES_DATA + 4) << 32;
    return Data;
}

void XIris_module_Set_output_result(XIris_module *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_OUTPUT_RESULT_DATA, (u32)(Data));
    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_OUTPUT_RESULT_DATA + 4, (u32)(Data >> 32));
}

u64 XIris_module_Get_output_result(XIris_module *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_OUTPUT_RESULT_DATA);
    Data += (u64)XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_OUTPUT_RESULT_DATA + 4) << 32;
    return Data;
}

void XIris_module_InterruptGlobalEnable(XIris_module *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_GIE, 1);
}

void XIris_module_InterruptGlobalDisable(XIris_module *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_GIE, 0);
}

void XIris_module_InterruptEnable(XIris_module *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_IER);
    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_IER, Register | Mask);
}

void XIris_module_InterruptDisable(XIris_module *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_IER);
    XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_IER, Register & (~Mask));
}

void XIris_module_InterruptClear(XIris_module *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    //XIris_module_WriteReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_ISR, Mask);
}

u32 XIris_module_InterruptGetEnabled(XIris_module *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_IER);
}

u32 XIris_module_InterruptGetStatus(XIris_module *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    // Current Interrupt Clear Behavior is Clear on Read(COR).
    return XIris_module_ReadReg(InstancePtr->Control_BaseAddress, XIRIS_MODULE_CONTROL_ADDR_ISR);
}

