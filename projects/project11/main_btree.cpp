/*
 * Author: Jason Wong
 * Project: 
 * Purpose: 
 * Notes:
 */
#include "BTree.h"
#include "tree_test.h"
#include "../project12/include/Pair.h"
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    // int a[10] = {1,3,4,5,6};
    // int size = 5;
    // ordered_insert(a, size, 7);
    // print_array(a, size);

    // int a[5] = {80, 90, 100};
    // auto b = new int[5];
    // int size1 = 2;
    // int size2;
    // array::split(a, size1, b, size2);
    // array::print_array(a, size1);
    // cout << endl;
    // array::print_array(b, size2);

    // testing BTree
    BTree<int> node75;
    BTree<int> node2550;
    BTree<int> node100;
    BTree<int> node12;
    BTree<int> node30;
    BTree<int> node60;
    BTree<int> node80;
    BTree<int> node110;
    
    
    // // dont autoformat this thx
    //                                                     node75.data[0] = 75;
    //                                                     node75.data_size = 1;
    //                                                     node75.child_size = 2;
    //                                                     node75.subset[0] = &node2550;
    //                                                     node75.subset[1] = &node100;

    //                     node2550.data[0] = 25;                                          node100.data[0] = 100;
    //                     node2550.data[1] = 50;                                          node100.data_size = 1;
    //                     node2550.data_size = 2;                                         node100.child_size = 2;
    //                     node2550.child_size = 3;                                        node100.subset[0] = &node80;
    //                     node2550.subset[0] = &node12;                                   node100.subset[1] = &node110;
    //                     node2550.subset[1] = &node30;
    //                     node2550.subset[2] = &node60;

    // node12.data[0] = 12;    node30.data[0] = 30;    node60.data[0] = 60;        node80.data[0] = 80;        node110.data[0] = 110;
    // node12.data_size = 1;   node30.data_size = 1;   node60.data_size = 1;       node80.data_size = 1;       node110.data_size = 1;

    // node75.print_tree();
    // cout << "===========================================================";
    // cout << endl;
    // cout << endl;
    // node75.insert(90);
    // node75.print_tree();
    // cout << "===========================================================";
    // cout << endl;
    // cout << endl;
    // node75.insert(95);
    // node75.print_tree();
    // cout << "===========================================================";
    // cout << endl;
    // cout << endl;
    // node75.insert(101);
    // node75.print_tree();
    // cout << "===========================================================";
    // cout << endl;
    // cout << endl;
    // node75.insert(111);
    // node75.print_tree();
    // cout << "===========================================================";
    // cout << endl;
    // cout << endl;
    // node75.insert(81);
    // node75.print_tree();
    BTree<int> tree(false);
    // test_tree(tree);
    tree.insert(75);
    tree.insert(100);
    tree.insert(25);
    tree.insert(50);
    tree.insert(110);
    tree.insert(80);
    tree.insert(12);
    tree.insert(30);
    tree.insert(60);
    tree.print_tree();

    // auto item = ;
    const auto a =tree.get(60);
    cout << tree.get(60) << endl;

    cout << endl;
    system("pause");
    return 0;
}