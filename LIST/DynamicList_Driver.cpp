#include <iostream>
#include <map>
#include <ranges>

#include "DynamicList.h"


using namespace std;

// int R_to_D(const string &romanNumeral) {
//     int Decimal = 0;
//     map<char, int> romanN;
//     romanN['M'] = 1000;
//     romanN['D'] = 500;
//     romanN['C'] = 100;
//     romanN['L'] = 50;
//     romanN['X'] = 10;
//     romanN['V'] = 5;
//     romanN['I'] = 1;
//
//     for (int i = 0; i<romanNumeral.size(); i++) {
//         for (const auto &key: romanN | views::keys) {
//             if (key == romanNumeral[i]) {
//                 if (i + 1 < romanNumeral.size())
//                 {
//                     if (romanN[romanNumeral[i+1]] > romanN[romanNumeral[i]]){Decimal += romanN[romanNumeral[i+1]] - romanN[romanNumeral[i]]; i++;}
//                     else {
//                         Decimal += romanN[romanNumeral[i]];
//                     }
//
//                 }
//                 else {
//                     Decimal += romanN[romanNumeral[i]];
//                 }
//                 break;
//
//             }
//
//         }
//     }
//
//
//     return Decimal;}
//
//
// class  Linked_list {
//     struct node {
//         int data;
//         node* next;
//         int index;
//         explicit node(const int value, int idx): data(value), next(nullptr), index(idx) {}
//     };
//     node *h;
//     node *t;
//
// public:
//
//     Linked_list(): h(nullptr), t(nullptr) {}
//
//     void insert_at_head(int new_data) {
//         node* new_node = new node(new_data, 0);
//         new_node->next = h;
//         h = new_node;
//
//         // Update tail if a list was empty
//         if (t == nullptr) {
//             t = new_node;
//         }
//
//         // Reindex all nodes
//         reindex();
//     }
//
//     void insert(int value) {
//         node* new_node = new node(value, 0);
//
//         if (h == nullptr) {
//             // Empty list
//             h = t = new_node;
//             new_node->index = 0;
//         } else {
//             // Add to end
//             t->next = new_node;
//             t = new_node;
//             reindex();
//         }
//     }
//
//     void delete_node(const int index) {
//         if (h == nullptr) {
//             cout << "List is empty!" << endl;
//             return;
//         }
//
//         // Special case: delete head
//         if (index == 0) {
//             const node* temp = h;
//             h = h->next;
//             delete temp;
//
//             // Update tail if a list is now empty
//             if (h == nullptr) {
//                 t = nullptr;
//             }
//
//             reindex();
//             return;
//         }
//
//         // Find the node before the one to delete
//         node* current = h;
//         for (int i = 0; i < index - 1 && current != nullptr; i++) {
//             current = current->next;
//         }
//
//         // Check if the index is valid
//         if (current == nullptr || current->next == nullptr) {
//             cout << "Index out of bounds!" << endl;
//             return;
//         }
//
//         // Delete the node
//         const node* to_delete = current->next;
//         current->next = to_delete->next;
//
//         // Update tail if we deleted the last node
//         if (to_delete == t) {
//             t = current;
//         }
//
//         delete to_delete;
//         reindex();
//     }
//
//     void display() const {
//         node* current = h;
//         cout << "List: ";
//         while (current != nullptr) {
//             cout << "[" << current->index << ": " << current->data << "] ";
//             current = current->next;
//         }
//         cout << endl;
//     }
//
// private:
//     void reindex() const {
//         node* current = h;
//         int idx = 0;
//         while (current != nullptr) {
//             current->index = idx++;
//             current = current->next;
//         }
//     }
// };





int main() {

DynamicList mylist;
   mylist.insert(0, 10);
    mylist.insert(1, 20);
    mylist.insert(2, 30);;
    mylist.insert(3, 40);
    mylist.insert(4, 50);
    mylist.insert(5, 60);;
    mylist.insert(6, 70);
    mylist.insert(7, 80);
    mylist.insert(8, 90);
    mylist.insert(9, 100);
     mylist.insert(10, 110);
 cout << "After Insertion: \n";
cout << mylist<<endl;
     mylist.update(0, 11);
     mylist.update(1, 21);
     mylist.update(2, 31);
     mylist.update(3, 41);
     mylist.update(4, 51);
     mylist.update(5, 61);
     mylist.update(6, 71);
     mylist.update(7, 81);
     mylist.update(8, 91);
     mylist.update(9, 101);
  mylist.update(10, 111);
cout << "After Update: \n";
 cout << mylist << endl;
  mylist.erase(5);

 mylist.erase(0);
cout << "After Deletion: \n";
 cout << mylist<< endl << endl << endl;
 //

DynamicList list2;
 list2.insert(11, 120);
 list2.insert(12, 130);
 list2.insert(13, 140);
 list2.insert(14, 150);
 list2.insert(15, 160);
 list2.insert(16, 170);
 list2.insert(17, 180);
 list2.insert(18, 190);
 list2.insert(19, 200);

cout << "After Combination";
cout << endl << mylist + list2 << endl;

 DynamicList list3( mylist + list2);
 cout << "After Copying: \n";
 cout << list3 << endl<<endl<<endl;
 cout << "After = operator: \n\n";
DynamicList list4;
 list4.insert(0,5);
 list4.insert(1,10);
 list4.insert(2,15);
 list4.insert(3,20);
 list4.insert(4,25);






 cout << list4;






    return 0;
}
