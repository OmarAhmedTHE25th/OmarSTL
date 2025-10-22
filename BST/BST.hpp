//
// Created by DELL on 10/22/2025.
//

#ifndef OMAR_STL_BST_HPP
#define OMAR_STL_BST_HPP

#include "Node.h"

class BST {
    Node *parent{};
    Node *root{};
    static void inorderPrint(Node * head,int level);

    static void inorderTraversal(Node * node);
    void preorderTraversal(Node * node);
    static void postorderTraversal(Node * node);

public:
    BST()= default;
    void insert(int value);
    void delete_node(int value);
    void display() const;
    void update(int oldValue, int newValue);
    ~BST();
    Node *search(int value);
    Node* operator[](int value);
    BST(BST &Otree);





};


#endif //OMAR_STL_BST_HPP