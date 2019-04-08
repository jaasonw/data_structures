
#include <cctype>
#include <cmath>
#include <ctime>
#include <iostream>

template <typename T>
void test_priority_queue(T& priority_queue) {
    srand(time(0));
    while (true) {
        char input;
        std::cout << "[R]andom [I]nsert [C]lear [P]op e[X]it: ";
        std::cin >> input;
        switch (tolower(input)) {
            case 'r':
                priority_queue.insert_with_priority(rand() % 100, rand() % 10 + 1);
                break;
            case 'i': {
                int input;
                int priority;
                std::cin >> input;
                std::cin >> priority;
                priority_queue.insert_with_priority(input, priority);
                break;
            }
            case 'c':
                priority_queue = T();
                break;
            case 'p': ;
                try {
                    std::cout << "popped: " << priority_queue.pop() << std::endl;
                }
                catch (std::out_of_range& e) {
                    std::cout << "cannot pop from empty queue" << std::endl;
                }
                break;
            case 'x':
                return;
            default:
                std::cout << "invalid input" << std::endl;
        }
        std::cout << priority_queue;
    }
}