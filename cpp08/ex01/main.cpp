#include "Span.hpp"
#include <iostream>

int main()
{
    // Subject test
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // // 10 000 test
    // Span sp = Span(10000);
    // for (int i = 0; i < 10000; i++)
    //     sp.addNumber(rand());
    
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;

    // // Too few numbers
    // try {
    //     Span sp = Span(1);
    //     sp.addNumber(42);
    //     sp.shortestSpan();
    // }
    // catch (std::exception &e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // // Overfilling
    // try {
    //     Span sp = Span(2);
    //     sp.addNumber(1);
    //     sp.addNumber(2);
    //     sp.addNumber(3);
    // }
    // catch(const std::exception& e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl;
    // }

    // // Negative numbers
    // Span sp(3);
    // sp.addNumber(-10);
    // sp.addNumber(0);
    // sp.addNumber(10);

    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;

    return 0;
}