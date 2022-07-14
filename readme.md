- [CMakeList 不同情况下编译](#cmakelist-不同情况下编译)
  - [test01](#test01)
  - [test02](#test02)
  - [test03](#test03)
  - [test04](#test04)
  - [test05](#test05)
  - [test06](#test06)
- [CMake常用命令](#cmake常用命令)

# CMakeList 不同情况下编译
## test01
对单个文件进行编译

目录结构
```python
├── test01_0
│   ├── CMakeLists.txt
│   └── main.cpp

└── test01_1
    ├── build
    ├── camera_test.flv
    ├── CMakeLists.txt
    └── read_video.cpp
```


## test02
对多个文件进行编译
```python
├── CMakeLists.txt
├── inludes
│   ├── CMakeLists.txt
│   ├── show.cpp
│   └── show.h
└── main.cpp
```


## test03
对同一目录下多个文件进行编译
```python
├── CMakeLists.txt
├── main.cpp
├── show.cpp
└── show.h
```

## test04
使用编译好的库文件

先编译includes下的库，然后在编译主函数
```python
├── CMakeLists.txt
├── includes
│   ├── CMakeLists.txt
│   ├── libs
│   │   └── libshow.so
│   ├── show.cpp
│   └── show.h
└── main.cpp
```

## test05
加载使用自己编译的第三方库
```python
├── CMakeLists.txt
├── main.cpp
├── mnn
│    └── include
│    └── lib
│          └── libMNN.so
├── MNN_Infer.cpp
├── MNN_Infer.h
├── mnn_model
│   └── yolov5n.mnn
├── test1.jpg
└── test2.jpg
```
## test06

# CMake常用命令
```python
1. # 动态库；
   SHARED 

2. # 静态库
   STATIC 

3. # 用于导入第三方so库
set_target_properties
格式为：

set_target_properties(
		ThirdlibName PROPERTIES  # so 库名字
		IMPORTED_LOCATION        #  导入方式
		${CMAKE_CURRENT_SOURCE_DIR}/jniLibs/libThirdlib.so # 路径
)
第一个参数为 so 库名字， 第二个为 固定格式， 第三个为so 库所在的路径
如：
set(dis_DIR E:/Android_Proj/MyApplication/app/libs)
set_target_properties(MNN PROPERTIES IMPORTED_LOCATION ${dis_DIR}/arm64-v8a/libMNN.so)


4. # 查找当前目录下所有源文件并保存至SRC_LIST变量中
aux_source_directory(. SRC_LIST)

# 查找目录下的所有源文件， 不含子目录的CPP文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

#显示目录下的源文件
message( STATUS "source files : ${DIR_SRCS}")

5.1. # 生成 / 添加一个库
add_library(<name>  [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] source1 ... sourceN)

# 添加一个名称叫 native-lib的动态库，
# 该库的源文件为 src/main/native-lib.cpp
# 也就是将 native-lib.cpp的文件编译为ie native-lib的动态库 .so 或者静态库  .a
add_library( 
            native-lib # 库的名称
            SHARED     # SHARED:动态库、STATIC:静态库
            src/main/cpp/native-lib.cpp  # 源文件，可以是多个
            )

5.2. # 导入已有的库
add_library(<name> [STATIC | SHARED | MODULE | UNKNOWN] IMPORTED)

# 传入三个参数；第一个是要引入的库别名，第二个是库的类型，是静态库还是动态库。
# 第三个是通过什么样方式引入进来，第三方的库一般是包含进来，所以参数基本写 IMPORTED

add_library 后，就要设置.so的详细路径了，通过
set_target_properties() 函数来设置

# 导入库一般配合 set_target_properties 使用，这个命令用来指定导入库的路径,比如：
set(dis_DIR E:/Android_Proj/MyApplication/app/libs)
add_library(MNN SHARED IMPORTED)
set_target_properties(MNN PROPERTIES IMPORTED_LOCATION ${dis_DIR}/arm64-v8a/libMNN.so)

6. # add_subdirectory(NAME)
添加一个 文件夹 进行编译，该文件夹下的 CMakeLists.txt 负责编译该文件夹下的源码, NAME是想对于调用add_subdirectory  的CMakeListst.txt的相对路径．

7. # 将指定目录添加到编译器的头文件搜索路径之下，指定的目录被解释成当前源码路径的相对路径。
include_directories ([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])

include_directories(E:/Android_Proj/MyApplication/app/includes)

8. # set 设置CMake变量
set(dis_DIR E:/Android_Proj/MyApplication/app/libs)

#set 直接设置变量的值
set(SRC_LIST main.cpp test.cpp)
add_executable(demo ${SRC_LIST})

# set 追加变量的值
set(SRC_LIST main.cpp)

set(SRC_LIST ${SRC_LIST} test.cpp)
add_executable(demo ${SRC_LIST})

# list 追加或者删除变量的值
set(SRC_LIST main.cpp)

list(APPEND SRC_LIST test.cpp)

list(REMOVE_ITEM SRC_LIST main.cpp)

add_executable(demo ${SRC_LIST})

9. # target_link_libraries 将若干库链接到目标库文件
target_link_libraries(<name> lib1 lib2 lib3)

# 添加链接库
target_link_libraries(Demo MathFunctions)
# 使用命令 target_link_libraries 指明可执行文件 Demo 需要连接
# 一个名为 MathFunctions 的链接库

10. # find_library  在指定目录下搜索库,并保存在log-lib中
# 搜索指定动态文件路径，里面的内容为自定义的变量名、动态文件名、具体路径。
find_library( 
        log-lib # 指定要查找的系统库, 给一个名字
        log     # 真正要查找的liblog.so或者liblog.a
        )

用来添加一些我们在编译我们的本地库的时候需要依赖的一些库，这个主要是查找系统库用的，
如果项目里面有用到系统的 .so 库就是要把库名写到这个函数里面去找到相对应的为。由于
cmake已经 知道系统库的路径，所以我们这里只是 指定使用log库，然后给log库 起别名为
log-lib 便于我们后面引用，此处的log库是我们后面调试时需要用来打log日志的库，是NDK
为我们提供的

11. # option 为变量赋值

option (USE_MYMATH "Use tutorial provided math implementation" ON) 

ption（）的作用是将变量的值赋为 `ON` 或 `OFF`，第一个参数为设置的变量，
第二个参数为说明文本，第三个参数为设定的值，如果为空，则默认为 `OFF`，
加上这条语句后如果我们使用CMake的GUI的话就会出现一个复选框。

12. # 设置构建类型
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_BUILD_TYPE Debug)

13. # 设置C++标准

如果需要使用C++某些新特性，那就要设置C++的标准，通过两个全局变量设置：

set(CMAKE_CXX_STANDARD 11)



set(CMAKE_CXX_STANDARD_REQUIRED True)
```

CMakeLists部分
```python
# 声明最低的cmake版本
cmake_minimum_required(VERSION 3.4.1)
# 添加一个名称叫native-lib的动态库，该库的源文件为src/main/native-lib.cpp
add_library( 
            native-lib # 库的名称
             SHARED # SHARED:动态库、STATIC:静态库
             src/main/native-lib.cpp # 源文件，可以是多个
            )
             
# 寻找系统中的log库，保存在log-lib变量中
# 定义当前代码库需要依赖的系统或者第三方库文件(可以写多个)
find_library( 
            log-lib 
            log
            )
              
# native-lib这个库会去依赖log-lib这个库
target_link_libraries( 
                     native-lib
                     ${log-lib} 
                     )

13. #添加需要链接的库文件目录
link_directories（添加需要链接的库文件目录）
语法：
link_directories(directory1 directory2 ...)

它相当于g++命令的-L选项的作用，也相当于环境变量中增加 LD_LIBRARY_PATH 的路径的作用。
比如：
set(OpenCV_LIBS_DIR /usr/local/opencv450/lib)
link_directories(${OpenCV_LIBS_DIR})


14. # 添加需要链接的库文件路径，注意这里是绝对路径
List of direct link dependencies.
比如：
link_libraries("/opt/MATLAB/R2012a/bin/glnxa64/libeng.so")

link_libraries("/opt/MATLAB/R2012a/bin/glnxa64/libmx.so")
```