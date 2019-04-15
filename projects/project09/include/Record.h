#pragma once
#include <iostream>

template <typename T>
struct Record {
    int _key;
    T _value;

    Record(int key = 0, T value = T()) {
        _key = key;
        _value = value;
    }
    friend bool operator==(const Record& left, const Record& right) {
        return left._key == right._key;
    }
    friend bool operator>(const Record& left, const Record& right) {
        return left._key > right._key;
    }
    friend bool operator<(const Record& left, const Record& right) {
        return left._key < right._key;
    }
    friend std::ostream& operator<<(std::ostream& outs, const Record& record) {
        outs << record._key << ":" << record._value;
        return outs;
    }
};