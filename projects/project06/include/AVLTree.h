#pragma once
#include "avl_functions.h"

template <typename T>
class AVLTree {
private:
    binary_tree::Node<T>* root;
    unsigned int _size = 0;
public:
    AVLTree();
    AVLTree(const T* sorted_array, int size);
    AVLTree(const AVLTree<T>& other);
    ~AVLTree();
    AVLTree<T>& operator=(const AVLTree<T>& other);

    void insert(const T& item);
    void erase(const T& target);
    bool search(const T& target, binary_tree::node_ptr<T>& found_ptr) const;
    unsigned int size() const { return _size; };
    void print_in_order(std::ostream& outs = std::cout) const {
        binary_search_tree::print_in_order(root, outs);
    }

    AVLTree<T>& operator+=(const AVLTree<T>& other) {
        binary_search_tree::add(root, other.root);
    }
    friend std::ostream& operator<<(std::ostream& outs,
                                    const AVLTree<T>& tree) {
        binary_search_tree::print(tree.root, 0, outs);
        return outs;
    }
};

template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template <typename T>
AVLTree<T>::AVLTree(const T* sorted_array, int size) {
    root = binary_search_tree::create_from_sorted_list(sorted_array, size);
}

template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T>& other) {
    root = binary_search_tree::copy(other.root);
}

template <typename T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T>& other) {
    if (this == &other)
        return *this;
    binary_search_tree::clear(root);
    root = binary_search_tree::copy(other.root);
    return *this;
}

template <typename T>
AVLTree<T>::~AVLTree() {
    binary_search_tree::clear(root);
}

template <typename T>
void AVLTree<T>::insert(const T& item) {
    avl::insert(root, item);
    ++_size;
}

template <typename T>
void AVLTree<T>::erase(const T& target) {
    avl::erase(root, target) ? --_size : _size;
}

template <typename T>
bool AVLTree<T>::search(const T& target, binary_tree::node_ptr<T>& found_ptr) const {
    found_ptr = binary_tree::node_ptr<T>(binary_search_tree::search(root, target));
    return found_ptr != nullptr;
}