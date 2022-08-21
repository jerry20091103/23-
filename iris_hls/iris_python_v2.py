import numpy as np
import time
import matplotlib.pyplot as plt 

from pynq import Overlay
from pynq import allocate

if __name__ == "__main__":
    ol = Overlay("/home/xilinx/jupyter_notebooks/iris_hls_stream/iris_hls_streamv5.bit")
    ip_iris = ol.iris_compute_0
    ipDMAIn = ol.axi_dma_in_0
    ipDMAOut = ol.axi_dma_out_0

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
    inBuffer = allocate(shape=(inputmem,), dtype=np.int8) 
    outBuffer = allocate(shape=(inputNum,), dtype=np.int8)
    outBufferPy = allocate(shape=(inputNum,), dtype=np.int8)
    acc = [0]*totalmem

    # prepare input data
    Image.seek(0)
    for i in range(inputmem):
        line = Image.readline()
        inBuffer[i] = int(line)
        acc[i] = int(line)
    Image.close()

    # *start the computation for hls hardware
    print("start compute hls")
    timeKernelStart = time.time()

    recv_count = 0

    while recv_count < inputNum / 4:
        # ap_start
        ip_iris.write(0x00, 0x01)
        # we send 4 sets of data at once, because the DMA library requires 32bit aligned transfer, 
        # our output is only 8 bit at a time
        ipDMAIn.sendchannel.transfer(inBuffer, recv_count * 16, 16)
        ipDMAOut.recvchannel.transfer(outBuffer, recv_count * 4, 4)
        # wait for the computation to finish
        ipDMAIn.sendchannel.wait()
        ipDMAOut.recvchannel.wait()
        # print 4 results
        for i in range(4):
            if recv_count * 4 + i < inputNum:
                print(f"   image{recv_count * 4 + i} : {outBuffer[recv_count * 4 + i]}")
        recv_count = recv_count + 1
        #time.sleep(1)
    
    

    timeKernelEnd = time.time()
    print("hardware execution time: " + str(timeKernelEnd - timeKernelStart) + " s")
     
    # *prepare weights data for python
    scale_FC1 = 402
    scale_FC2 = 288
    weight = [31, 46, -99, -89, 26, 20, -91, -85, 62, -125, 127, -31, 60, -92, 
            112, -17, 24, -40, 98, 14, -2, -9, -44, -66, 2, -17, -49, -66, -8,
            -16, 3, 13, 82, 68, -128, -128, -126, 38, 37, 1, 29, 34, 4, 0, -19,
            29, 35, -4, -80, -66, 14, 19, 26, -45, -48, -3, -843, -91, 654 ]
    # *start the computation for python
    timePythonStart = time.time()
    #FC1
    for i in range(inputNum):
        for j in range(8):
            for k in range(4):
                acc[inputNum*4+8*i+j] += acc[4*i+k]*weight[4*j+k] 
    for i in range(inputNum*4, inputNum*12):
        # Relu
        if(acc[i]<0):
            acc[i] = 0
        # Quan
        acc[i] = acc[i]*scale_FC1 / 65536
        if(acc[i]>127):
            acc[i] = 127
    #FC2
    for i in range(inputNum):
        for j in range(3):
            acc[inputNum*12+3*i+j] += weight[56+j]
            for k in range(8):
                acc[inputNum*12+3*i+j] += acc[inputNum*4+8*i+k]*weight[32+8*j+k]
    #maxpooling
    for i in range(inputNum):
        #find max
        max = acc[inputNum*12+3*i]
        max_index = 0
        for j in range(3):
            if(acc[inputNum*12+3*i+j] > max):
                max = acc[inputNum*12+3*i+j]
                max_index = j
        outBufferPy[i] = max_index
    timePythonEnd = time.time()
    print("Python execution time: " + str(timePythonEnd - timePythonStart) + " s")
    
    # *compare results
    if(np.array_equal(outBuffer, outBufferPy)):
        print(">> results are the same!")
    
    else:
        print("results are different!")
        for i in range(inputNum):
            print(f"index {i}: {outBuffer[i]} <-> {outBufferPy[i]}")
            