#ifndef UTILS_HPP
#define UTILS_HPP


#include <png.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

void write_png(const char* filename, int width, int height, const std::vector<unsigned char>& data) {
    char file_name[200];
    sprintf(file_name, "../result/");
    sprintf(file_name, "../result/%s", filename);
    FILE* fp = fopen(file_name, "wb");
    if (!fp) {
        std::cerr << "Erreur ouverture fichier PNG.\n";
        return;
    }

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    png_infop info = png_create_info_struct(png);

    if (!png || !info) {
        std::cerr << "Erreur initialisation libpng.\n";
        fclose(fp);
        return;
    }

    if (setjmp(png_jmpbuf(png))) {
        std::cerr << "Erreur d'écriture PNG.\n";
        fclose(fp);
        png_destroy_write_struct(&png, &info);
        return;
    }

    png_init_io(png, fp);

    // Définir les informations d'en-tête
    png_set_IHDR(
        png, info, width, height,
        8, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE
    );

    png_write_info(png, info);

    // Préparer les lignes
    std::vector<png_bytep> row_pointers(height);
    for (int y = 0; y < height; ++y) {
        row_pointers[y] = (png_bytep)&data[y * width];
    }

    png_write_image(png, row_pointers.data());
    png_write_end(png, nullptr);

    fclose(fp);
    png_destroy_write_struct(&png, &info);

    std::cout << "Image sauvegardée : " << file_name << std::endl;
}


std::vector<int> read_bin(const std::string& filename, int width, int height) {
    std::vector<unsigned char> buffer(width * height);
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur d'ouverture du fichier binaire." << std::endl;
        return {};
    }
    file.read(reinterpret_cast<char*>(buffer.data()), width * height);

    std::vector<int> data(width * height);
    for (size_t i = 0; i < buffer.size(); ++i) {
        data[i] = static_cast<int>(buffer[i]);
    }
    return data;
}



void write_bin(const std::string& filename, const std::vector<int>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur d'ouverture du fichier binaire en écriture." << std::endl;
        return;
    }
    std::vector<unsigned char> buffer(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        buffer[i] = static_cast<unsigned char>(data[i]);
    }
    file.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
}

void write_bin_int(const std::string& filename, const std::vector<int>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Erreur d'ouverture du fichier binaire en écriture." << std::endl;
        return;
    }
    // for(int i = 0; i < data.size(); ++i) {
    //     printf("data[%d] = %d\n", i, data[i]);
    // }
    for (const int& value : data) {
        file.write(reinterpret_cast<const char*>(&value), sizeof(int));
    }
}


#endif // UTILS_HPP

