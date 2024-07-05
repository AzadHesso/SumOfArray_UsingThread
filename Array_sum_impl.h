#ifndef ARRAY_SUM_IMPL_H
#define ARRAY_SUM_IMPL_H

#include <chrono>

template <typename Func>
double ArraySum::measure_time(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    return elapsed.count();
}

#endif // ARRAY_SUM_IMPL_H
