#pragma once
#include "AVLTree.h"
#include "Record.h"
#include <iomanip>
#include <iostream>
#include <vector>

template <typename T>
class ChainedHash {
public:
    static const int CAPACITY = 10;
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
                                    const ChainedHash<U>& hash);
private:
    // table chains
    AVLTree<Record<T>> _data[CAPACITY];
    // number of keys in the table
    int _size = 0;

    // hash function
    int hash(int key) const { return key % CAPACITY; }
    // find this key in the table
    // typename List<T>::Iterator find_node(int key) const;
};

template <typename T>
bool ChainedHash<T>::insert(int key, const T& value) {
    _data[hash(key)].insert(Record<T>(key, value));
    _size++;
    return true;
}

template <typename T>
bool ChainedHash<T>::remove(int key) {
    T item;
    bool key_found = get(key, item);
    _data[hash(key)].erase(Record<T>(key));
    if (key_found)
        --_size;
}

template <typename T>
bool ChainedHash<T>::get(int key, T& item) const {
    binary_tree::node_ptr<Record<T>> search;
    bool item_found = _data[hash(key)].search(Record<T>(key), search);
    if (item_found)
        item = search->_value;
    return item_found;
}

template <typename T>
bool ChainedHash<T>::key_exists(int key) const {
    binary_tree::node_ptr<T> search;
    return _data[hash(key)].search(Record<T>(key), search);
}

template <typename T>
T& ChainedHash<T>::operator[](int key) {
    binary_tree::node_ptr<Record<T>> search;
    bool item_found = _data[hash(key)].search(Record<T>(key), search);
    if (item_found)
        return search->_value;
    else
        insert(key, T());
    return operator[](key);
}

template <typename U>
std::ostream& operator<<(std::ostream& outs, const ChainedHash<U>& hash) {
    for (int i = 0; i < hash.CAPACITY; i++) {
        std::cout << '[' << std::setfill('0') << std::setw(3) << i << "] ";
        hash._data[i].print_in_order(std::cout);
        std::cout << std::endl;
    }
}