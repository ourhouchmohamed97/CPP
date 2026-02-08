#pragma once

#include <vector>

class Span {
    private:
        unsigned int N;
        std::vector<int> integers;

    public:
        Span( unsigned int N );
        Span( const Span& other );
        Span& operator=( const Span& other );
        ~Span();

        void addNumber( int value );

        int shortestSpan();
        int longestSpan();
};