#include "Average.h"

Average::Average() {
    sum = 0;
    average = 0;
    total = 0;
}

double Average::add(double num) {
    sum += num;
    total++;
    average = sum / total;
    return average;
}