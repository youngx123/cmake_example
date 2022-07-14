cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_CXX_STANDARD 11)

#find_package(OpenCV REQUIRED)
#message(STATUS "CMAKE_SYSTEM_NAME is :${OpenCV_LIBS}")
# 添加 inludes 子目录
include_directories(includes)

# # 1 
# set(show  includes/libs)
# link_directories(${show})

# 2
link_libraries("/home/user/xyoung/Infer_Lib/CmakeDemo/test04/includes/libs/libshow.so")

# aux_source_directory(. SRCS)
add_executable (SHOWIMAGE main.cpp)
# 添加链接库

# 
# target_link_libraries(SHOWIMAGE show)
