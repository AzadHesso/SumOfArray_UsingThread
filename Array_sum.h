#pragma once

#include <vector>
#include <thread>
#include <mutex>

class ArraySum {
public:
    ArraySum(int N, int M);

    // Функция для подсчета суммы элементов части массива
    void calc_sum(int num);

    // Подсчет суммы с использованием потоков
    int parallel_sum();

    // Подсчет суммы в основном потоке
    int single_thread_sum();

    // Функция для измерения времени выполнения
    template <typename Func>
    double measure_time(Func func);

private:
    std::size_t _N;
    int _M;
    std::vector<int> arr;
    std::vector<int> results;
    std::mutex mtx;
};

#include "array_sum_impl.h"
