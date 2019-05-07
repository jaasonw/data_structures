#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace array {
// return the larger of the two items
template <typename T>
T maximal(const T& a, const T& b) {
    return (a > b) ? a : b;
}

// swap the two items
template <typename T>
void swap(T& a, T& b) {
    T t = a;
    a = b;
    a = t;
}
// return index of the largest item in data
template <typename T>
int index_of_maximal(T* data, int size) {
    int largest = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] > data[largest]) {
            largest = i;
        }
    }
    return largest;
}

// insert entry at index i in data
template <typename T>
void insert_item(T* data, int pos, int& size, const T& entry) {
    for (int i = ++size; i > pos; i--) {
        data[i] = data[i - 1];
    }
    data[pos] = entry;
}

// insert entry into the sorted array data with length n
template <typename T>
void ordered_insert(T* data, int& size, const T& entry) {
    int pos = 0;
    for (int i = 0; i < size; i++) {
        if (entry > data[i]) {
            pos = i + 1;
        }
    }
    insert_item(data, pos, size, entry);
}

// return the first element in data that is not less than entry
template <typename T>
int first_ge(const T* data, int size, const T& entry) {
    for (int i = 0; i < size; i++) {
        if (!(data[i] < entry)) {
            return i;
        }
    }
    return size;
}

// append entry to the right of data
template <typename T>
void attach_item(T* data, int& size, const T& entry) {
    data[size++] = entry;
}

// remove the last element in data and place it in entry
template <typename T>
T detach_item(T* data, int& size) {
    return data[--size];
}

// delete item at index i and place it in entry
template <typename T>
T delete_item(T* data, int i, int& size) {}

// append data2 to the right of data1
template <typename T>
void merge(T* data1, int& size1, T* data2, int& size2);

// move n/2 elements from the right of data1 and move to data2
template <typename T>
void split(T* data1, int& size1, T* data2, int& size2) {
    int size = size1;
    for (int i = ((size + 1) / 2); i < size; i++) {
        data2[i - ((size + 1) / 2)] = data1[i];
    }
    size1 = (size + 1) / 2;
    size2 = size - size1;
}

// copy src[] into dest[]
template <typename T>
void copy_array(const T src[], T dest[], int src_size, int& dest_size) {
    for (int i = 0; i < src_size; i++) {
        dest[i] = src[i];
    }
    dest_size = src_size;
}

// print array data
template <typename T>
void print_array(const T data[], int size, int level = 0,
                 std::ostream& outs = std::cout) {
    const int SPACING = 8;
    outs << std::string(level * SPACING, ' ');
    outs << '[' << ' ';
    for (int i = 0; i < size; i++) {
        outs << data[i] << " ";
    }
    outs << ']';
}

// item > all data[i]
template <typename T>
bool is_gt(const T data[], int size, const T& item);

// item <= all data[i]
template <typename T>
bool is_le(const T data[], int size, const T& item);

} // namespace array

//-------------- Vector Extra operators: ---------------------
// print vector list
template <typename T>
std::ostream& operator<<(std::ostream& outs, const std::vector<T>& list) {
    array::print_array(&list[0], list.size(), 0, outs);
    return outs;
}

// list.push_back item
template <typename T>
std::vector<T>& operator+=(std::vector<T>& list, const T& item) {
    list.push_back(item);
}