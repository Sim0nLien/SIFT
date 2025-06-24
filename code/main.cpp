#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <filesystem>  // C++17 pour créer un dossier
#include <cstdint>

#include "src/src.hpp"
#include "utils/utils.hpp"
#include "src/interst_point.hpp"




int main(int argc, char* argv[]) {

    printf("Début du programme\n");

    std::vector<int>result_coord;

    char* input_file = argv[1]; 

    result_coord = interest_point<int>(input_file);

    for(int i = 0; i < result_coord.size(); i += 2) {
        printf("Coordonnée %d : (%d, %d)\n", i / 2, result_coord[i], result_coord[i + 1]);
    }

    write_bin_int("../coordinates.bin", result_coord);

    printf("Fin du programme\n");

    
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





