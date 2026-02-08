#pragma once

class Span {
    private:
        unsigned int N;

    public:
        Span( unsigned int N );
        Span( const Span& other );
        Span& operator=( const Span& other );
        ~Span();

        void addNumber();
        void shortestSpan();
        void longestSpan();
};