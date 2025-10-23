//
// Created by DELL on 10/22/2025.
//

#include "LLDeque.h"
#include "Node.hpp"
#include <iostream>
using namespace std;
void LLDeque::pushFront(ElementType value) {
    if (head == nullptr) {
        const auto newnode = new Node(value);
       head = newnode;
        tail = head;
        nodeN++;
        return;
    }
    const auto newnode = new Node(value);
    newnode->next = head;
    head ->prev = newnode;
    head = newnode;
    nodeN++;

}
void LLDeque::pushBack(ElementType value) {
    const auto newnode = new Node(value);
    if (nodeN == 0) {
        tail = newnode;
        head = newnode;
        nodeN++;
        return;
    }
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
    nodeN++;
}
void LLDeque::popFront() {
    Node *temp = head;

    if (head != nullptr) {
        head->prev = nullptr;  // ✅ Break link to deleted node
    } else {
        tail = nullptr;  // List is now empty
    }

    head = head->next;

    delete temp;
    nodeN--;

}
void LLDeque::popBack() {
    Node *temp = tail;
    tail =tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    nodeN--;
}
void LLDeque::display() {
    Node *temp = head;



        for (int i=0; i<nodeN; i++) {
            std::cout << "------------";
            string box = format(R"(
|    {}    |
)" ,temp->data );

            cout<< box;

            if (i == nodeN-1)cout << "------------";
            temp = temp->next;
        }

    }
ElementType LLDeque::back() {
    return tail->data;
}
ElementType LLDeque::front() {
    return head->data;
}
int LLDeque::getSize() {
    return nodeN;
}
bool LLDeque::isEmpty() {
    return nodeN==0;
}
LLDeque::LLDeque(const LLDeque &Olist) {
    if (Olist.head == nullptr){return;}
    Node *temp = Olist.head;

        for (int i =0; i<Olist.nodeN; i++) {
            pushBack(temp->data);
            temp = temp ->next;
        }

}
LLDeque::~LLDeque() {
    Node* temp = head;

    while (temp != nullptr) {
        Node* del = temp->next;
        delete temp;
        temp = del;
    }
    head = nullptr;
    tail = nullptr;
    nodeN =0;
}






