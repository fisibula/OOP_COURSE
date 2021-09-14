cmake_minimum_required(VERSION 3.19)
project(OOP_COURSE VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)
file(GLOB src_files
        "*.cpp"
        "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${src_files} include/matrix.h src/matrix.cpp include/rgb_matrix.h include/bw_matrix.h src/rgb_matrix.cpp src/bw_matrix.cpp)