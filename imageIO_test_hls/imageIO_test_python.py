from PIL import Image
import numpy as np
from IPython.display import display
from pynq import Overlay
from pynq import allocate

# load the IP
ol = Overlay("./imageIO_test_v2.bit")
ip_imageIO = ol.imageIO_test_0


# allcate array
image_in_array = allocate(shape=(112, 112, 3), dtype=np.uint8)
image_out_array = allocate(shape=(112, 112, 3), dtype=np.uint8)

# load an input image and remove alpha channel
image_path = "./DSC09011_112p.png"
input_image = Image.open(image_path).convert("RGB")
input_image.load()
# the image is stored in 3d array, 112row x 112col x 3rgb (8x3=24bit for each pixel)
image_in_array[:] = np.array(input_image)
print(image_in_array.shape)

# show original image
print("Before:")
display(Image.fromarray(image_in_array))

# run the IP
# This IP sets the blue channel to 0
print("Start IP")
ip_imageIO.write(0x10, image_in_array.device_address)
ip_imageIO.write(0x1C, image_out_array.device_address)
ip_imageIO.write(0x00, 0x01)

while (ip_imageIO.read(0x00) & 0x4) == 0x0:
    continue

print("IP end")

# show processed image
print("After:")
display(Image.fromarray(image_out_array))
