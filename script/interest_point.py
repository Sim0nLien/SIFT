import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

def load_image(filename):
    img = Image.open(filename).convert('L')
    return np.array(img)

def read_bin_int32(filename):

    data = np.fromfile(filename, dtype=np.int32)
    return data


image_filename = "images/Lenna.png"
point_filename = "result/coordinates.bin"


# Load the image
image = load_image(image_filename)
coord = read_bin_int32(point_filename)

print(coord)

coord = coord.reshape(-1, 2)  # Reshape to pairs of coordinates
for x, y in coord:
    if 0 <= x < image.shape[1] and 0 <= y < image.shape[0]:
        # Draw a red cross for each interest point
        plt.plot(x, y, 'rx', markersize=8, markeredgewidth=2)


plt.imshow(image, cmap='gray')
plt.axis('off')
plt.show()