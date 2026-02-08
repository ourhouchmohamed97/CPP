#include "Span.hpp"
#include <exception>
#include <algorithm>

Span::Span( unsigned int N ) : N(N) {}

Span::Span( const Span& other ) : N(other.N) {}
        
Span& Span::operator=( const Span& other ) {
    if (this != &other)
        N = other.N;
    return *this;
}

Span::~Span() {}

void Span::addNumber( int value ) {
    if (integers.size() >= N)
        throw std::exception();
    integers.push_back(value);
}

int Span::shortestSpan() {
    if (integers.size() < 2)
        throw std::exception();

    std::vector<int> tmp(integers);
    std::sort(tmp.begin(), tmp.end());

    int shortest = tmp[1] - tmp[0];

    for (size_t i = 1; i < integers.size() - 1; i++) {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() {
    if (integers.size() < 2)
        throw std::exception();
    
    int min = *std::min_element(integers.begin(), integers.end());
    int max = *std::max_element(integers.begin(), integers.end());

    return max - min;
}