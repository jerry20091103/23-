import numpy as np
from time import time
import matplotlib.pyplot as plt 

from pynq import Overlay
from pynq import allocate

if __name__ == "__main__":
    ol = Overlay("/home/xilinx/iris_hls/iris_hls.bit")
    ip_iris = ol.iris_module_0

    # calculate the number of image & weight data
    Image = open("image.txt", "r+")
    numImage = 0
    line = Image.readline()
    while line:
        numImage = numImage + 1
        line = Image.readline()
    
    Weight = open("weight.txt", "r+")
    numWeight = 0
    line = Weight.readline()
    while line:
        numWeight = numWeight + 1
        line = Weight.readline()

    # allocate memory 
    actBuffer = allocate(shape=(120,), dtype=np.int32)
    weightBuffer = allocate(shape=(numWeight,), dtype=np.int32)
    outBufferPy = allocate(shape=(120,), dtype=np.int32)
    
    # prepare image & weight data
    Image.seek(0)
    for i in range(numImage):
        line = Image.readline()
        actBuffer[i] = int(line)
        outBufferPy[i] = int(line)
    Image.close()
    
    Weight.seek(0)
    for i in range(numWeight):
        line = Weight.readline()
        weightBuffer[i] = int(line)
    Weight.close()


    # prepare scale
    scale_FC1 = 402
    scale_FC2 = 288

    # *start the computation for hls hardware
    timeKernelStart = time()
    # write scale
    ip_iris.write(0x28, scale_FC1)
    ip_iris.write(0x30, scale_FC2)

    # write input address
    ip_iris.write(0x10, actBuffer.device_address)
    # write output address
    ip_iris.write(0x1C, weightBuffer.device_address)
    # ap_start
    ip_iris.write(0x00, 0x01)
    # wait for the computation to finish
    while (ip_iris.read(0x00) & 0x4) == 0x0:
        continue
    timeKernelEnd = time()
    print("hardware execution time: " + str(timeKernelEnd - timeKernelStart) + " s")
    
    # *start the computation for python
    timePythonStart = time()
    for i in range(8):
        for j in range(8):
            for k in range(4):
                outBufferPy[32+8*i+j] += outBufferPy[4*i+k]*weightBuffer[4*j+k] 
    for i in range(32, 96):
        # Relu
        if(outBufferPy[i]<0):
            outBufferPy[i] = 0
        # Quan
        outBufferPy[i] = outBufferPy[i]*scale_FC1 / 65536
        if(outBufferPy[i]>127):
            outBufferPy[i] = 127
    for i in range(8):
        for j in range(3):
            outBufferPy[96+3*i+j] += weightBuffer[56+j]
            for k in range(8):
                outBufferPy[96+3*i+j] += outBufferPy[32+8*i+k]*weightBuffer[32+8*j+k]
    timePythonEnd = time()
    print("Python execution time: " + str(timePythonEnd - timePythonStart) + " s")
    
    # *compare results
    if(np.array_equal(actBuffer, outBufferPy)):
        print("results are the same!")
    else:
        print("results are different!")
        for i in range(120):
            print(f"{actBuffer[i]} <-> {outBufferPy[i]}")

