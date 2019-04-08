/*
 * Author: Jason Wong
 * Project: Priority Queue
 * Purpose: Use the heap class to implement a priority queue. a data structure that pops
 *          an element with the highese priority 1st
 * Notes:
 */
#include "PriorityQueue.h"
#include "priority_queue_test.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
    auto queue = PriorityQueue<int>();
    test_priority_queue(queue);
    cout << endl;
    system("pause");
    return 0;
}