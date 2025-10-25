//
// Created by DELL on 10/18/2025.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <iosfwd>
#include "C:\Users\DELL\CLionProjects\Omar STL\BST\Node.h"
typedef Node* ElementType;
class STACK {
    ElementType stack[1000]{};
    int SIZE = 1000;

    int elementN = 0;
public:
    STACK(STACK& stack);
    STACK()=default;
    void pop();
    void push(ElementType value);
    ElementType peek() const;
    friend  std::ostream& operator<< (std::ostream& stream, const STACK& stack);
    bool isEmpty() const;
    int getSize() const;



};


#endif//STACK_STACK_H
