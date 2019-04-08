/*
 * Author: Jason Wong
 * Project: Heap Class
 * Purpose: Implement the a heap, a data structure that uses an array represented as a
 *          binary tree every element is larger than its 2 child element. Used to
 *          implement a priority queue
 * Notes:
 */
#include "Heap.h"
#include "heap_test.h"
#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    auto heap = Heap<int>();
    test_heap(heap);
    cout << endl;
    system("pause");
    return 0;
}