//
// Created by DELL on 10/21/2025.
//

#ifndef PRACTICE_DYNAMICLIST_H
#define PRACTICE_DYNAMICLIST_H
#include <iosfwd>

typedef int ElementType;
class DynamicList {

    ElementType size =10;
    ElementType *list = new ElementType[size]{};
    ElementType elementN = 0;
public:
    void insert(int pos,ElementType value);

    void erase(int pos);
    void update(int pos, ElementType value);

    friend std::ostream& operator<<(std::ostream& stream , const DynamicList &olist);
    int search(int pos);
    friend DynamicList operator+(const DynamicList &list1,const DynamicList &list2);
    DynamicList(DynamicList &Olist);
    DynamicList() = default;
   DynamicList operator=(DynamicList &list1);

~DynamicList();
};


#endif //PRACTICE_DYNAMICLIST_H