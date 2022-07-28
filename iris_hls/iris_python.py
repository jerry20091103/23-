import numpy as np
from time import time
import matplotlib.pyplot as plt 

from pynq import Overlay
from pynq import allocate

if __name__ == "__main__":
    ol = Overlay("/home/xilinx/iris_hls/iris_hls.bit")
    ip_iris = ol.iris_module_0

    inBuffer = allocate(shape=(32,), dtype=np.int32)
    outBuffer = allocate(shape=(120,), dtype=np.int32)
    outBufferPy = allocate(shape=(120,), dtype=np.int32)

    # prepare dummy input data
    for i in range(32):
        inBuffer[i] = i

    # *start the computation for hls hardware
    timeKernelStart = time()
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
    
    # *start the computation for python
    timePythonStart = time()
    for set in range(8):
        offset = set * 4
        avg = (inBuffer[offset] + inBuffer[offset + 1] + inBuffer[offset + 2] + inBuffer[offset + 3]) / 4
        offset2 = set * 15
        for i in range(15):
            outBufferPy[offset2 + i] = avg
    
    timePythonEnd = time()
    print("Python execution time: " + str(timePythonEnd - timePythonStart) + " s")
    
    # *compare results
    if(np.array_equal(outBuffer, outBufferPy)):
        print("results are the same!")
    else:
        print("results are different!")
        for i in range(120):
            print(f"{outBuffer[i]} <-> {outBufferPy[i]}")

