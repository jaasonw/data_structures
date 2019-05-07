/*
 * Author: Jason Wong
 * Project: 
 * Purpose: 
 * Notes:
 */
#include "Map.h"
#include "MultiMap.h"
#include "array_util.h"
#include <iostream>

using namespace std;

void test(const Map::Map<int, int> test) {
    cout << test[75];
}

int main(int argc, char const* argv[]) {
    // Map Test
    Map::Map<int, int> test1;
    test1.set(75, 10);
    test1.set(100, 10);
    test1.set(25, 10);
    test1.set(50, 10);
    test1.set(110, 10);
    test1.set(80, 10);
    test1.set(12, 10);
    test1.set(30, 10);
    test1.set(60, 10);
    cout << test1 << endl;

    test1.at(75) = 11;
    cout << test1[75] << endl;
    test1[69] = 12;
    cout << test1[69] << endl;

    test(test1);

    // MultiMap Test
    // MultiMap::MultiMap<int, int> test2;

    // test2.insert(5, 7);
    // test2[5] += 9;
    // test2[5].push_back(10);
    // test2.insert(9, 10);
    // test2.insert(7, 20);

    // cout << test2[5] << endl;
    // cout << test2 << endl;

    cout << endl;
    system("pause");
    return 0;
}