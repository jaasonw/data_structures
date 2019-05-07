#pragma once
#include "BTree.h"
#include "MultiPair.h"

namespace MultiMap {

template <typename Key, typename T>
class MultiMap {
private:
    BTree<Pair<Key, T>> tree;
public:
    MultiMap();
    std::vector<T>& get(const T& item);

    std::vector<T>& operator[](const Key& key);
    const std::vector<T>& operator[](const Key& key) const;

    std::vector<T>& at(const Key& key);
    const std::vector<T>& at(const Key& key) const;

    void insert(const Key& key, const T& value);

    friend std::ostream& operator<<(std::ostream& outs,
                                    const MultiMap<Key, T>& map) {
        map.tree.print_tree();
        return outs;
    }
};

template <typename Key, typename T>
MultiMap<Key, T>::MultiMap() : tree(true) {}

template <typename Key, typename T>
void MultiMap<Key, T>::insert(const Key& key, const T& value) {
    tree.insert(Pair<Key, T>(key, value));
}
template <typename Key, typename T>
std::vector<T>& MultiMap<Key, T>::operator[](const Key& key) {
    return tree.get(Pair<Key, T>(key, T())).values;
}

template <typename Key, typename T>
const std::vector<T>& MultiMap<Key, T>::operator[](const Key& key) const {
    try {
        return tree.get(key);
    } catch (std::out_of_range()) {
        throw std::out_of_range("Key not found");
    }
}

} // namespace Map
