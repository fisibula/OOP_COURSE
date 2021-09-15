cmake_minimum_required(VERSION 3.19)
project(OOP_COURSE VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(
        ${PROJECT_SOURCE_DIR}/include
)

file(GLOB lib_src
        "src/*.cpp"
)

add_library(${PROJECT_NAME} STATIC
        ${lib_src}
)

file(GLOB src_files
        "*.cpp"
)

add_executable(runner ${src_files})

target_link_libraries(runner
        ${PROJECT_NAME}
)