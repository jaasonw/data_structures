#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

template <typename T>
class Heap {
private:
    std::vector<T> _data;

    void print_tree(unsigned int root, int level = 0,
                    std::ostream& outs = std::cout) const;
    void print_tree(std::ostream& outs = std::cout) const { print_tree(0); };

    bool is_heap(unsigned int root) const;
    bool is_leaf(unsigned int i) const {
        return left_child_index(i) >= size();
    };

    unsigned int left_child_index(unsigned int i) const { return i * 2 + 1; }
    unsigned int right_child_index(unsigned int i) const { return i * 2 + 2; }
    unsigned int big_child_index(unsigned int i) const;

    unsigned int parent_index(unsigned int i) const {
        return (i > 0) ? (i - 1) / 2 : 0;
    }
    void swap_with_parent(unsigned int i) {
        std::swap(_data[i], _data[parent_index(i)]);
    }

    void sift_down(unsigned int root);
    void sift_up(unsigned int i);

public:
    Heap();
    Heap(const T& root);

    bool insert(const T& item);
    T pop();

    bool is_empty() const { return _data.size() == 0; }
    unsigned int size() const { return _data.size(); }
    unsigned int max_size() const { return _data.max_size(); }
    unsigned int capacity() const { return _data.capacity(); }
    friend std::ostream& operator<<(std::ostream& outs, const Heap<T>& heap) {
        heap.print_tree();
        return outs;
    }
};

template <typename T>
Heap<T>::Heap() {
    _data = std::vector<T>();
}

template <typename T>
Heap<T>::Heap(const T& root) {
    _data.push_back(root);
}

template <typename T>
unsigned int Heap<T>::big_child_index(unsigned int i) const {
    unsigned int left_index = left_child_index(i);
    unsigned int right_index = right_child_index(i);
    if (is_leaf(i)) {
        throw std::out_of_range("big child called on leaf");
    }
    if (right_index >= _data.size())
        return left_index;
    return (_data[left_index] > _data[right_index]) ? left_index : right_index;
}

template <typename T>
bool Heap<T>::insert(const T& item) {
    if (size() == max_size())
        return false;
    _data.push_back(item);
    int index = _data.size() - 1;
    sift_up(index);
    return true;
}

template <typename T>
void Heap<T>::print_tree(unsigned int root, int level,
                         std::ostream& outs) const {
    if (root >= size())
        return;
    print_tree(right_child_index(root), level + 1);
    for (int i = 0; i < level; i++) {
        outs << "    ";
    }
    outs << _data[root] << std::endl;
    print_tree(left_child_index(root), level + 1);
}

template <typename T>
bool Heap<T>::is_heap(unsigned int root) const {
    if (is_leaf(root)) {
        return true;
    }
    int left = left_child_index(root);
    int right = right_child_index(root);
    return _data[root] > _data[left] && _data[root] > _data[right];
}

template <typename T>
void Heap<T>::sift_down(unsigned int root) {
    if (!is_heap(root) && !is_leaf(root)) {
        int large_child = big_child_index(root);
        if (_data.at(root) < _data.at(large_child)) {
            std::swap(_data.at(root), _data.at(large_child));
            sift_down(large_child);
        }
    }
}
template <typename T>
void Heap<T>::sift_up(unsigned int i) {
    int parent = parent_index(i);
    while (i > 0 && _data[i] > _data[parent_index(i)]) {
        swap_with_parent(i);
        i = parent;
        parent = parent_index(i);
    }
}

template <typename T>
T Heap<T>::pop() {
    if (is_empty())
        throw std::out_of_range("attempted to pop from empty heap");
    T hold = _data[0];
    _data[0] = _data[_data.size() - 1];
    _data.pop_back();
    sift_down(0);
    return hold;
}