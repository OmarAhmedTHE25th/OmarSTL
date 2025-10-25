//
// Created by DELL on 10/22/2025.
//

#ifndef OMAR_STL_BST_HPP
#define OMAR_STL_BST_HPP

#include <string>
#include "Node.h"
#include "C:/Users/DELL/CLionProjects/Omar STL/LIST/DynamicList.h"

class BST {
    Node *root{};

    int H = 0;
    int leftDepth=0;
    int rightDepth =0;
    static void inorderPrint(Node * head,int level);
    void inorderTraversal(Node * node,DynamicList &list);
    void preorderTraversal(Node * node);
    static void postorderTraversal(Node * node);
    Node* insertHelper(Node * node,int value);
     int findH(Node *node,int depth);
    void print(Node* node);
    double n = 0;
public:
    BST()= default;
    void insertNode(int value);
    void deleteNode(int value);
    void display() ;
    void update(int oldValue, int newValue);
    ~BST();
    Node *search(int value);
    Node* operator[](int value);
    BST(BST &Otree);
    void printH();

    double countNodes(Node* node);
    ElementType BuildBalancedFromList(DynamicList &list,int start,int end);
friend class BST;




};


#endif //OMAR_STL_BST_HPP