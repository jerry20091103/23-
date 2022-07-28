// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xiris_module.h"

extern XIris_module_Config XIris_module_ConfigTable[];

XIris_module_Config *XIris_module_LookupConfig(u16 DeviceId) {
	XIris_module_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XIRIS_MODULE_NUM_INSTANCES; Index++) {
		if (XIris_module_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XIris_module_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XIris_module_Initialize(XIris_module *InstancePtr, u16 DeviceId) {
	XIris_module_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XIris_module_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XIris_module_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

