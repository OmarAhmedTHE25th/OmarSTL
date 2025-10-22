//
// Created by DELL on 10/22/2025.
//

#ifndef OMAR_STL_LLDEQUE_H
#define OMAR_STL_LLDEQUE_H

#include <inttypes.h>

#include "Node.hpp"
class LLDeque {
Node *head{};
Node *tail{};
    int nodeN =0;
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
    LLDeque()=default;
    LLDeque(const LLDeque &Olist);
    ~LLDeque();
};


#endif //OMAR_STL_LLDEQUE_H