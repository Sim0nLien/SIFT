# Crée une "library" appelée utils avec les fichiers cpp trouvés automatiquement
file(GLOB UTILS_FILES *.cpp)
add_library(utils ${UTILS_FILES})
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
