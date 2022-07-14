cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_CXX_STANDARD 11)

# 添加opencv includes 路径和库
find_package(OpenCV REQUIRED)

message(STATUS "CMAKE_SYSTEM_NAME is :${OpenCV_LIBS}")
aux_source_directory(. DIR_LIB_SRCS)
add_library(show SHARED ${DIR_LIB_SRCS})
target_link_libraries(show ${OpenCV_LIBS})


