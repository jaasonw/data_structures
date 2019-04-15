#pragma once
#include "AVLTree.h"
#include "Record.h"
#include <iomanip>
#include <iostream>
#include <vector>

template <typename T>
class OpenHash {
public:
    static const int CAPACITY = 10000;
    // insert entry
    bool insert(int key, const T& value);
    // remove this key
    bool remove(int key);

    // gets the value at key and inserts it at item, returns true if found
    // (read only)
    bool get(int key, T& item) const;
    // is this key present in table?
    bool key_exists(int key) const;
    // number of keys in the table
    int size() const { return _size; }
    // gets the value at a key and returns a reference to it, initializes and
    // inserts if not found (to emulate an array with infinite size hash[n] = x)
    T& operator[](int key);
    // print entire table with keys, etc.
    template <typename U>
    friend std::ostream& operator<<(std::ostream& outs,
                                    const OpenHash<U>& hash);
private:
    // table chains
    Record<T> _data[CAPACITY];
    // number of keys in the table
    int _size = 0;

    // hash function
    int hash(int key) const { return key % CAPACITY; }
    // check if space is occupied 
    bool space_occupied(int index) const {
        return _data[index]._key == 0 && _data[index]._value == T();
    }
    // find this key in the table
    // typename List<T>::Iterator find_node(int key) const;
};

template <typename T>
bool OpenHash<T>::insert(int key, const T& value) {
    int index = hash(key);
    for (; !space_occupied(index); index++) {
        if (index >= CAPACITY)
            return false;
    }
    _data[index] = Record<T>(key, value);
    _size++;
    return true;
}

template <typename T>
bool OpenHash<T>::remove(int key) {
    int index = hash(key);
    if (space_occupied(index))
        --_size;
    else
        return false;
    _data[index] = Record<T>();
    return true;
}

template <typename T>
bool OpenHash<T>::get(int key, T& item) const {
    item = _data[hash(key)]._value;
    return (space_occupied(hash(key))) ? true : false;
}

template <typename T>
bool OpenHash<T>::key_exists(int key) const {
    return space_occupied(hash(key));
}

template <typename T>
T& OpenHash<T>::operator[](int key) {
    return _data[hash(key)];
}

template <typename U>
std::ostream& operator<<(std::ostream& outs, const OpenHash<U>& hash) {
    for (int i = 0; i < hash.CAPACITY; i++) {
        std::cout << '[' << std::setfill('0') << std::setw(3) << i << "] ";
        std::cout << hash._data[i];
        std::cout << std::endl;
    }
}