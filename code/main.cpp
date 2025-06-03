#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <filesystem>  // C++17 pour créer un dossier

#include "src/src.hpp"
#include "utils/utils.hpp"


int main() {
    const int width = 200;
    const int height = 100;

    std::vector<unsigned char> image_data(width * height);
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < width * height; ++i) {
        image_data[i] = std::rand() % 256;
    }

    write_png("image_grayscale.png", width, height, image_data);

    return 0;
}