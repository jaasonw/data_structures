/*
 * Author: Jason Wong
 * Project: BST Class
 * Purpose: To implement functions to manipulate a binary search tree and a 
 *          class wrapper around them
 * Notes:
 */
#include "BinarySearchTree.h"
#include "tree_test.h"
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    auto tree = BinarySearchTree<int>();
    test_tree(tree);
    cout << endl;
    system("pause");
    return 0;
}