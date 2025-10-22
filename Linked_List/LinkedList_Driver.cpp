#include <iostream>

#include "CircularLinkedList.h"
#include "Linked_List.h"
#include "STACK.h"
using namespace std;
int main() {
STACK myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);



   // cout << myStack;
    // myStack.pop();
    //  cout << myStack.peek();
    // cout << endl;
    // cout << myStack.size();    30 - 10 - 90 - 40 - 70 - 30
    CircularLinkedList my_list;
    my_list.insertAtFront(10);
    my_list.insertAtPos(1,40);
     my_list.insertAtFront(30);
     my_list.insertAtPos(5,5);
     my_list.insertAtPos(2,90);
     my_list.insertAtEnd(70);
     my_list.deleteByPos(3);
 my_list.insertAtEnd(50);


cout << my_list << endl<<endl<<endl;
//
//     my_list.displayInReverse();
   // CircularLinkedList list2(my_list);
    //cout << boolalpha;
    //cout << my_list.isEqual(list2) << endl;
    my_list.SortAscendingly();
   // cout << my_list.isEqual(list2) << endl;

cout << my_list;

//      Linked_List my_list;
//
//    my_list.update_by_pos(0,1);
//      my_list.update_by_value(9,0);
//      my_list.insert_at_pos(0,99);
//      my_list.insert_node(10);
//      my_list.insert_node(20);
//      my_list.insert_node(30);
//      my_list.insert_node(40);
//      my_list.insert_node(50);
//      my_list.insert_node(60);
//      my_list.insert_node(70);
//
//      const Linked_List list2(my_list);
//
//
//      cout << my_list;
//      cout << list2;
//
//
//     cout << my_list + list2;
//     cout << my_list - list2;
//
//
//     my_list.display();
// cout << endl;
//     my_list.insert_at_pos(5,69);
//     my_list.display();
//
//     my_list.insert_at_pos(8,67);
//     cout << endl;
//     my_list.display();
//     my_list.delete_at_pos(0);
//     my_list.delete_at_pos(2);
//     my_list.delete_at_pos(4);
//     cout << endl;
//     my_list.display();
//
//       cout << endl << endl;
//         my_list.delete_node(40);
//         my_list.delete_node(10);
//         my_list.delete_node(70);
//         my_list.display();
//         my_list.update_by_pos(6,100);
//         my_list.display();
//         my_list.update_by_value(30,90);
//         my_list.display();
//         my_list.update_by_value(80,10);
//         my_list.display_reverse();
//     cout << boolalpha << endl;

        return 0;
    }
