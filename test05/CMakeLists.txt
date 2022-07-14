cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_CXX_STANDARD 11)
# 添加MNN includes路径
set(mnn_Dir "/home/user/xyoung/Infer_Lib/CmakeDemo/test05/mnn/include")  #内为第三方库头文件路径
include_directories(${mnn_Dir})
# 添加MNN 库
set(mnn_dirso "/home/user/xyoung/Infer_Lib/CmakeDemo/test05/mnn/lib")
add_library(MNN SHARED IMPORTED)
set_target_properties(MNN PROPERTIES IMPORTED_LOCATION ${mnn_dirso}/libMNN.so)

# 添加opencv includes 路径和库
# set(OpenCV_INCLUDE_DIRS /usr/local/opencv450/include/opencv4)
# set(OpenCV_LIBS_DIR /usr/local/opencv450/lib)
# set(OpenCV_LIBS opencv_core opencv_imgproc opencv_imgcodecs opencv_highgui opencv_videoio)

# include_directories(${OpenCV_INCLUDE_DIRS})
# link_directories(${OpenCV_LIBS_DIR})
# link_libraries(${OpenCV_LIBS})
find_package(OpenCV REQUIRED)
# 添加制定头文件
aux_source_directory(. SRCS)

add_executable(MNNInfer ${SRCS})

target_link_libraries(MNNInfer MNN ${OpenCV_LIBS})
