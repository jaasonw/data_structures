#pragma once
#include "benchmark/benchmark.h"
#include "util/Timer.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

void create_spreadsheet() {

    std::cout << "Measuring Performance" << std::endl;
    std::stringstream csv;

    Timer timer;
    csv << "Number of items, Bubble Sort, Quick Sort, Heap Sort, Insertion "
           "Sort, Merge Sort"
        << std::endl;
    timer.start();
    for (int number_items = 10; number_items <= 10000; number_items += 100) {
        int number_runs = 30;
        // Bubble sort
        csv << number_items << ", ";
        csv << std::fixed << std::setprecision(5)
            << avg_runtime<microseconds>(bubble_sort, number_items, number_runs)
            << ", ";
        // Quick Sort
        csv << std::fixed << std::setprecision(5)
            << avg_runtime<microseconds>(quick_sort, number_items, number_runs)
            << ", ";
        // Heap Sort
        csv << std::fixed << std::setprecision(5)
            << avg_runtime<microseconds>(heap_sort, number_items, number_runs)
            << ", ";
        // Insertion Sort
        csv << std::fixed << std::setprecision(5)
            << avg_runtime<microseconds>(insertion_sort, number_items, number_runs)
            << ", ";
        // Merge Sort
        csv << std::fixed << std::setprecision(5)
            << avg_runtime<microseconds>(merge_sort, number_items, number_runs)
            << ", ";
        csv << std::endl;
    }
    timer.stop();

    std::cout << "Time elapsed: " << timer.duration<seconds>()
              << " seconds" << std::endl;

    std::cout << "Writing to file" << std::endl;
    std::ofstream csv_file;
    csv_file.open("times.csv");
    csv_file << csv.str();
    csv_file.close();
    std::cout << "Done" << std::endl;
}

void create_spreadsheet_merge_vs_quick() {
    std::cout << "Measuring Performance" << std::endl;
    std::stringstream csv;

    Timer timer;
    csv << "Number of items, Quick Sort, Merge Sort" << std::endl;
    timer.start();
    for (int number_items = 10; number_items <= 50000; number_items += 50) {
        int number_runs = 1;
        // Quick Sort
        csv << number_items << ", ";
        csv << std::fixed << std::setprecision(5)
            << avg_runtime<microseconds>(quick_sort, number_items, number_runs)
            << ", ";
        // Merge Sort
        csv << std::fixed << std::setprecision(5)
            << avg_runtime<microseconds>(merge_sort, number_items, number_runs)
            << ", ";
        csv << std::endl;
    }
    timer.stop();

    std::cout << "Time elapsed: " << timer.duration<seconds>()
              << " seconds" << std::endl;

    std::cout << "Writing to file" << std::endl << std::endl;
    std::ofstream csv_file;
    csv_file.open("times2.csv");
    csv_file << csv.str();
    csv_file.close();
}