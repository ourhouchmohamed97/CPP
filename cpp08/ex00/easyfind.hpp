#pragma once

#include <algorithm>
#include <exception>

template <typename T>
void easyfind(const T& a, int b) {
    if (std::find(a.begin(), a.end(), b) == a.end())
        throw std::exception();
}