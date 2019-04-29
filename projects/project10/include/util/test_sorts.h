#pragma once
#include "Sort.h"
#include "util/sort_utility.h"
#include <iostream>

void test_sort(void (*f)(int*, unsigned int), bool ascending) {
    const int SIZE = 20;
    int array[SIZE];
    randomize(array, SIZE);
    std::cout << "BEFORE: ";
    print_array(array, SIZE) << std::endl;
    f(array, SIZE);
    std::cout << "AFTER: ";
    print_array(array, SIZE) << std::endl;
    std::cout << is_sorted_str(array, SIZE, ascending) << std::endl << std::endl;
}

void test_all_sorts() {
    std::cout << "BUBBLE SORT" << std::endl;
    test_sort(bubble_sort, true);
    std::cout << "INSERTION SORT" << std::endl;
    test_sort(insertion_sort, true);
    std::cout << "HEAP SORT" << std::endl;
    test_sort(heap_sort, false);
    std::cout << "MERGE SORT" << std::endl;
    test_sort(merge_sort, true);
    std::cout << "QUICK SORT" << std::endl;
    test_sort(quick_sort, true);
}