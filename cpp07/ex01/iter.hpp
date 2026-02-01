#pragma once

#include <iostream>
#include <cstdlib>

template <typename T, typename F>
void iter(T *arr, const size_t len, F func) {
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

template <typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

template <typename T>
void increment(T &x) {
    x++;
}