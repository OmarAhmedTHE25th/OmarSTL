//
// Created by DELL on 10/18/2025.
//

#include "STACK.h"
#include <iostream>

#include "DSTACK.h"
using namespace std;
std::ostream& operator<< (std::ostream& stream, const STACK& stack) {
    if (stack.isEmpty())
    {
        cout<<"EMPTY STACK!\n";
        return stream;

}
    for (int i =0; i < stack.elementN; i++ ) {
        if (i ==0)cout<< "--------\n";
        cout<< "|      |\n";
        cout <<"   "  <<  stack.stack[i] << endl;
        cout<< "|      |\n";
        if (i== stack.elementN-1) cout<< "--------\n";
        if (i!= stack.elementN-1) cout<< "--------\n";

    }
    return stream;

}
void STACK::push(const int value)  {

    if (isEmpty()) {
        stack[0] = value;
        elementN++;
        return;
    }

    for (int idx=elementN-1; idx >= 0; idx--) {

        stack[idx+1 ] = stack[idx];

    }

    stack[0] = value;
    elementN++;

}
void STACK::pop() {
    if (isEmpty()){cout<<"EMPTY STACK!\n";return;}
    for (int i =0; i < elementN; i++) {
        stack[i] = stack[i+1];
    }
    elementN--;
}
int STACK::getSize() const {
    return elementN;
}
bool STACK::isEmpty() const {
    return elementN ==0;
}
int STACK::peek() const {
    return stack[0];
}
STACK::STACK(STACK &stack) {
    for (int i =0; i <  SIZE; i++) {
         stack.stack[i] = this->stack[i];

    }
}




