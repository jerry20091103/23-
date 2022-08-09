// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xsw_compute.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XSw_compute_CfgInitialize(XSw_compute *InstancePtr, XSw_compute_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XSw_compute_Start(XSw_compute *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_AP_CTRL) & 0x80;
    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XSw_compute_IsDone(XSw_compute *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XSw_compute_IsIdle(XSw_compute *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XSw_compute_IsReady(XSw_compute *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XSw_compute_EnableAutoRestart(XSw_compute *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XSw_compute_DisableAutoRestart(XSw_compute *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_AP_CTRL, 0);
}

void XSw_compute_Set_im(XSw_compute *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_IM_DATA, (u32)(Data));
    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_IM_DATA + 4, (u32)(Data >> 32));
}

u64 XSw_compute_Get_im(XSw_compute *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_IM_DATA);
    Data += (u64)XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_IM_DATA + 4) << 32;
    return Data;
}

void XSw_compute_Set_out_r(XSw_compute *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_OUT_R_DATA, (u32)(Data));
    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_OUT_R_DATA + 4, (u32)(Data >> 32));
}

u64 XSw_compute_Get_out_r(XSw_compute *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_OUT_R_DATA);
    Data += (u64)XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_OUT_R_DATA + 4) << 32;
    return Data;
}

void XSw_compute_InterruptGlobalEnable(XSw_compute *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_GIE, 1);
}

void XSw_compute_InterruptGlobalDisable(XSw_compute *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_GIE, 0);
}

void XSw_compute_InterruptEnable(XSw_compute *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_IER);
    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_IER, Register | Mask);
}

void XSw_compute_InterruptDisable(XSw_compute *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_IER);
    XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_IER, Register & (~Mask));
}

void XSw_compute_InterruptClear(XSw_compute *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    //XSw_compute_WriteReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_ISR, Mask);
}

u32 XSw_compute_InterruptGetEnabled(XSw_compute *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_IER);
}

u32 XSw_compute_InterruptGetStatus(XSw_compute *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    // Current Interrupt Clear Behavior is Clear on Read(COR).
    return XSw_compute_ReadReg(InstancePtr->Control_BaseAddress, XSW_COMPUTE_CONTROL_ADDR_ISR);
}

