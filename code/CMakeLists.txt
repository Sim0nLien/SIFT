cmake_minimum_required(VERSION 3.10)
project(SIFT)

set(CMAKE_CXX_STANDARD 17)

find_package(PNG REQUIRED)

# Ajout des sous-répertoires
add_subdirectory(src)
add_subdirectory(utils)

# Création de l'exécutable
add_executable(SIFT main.cpp)

# Lier les bibliothèques (src et utils)
target_link_libraries(SIFT src utils)
target_link_libraries(SIFT PNG::PNG)