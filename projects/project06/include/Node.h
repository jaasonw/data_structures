#pragma once
#include <algorithm>
#include <iostream>

// A generic node for binary trees
namespace binary_tree {
    template <typename T>
    struct Node {
        T data;
        Node<T>* left;
        Node<T>* right;
        int _height;

        Node(T data = T(), Node* left = nullptr, Node* right = nullptr)
            : data(data), left(left), right(right), _height(0) {
            update_height();
        }

        // balance factor = height of the right subtree - the height of the left
        // subtree
        // a NULL child has a height of -1
        // a leaf has a height of 0
        int balance_factor() {
            int left_height, right_height;
            left_height = (left == nullptr) ? -1 : left->_height;
            right_height = (right == nullptr) ? -1 : right->_height;
            return right_height - left_height;
        }

        // Height of a node is 1 + height of the "taller" child
        // A leaf node has a height of zero: 1 + max(-1,-1)
        int height() {
            int left_height, right_height;
            left_height = (left == nullptr) ? -1 : left->_height;
            right_height = (right == nullptr) ? -1 : right->_height;
            return 1 + std::max(left_height, right_height);
        }

        // set the _height member variable (call height();)
        int update_height() { return _height = height(); }

        friend std::ostream& operator<<(std::ostream& outs, const Node<T>& n) {
            outs << "|" << n.data << "|";
            return outs;
        }

        // a buuuunch of self explanatory comparisons
        bool operator<(const Node<T>& other) { return data < other.data; }
        bool operator<=(const Node<T>& other) { return data <= other.data; }
        bool operator>(const Node<T>& other) { return data > other.data; }
        bool operator>=(const Node<T>& other) { return data >= other.data; }

        bool operator<(const T& other_item) { return data < other_item; }
        bool operator<=(const T& other_item) { return data <= other_item; }
        bool operator>(const T& other_item) { return data > other_item; }
        bool operator>=(const T& other_item) { return data >= other_item; }

        bool operator==(const T& other_item) { return data == other_item; }
    };

    template <typename T>
    class node_ptr {
    private:
        Node<T>* ptr;
    public:
        node_ptr() { ptr = nullptr; }
        node_ptr(Node<T>* node) { ptr = node; }
        T& operator*() { return ptr->data; }
        T* operator->() { return &ptr->data; }
        friend bool operator==(const node_ptr& left, const node_ptr& right) {
            return left.ptr == right.ptr;
        }
        friend bool operator!=(const node_ptr& left, const node_ptr& right) {
            return left.ptr != right.ptr;
        }
        friend bool operator==(const node_ptr& left, const std::nullptr_t null) {
            return left.ptr == null;
        }
        friend bool operator!=(const node_ptr& left, const std::nullptr_t null) {
            return left.ptr != null;
        }
        bool is_null() { return ptr == nullptr; }
    };
} // namespace binary_tree