//
// Created by DELL on 10/18/2025.
//

#ifndef LINKED_LIST_CIRCULARLINKEDLIST_H
#define LINKED_LIST_CIRCULARLINKEDLIST_H
#include "Linked_List.h"
typedef  int Element_type;

class CircularLinkedList {
    Node *head {};
    Node *tail {};
    Element_type elementN =0;
    void Reverse(const Node *node);

public:
    void insertAtFront(Element_type value);
    void insertAtEnd(Element_type value);
    void insertAtPos(Element_type pos, Element_type value);
    void deleteByPos(Element_type pos);
    void deleteByVal(Element_type value);
    void updateByPos(Element_type pos,Element_type newVal) const;
    void updateByVal(Element_type oldVal, Element_type newVal) const;
    Element_type getValueAt(Element_type pos)const;
friend std::ostream& operator<<(std::ostream& stream,const CircularLinkedList& list);
    void displayInReverse();
    CircularLinkedList (const CircularLinkedList &other);
    CircularLinkedList()=default;
    ~CircularLinkedList();
    void SortAscendingly() const;
    bool isEqual(const CircularLinkedList &other) const;


};


#endif //LINKED_LIST_CIRCULARLINKEDLIST_H