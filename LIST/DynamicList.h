//
// Created by DELL on 10/21/2025.
//

#ifndef PRACTICE_DYNAMICLIST_H
#define PRACTICE_DYNAMICLIST_H
#include <iosfwd>
#include "C:\Users\DELL\CLionProjects\Omar STL\BST\Node.h"

typedef Node* ElementType;
class DynamicList {

    int size =10;
    ElementType *list = new ElementType[size]{nullptr};
    int elementN = 0;
    ElementType search(int pos);
public:
    void insert(int pos,ElementType value);
    void insertEnd(ElementType value);
    void erase(int pos);
    void update(int pos, ElementType value);
    friend std::ostream& operator<<(std::ostream& stream , const DynamicList &olist);
    friend DynamicList operator+(const DynamicList &list1,const DynamicList &list2);
    DynamicList(DynamicList &Olist);
    DynamicList() = default;
   DynamicList operator=(DynamicList &list1);
   ElementType operator[](int index);
    int getSize() const;
~DynamicList();
};


#endif //PRACTICE_DYNAMICLIST_H