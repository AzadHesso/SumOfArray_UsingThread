#include "Array_sum.h"
#include <iostream>

int main() {
    std::size_t N = 0;
    int M = 0;
    std::cout << "Input array size: ";
    std::cin >> N;
    std::cout << "Input count of array parts: ";
    std::cin >> M;

    ArraySum arraySum(N, M);

    // Подсчет суммы с использованием потоков
    double parallel_time = arraySum.measure_time([&]() {
        int sum = arraySum.parallel_sum();
        std::cout << "Parallel sum: " << sum << std::endl;
        });

    // Подсчет суммы в основном потоке
    double single_thread_time = arraySum.measure_time([&]() {
        int sum = arraySum.single_thread_sum();
        std::cout << "Single thread sum: " << sum << std::endl;
        });

    std::cout << "Parallel execution time: " << parallel_time << " seconds" << std::endl;
    std::cout << "Single thread execution time: " << single_thread_time << " seconds" << std::endl;

    if (parallel_time < single_thread_time) {
        std::cout << "Parallel sum faster than single thread sum" << std::endl;
    }
    else {
        std::cout << "Single thread sum faster than parallel sum" << std::endl;
    }

    // Количество ядер процессора
    int numCPU = std::thread::hardware_concurrency();
    std::cout << "Processor cores count: " << numCPU << std::endl;

    return 0;
}
