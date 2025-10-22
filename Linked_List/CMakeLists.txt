cmake_minimum_required(VERSION 4.0)
project(Linked_List)

set(CMAKE_CXX_STANDARD 23)

add_executable(Linked_List LinkedList_Driver.cpp
        Node.h
        Linked_List.cpp
        Linked_List.h
        STACK.cpp
        STACK.h
        STACK.h
        CircularLinkedList.cpp
        CircularLinkedList.h
        CircularLinkedList.h
        CircularLinkedList.cpp
)
