/*
 * Author: Jason Wong
 * Project: 
 * Purpose: 
 * Notes:
 */
#include "ChainedHash.h"
#include "test_hash.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const* argv[]) {
    ChainedHash<string> table;
    interactive_test(table);

    cout << endl;
    system("pause");
    return 0;
}