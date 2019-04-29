#pragma once
#include <chrono>

// just to make things look neater
typedef std::chrono::seconds seconds;
typedef std::chrono::milliseconds milliseconds;
typedef std::chrono::microseconds microseconds;
typedef std::chrono::nanoseconds nanoseconds;

class Timer {
private:
    std::chrono::high_resolution_clock::time_point _start;
    std::chrono::high_resolution_clock::time_point _stop;

public:
    Timer()
        : _start(std::chrono::high_resolution_clock::now()),
          _stop(std::chrono::high_resolution_clock::now()) {}

    void start() { _start = std::chrono::high_resolution_clock::now(); }
    void stop() { _stop = std::chrono::high_resolution_clock::now(); }
    template <typename T>
    double duration() {
        return std::chrono::duration_cast<T>(_stop - _start).count();
    }
};