//
// Created by DELL on 10/22/2025.
//

#include "BST.hpp"


#include <format>
#include <queue>

#include "iostream"
using namespace  std;

//new is smaller go left
//new is bigger go right



void BST::insertNode(int value) {
    const auto newNode = new Node(value);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    Node* temp = insertHelper(root,value);
  if (temp == nullptr){cout << "Recursion Failed\n"; return;}
    if (value > temp->data) {
        temp->right = newNode;
    }
    if (value < temp->data) {
        temp->left = newNode;
    }




}
Node* BST::insertHelper(Node *node,int value) {
    if (value < node->data && node->left == nullptr) return node;
    if (value > node->data && node->right == nullptr) return node;
    if (value < node->data)return  insertHelper(node->left,value);
    if (value > node->data) return  insertHelper(node->right,value);
    return nullptr;
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
int BST::countNodes(Node* node) {
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}
void BST::printBST(Node* node, std::string prefix = "", bool isLeft = true, bool isRoot = true) {
    if (!node) return;

    // Print right subtree first
    if (node->right)
        printBST(node->right, prefix + (isRoot ? "" : (isLeft ? "|   " : "    ")), false, false);

    // Print current node
    std::cout << prefix;
    if (isRoot)
        std::cout << node->data << std::endl;   // Root has no prefix
    else
        std::cout << (isLeft ? "+-- " : "\\-- ") << node->data << std::endl;

    // Print left subtree
    if (node->left)
        printBST(node->left, prefix + (isRoot ? "" : (isLeft ? "|   " : "    ")), true, false);
}
BST::~BST() {
postorderTraversal(root);
}
void BST::update(int oldValue, int newValue) {
    delete_node(oldValue);
    insertNode(newValue);
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
void BST::inorderTraversal(Node *node) {

    if (node->right != nullptr && node->left != nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
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
    printBST(root);
}
int BST::findH(Node *node,int depth=1) {
    
    if (node == nullptr) return 0;
    if (node->right == nullptr && node->left == nullptr) return H;
   int leftDepth= findH(node->left,depth+1);
    int rightDepth = findH(node->right,depth+1);
    H = max(leftDepth,rightDepth)+1;
 return H;
}
void BST::printH() {
    cout << findH(root);
}





