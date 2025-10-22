#include <iostream>

#include "BST.hpp"
using namespace std;
int main() {
    BST mytree;
    mytree.insert(50);   // root, the king
    mytree.insert(25);   // left child
    mytree.insert(75);   // right child
    mytree.insert(10);   // left-left
    mytree.insert(60);   // right-left
    mytree.insert(5);    // deep left chain
    mytree.insert(1);    // ultra deep left chain (NULL checking hell)
    mytree.insert(15);   // slightly right on left side
    mytree.insert(13);   // oh yes, middle chaos
    mytree.insert(12);   // left of 13, why not
    mytree.insert(14);   // right of 13, perfect sibling rivalry
    mytree.insert(65);   // mid-right
    mytree.insert(63);   // left child of 65
    mytree.insert(62);   // nesting deeper
    mytree.insert(64);   // testing middle branches
    mytree.insert(80);   // rightmost
    mytree.insert(78);   // left of 80
    mytree.insert(79);   // right of 78 (so deep you’ll need a map)
    mytree.insert(90);   // last layer of doom
    mytree.insert(89);   // nearly the edge of sanity
    mytree.insert(91);   // actual edge of sanity
    mytree.insert(88);   // because chaos demands balance
    mytree.insert(40);   // right of 25, shift in structure
    mytree.insert(45);   // right of 40
    mytree.insert(30);   // left of 40
    mytree.insert(35);   // right of 30
    mytree.insert(33);   // nested inside that chaos
    mytree.insert(34);   // sweet spot to make your destructor sweat
    mytree.insert(26);   // to mess with your left-right navigation
    mytree.insert(27);   // deeper still
    mytree.insert(28);   // deeper than before
    mytree.insert(29);   // DEEPER
mytree.display();
    cout << endl << endl;
BST mytree2(mytree);
    mytree2.display();


    return 0;
}