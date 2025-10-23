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

    Node* insertHelper(Node * node,int value);
    void printBST(Node* node, std::string prefix , bool isLeft ,bool isRoot) ;
    static int findH(Node *node,int left,int right);

public:
    BST()= default;
    void insertNode(int value);
    void delete_node(int value);
    void display() ;
    void update(int oldValue, int newValue);
    ~BST();
    Node *search(int value);
    Node* operator[](int value);
    BST(BST &Otree);
    void printH();
    int countNodes(Node* node);




};


#endif //OMAR_STL_BST_HPP