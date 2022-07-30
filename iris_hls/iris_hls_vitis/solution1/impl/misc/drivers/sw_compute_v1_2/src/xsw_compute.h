// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XSW_COMPUTE_H
#define XSW_COMPUTE_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xsw_compute_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u64 Control_BaseAddress;
} XSw_compute_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XSw_compute;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XSw_compute_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XSw_compute_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XSw_compute_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XSw_compute_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XSw_compute_Initialize(XSw_compute *InstancePtr, u16 DeviceId);
XSw_compute_Config* XSw_compute_LookupConfig(u16 DeviceId);
int XSw_compute_CfgInitialize(XSw_compute *InstancePtr, XSw_compute_Config *ConfigPtr);
#else
int XSw_compute_Initialize(XSw_compute *InstancePtr, const char* InstanceName);
int XSw_compute_Release(XSw_compute *InstancePtr);
#endif

void XSw_compute_Start(XSw_compute *InstancePtr);
u32 XSw_compute_IsDone(XSw_compute *InstancePtr);
u32 XSw_compute_IsIdle(XSw_compute *InstancePtr);
u32 XSw_compute_IsReady(XSw_compute *InstancePtr);
void XSw_compute_EnableAutoRestart(XSw_compute *InstancePtr);
void XSw_compute_DisableAutoRestart(XSw_compute *InstancePtr);

void XSw_compute_Set_im(XSw_compute *InstancePtr, u64 Data);
u64 XSw_compute_Get_im(XSw_compute *InstancePtr);
void XSw_compute_Set_out_r(XSw_compute *InstancePtr, u64 Data);
u64 XSw_compute_Get_out_r(XSw_compute *InstancePtr);

void XSw_compute_InterruptGlobalEnable(XSw_compute *InstancePtr);
void XSw_compute_InterruptGlobalDisable(XSw_compute *InstancePtr);
void XSw_compute_InterruptEnable(XSw_compute *InstancePtr, u32 Mask);
void XSw_compute_InterruptDisable(XSw_compute *InstancePtr, u32 Mask);
void XSw_compute_InterruptClear(XSw_compute *InstancePtr, u32 Mask);
u32 XSw_compute_InterruptGetEnabled(XSw_compute *InstancePtr);
u32 XSw_compute_InterruptGetStatus(XSw_compute *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
