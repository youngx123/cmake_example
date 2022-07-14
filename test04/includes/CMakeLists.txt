cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "../libs")

find_package(OpenCV REQUIRED)

add_library(show SHARED show.cpp)

target_link_libraries(show ${OpenCV_LIBS})
