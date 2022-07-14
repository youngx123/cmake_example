cmake_minimum_required(VERSION 3.22.5)
project(ReadVideo)

find_package(OpenCV REQUIRED)
add_executable (Demo read_video.cpp)
target_link_libraries(Demo ${OpenCV_LIBS})