//
// Created by DELL on 10/22/2025.
//

#include "BST.hpp"

#include <execution>
#include <format>

#include "iostream"
using namespace  std;

//new is smaller go left
//new is bigger go right

void BST::insert(int value) {
    if (root == nullptr) {
        const auto newNode = new Node(value);
        root = newNode;
        root->right = nullptr;
        root->left = nullptr;
        return;
    }
    const auto newNode = new Node(value);
    Node *temp = root;



    if (value <  temp->data)
        while (temp->left != nullptr ) {
        if (value <  temp->data){parent = temp; temp = temp->left;}
            if (value > temp->data)break;
        if (value == temp->data)return;
    }

    if (value >  temp->data)
    while (temp->right != nullptr ) {
    if (value >  temp->data){ parent = temp; temp = temp->right;}
        if (value < temp->data)break;
    if (value == temp->data)return;
}


    if (value <  temp->data){parent = temp;temp->left = newNode;return;}
    if (value >  temp->data) {parent = temp;temp->right = newNode;}

}
void BST::delete_node(int value) {
    if (root == nullptr)return;

    Node *temp = root;
    if (root->data == value) {
        if (root->left == nullptr && root->right == nullptr) {delete temp;return;}
        if (root->left == nullptr || root->right == nullptr) {
            if (root->left != nullptr) {
                root = root->left;
                delete temp;
                return;
            }
            if (root->right != nullptr) {
                root = root->right;
                delete temp;
                return;
            }
        }

        Node *leftmost = root->right;
        while (leftmost->left != nullptr) {parent = leftmost; leftmost= leftmost->left;}
        parent->left = nullptr;
        root = leftmost;
        root->left = temp->left ;
        root->right = temp->right ;
        delete temp;

        return;
    }

    while (temp->left != nullptr || temp->right != nullptr ) {
        if (value <  temp->data){parent = temp; temp = temp->left;}

        if (value >  temp->data) {parent = temp; temp = temp->right;}

        if (value == temp->data) {

            if (temp ->right == nullptr && temp->left == nullptr) {
                if (value > parent->data) parent->right = nullptr;
                if (value < parent->data) parent->left = nullptr;
                delete temp;
                return;
            }
            parent->right = temp->right;
            parent->left = temp->left;

            delete temp;
            return;
        }

    }
}




BST::~BST() {
    Node *temp = root;

    Node *left = root->left;
    Node *right = root->right;


    while (temp->right != nullptr || temp->left != nullptr) {

        while (left != nullptr) {

            temp = left;
            if (temp->right != nullptr) {

                delete temp->right;

            }


            delete temp;
            left = left->left;

        }

        while (right != nullptr) {
            temp = right;
            if (temp->left != nullptr) {

                delete temp->left;

            }

            delete temp;

            temp = right;
            right = right->right;
        }
    }

delete root;
}

void BST::update(int oldValue, int newValue) {
    delete_node(oldValue);
    insert(newValue);
}

Node *BST::search(int value) {
    Node * temp = root;
    while (temp->left != nullptr || temp->right != nullptr ) {
        if (value <  temp->data){parent = temp; temp = temp->left;}

        if (value >  temp->data) {parent = temp; temp = temp->right;}

        if (value == temp->data) {
            return  temp;
        }
    }
    return  nullptr;
}

Node *BST::operator[](int value) {
    return search(value);
}



void BST::inorderTraversal(Node * head, int level =0 ) {


if (head == nullptr){return;}

    inorderTraversal(head->right, level +1);

    for (int i = 0; i < level; ++i) {
        std::cout << "    "; // Indentation
    }
    cout << head->data << endl;

    inorderTraversal(head->left,level +1);

}
void BST::display() const {
    inorderTraversal(root);
}




