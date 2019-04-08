/*
 * Author: Jason Wong
 * Project: AVL Tree Class
 * Purpose: To implement the AVL Tree, a self balancing binary search tree
 * Notes:
 */
#include "AVLTree.h"
#include "tree_test.h"
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    auto tree = AVLTree<int>();
    test_tree(tree);
    cout << endl;
    system("pause");
    return 0;
}