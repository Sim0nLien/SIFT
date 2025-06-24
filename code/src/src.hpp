#ifndef SRC_HPP
#define SRC_HPP


#include <vector>
#include <iostream>
#include <cmath>


struct coordinate {
    int x;
    int y;
};

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

template <class T> std::vector<T> init_gaussian(){
    return {
        static_cast<T>(1.0/16), static_cast<T>(2.0/16), static_cast<T>(1.0/16),
        static_cast<T>(2.0/16), static_cast<T>(4.0/16), static_cast<T>(2.0/16),
        static_cast<T>(1.0/16), static_cast<T>(2.0/16), static_cast<T>(1.0/16)
    };
}


template <class T, int H, int W, int size_kernel> std::vector<T> convolution_2D(const std::vector<T> &image, const std::vector<T> &kernel) {

    std::vector<T> result(H * W, 0);

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

    // Fin de l'affichage de la matrice

    for(int h = kernel_midle; h < height - kernel_midle; ++h){
        for(int w = kernel_midle; w < width - kernel_midle; ++w){
            
            T sum = 0;
            
            for(int hk = 0; hk < kernel_size; ++hk){
                for(int wk = 0; wk < kernel_size; ++wk){

                    int y = h + hk - kernel_midle;
                    int x = w + wk - kernel_midle;

                    sum += image[y * width + x] * kernel[hk * kernel_size + wk];
                }
            }
            
            result[(h - 1) * width + (w - 1)] = sum;

        }
    }
    printf("Fin de la convolution\n");
    return result;
}


template <class T, int H, int W, int size_kernel> std::vector<T> convolution_2D_Display(const std::vector<T> &image, const std::vector<T> &kernel) {

    std::vector<T> result(H * W, 0);

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

    // Fin de l'affichage de la matrice

    for(int h = kernel_midle; h < height - kernel_midle; ++h){
        for(int w = kernel_midle; w < width - kernel_midle; ++w){
            
            T sum = 0;
        
            for(int hk = 0; hk < kernel_size; ++hk){
                for(int wk = 0; wk < kernel_size; ++wk){

                    int y = h + hk - kernel_midle;
                    int x = w + wk - kernel_midle;

                    sum += image[y * width + x] * kernel[hk * kernel_size + wk];
                }
            }
            
            if (sum > 0) {
                result[(h - 1) * width + (w - 1)] = sum;
            }
    
            if (sum > 255){
                result[(h - 1) * width + (w - 1)] = 255;
            }

        }
    }
    printf("Fin de la convolution\n");
    return result;
}



template <class IN, class OUT, int H, int W, int size_kernel> std::vector<OUT> convolution_2D_(const std::vector<IN> &image, const std::vector<OUT> &kernel) {

    std::vector<OUT> result(H * W, 0);

    int height;
    int width;
    
    int kernel_size;
    int kernel_midle;

    height = H;
    width = W;

    //Afin de régler les problèmes de padding :

    std::vector<OUT> pad_image;

    kernel_size = size_kernel;
    kernel_midle = kernel_size / 2;

    pad_image.resize((height + size_kernel - 1) * (width + size_kernel - 1), 0);

    for(int h = 0; h < height; ++h){
        for(int w = 0; w < width; ++w){
            pad_image[(h + kernel_midle) * (width + size_kernel - 1) + (w + kernel_midle)] = image[h * width + w];
        }
    }

    // Fin de l'affichage de la matrice

    for(int h = kernel_midle; h < height - kernel_midle; ++h){
        for(int w = kernel_midle; w < width - kernel_midle; ++w){
            
            OUT sum = 0;
            
            for(int hk = 0; hk < kernel_size; ++hk){
                for(int wk = 0; wk < kernel_size; ++wk){

                    int y = h + hk - kernel_midle;
                    int x = w + wk - kernel_midle;

                    sum += image[y * width + x] * kernel[hk * kernel_size + wk];
                }
            }
            
            result[(h - 1) * width + (w - 1)] = sum;

        }
    }
    printf("Fin de la convolution\n");
    return result;
}



template <class IN, class OUT> std::vector<OUT> magnitude(const std::vector<IN> &image_x, const std::vector<IN> &image_y){
    
    std::vector<IN> result(image_x.size(), 0);

    for(size_t i = 0; i < image_x.size(); ++i){
        result = sqrt(image_x[i] * image_x[i] + image_y[i] * image_y[i]);
    }
    
    printf("Fin du calcul de la magnitude\n");
    
    return result;
}

