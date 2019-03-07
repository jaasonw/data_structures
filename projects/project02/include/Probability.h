#pragma once
#include <cstdlib>

class Probability {
private:
    double probability;

public:
    Probability(double probability) : probability(probability){};
    bool roll() { return rand() < probability * RAND_MAX; }
    double get_probability() { return probability; }
    friend std::ostream& operator<<(std::ostream& outs, const Probability& p) {
        outs << p.probability;
        return outs;
    }
};
