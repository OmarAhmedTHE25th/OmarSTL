#include <iostream>

#include "BST.hpp"
using namespace std;
int main() {
    BST mytree;
    mytree.insertNode(50);
    mytree.insertNode(60);
    mytree.insertNode(40);
    mytree.insertNode(70);
    mytree.insertNode(90);
    mytree.insertNode(100);
    mytree.insertNode(110);
    // mytree.insertNode(120);
    // mytree.insertNode(130);
    // mytree.insertNode(150);
    // root, the king
    // mytree.insertNode(25);   // left child
    // mytree.insertNode(75);   // right child
    // mytree.insertNode(10);   // left-left
    // mytree.insertNode(60);   // right-left
    // mytree.insertNode(5);    // deep left chain
    // mytree.insertNode(1);    // ultra deep left chain (NULL checking hell)
    // mytree.insertNode(15);   // slightly right on left side
    // mytree.insertNode(13);   // oh yes, middle chaos
    // mytree.insertNode(12);   // left of 13, why not
    // mytree.insertNode(14);   // right of 13, perfect sibling rivalry
    // mytree.insertNode(65);   // mid-right
    // mytree.insertNode(63);   // left child of 65
    // mytree.insertNode(62);   // nesting deeper
    // mytree.insertNode(64);   // testing middle branches
    // mytree.insertNode(80);   // rightmost
    // mytree.insertNode(78);   // left of 80
    // mytree.insertNode(79);   // right of 78 (so deep you?ll need a map)
    // mytree.insertNode(90);   // last layer of doom
    // mytree.insertNode(89);   // nearly the edge of sanity
    // mytree.insertNode(91);   // actual edge of sanity
    // mytree.insertNode(88);   // because chaos demands balance
    // mytree.insertNode(40);   // right of 25, shift in structure
    // mytree.insertNode(45);   // right of 40
    // mytree.insertNode(30);   // left of 40
    // mytree.insertNode(35);   // right of 30
    // mytree.insertNode(33);   // nested inside that chaos
    // mytree.insertNode(34);   // sweet spot to make your destructor sweat
    // mytree.insertNode(26);   // to mess with your left-right navigation
    // mytree.insertNode(27);   // deeper still
    // mytree.insertNode(28);   // deeper than before
    // mytree.insertNode(29);// DEEPER

    //
    //   mytree.deleteNode(26);
    //   mytree.deleteNode(30);
    //   mytree.deleteNode(40);
    //  mytree.deleteNode(29);
    // mytree.deleteNode(90);
    //mytree.deleteNode(50);
    cout << endl;
 // mytree.printH();
    cout << endl<< endl<< endl<< endl;
  mytree.display();


    return 0;
}
// Level 0: 50
// Level 1: 25 75
// Level 2: 10 40 60 80
// Level 3: 5 15 30 45 65 78 90
// Level 4: 1 13 26 27 63 79 89 91
// Level 5: 12 14 28 62 64 88
// Level 6: 29
