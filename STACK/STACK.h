//
// Created by DELL on 10/18/2025.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <iosfwd>


class STACK {
    int stack[1000]{};
    int SIZE = 1000;

    int elementN = 0;
public:
    STACK(STACK& stack);
    STACK()=default;
    void pop();
    void push(int value);
    int peek() const;
    friend  std::ostream& operator<< (std::ostream& stream, const STACK& stack);
    bool isEmpty() const;
    int getSize() const;



};


#endif//STACK_STACK_H
