#include "binary_search_tree_functions.h"
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const* argv[]) {
    // create from sorted list
    cout << "CREATE FROM SORTED LIST" << endl;
    int sorted[] = {1,2,3,4,5,6,7,8,9,10};
    auto tree = binary_search_tree::create_from_sorted_list(sorted, 10);
    binary_search_tree::print(tree);
    cout << endl;
    cout << endl;

    cout << "INSERT ITEMS" << endl;
    binary_search_tree::insert(tree, 11);
    binary_search_tree::insert(tree, 12);
    binary_search_tree::insert(tree, 13);
    binary_search_tree::print(tree);
    cout << endl;
    cout << endl;

    cout << "ERASE 10" << endl;
    binary_search_tree::erase(tree, 10);
    binary_search_tree::print(tree);
    cout << endl;
    cout << endl;
    cout << "ERASE 5" << endl;
    binary_search_tree::erase(tree, 5);
    binary_search_tree::print(tree);
    cout << endl;
    cout << endl;
    cout << "ERASE 9" << endl;
    binary_search_tree::erase(tree, 5);
    binary_search_tree::print(tree);
    cout << endl;
    cout << endl;

    system("pause");
    return 0;
}