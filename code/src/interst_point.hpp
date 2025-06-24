#ifndef INTERST_POINT_HPP
#define INTERST_POINT_HPP

#include <vector>
#include <iostream>
#include "src.hpp"

template <typename T>std::vector<int> interest_point(const char*filename) {

    double trace = 0.04;
    double max_R = 0.0;

    std::vector<int> Ix;
    std::vector<int> Iy;

    std::vector<int> Ixx;
    std::vector<int> Iyy;
    std::vector<int> Ixy;    

    std::vector<double> Sxx;
    std::vector<double> Syy;
    std::vector<double> Sxy;

    std::vector<double> R;

    std::vector<double> map_max;

    std::vector<coordinate> coordinates;
    
    std::vector<int>result_coord;

    printf("toto 1 \n");

    std::vector<int> matrices = read_bin(filename, 512, 512);

    std::vector<int> kernel_x = init_SobelX<int>();
    std::vector<int> kernel_y = init_SobelY<int>();
    std::vector<double> gaussian_kernel = init_gaussian<double>();

    printf("toto 2 \n");

    Ix = convolution_2D<int, 512, 512, 3>(matrices, kernel_x);
    Iy = convolution_2D<int, 512, 512, 3>(matrices, kernel_y);

    // std::vector<double> magnitude_result = magnitude<int, double>(result_x, result_y);
    // std::vector<double> angle_result = atan2<int, double>(result_x, result_y);

    printf("toto 3 \n");

    Ixx = multiplication_2_matrices<int>(Ix, Ix);
    Iyy = multiplication_2_matrices<int>(Iy, Iy);
    Ixy = multiplication_2_matrices<int>(Ix, Iy);

    // for(int i = 0; i < Ixx.size(); ++i) {
    //     printf("Ixx[%d] = %d, Iyy[%d] = %d, Ixy[%d] = %d\n", i, Ixx[i], i, Iyy[i], i, Ixy[i]);
    // }

    printf("toto 4 \n");

    Syy = convolution_2D_<int, double, 512, 512, 3>(Iyy, gaussian_kernel);
    Sxx = convolution_2D_<int, double, 512, 512, 3>(Ixx, gaussian_kernel);
    Sxy = convolution_2D_<int, double, 512, 512, 3>(Ixy, gaussian_kernel);
    
    // for(int i = 0; i < Syy.size(); ++i) {
    //     printf("Syy[%d] = %lf, Sxx[%d] = %lf, Sxy[%d] = %lf\n", i, Syy[i], i, Sxx[i], i, Sxy[i]);
    // }

    printf("toto 5 \n");
    
    R = R_score<double>(Sxx, Syy, Sxy, trace);

    coordinates = coordinate_intesting<double, coordinate>(R);

    result_coord = coord2vector<int, coordinate>(coordinates);

    return result_coord;
}

#endif // INTERST_POINT_HPP