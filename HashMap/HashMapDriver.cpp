#include <cassert>

#include "HashMap.hpp"
#include "iostream"

int main() {
    // Create two maps
    HashMap<int, std::string> map1;
    HashMap<int, std::string> map2;
    map1.set(1, "Omar");
    map1.set(2, "Ali");
    map1[3] = "Patrick";  // using operator[]
    map2.set(4, "Ahmed");
    map2[5] = "Zara";
    std::cout << "Map1:\n" << map1;
    std::cout << "Map2:\n" << map2;
    if (map1.contains(2)) std::cout << "Key 2 exists at index " << map1.findKey(2) << "\n";
    if (!map2.contains(10)) std::cout << "Key 10 does not exist in map2\n";
    std::cout << "Map1 size: " << map1.size() << "\n";
    std::cout << "Map2 is empty? " << (map2.Empty() ? "Yes" : "No") << "\n";
    std::cout << "Map1 max size: " << map1.maxSize() << "\n";
    map1.Delete(3);  // removes Patrick
    std::cout << "Map1 after removing key 3:\n" << map1;
    HashMap<int, std::string> copyMap(map1);
    std::cout << "Copy of Map1:\n" << copyMap;
    HashMap<int, std::string> assignMap = map2;
    std::cout << "Assigned map2 to assignMap:\n" << assignMap;
    HashMap<int, std::string> mergedMap = map1 + map2;
    std::cout << "Merged Map1 + Map2:\n" << mergedMap;
    mergedMap[2] = "Ali Updated";
    mergedMap[6] = "New Entry";  // adds new key
    std::cout << "Merged Map after updates:\n" << mergedMap;
    std::cout << "Final Map Sizes:\n";
    std::cout << "Map1: " << map1.size() << "\n";
    std::cout << "Merged: " << mergedMap.size() << "\n";




}
