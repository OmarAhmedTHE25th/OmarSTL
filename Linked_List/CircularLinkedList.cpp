//
// Created by DELL on 10/18/2025.
//

#include "CircularLinkedList.h"
#include <iostream>
using namespace  std;

void CircularLinkedList::insertAtFront(const Element_type value) {
    if (head == nullptr) {
        const auto newNode = new Node(value);
        head = newNode;
        tail= head;
        tail->next = head;
        elementN++;
        return;
    }
    Node *temp = head;
    const auto newNode = new Node(value);
    newNode->next = temp;
    head = newNode;
    elementN++;


}
void CircularLinkedList::insertAtEnd(const Element_type value) {
    if (head != nullptr) {
        const auto newNode = new Node(value);
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
        elementN++;


    }

}
Element_type CircularLinkedList::getValueAt(const Element_type pos) const{
    int i = 1;
    const Node *temp = head;
    if (pos < 0 or pos>elementN) {std::cout<< "[[ERROR]] Invalid position\n" << std::endl; return -1;}
    if (pos == 0)return head->data;
    if (pos == elementN)return tail->data;
    while (temp->next != head) {
        if (pos == i) {
        return temp->data;
        }
        temp = temp->next;
        i++;
    }
    cout<<"Position not found";
    return -1;

}
void CircularLinkedList::insertAtPos(const Element_type pos, const Element_type value) {
    if (pos ==0) {insertAtFront(value);  return;}
    if (pos == elementN) {insertAtEnd(value); return;}
    if (pos < 0 or pos>elementN) {std::cout<< "[[ERROR]] Invalid position\n" << std::endl; return;}
        int i =1;


         Node *prev = head;
         Node *temp = head->next;
    while (temp->next != head) {
        if (pos == i) {
            const auto newNode = new Node(value);
            newNode->next = temp;
            prev->next = newNode;
            elementN++;

            return;
        }
        prev = temp;
        temp = temp->next;
        i++;

    }

}
void CircularLinkedList::deleteByPos(const Element_type pos) {
    int i =1;
    if (pos < 0 or pos >= elementN) {
        cout << "[[ERROR]] invalid Position\n"; return;
    }
    if (pos ==0) {
        const Node *curr = head;
        head = head->next;
        delete curr;
        elementN--;
        return;
    }
     if (pos == elementN-1) {
        Node *prev = head;

        while (prev->next != tail) prev = prev->next;
        prev->next = head;
        delete tail;
        tail = prev;
        elementN--;
        return;
    }
     Node *prev = head;
     Node *temp = head->next;
    while (temp->next != head) {
        if (pos ==i) {
            prev->next = temp->next;
            delete temp;
            elementN--;
            return;
        }
        prev = temp;
        temp = temp->next;
        i++;
    }
}
void CircularLinkedList::deleteByVal(const Element_type value) {
    Node *temp = head;
    Node *prev = head ->next;
    while (temp->next != head) {
        if (temp->data == value) {
            prev->next = temp->next;
            delete temp;
            elementN--;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "[[ERROR]] value not found!\n";
}
void CircularLinkedList::updateByPos(const Element_type pos, const Element_type newVal) const {
    if (pos < 0 or pos>elementN) {std::cout<< "[[ERROR]] Invalid position\n" << std::endl; return;}
    if (pos ==0) {
        head->data = newVal;
        return;
    }
    if (pos == elementN) {
        tail->data = newVal;return;
    }
    Node *temp = head;
    int i =1;
    while (temp->next != head) {
        if (pos == i) {
            temp->data = newVal;
            cout << "Updated!\n";
        }
        temp = temp->next;
        i++;
    }



}
void CircularLinkedList::updateByVal(const Element_type oldVal, const Element_type newVal) const {
    Node *temp = head;
    while (temp->next != head) {
        if (temp->data == oldVal) {
            temp->data = newVal;
        }
        temp = temp->next;
    }
    cout <<"[[ERROR]] Value not found!";
}
std::ostream& operator<<(std::ostream& stream,const CircularLinkedList& list) {
    const Node *temp = list.head;
    if (list.head == nullptr){ stream<<"Empty List!"; return stream;}
    for (int i =0; i < list.elementN; i++) {
        std::string box = std::format(R"(
--------------
|   {}. {}    |
--------------
      |
      v)", i,temp->data);


    if (i == list.elementN-1) {
        const string box2 = format(R"(
---------------
|   {}. {}     |
---------------
      |
      v
---------------
|   0. {}      |
---------------              )",i, temp->data, list.getValueAt(0));

        stream << box2;
        return stream;
    }
       stream<<box;
        temp = temp -> next;
    }

    return stream;
}
void CircularLinkedList::Reverse(const Node *node) {
    static Element_type idx = elementN-1;
    static  bool skipFirst = true;
    if (node == head)
    {
        if (skipFirst)skipFirst =false;
        else {
            return;
        }
    }


    Reverse(node->next);

        const std::string box = std::format(R"(
--------------
|    {}.{}    |
--------------
      |
      v)",idx, node->data);
cout<<box;

    idx--;


}
void CircularLinkedList::displayInReverse() {
    Reverse(head);
   int idx =elementN -1;
        const string box2 = format(R"(
---------------
|   {}. {}      |
---------------              )", idx,tail->data);

        cout << box2;

}
CircularLinkedList::~CircularLinkedList() {
if (head == nullptr)return;
    Node *curr = head;
    tail->next = nullptr;
    while (curr->next != head) {

         Node *next = curr->next;
        delete curr;
        curr = next;

    }
    head = nullptr;
    tail = nullptr;
}
CircularLinkedList::CircularLinkedList(const CircularLinkedList &other) {
    if (other.head == nullptr) {
        head = nullptr;
        tail = nullptr;
        elementN = 0;
        return;
    }
    head = new Node(other.head->data);
    elementN = 1;

    Node *temp = other.head->next;
    Node *curr = head;

        while (temp != other.head) {
            curr->next = new Node(temp->data);
            curr = curr->next;
            temp = temp->next;
            elementN++;

        }

        tail = curr;

        tail->next  = head;


}
void CircularLinkedList::SortAscendingly() const {

    Node *curr= head;
    Node *next = head->next;
    while (next->next != head) {
        if (curr->data > next->data) {
            const int t = next->data;
            next->data = curr->data;
            curr->data = t;
        }
        curr = next;
        next = next->next;
    }
}
bool CircularLinkedList::isEqual(const CircularLinkedList &other) const {
    const Node *h = head;
    const Node *oh = other.head;
    if (elementN != other.elementN) return false;
    while (h-> next  != head and oh->next!= other.head) {
        if (h->data != oh->data)return false;
        h= h->next;
        oh = oh->next;
    }
    return true;
}







