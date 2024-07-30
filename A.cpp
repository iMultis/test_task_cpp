#include "A.h"

void A::setVector(double x0, double x1, double x2) {
    std::lock_guard<std::mutex> lock(mtx);
    vector[0] = x0;
    vector[1] = x1;
    vector[2] = x2;
}

void A::getVector(double& x0, double& x1, double& x2) {
    std::lock_guard<std::mutex> lock(mtx);
    x0 = vector[0];
    x1 = vector[1];
    x2 = vector[2];
}