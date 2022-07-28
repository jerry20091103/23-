// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XIRIS_MODULE_H
#define XIRIS_MODULE_H

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
#include "xiris_module_hw.h"

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
} XIris_module_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XIris_module;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XIris_module_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XIris_module_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XIris_module_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XIris_module_ReadReg(BaseAddress, RegOffset) \
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
int XIris_module_Initialize(XIris_module *InstancePtr, u16 DeviceId);
XIris_module_Config* XIris_module_LookupConfig(u16 DeviceId);
int XIris_module_CfgInitialize(XIris_module *InstancePtr, XIris_module_Config *ConfigPtr);
#else
int XIris_module_Initialize(XIris_module *InstancePtr, const char* InstanceName);
int XIris_module_Release(XIris_module *InstancePtr);
#endif

void XIris_module_Start(XIris_module *InstancePtr);
u32 XIris_module_IsDone(XIris_module *InstancePtr);
u32 XIris_module_IsIdle(XIris_module *InstancePtr);
u32 XIris_module_IsReady(XIris_module *InstancePtr);
void XIris_module_EnableAutoRestart(XIris_module *InstancePtr);
void XIris_module_DisableAutoRestart(XIris_module *InstancePtr);

void XIris_module_Set_input_features(XIris_module *InstancePtr, u64 Data);
u64 XIris_module_Get_input_features(XIris_module *InstancePtr);
void XIris_module_Set_output_result(XIris_module *InstancePtr, u64 Data);
u64 XIris_module_Get_output_result(XIris_module *InstancePtr);

void XIris_module_InterruptGlobalEnable(XIris_module *InstancePtr);
void XIris_module_InterruptGlobalDisable(XIris_module *InstancePtr);
void XIris_module_InterruptEnable(XIris_module *InstancePtr, u32 Mask);
void XIris_module_InterruptDisable(XIris_module *InstancePtr, u32 Mask);
void XIris_module_InterruptClear(XIris_module *InstancePtr, u32 Mask);
u32 XIris_module_InterruptGetEnabled(XIris_module *InstancePtr);
u32 XIris_module_InterruptGetStatus(XIris_module *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
