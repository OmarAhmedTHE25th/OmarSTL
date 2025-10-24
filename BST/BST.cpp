//
// Created by DELL on 10/22/2025.
//

#include "BST.hpp"


#include <format>


#include "iostream"
using namespace  std;
#include "C:/Users/DELL/CLionProjects/Omar STL/LIST/DynamicList.h"
#include "C:/Users/DELL/CLionProjects/Omar STL/LIST/DynamicList.cpp"
//new is smaller go left
//new is bigger go right



void BST::insertNode(int value) {
    const auto newNode = new Node(value);
    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* temp = insertHelper(root,value);
    newNode->parent = temp;
    if (temp == nullptr){cout << "Recursion Failed\n"; return;}
    if (value > temp->data) {
        temp->right = newNode;


     // H = findH(root,1);





    }
    if (value < temp->data) {
        temp->left = newNode;
       // H = findH(root,1);
    }




}
Node* BST::insertHelper(Node *node,int value) {
    if (value < node->data && node->left == nullptr) return node;
    if (value > node->data && node->right == nullptr) return node;
    if (value < node->data)return  insertHelper(node->left,value);
    if (value > node->data) return  insertHelper(node->right,value);
    return nullptr;
}
void BST::deleteNode(int value) {
    if (root == nullptr)return;
    Node *temp = root;
    while (temp!= nullptr) {
        if (value <  temp->data){ temp = temp->left;}

        else if (value >  temp->data) {temp = temp->right;}

        else if (value == temp->data){


            if (temp->right && temp->left) {

                Node *leftmost = temp->right;

                while (leftmost->left != nullptr) {leftmost= leftmost->left;}
                temp->data = leftmost->data;
                if (leftmost->right) {
                    if (leftmost == leftmost->parent->left) leftmost->parent->left = leftmost->right;
                    else if (leftmost ==leftmost->parent->right) leftmost->parent->right = leftmost->right;
                    leftmost->right->parent = leftmost->parent;
                }
                else if (!leftmost->right) {

                   if (leftmost == leftmost->parent->left)  leftmost->parent->left = nullptr;
                   else if (leftmost ==leftmost->parent->right) leftmost->parent->right = nullptr;

                 }

                delete leftmost;
                return;
            }

            if (!temp ->right && !temp->left) {
                if (temp == temp->parent->left) {
                    temp->parent->left = nullptr;
                } else {
                    temp->parent->right = nullptr;
                }
                delete temp;
                return;
            }

            Node* child = temp->left ? temp->left : temp->right;
            if (temp == temp->parent->left) {
                temp->parent->left = child;
            } else {
                temp->parent->right = child;
            }
            child->parent = temp->parent;
            delete temp;
            return;
        }

    }
    cout << "Value Not found\n";
}
int BST::countNodes(Node* node) {
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}
BST::~BST() {
postorderTraversal(root);
}
void BST::update(int oldValue, int newValue) {
    deleteNode(oldValue);
    insertNode(newValue);
}
Node *BST::search(int value) {
    Node * temp = root;
    while (temp->left != nullptr || temp->right != nullptr ) {
        if (value <  temp->data){temp->parent = temp; temp = temp->left;}

        if (value >  temp->data) {temp->parent= temp; temp = temp->right;}

        if (value == temp->data) {
            return  temp;
        }
    }
    return  nullptr;
}
Node *BST::operator[](int value) {
    return search(value);
}
void BST::inorderTraversal(Node *node) {
    DynamicList list;
    if (node->right != nullptr && node->left != nullptr) return;
    inorderTraversal(node->left);
    list.insertEnd(node);
    inorderTraversal(node->right);
}
void BST::postorderTraversal(Node *node) {
    if (node->right != nullptr && node->left != nullptr) return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    delete node;
}
void BST::preorderTraversal(Node *node) {
    if (node->right != nullptr && node->left != nullptr) return;
    insertNode(node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);

}
BST::BST(BST &Otree) {
    if (Otree.root == nullptr) return;
    root = Otree.root;
    preorderTraversal(root);
}
void BST::inorderPrint(Node * head, int level =0 ) {


if (head == nullptr){return;}

    inorderPrint(head->right, level +1);

    for (int i = 0; i < level; ++i) {
        std::cout << "   "; // Indentation
    }
    cout << head->data << endl;

    inorderPrint(head->left,level +1);

}
void BST::display()  {
    print(root);
}
void BST::print(Node *node) {

        if (node == nullptr) return; // base case

        // left subtree first

             cout << "Node: " << node->data
             << " | Parent: " << (node->parent ? to_string(node->parent->data) : "NULL")
             << " | Left: " << (node->left ? to_string(node->left->data) : "NULL")
             << " | Right: " << (node->right ? to_string(node->right->data) : "NULL")
             << endl << endl;
        print(node->left);
        print(node->right); // right subtree next


}










int BST::findH(Node *node,int depth=1) {
    
    if (node == nullptr) return 0;
    if (node->right == nullptr && node->left == nullptr) return H;
    leftDepth= findH(node->left,depth+1);
     rightDepth = findH(node->right,depth+1);
    H = max(leftDepth,rightDepth)+1;
 return H;
}
void BST::printH() {
    cout << findH(root);
}
ElementType BST::BuildBalanced(DynamicList list) {
    if (list.Size()== 0) return nullptr;
    int cent = list.Size() /2;
    Node*root =list[cent];
    root->left = BuildBalanced(list.subList(0,cent));



}





