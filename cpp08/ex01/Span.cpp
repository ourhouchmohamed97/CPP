#include "Span.hpp"
#include <exception>

Span::Span( unsigned int N ) : N(N) {}

Span::Span( const Span& other ) : N(other.N) {}
        
Span& Span::operator=( const Span& other ) {
    if (this != &other)
        N = other.N;
    return *this;
}

Span::~Span() {}

void Span::addNumber() {
    if ()
        throw std::exception;
}

void Span::shortestSpan() {}

void Span::longestSpan() {}