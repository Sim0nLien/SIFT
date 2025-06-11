# -*- coding: utf-8 -*-

import numpy as np
from PIL import Image



def list2image(data, width, height):
    if len(data) != width * height:
        raise ValueError("Data length does not match specified width and height.")
    return np.array(data).reshape((height, width))

def save_image(image, filename):
    img = Image.fromarray(np.uint8(image))
    img.save(filename)

def load_image(filename):
    img = Image.open(filename)
    return np.array(img)

def array2_txt(array, filename):
    with open(filename, 'w') as f:
        for row in array:
            f.write(' '.join(map(str, row)) + '\n')

def txt2array(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()
    return np.array([list(map(int, line.split())) for line in lines])





# if __name__ == "__main__":
#     array = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
#     txt_filename = "test_array.txt"
#     array2_txt(array, txt_filename)
#     print(f"Array saved to {txt_filename}")

#     loaded_array = txt2array(txt_filename)
#     print("Loaded array from txt:")
#     print(loaded_array)

# if __name__ == "__main__":
#     data = [10, 20, 30, 40, 50, 60, 70, 80, 90]
#     width = 3
#     height = 3
#     img = list2image(data, width, height)
#     print("Image :\n", img)
#     save_image(img, "test_image.png")
#     print("Image saved as test_image.png")






