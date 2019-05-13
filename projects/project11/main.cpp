/*
 * Author: Jason Wong
 * Project: 
 * Purpose: 
 * Notes:
 */
#include "BTree.h"
#include "test/tree_test.h"
#include "test/three_test.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const* argv[]) {
    btree_big_three::test_assignment_operator();
    btree_big_three::test_copy_constructor();
    // it passes
    btree_big_three::test_delete();

    BTree<int> tree;
    interactive_test(tree);

    cout << endl;
    system("pause");
    return 0;
}