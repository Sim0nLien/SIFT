import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

def load_image(filename):
    img = Image.open(filename).convert('L')
    return np.array(img)

def read_bin_int32(filename):

    data = np.fromfile(filename, dtype=np.int32)
    return data

def new_image_points(filename_image, filename_points, show=False):
    image = load_image(filename_image)
    points = read_bin_int32(filename_points)

    points = points.reshape(-1, 2)  # Reshape to pairs of coordinates
    for x, y in points:
        if 0 <= x < image.shape[1] and 0 <= y < image.shape[0]:
            # Draw a red cross for each interest point
            plt.plot(x, y, 'rx', markersize=8, markeredgewidth=2)

    if not show:
        plt.imshow(image, cmap='gray')
        plt.axis('off')
        plt.savefig('../data/tmp/result.png', bbox_inches='tight', pad_inches=0)
        plt.close()
        return '../data/tmp/result.png'

    else:
        plt.imshow(image, cmap='gray')
        plt.axis('off')
        plt.show()
        return None

if __name__ == "__main__":
    filename_image = '../script/images/Lenna.png'
    filename_points = '../coordinates.bin'
    new_image_path = new_image_points(filename_image, filename_points, True)