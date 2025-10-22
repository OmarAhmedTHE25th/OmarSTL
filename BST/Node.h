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



    public:
        explicit Node (const int data);
        friend class BST;
    };
 // std

#endif //BST_NODE_H