//
// Created by DELL on 10/15/2025.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H
#include 


class Node {
    Node *data = 0;
    Node *next{};
    Node()= default;
    explicit Node(const int data): data(data){}
    friend class Linked_List;
    friend std::ostream& operator<<(std::ostream& stream,const Linked_List& list);
    friend Linked_List operator+(const Linked_List& list);
    friend class CircularLinkedList;
    friend std::ostream& operator<<(std::ostream& stream,const CircularLinkedList& list);
};


#endif //LINKED_LIST_NODE_H