//
// Created by DELL on 10/21/2025.
//

#include "DynamicList.h"

#include <ostream>
#include <iostream>
using namespace std;
 DynamicList::~DynamicList() {
    delete[] list;
}



void DynamicList::insert(const int pos, const ElementType value) {
     if (pos>=size || elementN >= size) {

         while (pos >= size || elementN >= size)size *=2;
         auto newList = new int[size]{};
         for (int i =0; i<elementN;i++) {
             newList[i] = list[i];
         }

         for (int i = elementN-1; i>=pos; i--) {
             newList[i+1] = newList[i];
         }
         newList[pos] = value;

         delete[] list;
         list = newList;
         elementN = std::max(elementN, pos + 1);
         return;

     }
for (int i = elementN-1; i>=pos; i--) {
    list[i+1] = list[i];
}
     list[pos] = value;
     elementN = std::max(elementN, pos + 1);
}

DynamicList operator+(const DynamicList &list1, const DynamicList &list2)
{
      DynamicList FList;
     for (int i=0; i<list1.elementN ; i++) {
         FList.insert(i,list1.list[i]);
     }
     for (int i=list1.elementN; i<list2.elementN; i++) {


             FList.insert(i,list2.list[i]);

     }
     return FList;
}

 std::ostream &operator<<(std::ostream &stream, const DynamicList &olist) {
    for (int i = 0; i < olist.elementN; i++) {
        stream << "[" << olist.list[i] << "] ";
    }

    return stream;
}


void DynamicList::erase(int pos) {

     if (pos>elementN|| pos <0) {
         cout <<  "[[ERROR]] Invalid Position\n";
         return;
     }
     for (int i =pos; i<elementN; i++) {
         list[i] = list[i+1];

     }
     elementN--;

}
int DynamicList::search(int pos) {
     if (pos>elementN|| pos <0) {
         cout <<  "[[ERROR]] Invalid Position\n";
         return 0;
     }
     return list[pos];
}



void DynamicList::update(const int pos, const ElementType value) {
if (elementN == 0){cout<<"Empty List! Nothing to update\n"; return;}


     if (pos == 0){list[0] = value;  return;}
     if (pos>elementN || pos <0) {
         cout <<  "[[ERROR]] Invalid Position\n";
         return;
     }

     for (int i =1; i < size; i++) {

         if ( i == pos){list[i] = value;  return;}
     }
}

DynamicList::DynamicList(DynamicList &Olist) {


    for (int i = 0; i < Olist.elementN; i++) {

            insert(i,Olist.search(i));
            if (i >=10) {
                insert(i,Olist.search(i));
            }

    }
}

DynamicList DynamicList::operator=( DynamicList &list1) {
if (elementN == 0) for (int i = 0; i < list1.elementN; i++) insert(i,list1.search(i));
     while (list1.elementN < elementN) {
         erase(elementN);
     }
     for (int i = 0; i < list1.elementN; i++) {
         update(i,list1.search(i));

         if (i >=size) insert(i,list1.search(i));

     }
 if (this == &list1)return*this;
}






