//
// Created by DELL on 10/18/2025.
//

#include "DSTACK.h"
#include <iostream>
using namespace std;
std::ostream& operator<< (std::ostream& stream, const DSTACK& stack) {
    if (stack.isEmpty())
    {
        cout<<"EMPTY STACK!\n";
        return stream;

    }
    for (int i =0; i < stack.elementN; i++ ) {
        if (i ==0)stream<< "--------\n";
        stream<< "|      |\n";
        stream <<"   "  <<  stack.stack[i] << endl;
        stream<< "|      |\n";
        if (i== stack.elementN-1) stream<< "--------\n";
        if (i!= stack.elementN-1) stream<< "--------\n";

    }
    return stream;

}
void DSTACK::push(const int value) {

    if (isEmpty()) {
        stack[0] = value;
        elementN++;
        return;
    }
    if (elementN < size) {
        for (int idx=elementN-1; idx >= 0; idx--) {

            stack[idx+1 ] = stack[idx];

        }
        stack[0] = value;
        elementN++;
        return;
    }

        size*=2;
        const auto newStack = new int[size];
    for (int i = 0; i<elementN; i++) {
        newStack[i] = stack[i];
    }
    delete[] stack;
    for (int idx=elementN-1; idx >= 0; idx--) {

        newStack[idx+1 ] = newStack[idx];

    }
    newStack[0] = value;
    elementN++;
    stack = newStack;


}
void DSTACK::pop() {
    if (isEmpty()){cout<<"EMPTY STACK!\n";return;}
    for (int i =0; i < elementN; i++) {
        stack[i] = stack[i+1];
    }
    elementN--;

}
int DSTACK::getSize() const {
    return elementN;
}
bool DSTACK::isEmpty() const {
    return elementN ==0;
}
int DSTACK::peek() const {
    return stack[0];
}
DSTACK::DSTACK(const DSTACK &stack2) {
    elementN =  stack2.elementN ;
    size = stack2.size;
    const auto newStack = new int[size];
    for (int i =0; i < elementN; i++) {
         newStack[i] =stack2.stack[i];

    }
    stack = newStack;

}
