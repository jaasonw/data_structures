// TODO
// big 3
// delete
// 

#pragma once
#include "array_util.h"
#include <cassert>
#include <exception>
#include <iostream>
#include <string>

// #define DEBUG

template <typename T>
class BTree {

private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    // number of data elements
    int data_size = 0;

    // number of children
    int child_size = 0;

    // max data capacity
    static const int DATA_CAPACITY = MAXIMUM + 1;
    // max subset capacity
    static const int SUBSET_CAPACITY = MAXIMUM + 2;

    // holds the keys
    T data[DATA_CAPACITY] = {T()};

    // subtrees
    BTree* subset[SUBSET_CAPACITY] = {nullptr};
    // true if duplicate keys may be inserted
    bool duplicates_allowed;

    // true if this is a leaf node
    bool is_leaf() const { return child_size == 0; }

    // insert element functions
    // allows MAXIMUM+1 data elements in the root
    void loose_insert(const T& entry);
    // fix excess of data elements in child i
    void fix_excess(int i);

    // remove element functions:
    // allows MINIMUM-1 data elements in the root
    void loose_remove(const T& entry);
    // fix shortage of data elements in child i
    void fix_shortage(int i);

    // remove the biggest child of this tree->entry
    void remove_biggest(T& entry);
    // transfer one element LEFT from child i
    void rotate_left(int i);
    // transfer one element RIGHT from child i
    void rotate_right(int i);
    // merge subset i with subset i+1
    void merge_with_next_subset(int i);

public:
    BTree(bool duplicates_allowed = false);
    BTree(const BTree<T>& other);
    ~BTree();
    BTree<T>& operator=(const BTree<T>& other);

    // insert entry into the tree
    void insert(const T& entry);
    // remove entry from the tree
    void remove(const T& entry);

    // clear this object (delete all nodes etc.)
    void clear_tree();
    // copy other into this object
    void copy_tree(const BTree<T>& other);

    // true if entry can be found in the array
    bool contains(const T& entry) const;
    // return a const reference to entry in the tree
    const T& get(const T& entry) const;
    // return a reference to entry in the tree
    T& get(const T& entry);
    // return a pointer to this key. NULL if not there.
    T* find(const T& entry);

    // count the number of elements in the tree
    int size() const;
    // true if the tree is empty
    bool empty() const;

    //print a readable version of the tree
    void print_tree(std::ostream& outs = std::cout, int level = 0) const;

    friend std::ostream& operator<<(std::ostream& outs, const BTree<T>& tree){
        tree.print_tree();
        return outs;
    }
};

template <typename T>
BTree<T>::BTree(bool dupes_allowed) : duplicates_allowed(dupes_allowed) {
}

// TODO: FINISH WORKING ON THIS
template <typename T>
BTree<T>::BTree(const BTree<T>& other) {
    // copy root
    array::copy_array(other.data, data, other.data_size, data_size);
    child_size = other.child_size;
    for (int i = 0; i < other.child_size; i++) {

    }
}

template<typename T>
BTree<T>::~BTree() {
    for (int i = 0; i < child_size; i++) {
        delete subset[i];
    }
}

template <typename T>
void BTree<T>::print_tree(std::ostream& outs, int level) const {
    // if not leaf keep recursioning down until it is
    if (child_size > 1) {
        // print half of the subset backwards
        for (int i = child_size - 1; i >= child_size / 2; i--) {
            if (subset[i] != nullptr)
                subset[i]->print_tree(outs, level + 1);
        }
    }

    // print the parent dataset
    array::print_array(data, data_size, level, outs);
    outs << std::endl;

    if (child_size > 1) {
        // print the other half
        for (int i = (child_size / 2) - 1; i >= 0; i--) {
            if (subset[i] != nullptr)
                subset[i]->print_tree(outs, level + 1);
        }
    }
}
template <typename T>
void BTree<T>::loose_insert(const T& entry) {
    int index = array::first_ge(data, data_size, entry);
    if (!is_leaf())
        subset[index]->loose_insert(entry);
    else {
        if (data[index] != entry)
            array::insert_item(data, index, data_size, entry);
        else if (data[index] == entry && duplicates_allowed)
            data[index] += entry;
        else
            data[index] = entry;
        return;
    }
    if (subset[index]->data_size > MAXIMUM) {
        fix_excess(index);
    }
}
template <typename T>
void BTree<T>::insert(const T& entry) {
    // the function that called this has to be root
    loose_insert(entry);
    // so do root checks here
    if (data_size > MAXIMUM) {
        // create new temp node
        BTree<T>* temp = new BTree<T>(duplicates_allowed);
        // copy data to temp node
        array::copy_array(data, temp->data, data_size, temp->data_size);
        array::copy_array(subset, temp->subset, child_size, temp->child_size);
        // zero out root data
        data_size = 0;
        child_size = 0;
        for (int i = 0; i < SUBSET_CAPACITY; i++) {
            if (i < DATA_CAPACITY)
                data[i] = T();
            subset[i] = nullptr;
        }
        // point root to temp
        subset[0] = temp;
        child_size = 1;
        // call fix_excess
        fix_excess(0);
    }
}

template <typename T>
void BTree<T>::fix_excess(int index) {
    BTree<T>* node = subset[index];
    // dont do anything, why are we even here to begin with?
    if (node->data_size <= MAXIMUM)
        return;
    BTree<T>* split = new BTree<T>(duplicates_allowed);
    // split data and child
    array::split(node->data, node->data_size, split->data, split->data_size);
    array::split(node->subset, node->child_size, split->subset,
                 split->child_size);
    // insert the last item into self
    T item = array::detach_item(node->data, node->data_size);
    array::ordered_insert(data, data_size, item);
    // if (subset[index] == nullptr)
    //     array::insert_item(subset, index, child_size, split);
    // else
        array::insert_item(subset, index + 1, child_size, split); 
}

template <typename T>
const T& BTree<T>::get(const T& entry) const {
    std::cout << "const version called" << std::endl;
    int index = array::first_ge(data, data_size, entry);
    if (data[index] == entry)
        return data[index];
    if (data[index] != entry && subset[index] == nullptr)
        throw std::out_of_range("Item not in tree");
    else {
        return subset[index]->get(entry);
    }
}

template <typename T>
T& BTree<T>::get(const T& entry) {
    std::cout << "not const version called" << std::endl;
    T* item = find(entry);
    if (item == nullptr)
        insert(entry);
    return *find(entry);
}

template <typename T>
T* BTree<T>::find(const T& entry) {
    int index = array::first_ge(data, data_size, entry);
    if (data[index] == entry)
        return &data[index];
    if (data[index] != entry && is_leaf())
        return nullptr;
    else
        return subset[index]->find(entry);
}
template <typename T>
bool BTree<T>::contains(const T& entry) const  {
    for (int i = 0; i < data_size; i++) {
        if (data[i] == entry)
            return true;
    }
    return false;
}