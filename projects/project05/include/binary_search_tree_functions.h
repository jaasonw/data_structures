#pragma once
#include "Node.h"

// Contains functions specific to manipulating binary search trees
namespace binary_search_tree {
    // inserts an item into the tree
    template <typename T>
    void insert(binary_tree::Node<T>*& root, const T& item) {
        if (root == nullptr)
            root = new binary_tree::Node<T>(item);
        else if (*root > item) {
            insert(root->left, item);
            root->update_height();
        } else if (*root < item) {
            insert(root->right, item);
            root->update_height();
        } else {
            root->data = item;
        }
    }

    // returns a pointer to a node containing the item in the tree
    // returns null if item not found
    template <typename T>
    binary_tree::Node<T>* search(binary_tree::Node<T>* root, const T& target) {
        if (root == nullptr)
            return nullptr;
        else if (*root == target)
            return root;
        else if (*root < target)
            return search(root->right, target);
        else if (*root > target)
            return search(root->left, target);
        else
            return nullptr;
    }

    // prints the tree
    template <typename T>
    void print(const binary_tree::Node<T>* root, int level = 0,
               std::ostream& outs = std::cout) {
        if (root == nullptr) {
            outs << "|empty tree|" << std::endl;
            return;
        }
        if (root->right != nullptr)
            print(root->right, level + 1);

        for (int i = 0; i < level; i++)
            outs << "    ";
        outs << *root << std::endl;

        if (root->left != nullptr)
            print(root->left, level + 1);
    }

    // prints the tree with (height, balance factor) next to each node
    template <typename T>
    void print_debug(binary_tree::Node<T>* root, int level = 0,
                     std::ostream& outs = std::cout) {
        if (root == nullptr) {
            outs << "|empty tree|" << std::endl;
            return;
        }
        if (root->right != nullptr)
            print_debug(root->right, level + 1);

        for (int i = 0; i < level; i++)
            outs << "    ";
        outs << *root << '(' << root->_height << ',' << root->balance_factor()
             << ')' << std::endl;

        if (root->left != nullptr)
            print_debug(root->left, level + 1);
    }

    // frees all nodes on the tree and sets root to null
    template <typename T>
    void clear(binary_tree::Node<T>*& root) {
        if (root == nullptr)
            return;
        if (root->right != nullptr) {
            clear(root->right);
        }
        if (root->left != nullptr) {
            clear(root->left);
        }
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
    }

    // returns a pointer to the largest node beneath root
    template <typename T>
    binary_tree::Node<T>* get_max(binary_tree::Node<T>* root) {
        if (root->right != nullptr)
            return get_max(root->right);
        return root;
    }

    // erases the max node from the given root and stores the item in max_value
    template <typename T>
    void remove_max(binary_tree::Node<T>*& root, T& max_value) {
        if (root->right != nullptr) {
            remove_max(root->right, max_value);
            root->update_height();
        } else if (root->left != nullptr && root->right == nullptr) {
            max_value = root->data;
            *root = *root->left;
            delete root->left;
            root->update_height();
        } else {
            max_value = root->data;
            binary_tree::Node<T>* temp = root;
            root = nullptr;
            delete temp;
        }
    }

    // erases an item from the tree
    // returns true if item was successfully erased
    // returns false if item not found
    template <typename T>
    bool erase(binary_tree::Node<T>*& root, const T& target) {
        // we probably didnt find anything
        if (root == nullptr)
            return false;
        if (*root < target) {
            bool item_erased = erase(root->right, target);
            root->update_height();
            return item_erased;
        } else if (*root > target) {
            bool item_erased = erase(root->left, target);
            root->update_height();
            return item_erased;
        } else if (*root == target) {
            if (root->left != nullptr && root->right != nullptr) {
                T max_value;
                remove_max(root->left, max_value);
                root->data = max_value;
            } else if (root->left != nullptr && root->right == nullptr) {
                binary_tree::Node<T>* temp = root;
                root = root->left;
                delete temp;
            } else if (root->left == nullptr && root->right != nullptr) {
                binary_tree::Node<T>* temp = root;
                root = root->right;
                delete temp;
            } else {
                // no children
                delete root;
                root = nullptr;
            }
            root->update_height();
            return true;
        }
        // getting here isnt very likely but if it ever happens, return false
        return false;
    }

    // creates a copy of a tree given a root
    // returns a pointer to the root of the new tree
    template <typename T>
    binary_tree::Node<T>* copy(binary_tree::Node<T>* root) {
        if (root == nullptr)
            return nullptr;
        root = new binary_tree::Node<T>(root->data, copy(root->left),
                                        copy(root->right));
        return root;
    }

    // creates a tree from a sorted array
    // returns a pointer to the root of the created tree
    template <typename T>
    binary_tree::Node<T>* create_from_sorted_list(const T* array, int size) {
        if (size == 0)
            return nullptr;
        binary_tree::Node<T>* root;
        if (size > 1) {
            root = new binary_tree::Node<T>(
                array[size / 2], create_from_sorted_list(array, size / 2),
                create_from_sorted_list(&array[size / 2 + 1], (size - 1) / 2));
        } else
            root = new binary_tree::Node<T>(array[size / 2]);
        root->update_height();
        return root;
    }

    // Add tree src to dest
    template <typename T>
    void add(binary_tree::Node<T>*& dest, const binary_tree::Node<T>* src) {
        if (src == nullptr)
            return;
        dest.insert(src->data);
        add(dest, src->right);
        add(dest, src->left);
    }
}; // namespace binary_search_tree