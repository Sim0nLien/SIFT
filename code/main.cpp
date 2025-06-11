#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <filesystem>  // C++17 pour créer un dossier
#include <cstdint>

#include "src/src.hpp"
#include "utils/utils.hpp"




int main() {

    printf("Début du programme\n");

    const char* filename = "../script/data/Lennas.bin";

    std::vector<int> result;
    
    std::vector<uint8_t> matrices = read_bin(filename, 512, 512);

    for(int i = 0; i < 512 * 512; i++) {
        printf("%d ", affichage[i]);
        if ((i + 1) % 512 == 0) {
            printf("\n");
        }
    }

    

    // Assurez-vous que uint8 est défini, par exemple :
    // ou utilisez uint8_t à la place de uint8
    
}












// return 0;
// const int width = 200;
// const int height = 100;

// std::vector<unsigned char> image_data(width * height);
// std::srand(static_cast<unsigned>(std::time(nullptr)));

// for (int i = 0; i < width * height; ++i) {
//     image_data[i] = std::rand() % 256;
// }

// write_png("image_grayscale.png", width, height, image_data);





