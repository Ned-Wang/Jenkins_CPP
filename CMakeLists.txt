# 在 CMakeLists.txt 顶部声明
cmake_minimum_required(VERSION 3.20)
project(Demo)
add_executable(main main.cpp)


# set(CMAKE_C_COMPILER "D:/MINI-ATE/mingw64/bin/gcc.exe")
# set(CMAKE_C_COMPILER "C:/D/Programs/msys64/mingw64/bin/gcc.exe")
set(CMAKE_C_COMPILER "C:/D/Programs/msys64/ucrt64/bin/gcc.exe")

# set(CMAKE_CXX_COMPILER "D:/MINI-ATE/mingw64/bin/g++.exe")
# set(CMAKE_CXX_COMPILER "C:/D/Programs/msys64/mingw64/bin/g++.exe")
set(CMAKE_CXX_COMPILER "C:/D/Programs/msys64/ucrt64/bin/g++.exe")
