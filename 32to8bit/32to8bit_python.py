import numpy as np
from time import time
import matplotlib.pyplot as plt 

from pynq import Overlay
from pynq import allocate

if __name__ == "__main__":
    ol = Overlay("/home/xilinx/jupyter_notebooks/32to8bit/32to8bit.bit")
    ip_iris = ol.sw_compute_0
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
    inBuffer = allocate(shape=(inputNum,), dtype=np.uint32) 
    outBuffer = allocate(shape=(inputmem,), dtype=np.int32)
    outBufferPy = [148, 2,  -182, -256, 254, -114, 90, -210]
    im = [0]*inputmem
    
    # prepare input data
    print("prepare input data")
    Image.seek(0)
    for i in range(inputmem):
        line = Image.readline()
        im[i] = np.uint8(line)
        print(im[i])
    Image.close()
    print("===input data prepared===")

    for i in range(inputNum):
        inBuffer[i] = (im[3 + i*4] << 24) | (im[2 + i*4] << 16) | (im[1 + i*4] << 8) | im[0 + i*4]

    # *start the computation for hls hardware
    print("start compute hls")
    timeKernelStart = time()
    # ap_start
    ip_iris.write(0x00, 0x01)
    # write input output data
    ipDMAIn.sendchannel.transfer(inBuffer)
    ipDMAOut.recvchannel.transfer(outBuffer)
    # wait for the computation to finish
    ipDMAIn.sendchannel.wait()
    ipDMAOut.recvchannel.wait()
    timeKernelEnd = time()
    print("hardware execution time: " + str(timeKernelEnd - timeKernelStart) + " s")
     
   
    # *compare results
    if(np.array_equal(outBuffer, outBufferPy)):
        print(">> results are the same!")
        print(">> the result:")
        for i in range(inputNum):
            print(f"   image{i} : {outBuffer[i]}")
    else:
        print(">> results are different!")
        for i in range(inputNum):
            print(f"index {i}: {outBuffer[i]} <-> {outBufferPy[i]}")
            

