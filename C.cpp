#include <random>

#include "C.h"

void C::start() {
    modifier_thread = std::thread(&C::modify, this);
}

void C::stop() {
    running = false;
    if (modifier_thread.joinable()) {
        modifier_thread.join();
    }
}

void C::modify() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min_vector_component, max_vector_component);

    while (running) {
        vector.setVector(dis(gen), dis(gen), dis(gen));
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
}