#include "Node.h"
#include <cctype>
#include <cmath>
#include <iostream>

template <typename T>
void test_tree(T& tree) {
    while (true) {
        char input;
        std::cout << "[R]andom  [I]nsert  [C]lear  [S]earch   e[X]it: ";
        std::cin >> input;
        switch (tolower(input)) {
            case 'r':
                tree.insert(rand() % 100);
                break;
            case 'i': {
                int input;
                std::cin >> input;
                tree.insert(input);
                break;
            }
            case 'c':
                tree = T();
                break;
            case 's': {
                int input;
                std::cin >> input;
                binary_tree::Node<int>* search = nullptr;
                if (tree.search(input, search)) {
                    std::cout << "item found: " << *search << " at " << search
                              << std::endl;
                } else {
                    std::cout << "item not found" << std::endl;
                }
                break;
            }
            case 'x':
                return;
            default:
                std::cout << "invalid input" << std::endl;
        }
        std::cout << tree;
    }
}