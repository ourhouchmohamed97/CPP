#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat a("Alice", 2);
        std::cout << a << std::endl;

        a.incrementGrade(); // goes to grade 1
        std::cout << a << std::endl;

        a.incrementGrade(); // should throw
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    try {
        Bureaucrat b("Bob", 149);
        std::cout << b << std::endl;

        b.decrementGrade(); // goes to 150
        std::cout << b << std::endl;

        b.decrementGrade(); // should throw
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    try {
        Bureaucrat c("Charlie", 0); // invalid → throw in constructor
        std::cout << c << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
