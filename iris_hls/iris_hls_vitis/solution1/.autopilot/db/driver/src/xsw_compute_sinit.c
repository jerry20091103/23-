// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.1 (64-bit)
// Tool Version Limit: 2022.04
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xsw_compute.h"

extern XSw_compute_Config XSw_compute_ConfigTable[];

XSw_compute_Config *XSw_compute_LookupConfig(u16 DeviceId) {
	XSw_compute_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XSW_COMPUTE_NUM_INSTANCES; Index++) {
		if (XSw_compute_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XSw_compute_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XSw_compute_Initialize(XSw_compute *InstancePtr, u16 DeviceId) {
	XSw_compute_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XSw_compute_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XSw_compute_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

