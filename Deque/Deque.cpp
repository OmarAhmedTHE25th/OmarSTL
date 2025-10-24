//
// Created by DELL on 10/21/2025.
//

#include "Deque.h"
#include <iostream>
using namespace std;

void Deque::pushFront(ElementType value) {

    if (elementN >= size) {

        size *=2;

        auto *newlist = new ElementType[size]{};

        for (int i1 = 0; i1<elementN;i1++) {
            newlist[i1] = list[i1];
        }

       for (int i = elementN; i >=0;i--) newlist[i+1] = newlist[i];
        newlist[0] = value;
        elementN++;
        delete[] list;

        list = newlist;
        return;
    }
    for (int i = elementN; i >=0;i--) list[i+1] = list[i];


    list[0] = value;
    elementN++;



}
Deque::~Deque() {
    delete[] list;
}
void Deque::pushBack(ElementType value) {

    if (elementN>=size) {
        while (elementN>=size)size *=2;

        auto *newlist = new ElementType[size]{};

        for (int i1 = 0; i1<elementN;i1++) {
            newlist[i1] = list[i1];
        }

       newlist[elementN] = value;
        elementN++;
        list = newlist;
        return;
    }
    list[elementN] = value;
    elementN++;
}
void Deque::popFront() {
    for (int i =0; i < elementN; i++ ) {
        list[i] = list[i+1];
    }

    elementN--;
}
void Deque::popBack() {
    list[elementN] = 0;
    elementN--;
}
void Deque::display() {
    for (int i=0; i<elementN; i++) {
        cout << "------------";
        string box = format(R"(
|    {}    |
)" , list[i]);

        cout<< box;
        if (i == elementN-1)cout << "------------";
    }

}
ElementType Deque::front() {
    return list[0];
}
ElementType Deque::back() {
    return list[elementN-1];
}
int Deque::getSize() {
    return elementN;
}
bool Deque::isEmpty() {
    return elementN == 0;
}








