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
        int i = findKey(key);
        if (i != -1) {
            Buckets[i].value = value;
            return;
        }

        Buckets.push_back(newBucket);
    }
    HashMap()=default;
    ValueType& operator[](KeyType key) {
       int idx = findKey(key);
        if (idx != -1)return Buckets[idx].value;

        set(key,ValueType());
        for (int i=0; i<Buckets.size();i++)
        { if (Buckets[i].key == key) {
            return Buckets[i].value;
        }}
        throw std::runtime_error("operator[] insertion failed");
    }
    void Display()
    {
        for (int i =0; i<Buckets.size();i++) {
            cout << "Bucket " << i << ". Key: "<<Buckets[i].key << " Value: " << Buckets[i].value << endl;
        }
    }
    void Delete(KeyType key) {
       int i =findKey(key);
       if (i != -1){Buckets.erase(Buckets.begin() + i);return;}
        cout << "key Not found\n";
    }
    int findKey(KeyType key) {
        for (int i=0; i<Buckets.size(); i++)
        if (Buckets[i].key==key) return i;

    return -1;
    }
    void clear()
    {Buckets.clear();}
    bool contains(KeyType key) {
        int i =findKey(key);
        if (i != -1)return true;
return false;
    }
    int size(){return Buckets.size();};
    int maxSize(){return Buckets.capacity();}
    bool Empty() {return Buckets.empty();}
    void remove(const int idx) {
        for (int i =0; i < Buckets.size(); i++)
            {
            if (idx==i) {Buckets.erase(Buckets.begin() + i);
            return;}
            }

        cout << "Index not found\n";
    }
    HashMap(const HashMap& other) {
    Buckets = other.Buckets;
}
    HashMap& operator=(const HashMap& other) {
    if (this != &other) {
        Buckets = other.Buckets;
    }
    return *this;
}
    friend ostream& operator<<(ostream& os, const HashMap<int, string>& map){
        for (const auto& bucket : map.Buckets) {
            os << "Key: " << bucket.key << ", Value: " << bucket.value << endl;
        }
        return os;
    }


    HashMap operator+( HashMap& map) {
        HashMap newMap;
        for (int i =0; i<size(); i++)newMap.Buckets.push_back(this->Buckets[i]);
       for (int i =0; i<map.size(); i++) newMap.Buckets.push_back(map.Buckets[i]);

        return newMap;
    }
};



#endif //OMAR_STL_HASHMAP_HPP