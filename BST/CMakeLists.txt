cmake_minimum_required(VERSION 4.0)
project(BST)

set(CMAKE_CXX_STANDARD 23)

add_executable(BST BST_Driver.cpp
        Node.cpp
        Node.h
        BST.cpp
        BST.hpp
)
