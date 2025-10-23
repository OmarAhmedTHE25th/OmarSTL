//
// Created by DELL on 10/22/2025.
//

#ifndef OMAR_STL_BST_HPP
#define OMAR_STL_BST_HPP

#include <string>

#include "Node.h"

class BST {
    Node *parent{};
    Node *root{};


    static void inorderPrint(Node * head,int level);

    static void inorderTraversal(Node * node);
    void preorderTraversal(Node * node);
    static void postorderTraversal(Node * node);

public:
    int n =0;
    BST()= default;
    void insert(int value);
    void delete_node(int value);
    void display() ;
    void update(int oldValue, int newValue);
    ~BST();
    Node *search(int value);
    Node* operator[](int value);
    BST(BST &Otree);
void printBST(Node* node, std::string prefix , bool isLeft);
    static int findH(Node *node,int left,int right);
    void printH();




};


#endif //OMAR_STL_BST_HPP