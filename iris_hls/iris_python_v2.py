import numpy as np
from time import time
import matplotlib.pyplot as plt 

from pynq import Overlay
from pynq import allocate

if __name__ == "__main__":
    ol = Overlay("/home/xilinx/jupyter_notebooks/iris/iris_hls_v3.bit")
    ip_iris = ol.sw_compute_0

    # calculate the number of input data
    Image = open("image.txt", "r+")
    inputNum = 0
    line = Image.readline()
    while line:
        inputNum = inputNum + 1
        line = Image.readline()
    inputNum = int(inputNum/4)

    # allocate memory 
    inputmem = inputNum*4
    totalmem = inputNum*16
    inBuffer = allocate(shape=(inputmem,), dtype=np.int32) 
    outBuffer = allocate(shape=(totalmem,), dtype=np.int32)
    outBufferPy = allocate(shape=(totalmem,), dtype=np.int32)
    
    # prepare input data
    Image.seek(0)
    for i in range(inputmem):
        line = Image.readline()
        inBuffer[i] = int(line)
        outBufferPy[i] = int(line)
    Image.close()

    # *start the computation for hls hardware
    timeKernelStart = time()
    # write input data number
    ip_iris.write(0x28, inputNum)
    # write input address
    ip_iris.write(0x10, inBuffer.device_address)
    # write output address
    ip_iris.write(0x1C, outBuffer.device_address)
    # ap_start
    ip_iris.write(0x00, 0x01)
    # wait for the computation to finish
    while (ip_iris.read(0x00) & 0x4) == 0x0:
        continue
    timeKernelEnd = time()
    print("hardware execution time: " + str(timeKernelEnd - timeKernelStart) + " s")
    
    # *prepare weights data for python
    scale_FC1 = 402
    scale_FC2 = 288
    weight = [31, 46, -99, -89, 26, 20, -91, -85, 62, -125, 127, -31, 60, -92, 
            112, -17, 24, -40, 98, 14, -2, -9, -44, -66, 2, -17, -49, -66, -8,
            -16, 3, 13, 82, 68, -128, -128, -126, 38, 37, 1, 29, 34, 4, 0, -19,
            29, 35, -4, -80, -66, 14, 19, 26, -45, -48, -3, -843, -91, 654 ]

    # *start the computation for python
    timePythonStart = time()
    for i in range(inputNum):
        for j in range(8):
            for k in range(4):
                outBufferPy[inputNum*4+8*i+j] += outBufferPy[4*i+k]*weight[4*j+k] 
    for i in range(inputNum*4, inputNum*12):
        # Relu
        if(outBufferPy[i]<0):
            outBufferPy[i] = 0
        # Quan
        outBufferPy[i] = outBufferPy[i]*scale_FC1 / 65536
        if(outBufferPy[i]>127):
            outBufferPy[i] = 127
    for i in range(inputNum):
        for j in range(3):
            outBufferPy[inputNum*12+3*i+j] += weight[56+j]
            for k in range(8):
                outBufferPy[inputNum*12+3*i+j] += outBufferPy[inputNum*4+8*i+k]*weight[32+8*j+k]
    #maxpooling
    for i in range(inputNum):
        #find max
        max = outBufferPy[inputNum*12+3*i]
        max_index = 0
        for j in range(3):
            if(outBufferPy[inputNum*12+3*i+j] > max):
                max = outBufferPy[inputNum*12+3*i+j]
                max_index = j
        outBufferPy[inputNum*15+i] = max_index
    timePythonEnd = time()
    print("Python execution time: " + str(timePythonEnd - timePythonStart) + " s")
    
    # *compare results
    if(np.array_equal(outBuffer, outBufferPy)):
        print(f">> {inputNum} image results are the same!")
        print(">> the result:")
        for i in range(inputNum):
            print(f"   image{i} : {outBuffer[inputNum*15+i]}")
    else:
        print("results are different!")
        for i in range(inputNum*16):
            print(f"index {i}: {outBuffer[i]} <-> {outBufferPy[i]}")
            

