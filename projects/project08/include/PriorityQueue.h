#include "Heap.h"
#include "Info.h"

template <typename T>
class PriorityQueue {
private:
    Heap<Info<T>> _data;
public:
    bool insert(const T& value);
    bool insert_with_priority(const T& value, int priority);
    T pop();

    bool is_empty() const { return _data.is_empty(); };
    unsigned int size() const { return _data.size(); };
    void print_tree() const { std::cout << _data; };
    friend std::ostream& operator<<(std::ostream& outs, const PriorityQueue<T>& q) {
        return outs << q._data;
    }
};

template <typename T>
bool PriorityQueue<T>::insert(const T& value) {
    return _data.insert(Info<T>(value, 0));
}

template <typename T>
bool PriorityQueue<T>::insert_with_priority(const T& value, int priority) {
    return _data.insert(Info<T>(value, priority));
}

template <typename T>
T PriorityQueue<T>::pop() {
    return *_data.pop();
}