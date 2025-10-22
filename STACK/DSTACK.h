//
// Created by DELL on 10/18/2025.
//

#ifndef STACK_DSTACK_H
#define STACK_DSTACK_H
#include <iosfwd>


class DSTACK {
    int size = 10;
    int *stack =  new int[size];
    int elementN = 0;


public:
    void pop();
    void push(int value);
    int peek() const;
    friend  std::ostream& operator<< (std::ostream& stream, const DSTACK& stack);
    bool isEmpty() const;
    int getSize() const;
    DSTACK(const DSTACK &stack2);
    DSTACK()=default;
    ~DSTACK() {
        delete[] stack;

    }

};


#endif //STACK_DSTACK_H