template <class IN, class OUT> std::vector<OUT> atan2(const std::vector<IN> &image_x, const std::vector<IN> &image_y){
    
    std::vector<OUT> result(image_x.size(), 0);

    for(size_t i = 0; i < image_x.size(); ++i){
        result[i] = atan2(image_y[i], image_x[i]);
    }
    
    printf("Fin du calcul de l'angle\n");
    
    return result;
}


template <class T> std::vector<T> multiplication_2_matrices(const std::vector<T> &matrice1, const std::vector<T> &matrice2){
    if (matrice1.size() != matrice2.size()) {printf("les matrices ne sont pas de la même taille\n"); return {};
    }

    std::vector<T> result(matrice1.size(), 0);

    for(size_t i = 0; i < matrice1.size(); ++i){
        result[i] = matrice1[i] * matrice2[i];
    }

    printf("Fin de la multiplication de matrices\n");
    
    return result;
}

// template <class T> std::vector<T>{

// }


template <class T> std::vector<T> R_score(const std::vector<T> &Sxx, const std::vector<T> &Syy, const std::vector<T> &Sxy, double trace_coeff){
 
    std::vector<T> R(Sxx.size(), 0);

    for(size_t i = 0; i < Sxx.size(); ++i){
        T det = Sxx[i] * Syy[i] - Sxy[i] * Sxy[i];
        T trace = Sxx[i] + Syy[i];

        // printf("Calcul de R[%zu] : det = %lf, trace = %lf\n", i, det, trace);

        R[i] = det - trace_coeff * (trace * trace);

    }
    
    printf("Fin du calcul de R\n");

    return R;
}


template <class T> std::vector<T> threeshold(const std::vector<T> &R){
    
    std::vector<T> result(R.size(), 0);



    T max_value = 0;

    for(size_t i = 0; i < R.size(); ++i){
        if (R[i] > max_value) {
            max_value = R[i];
        }
    }

    printf("Max value: %f\n", max_value);
    
    T threshold = max_value * 0.05;

    for(size_t i = 0; i < R.size(); ++i){
        if (R[i] > threshold) {
            result[i] = R[i];
        } else {
            result[i] = 0;
        }
    }

    return result;
    printf("Fin du seuil\n");

}



// TODO : Remplacer le carré par un cercle de rayon 15 pixels

template <class T> void local(std::vector<T> &R, coordinate coord){
    
    for(int i = std::max(0, coord.x - 15); i < std::min(512, coord.x + 15); ++i){
        for(int j = std::max(0, coord.y - 15); j < std::min(512, coord.y + 15); ++j){
            R[j * 512 + i] = 0;
        }
    }
}


template <class T, class COORD> std::vector<COORD> coordinate_intesting(const std::vector<T> &R){

    std::vector<T> map_R;
    std::vector<COORD> result;

    int idx_max = 0;

    map_R = threeshold(R);

    COORD tmp_coords;

    double tmp_max = 1.0;
    int count = 0;

    while (tmp_max > 0.05 && count < 200) {

        tmp_max = 0.0;
        
        for(size_t i = 0; i < R.size(); ++i){
            
            if (map_R[i] > tmp_max) {
                tmp_max = map_R[i];
                idx_max = i;
            }

        }

        tmp_coords.x = idx_max % 512;
        tmp_coords.y = idx_max / 512;

        // printf("Coordonnée trouvée : (%d, %d) avec une valeur de %lf\n", tmp_coords.x, tmp_coords.y, map_R[idx_max]);
        
        map_R[idx_max] = 0; // On met à zéro la valeur pour ne pas la prendre en compte dans les prochaines itérations
        local(map_R, tmp_coords); // On met à zéro les valeurs autour de la coordonnée trouvée
        result.push_back(tmp_coords);
        count++;

    }

    printf("Fin de la recherche des coordonnées intéressantes\n");

    return result;

}


template <class T, class COORD> std::vector<T> coord2vector(const std::vector<COORD> &coordinates) {
    std::vector<T> result;

    for (const auto &coord : coordinates) {
        result.push_back(coord.x);
        result.push_back(coord.y);
    }
    return result;
}
#endif // SRC_HPP


