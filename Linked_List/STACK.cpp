//
// Created by DELL on 10/18/2025.
//

#include "STACK.h"

#include <iostream>
using namespace std;
void STACK::pop()  {
list.delete_at_pos(0);
}
void STACK::push(const int value)  {
    list.insert_at_pos(0,value);
}
int STACK::peek() const {

    return list.get_Value_At(0); ;
}
bool STACK::isEmpty() const{
    return list.is_empty();
}
int STACK::size() const {
    return list.get_size();
}
std::ostream& operator<< (std::ostream& stream, const STACK& stack) {
    for (int i=0; i < stack.list.n_count; i++) {
        if (i ==0)cout<< "--------\n";
        cout<< "|      |\n";
        cout <<"   " <<  stack.list.get_Value_At(i) << endl;
        cout<< "|      |\n";
        if (i== stack.list.n_count-1) cout<< "--------\n";
        if (i!= stack.list.n_count-1) cout<< "--------\n";


    }
    return stream;
}



