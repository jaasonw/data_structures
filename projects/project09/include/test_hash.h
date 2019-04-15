#pragma once
#include "ChainedHash.h"
#include "OpenHash.h"
#include <cctype>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iostream>

std::string generate_random_string() {
    std::string alphanum =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz123456789";
    std::string result = "";
    for (int i = 0; i < 5; i++) {
        result += alphanum.at(rand() % (alphanum.size() - 1));
    }
    return result;
}

template <typename T>
void benchmark_hash(T& table) {
    srand(time(0));
    const unsigned int NUM_ITEMS = 10000;

    // BENCHMARK INSERTIONS
    std::cout << "Inserting " << NUM_ITEMS << " items: ";
    auto t0 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ITEMS; i++) {
        table.insert(i, generate_random_string());
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << duration << " microseconds" << std::endl;

    // BENCHMARK RETRIEVALS
    std::cout << "Retrieving " << NUM_ITEMS << " items: ";
    t0 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_ITEMS; i++) {
        std::string item;
        // table.get(i, item);
        table.get(rand() % (NUM_ITEMS - 1), item);
    }
    t1 = std::chrono::high_resolution_clock::now();
    duration =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << duration << " microseconds" << std::endl;

    // BENCHMARK CLEARING
    std::cout << "Removing " << NUM_ITEMS << " items: ";
    t0 = std::chrono::high_resolution_clock::now();
    table = T();
    for (int i = 0; i < NUM_ITEMS; i++) {
        std::string item;
        table.remove(i);
        // table.get(rand() % (NUM_ITEMS - 1), item);
    }
    t1 = std::chrono::high_resolution_clock::now();
    duration =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << duration << " microseconds" << std::endl;
}

template <typename T>
void interactive_test(T& table) {
    srand(time(0));
    while (true) {
        char input;
        std::cout << "[S]ize [B]enchmark [R]andom [F]ind [I]nsert [C]lear [D]elete e[X]it: ";
        std::cin >> input;
        switch (tolower(input)) {
            case 'r': {
                int random_key = rand() % 100;
                std::string random_string = generate_random_string();
                table.insert(random_key, random_string);
                std::cout << Record<std::string>(random_key, random_string);
                std::cout << " inserted" << std::endl;
                break;
            }
            case 'i': {
                int key;
                std::string value;
                std::cin >> key;
                std::cin >> value;
                table.insert(key, value);
                std::cout << Record<std::string>(key, value);
                std::cout << " inserted" << std::endl;
                break;
            }
            case 'c':
                table = T();
                break;
            case 'd': {
                int key;
                std::cin >> key;
                table.remove(key);
                break;
            }
            case 'b': {
                ChainedHash<std::string> chained;
                OpenHash<std::string> open;

                std::cout << "- - - - - Open Hash Test - - - - -" << std::endl;
                benchmark_hash(open);
                std::cout << std::endl;

                std::cout << "- - - - - Chained Hash Test - - - - -" << std::endl;
                benchmark_hash(chained);
                std::cout << std::endl;
                break;
            }
            case 's':
                std::cout << "Table size: " << table.size() << std::endl;
                break;
            case 'x':
                return;
            default:
                std::cout << "invalid input" << std::endl;
        }
        std::cout << table;
    }
}