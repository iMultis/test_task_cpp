#ifndef C_H
#define C_H
#include <thread>

#include "A.h"


class C {
public:
    C(A& vec, int M)
        : vector(vec), interval(1000 / M), running(true) {}

    void start();

    void stop();

private:
    void modify();

    const int min_vector_component = 0;
    const int max_vector_component = 100;

    A& vector;
    int interval;
    bool running;
    std::thread modifier_thread;
};



#endif //C_H
