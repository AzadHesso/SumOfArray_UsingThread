#include "Array_sum.h"
#include <iostream>
#include <ctime>
#include <numeric>

// Конструктор класса, инициализация массива случайных чисел
ArraySum::ArraySum(int N, int M) : _N(N), _M(M), arr(N), results(M, 0) {
    srand(static_cast<unsigned int>(time(0)));
    for (std::size_t i = 0; i < N; i++) {
        arr[i] = 1 + rand() % 9;
    }
}

// Функция для подсчета суммы элементов части массива
void ArraySum::calc_sum(int num) {
    int result = 0;
    int count = static_cast<int>(_N / _M);
    int start = num * count;
    int end = (num == _M - 1) ? _N : start + count;  // Последний поток берет оставшуюся часть

    for (int i = start; i < end; i++) {
        result += arr[i];
    }

    // Защищаем доступ к results с помощью мьютекса
    std::lock_guard<std::mutex> guard(mtx);
    results[num] = result;
}

// Подсчет суммы с использованием потоков
int ArraySum::parallel_sum() {
    std::vector<std::thread> threads;

    for (int i = 0; i < _M; ++i) {
        threads.emplace_back(&ArraySum::calc_sum, this, i);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return std::accumulate(results.begin(), results.end(), 0);
}

// Подсчет суммы в основном потоке
int ArraySum::single_thread_sum() {
    return std::accumulate(arr.begin(), arr.end(), 0);
}
