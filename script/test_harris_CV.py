import cv2
import numpy as np
import matplotlib.pyplot as plt



# Charger l'image en niveaux de gris
img = cv2.imread('images/Lenna.png', cv2.IMREAD_GRAYSCALE)

# Vérifier si l'image est chargée
if img is None:
    raise FileNotFoundError("L'image n'a pas été trouvée.")

# Convertir en float32
img_float = np.float32(img)

# Appliquer le détecteur de Harris
dst = cv2.cornerHarris(img_float, blockSize=2, ksize=3, k=0.04)

# Dilater pour mieux visualiser les coins
dst = cv2.dilate(dst, None)

# Créer une image couleur pour affichage
img_color = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
img_color[dst > 0.01 * dst.max()] = [0, 0, 255]

# Afficher le résultat avec matplotlib
plt.imshow(cv2.cvtColor(img_color, cv2.COLOR_BGR2RGB))
plt.title('Harris Corners')
plt.axis('off')
plt.show()
