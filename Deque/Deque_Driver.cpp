#include <iostream>

#include "Deque.h"
#include "LLDeque.h"
using namespace std;

int main() {
  LLDeque mylist;
    mylist.pushFront(5);
    mylist.pushFront(10);
    mylist.pushFront(15);
    mylist.pushFront(20);
    mylist.pushFront(25);
    mylist.pushFront(30);
    mylist.pushFront(35);
    mylist.pushFront(40);
    mylist.pushBack(0);
    mylist.pushBack(-5);
    mylist.pushBack(-10);
    mylist.pushBack(-15);
    mylist.pushBack(-20);
   mylist.popFront();
    mylist.popBack();
//    mylist.display();

    LLDeque list2(mylist);
    list2.display();
    return 0;
}
