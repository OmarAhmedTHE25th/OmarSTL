#include <cassert>

#include "HashMap.hpp"
#include "iostream"

int main() {
std::string name = "Omar";
    HashMap<int,std::string> map{};
    map.set(1, "Omar");
    map.set(2, "Ahmed");
    map.set(42, "Patrick");

    assert(map[1] == "Omar");
    assert(map[2] == "Ahmed");
    assert(map[42] == "Patrick");
    map.set(1, "Ali");  // overwrite previous value

    if (map[1] == "Ali") std::cout << "Overwrite Pass\n";


    map.Display();
}