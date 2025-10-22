
#include <iostream>

#include "DSTACK.h"
#include "STACK.h"
using namespace std;
int main() {
// STACK my_stack;

    DSTACK my_stack;

    my_stack.push(5);

    my_stack.push(7);

    my_stack.push(9);

    my_stack.push(11);
    const DSTACK stack2(my_stack);
    cout << stack2;


    return 0;
}