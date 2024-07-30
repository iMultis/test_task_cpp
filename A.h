#ifndef A_H
#define A_H
#include <mutex>
#include <vector>


class A {
public:
    A() : vector({0.0, 0.0, 0.0}) {}

    void setVector(double x0, double x1, double x2);

    void getVector(double& x0, double& x1, double& x2);

private:
    std::vector<double> vector;
    std::mutex mtx;
};



#endif //A_H
