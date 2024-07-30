#ifndef B_H
#define B_H
#include <thread>

#include "A.h"


class B {
public:
    B(A& vec, int N, double L1, double L2)
        : vector(vec), interval(1000 / N), lower_bound(L1), upper_bound(L2), running(true) {}

    void start();

    void stop();

private:
    void monitor();

    double magnitude(double x0, double x1, double x2);

    void print(double x0, double x1, double x2);

    A& vector;
    int interval;
    double lower_bound, upper_bound;
    bool running;
    std::thread monitor_thread;
};



#endif //B_H
