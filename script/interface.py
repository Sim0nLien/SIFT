import tkinter as tk
from tkinter import filedialog
from PIL import Image, ImageTk
from util_conv import conv_img_2_bin
import subprocess
from interest_point import new_image_points


def load_image(image_label, path_var):
    file_path = filedialog.askopenfilename(title="Sélectionner une image", filetypes=[("Image files", "*.jpg *.jpeg *.png")])
    if file_path:
        image = Image.open(file_path)
        image = image.resize((512, 512))
        photo = ImageTk.PhotoImage(image)
        print(f"Image chargée depuis : {file_path}")
        image_label.config(image=photo)
        image_label.image = photo
        image_label.pack()
        path_var.set(file_path)
    return image_label, file_path


def run_find_interesting_point(filename, image_label):
    print(f"Trouver les points d'intérêt dans l'image : {filename}")
    path =conv_img_2_bin(filename)
    binary_path = "../build/SIFT"
    args = [path]
    subprocess.run([binary_path] + args, check= True, text= True)
    print(filename)
    new_image_path = new_image_points(filename, "../data/tmp/coordinates.bin")
    if new_image_path:
        image = Image.open(new_image_path)
        image = image.resize((512, 512))
        photo = ImageTk.PhotoImage(image)
        image_label.config(image=photo)
        image_label.image = photo

    


def create_interface():
    root = tk.Tk()
    root.title("Harry's Interface")
    root.geometry("700x700")

    image_path_var = tk.StringVar()

    path_label = tk.Label(root, textvariable=image_path_var)
    path_label.pack(pady=5)

    image_label = tk.Label(root, text="Aucune image chargée")
    image_label.pack()

    btn = tk.Button(root, text="Charger l'image", command=lambda: load_image(image_label, image_path_var))   
    btn.pack(pady=10)

    btn_find_interest = tk.Button(root, text="Trouver les points d'intérêt", command=lambda: run_find_interesting_point(filename = image_path_var.get(), image_label=image_label))
    btn_find_interest.pack(pady=10)

    btn_quit = tk.Button(root, text="Quitter", command=root.quit)
    btn_quit.pack(pady=10)

    root.mainloop()

