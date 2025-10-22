//
// Created by DELL on 10/21/2025.
//

#ifndef OMAR_STL_DEQUE_H
#define OMAR_STL_DEQUE_H
#include <iostream>
typedef int ElementType;
class Deque {
    int size =10;
    ElementType *list = new ElementType[size]{};
    int elementN = 0;
public:
    void pushFront(ElementType value);
    void pushBack(ElementType value);
    void popFront();
    void popBack();
    ElementType front();
    ElementType back();
    int getSize();
    bool isEmpty();
    void display();
    Deque()=default;
    ~Deque();

};


#endif //OMAR_STL_DEQUE_H