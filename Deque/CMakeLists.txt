cmake_minimum_required(VERSION 4.0)
project(Deque)

set(CMAKE_CXX_STANDARD 23)

add_executable(Deque Deque_Driver.cpp
        Deque.cpp
        Deque.h
        LLDeque.cpp
        LLDeque.h
        Node.cpp
        Node.hpp)
