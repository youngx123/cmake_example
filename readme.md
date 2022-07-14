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