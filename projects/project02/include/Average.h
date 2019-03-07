#pragma once
#include <iostream>
class Average {
private:
    double sum;
    double average;
    int total;
public:
    Average();
    double add(double num);
    double get_average() { return average; };
    friend std::ostream& operator<<(std::ostream& outs, const Average& a) {
        outs << a.average;
        return outs;
    }
};