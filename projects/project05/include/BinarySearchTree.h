#pragma once
#include "binary_search_tree_functions.h"

template <typename T>
class BinarySearchTree {
private:
    binary_tree::Node<T>* root;

public:
    BinarySearchTree();
    BinarySearchTree(const T* sorted_array, int size);
    BinarySearchTree(const BinarySearchTree<T>& other);
    ~BinarySearchTree();
    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other);

    void insert(const T& item);
    void erase(const T& target);
    bool search(const T& target, binary_tree::Node<T>*& found_ptr);

    BinarySearchTree<T>& operator+=(const BinarySearchTree<T>& other);
    friend std::ostream& operator<<(std::ostream& outs,
                                    const BinarySearchTree<T>& tree) {
        binary_search_tree::print_debug(tree.root, 0, outs);
        return outs;
    }
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const T* sorted_array, int size) {
    root = binary_search_tree::create_from_sorted_list(sorted_array, size);
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) {
    root = binary_search_tree::copy(other.root);
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::
operator=(const BinarySearchTree<T>& other) {
    if (this == &other)
        return *this;
    binary_search_tree::clear(root);
    root = binary_search_tree::copy(other.root);
    return *this;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    binary_search_tree::clear(root);
}

template <typename T>
void BinarySearchTree<T>::insert(const T& item) {
    binary_search_tree::insert(root, item);
}

template <typename T>
void BinarySearchTree<T>::erase(const T& target) {
    binary_search_tree::erase(root, target);
}