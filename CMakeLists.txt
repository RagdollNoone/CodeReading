cmake_minimum_required(VERSION 3.13)
project(CodeReading)

set(CMAKE_CXX_STANDARD 14)

add_executable(CodeReading src/main.cpp src/FunctionPointer/FunctionPointer.h src/FunctionPointer/FunctionPointer.cpp src/Struct/Point.cpp src/Struct/Point.h src/Struct/Point3D.cpp src/Struct/Point3D.h)