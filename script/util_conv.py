import numpy as np
import imageio.v2 as imageio
import sys


def conv_img_2_bin(filename):
    img = imageio.imread(filename)
    img = np.asarray(img, dtype=np.uint8)
    out_filename = "../data/tmp/tmp.bin"
    img.tofile(out_filename)
    return out_filename
