//
// Created by DELL on 10/22/2025.
//

#ifndef OMAR_STL_NODE_HPP
#define OMAR_STL_NODE_HPP
#include 

typedef int ElementType;

class Node {
    Node *data = 0;
    Node *next{};
    Node *prev{};
    friend class LLDeque;
public:
    explicit Node(ElementType value);
};


#endif //OMAR_STL_NODE_HPP