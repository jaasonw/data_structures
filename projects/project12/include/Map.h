#pragma once
#include "BTree.h"
#include "Pair.h"

namespace Map {

template <typename Key, typename T>
class Map {
private:
    BTree<Pair<Key, T>> tree;
public:
    Map();
    T& get(const T& item);
    T& operator[](const Key& key);
    const T& operator[](const Key& key) const;
    T& at(const Key& key);
    const T& at(const Key& key) const;

    void set(const Key& key, const T& value);

    friend std::ostream& operator<<(std::ostream& outs, const Map<Key,T>& map) {
        map.tree.print_tree();
        return outs;
    }
};

template <typename Key, typename T>
Map<Key, T>::Map() {}

template <typename Key, typename T>
void Map<Key, T>::set(const Key& key, const T& value) {
    tree.insert(Pair<Key, T>(key, value));
}
template <typename Key, typename T>
T& Map<Key, T>::operator[](const Key& key) {
    return tree.get(Pair<Key, T>(key, T())).value;
}

template <typename Key, typename T>
const T& Map<Key, T>::operator[](const Key& key) const {
    return tree.get(Pair<Key, T>(key, T())).value;
}

template <typename Key, typename T>
T& Map<Key, T>::at(const Key& key) {
    return tree.get(Pair<Key, T>(key, T())).value;
}

template <typename Key, typename T>
const T& Map<Key, T>::at(const Key& key) const {
    try {
        return tree.get(key);
    } catch (std::out_of_range()) {
        throw std::out_of_range("Key not found");
    }
}

} // namespace Map
