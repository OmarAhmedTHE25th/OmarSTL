//
// Created by DELL on 10/18/2025.
//

#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H
#include "Linked_List.h"


class STACK {
    Linked_List list;

public:
    void pop() ;
    void push(int value) ;
    [[nodiscard]] int peek() const;
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] int size() const;
friend std::ostream& operator<< (std::ostream& stream, const STACK& stack);

};


#endif //LINKED_LIST_STACK_H