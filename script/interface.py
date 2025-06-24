import tkinter as tk
from tkinter import filedialog
from PIL import Image, ImageTk




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
        path_var.set(file_path)  # Met à jour la variable avec le chemin
    return image_label, file_path

def run_find_interest(filename):
    print(f"Trouver les points d'intérêt dans l'image : {filename}")
    

def create_interface():
    root = tk.Tk()
    root.title("Harry's Interface")
    root.geometry("700x600")

    # Variable pour stocker le chemin de l'image
    image_path_var = tk.StringVar()

    # Label pour afficher le chemin de l'image
    path_label = tk.Label(root, textvariable=image_path_var)
    path_label.pack(pady=5)

    # Label pour afficher l'image
    image_label = tk.Label(root, text="Aucune image chargée")
    image_label.pack()

    btn = tk.Button(root, text="Charger l'image", command=lambda: load_image(image_label, image_path_var))   
    btn.pack(pady=10)

    btn_find_interest = tk.Button(root, text="Trouver les points d'intérêt", command=lambda: run_find_interest(filename = image_path_var.get()))

    btn_quit = tk.Button(root, text="Quitter", command=root.quit)
    btn_quit.pack(pady=10)

    root.mainloop()

