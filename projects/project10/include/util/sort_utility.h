#pragma once
#include "util/Random.h"
#include <algorithm>
#include <iostream>

// shuffles the content in an array
template <typename T>
void shuffle(T* array, int size) {
    Random r;
    for (int i = 0; i < size; i++) {
        std::swap(array[i], array[r.getNext(0, size - 1)]);
    }
}

// fills the array with random values between 1 - 10
template <typename T>
void randomize(T* array, int size) {
    Random r;
    for (int i = 0; i < size; i++) {
        array[i] = r.getNext(0, 10);
    }
}

// verifies if an array is ascending or decending order
template <typename T>
bool is_sorted(T* array, int size, bool ascending = true) {
    for (int i = 0; i < size - 1; i++) {
        if (ascending) {
            if (array[i] > array[i + 1])
                return false;
        }
        else {
            if (array[i] < array[i + 1])
                return false;
        }
    }
    return true;
}

// verifies if an array is ascending or decending order
// returns a cstring for sorted or not sorted
template <typename T>
const char* is_sorted_str(T* array, int size, bool ascending = true) {
    return is_sorted(array, size, ascending) ? "SORTED" : "NOT SORTED";
}

// prints the array
template <typename T>
std::ostream& print_array(T* array, int size, std::ostream& outs = std::cout) {
    for (int i = 0; i < size; i++) {
        outs << array[i] << " ";
    }
    return outs;
}