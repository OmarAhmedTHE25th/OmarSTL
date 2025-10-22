#include <iostream>

#include "BST.hpp"
using namespace std;
int main() {
    BST mytree;
    mytree.insert(20);
    mytree.insert(15);
    mytree.insert(25);
    mytree.insert(10);
    mytree.insert(16);
    mytree.insert(40);
    mytree.insert(23);
    mytree.delete_node(20);
    mytree.delete_node(10);
    mytree.insert(35);
    mytree.insert(24);
    mytree.insert(14);
    mytree.delete_node(35);
    mytree.insert(13);
    mytree.delete_node(13);
    mytree.display();

    cout << mytree[23] ;

    return 0;
}