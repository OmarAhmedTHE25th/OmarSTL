//
// Created by DELL on 10/25/2025.
//

#ifndef OMAR_STL_HASHMAP_HPP
#define OMAR_STL_HASHMAP_HPP

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <stdexcept>
using namespace std;
template <typename KeyType,typename ValueType>

class HashMap {
    class Bucket {
    public:
        KeyType key;
        ValueType value;
    };

     std::vector<Bucket> Buckets;
    int HashFunction(KeyType key)
    {
        if constexpr (is_same_v<KeyType, int> || is_same_v<KeyType, double> || is_same_v<KeyType, float>
            || is_same_v<KeyType, long> || is_same_v<KeyType, short> || is_same_v<KeyType,signed>) {
            return static_cast<size_t>(key);
            }
        if constexpr (std::is_same_v<KeyType, string>) {
            int hash =0;
            for (int i =0; i < key.size(); i++) {
                hash = hash * 31 + static_cast<int>(key[i]);
            }
            return hash;
        }


        if constexpr (is_same_v<KeyType, bool> ) {
            if (key == true)return 1;
            return 0;
        }
        if constexpr (is_same_v<KeyType, char> ) {
            return static_cast<int>(key);
        }

        if constexpr  (is_same_v<KeyType, int*> || is_same_v<KeyType, double*> || is_same_v<KeyType, float*>
               || is_same_v<KeyType, long*> || is_same_v<KeyType, short*> || is_same_v<KeyType,signed*>) {
            return reinterpret_cast<size_t>(key);
               }

        throw std::runtime_error("Type Not Supported\n");
    };
public:
    void set(KeyType key,ValueType value) {
        int ourKey = HashFunction(key);
       Bucket newBucket;
        newBucket.key = ourKey;
        newBucket.value = value;
        for (int i =0; i<Buckets.size();i++) {
            if (Buckets[i].key == key) {
                Buckets[i].value = value;
                return;
            }
        }
        Buckets.push_back(newBucket);
    }
    HashMap()=default;
    ValueType operator[](KeyType key) {
        for (int i=0; i <Buckets.size();i++) {
            if (Buckets[i].key == key) {
                return Buckets[i].value;
            }
        }
        throw std::runtime_error("Key Not found\n");
    }
    void Display()
    {
        for (int i =0; i<Buckets.size();i++) {
            cout << "Bucket " << i << ". Key: "<<Buckets[i].key << " Value: " << Buckets[i].value << endl;
        }
    }

};


#endif //OMAR_STL_HASHMAP_HPP