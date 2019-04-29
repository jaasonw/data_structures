#include "util/Random.h"
#include <stdlib.h>
#include <time.h>

//----------------------------------------------------------------------
// initialization of the static member variable must be done in the .cpp file.
//
int Random::objectCount = 0;
//
//----------------------------------------------------------------------

Random::Random() {
    objectCount++;
    if (objectCount == 1) {
        srand(time(0));
    }
}

int Random::getNext(int low, int high) {
    return rand() % (high - low + 1) + low;
}