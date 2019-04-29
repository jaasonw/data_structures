/*
 * Author: Jason Wong
 * Project: Sort Functions / Timing Sort Functiions
 * Purpose: To implement and time the performance of a few sorting algorithms
 * Notes:
 */
#include "benchmark/spreadsheet.h"
#include "benchmark/benchmark.h"
#include "util/test_sorts.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
    test_all_sorts();
    time_sort_routines();
    create_spreadsheet();

    // press any key to continue
    cout << endl;
    system("pause");
    return 0;
}