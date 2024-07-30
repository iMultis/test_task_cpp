#include <cmath>
#include <iostream>
#include <sstream>

#include "B.h"

void B::start() {
    monitor_thread = std::thread(&B::monitor, this);
}

void B::stop() {
    running = false;
    if (monitor_thread.joinable()) {
        monitor_thread.join();
    }
}

void B::monitor() {
    double x0, x1, x2, mag;

    while (running) {
        vector.getVector(x0, x1, x2);
        mag = magnitude(x0, x1, x2);

        if (mag >= lower_bound && mag <= upper_bound) {
            print(x0, x1, x2);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
}

double B::magnitude(double x0, double x1, double x2) {
    return std::sqrt(x0 * x0 + x1 * x1 + x2 * x2);
}

void B::print(double x0, double x1, double x2) {
    std::stringstream output;
    output << "(" << x0 << ", " << x1 << ", " << x2 << ")\n";
    std::cout << output.str();
}