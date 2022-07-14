cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
message(STATUS "CMAKE_SYSTEM_NAME is :${OpenCV_LIBS}")

add_executable (Demo main.cpp)
target_link_libraries(Demo ${OpenCV_LIBS})
