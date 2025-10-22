cmake_minimum_required(VERSION 4.0)
project(LIST)

set(CMAKE_CXX_STANDARD 23)

add_executable(LIST DynamicList_Driver.cpp
        DynamicList.cpp
        DynamicList.h
        DynamicList.h)
