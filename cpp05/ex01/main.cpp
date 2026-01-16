#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);

        Form taxForm("TaxForm", 50, 25);
        Form secretForm("SecretForm", 1, 1);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;

        std::cout << taxForm << std::endl;
        std::cout << secretForm << std::endl;

        std::cout << "------------------------" << std::endl;

        bob.signForm(taxForm);        // should fail
        alice.signForm(taxForm);      // should succeed
        alice.signForm(secretForm);   // should succeed

        std::cout << "------------------------" << std::endl;

        std::cout << taxForm << std::endl;
        std::cout << secretForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    try {
        Form invalidForm("Invalid", 0, 200); // should throw in constructor
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
