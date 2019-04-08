
#include <cctype>
#include <cmath>
#include <ctime>
#include <iostream>

template <typename T>
void test_heap(T& heap) {
    srand(time(0));
    while (true) {
        char input;
        std::cout << "[R]andom  [I]nsert  [C]lear  [P]op   e[X]it: ";
        std::cin >> input;
        switch (tolower(input)) {
            case 'r':
                heap.insert(rand() % 100);
                break;
            case 'i': {
                int input;
                std::cin >> input;
                heap.insert(input);
                break;
            }
            case 'c':
                heap = T();
                break;
            case 'p': ;
                try {
                    std::cout << "popped: " << heap.pop() << std::endl;
                }
                catch (std::out_of_range& e) {
                    std::cout << "cannot pop from empty heap" << std::endl;
                }
                break;
            case 'x':
                return;
            default:
                std::cout << "invalid input" << std::endl;
        }
        std::cout << heap;
    }
}