#ifndef SRC_HPP
#define SRC_HPP


#include <vector>
#include <iostream>

template <class T> std::vector<T> init_SobelX(){
    return {
        -1, 0, 1,
        -2, 0, 2,
        -1, 0, 1
    };
}


template <class T> std::vector<T> init_SobelY(){
    return {
        1, 2, 1,
        0, 0, 0,
        -1, -2, -1
    };
}

template <class T, int H, int W, int size_kernel> void convolution_2D(const std::vector<T> &image, const std::vector<T> &kernel, std::vector<T> &output) {

    int height;
    int width;
    
    int kernel_size;
    int kernel_midle;

    height = H;
    width = W;

    //Afin de régler les problèmes de padding :

    std::vector<T> pad_image;

    kernel_size = size_kernel;
    kernel_midle = kernel_size / 2;

    pad_image.resize((height + size_kernel - 1) * (width + size_kernel - 1), 0);

    for(int h = 0; h < height; ++h){
        for(int w = 0; w < width; ++w){
            pad_image[(h + kernel_midle) * (width + size_kernel - 1) + (w + kernel_midle)] = image[h * width + w];
        }
    }

    // Affichage de la matrice afin de vérifier le padding

    for(int h = 0; h < height + size_kernel - 1; ++h){
        for(int w = 0; w < width + size_kernel - 1; ++w){
            std::cout << pad_image[h * (width + size_kernel - 1) + w] << " ";
        }
        std::cout << std::endl;
    }
    // Fin de l'affichage de la matrice

    for(int h = kernel_midle; h < height - kernel_midle; ++h){
        for(int w = kernel_midle; w < width - kernel_midle; ++w){
            
            T sum = 0;

            printf("h: %d, w: %d\n", h, w);
            
            for(int hk = 0; hk < kernel_size; ++hk){
                for(int wk = 0; wk < kernel_size; ++wk){

                    int y = h + hk - kernel_midle;
                    int x = w + wk - kernel_midle;

                    sum += image[y * width + x] * kernel[hk * kernel_size + wk];
                }
            }

            output[h * width + w] = sum;

        }
    }
}








// template <class T> std::vector<T>{

// }


#endif // SRC_HPP


