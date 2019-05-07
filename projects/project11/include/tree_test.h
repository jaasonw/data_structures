#include <cctype>
#include <cmath>
#include <iostream>

template <typename T>
void test_tree(T& tree) {
    while (true) {
        char input;
        std::cout << "[R]andom [G]enerate [I]nsert  [C]lear  [S]earch   e[X]it: ";
        std::cin >> input;
        switch (tolower(input)) {
            case 'r':
                tree.insert(rand() % 100);
                break;
            case 'g':
                tree.insert(75);
                tree.insert(100);
                tree.insert(25);
                tree.insert(50);
                tree.insert(110);
                tree.insert(80);
                tree.insert(12);
                tree.insert(30);
                tree.insert(60);
                break;
            case 'i': {
                int input;
                std::cin >> input;
                tree.insert(input);
                break;
            }
            case 'c':
                // tree = T();
                break;
            case 's': {
                int input;
                std::cin >> input;
                if (tree.find(input))
                    std::cout << "found" << std::endl;
                else
                    std::cout << "not found" << std::endl;
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