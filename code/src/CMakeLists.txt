
file(GLOB UTILS_FILES *.cpp)
add_library(src ${UTILS_FILES})
target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})