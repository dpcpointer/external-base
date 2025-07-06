#pragma once

#include <stdint.h>
#include <memory>
#include <chrono>

class timer {
    using Clock = std::chrono::high_resolution_clock;
    Clock::time_point start_time;
    double elapsed = 0.0;
    bool running = false;
public:
    void start() {
        if (!running) {
            elapsed = 0;
            start_time = Clock::now();
            running = true;
        }
    }

    void stop() {
        if (running) {
            elapsed += std::chrono::duration<double>(Clock::now() - start_time).count();
            running = false;
        }
    }

    void reset() {
        elapsed = 0.0;
        running = false;
    }

    double get_time_elapsed() const {
        if (running)
            return elapsed + std::chrono::duration<double>(Clock::now() - start_time).count();
        return elapsed;
    }
};