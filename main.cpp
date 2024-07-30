#include <iostream>
#include <random>

#include "A.h"
#include "B.h"
#include "C.h"

int main() {
    const int N_min = 1000;
    const int N_max = 10000;
    const int M_min = 10;
    const int M_max = 100;
    const int L_min = 1;
    const int L_max = 200;
    const int L_min_difference = 20;
    const int B_theads_count = 5;
    const int C_theads_count = 2;
    const int max_execution_time = 60;

    A vector;
    std::vector<B*> monitors;
    std::vector<C*> modifiers;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> N_dis(N_min, N_max);
    std::uniform_int_distribution<> M_dis(M_min, M_max);
    std::uniform_real_distribution<> L_dis(L_min, L_max);

    double L1 = L_dis(gen);
    double L2;
    do {
        L2 = L_dis(gen);
    } while (std::abs(L1 - L2) < L_min_difference);

    if (L1 > L2) {
        std::swap(L1, L2);
    }

    for (int i = 0; i < B_theads_count; i++) {
        monitors.push_back(new B(vector, N_dis(gen), L1, L2));
    }

    for (int i = 0; i < C_theads_count; i++) {
        modifiers.push_back(new C(vector, M_dis(gen)));
    }

    for(B* monitor : monitors) {
        monitor->start();
    }

    for(C* modifier : modifiers) {
        modifier->start();
    }

    std::this_thread::sleep_for(std::chrono::seconds(max_execution_time));

    for(B* monitor : monitors) {
        monitor->stop();
    }

    for(C* modifier : modifiers) {
        modifier->stop();
    }

    return 0;
}
