#pragma once
#include "binary_search_tree_functions.h"

// Contains functions specific to manipulating AVL Trees
namespace avl {
    // rotates the tree to the right using a given root as a pivot
    // returns pointer to the new root of the tree/subtree
    template <typename T>
    binary_tree::Node<T>* rotate_right(binary_tree::Node<T>*& root) {
        binary_tree::Node<T>* temp_root = root;
        binary_tree::Node<T>* temp_right = root->left->right;
        root = root->left;
        temp_root->left = temp_right;
        root->right = temp_root;
        root->update_height();
        temp_root->update_height();
        return root;
    }

    // rotates the tree to the left using a given root as a pivot
    // returns pointer to the new root of the tree/subtree
    template <typename T>
    binary_tree::Node<T>* rotate_left(binary_tree::Node<T>*& root) {
        binary_tree::Node<T>* temp_root = root;
        binary_tree::Node<T>* temp_left = root->right->left;
        root = root->right;
        temp_root->right = temp_left;
        root->left = temp_root;
        root->update_height();
        temp_root->update_height();
        return root;
    }

    // inserts an item and balances the tree to be an AVL tree
    template <typename T>
    void insert(binary_tree::Node<T>*& root, const T& item) {
        // insert the thing
        if (root == nullptr)
            root = new binary_tree::Node<T>(item);
        else if (*root > item) {
            avl::insert(root->left, item);
            root->update_height();
        } else if (*root < item) {
            avl::insert(root->right, item);
            root->update_height();
        }

        // balance the tree
        while (root->balance_factor() > 1 && *(root->right) < item) {
            rotate_left(root);
        }
        while (root->balance_factor() < -1 && *(root->left) > item) {
            rotate_right(root);
        }
        while (root->balance_factor() > 1 && *(root->right) > item) {
            rotate_right(root->right);
            rotate_left(root);
        }
        while (root->balance_factor() < -1 && *(root->left) < item) {
            rotate_left(root->left);
            rotate_right(root);
        }
        root->update_height();
    }

}; // namespace avl