//
// Created by DELL on 10/13/2025.
//

#ifndef BST_NODE_H
#define BST_NODE_H
#pragma once



class Node {
       int data = 0;
        Node *left{};
        Node *right{};
        Node*parent{};



    public:
        explicit Node (int data);
    Node()=default;
        friend class BST;
    friend class DynamicList;
    };
 // std

#endif //BST_NODE_H