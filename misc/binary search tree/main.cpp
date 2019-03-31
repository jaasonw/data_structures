#include "binary_search_tree_functions.h"
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const* argv[]) {
    int sorted[] = {1,2,3,4,5,6,7,8,9,10};
    auto tree = binary_search_tree::create_from_sorted_list(sorted, 10);
    cout << tree;
    cout << endl;
    system("pause");
    return 0;
}