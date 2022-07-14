cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
#message(STATUS "CMAKE_SYSTEM_NAME is :${OpenCV_LIBS}")

# 1
aux_source_directory(. SRCS)
add_executable (SHOWIMAGE ${SRCS})

# 2
# add_executable(SHOWIMAGE main.cpp show.cpp)
# 添加链接库

target_link_libraries(SHOWIMAGE ${OpenCV_LIBS})
