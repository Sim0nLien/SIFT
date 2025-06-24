import numpy as np
from PIL import Image


def load_bin (filename, width=512, height=512):
    with open(filename, 'rb') as f:
        data = np.fromfile(f, dtype=np.uint8, count=width*height)
    image = data.reshape((height, width))
    return image

def save_image(image, filename):
    img = Image.fromarray(np.uint8(image))
    img.save(filename)


filename_x = "data/Lennas_Sobel_X.bin"
filename_y = "data/Lennas_Sobel_Y.bin"


image_x = load_bin(filename_x, width=512, height=512)
save_image(image_x, "result/Lennas_Sobel_X.png")

image_y = load_bin(filename_y, width=512, height=512)
save_image(image_y, "result/Lennas_Sobel_Y.png")





