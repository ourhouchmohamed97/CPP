#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av) {
    if (ac != 2)
        return 1;
    
    RPN rpn;
    if (!rpn.valid(av[1])) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    try {
        std::cout << rpn.ExpressionEvaluator(av[1]) << std::endl;
    } catch (...) {
        std::cout << "Error" << std::endl;
    }
    return 0;
}