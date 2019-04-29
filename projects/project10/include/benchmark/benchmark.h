#pragma once
#include "Sort.h"
#include "util/Timer.h"
#include "util/sort_utility.h"
#include <iomanip>
#include <iostream>

template <typename T>
double time_sort(int a[], unsigned int size, void (*f)(int*, unsigned int)) {
    Timer t;
    t.start();
    f(a, size);
    t.stop();
    return t.duration<std::chrono::milliseconds>();
}

template <typename T>
double avg_runtime(void (*f)(int*, unsigned int), int num_items, int runs) {
    double avg = 0;
    int array[num_items];
    for (int i = 0; i < runs; i++) {
        randomize(array, num_items);
        avg += time_sort<T>(array, num_items, f);
    }
    return avg / runs;
}

void time_sort_routines() {
    std::cout << "average duration - quick_sort(50000): " << std::fixed
              << std::setprecision(5)
              << avg_runtime<milliseconds>(quick_sort, 50000, 500) << "ms"
              << std::endl;
    std::cout << "average duration - merge_sort(50000): " << std::fixed
              << std::setprecision(5)
              << avg_runtime<milliseconds>(merge_sort, 50000, 500) << "ms"
              << std::endl;
    std::cout << "average duration - heap_sort(50000): " << std::fixed
              << std::setprecision(5)
              << avg_runtime<milliseconds>(heap_sort, 50000, 500) << "ms"
              << std::endl;
    std::cout << "average duration - insertion_sort(50000): " << std::fixed
              << std::setprecision(5)
              << avg_runtime<milliseconds>(insertion_sort, 50000, 500) << "ms"
              << std::endl;
}