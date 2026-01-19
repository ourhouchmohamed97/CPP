#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Create bureaucrats
    Bureaucrat bob("Bob", 150);   // weakest
    Bureaucrat alice("Alice", 1); // strongest

    // Create forms
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("Bender");
    PresidentialPardonForm pardon("Fry");

    std::cout << "\n=== ShrubberyCreationForm ===\n";
    try { bob.signForm(shrubbery); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try { bob.executeForm(shrubbery); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try { alice.signForm(shrubbery); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try { alice.executeForm(shrubbery); } catch (std::exception &e) { std::cout << e.what() << std::endl; }

    std::cout << "\n=== RobotomyRequestForm ===\n";
    try { bob.signForm(robotomy); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try { bob.executeForm(robotomy); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try { alice.signForm(robotomy); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try { alice.executeForm(robotomy); } catch (std::exception &e) { std::cout << e.what() << std::endl; }

    std::cout << "\n=== PresidentialPardonForm ===\n";
    try { bob.signForm(pardon); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try { bob.executeForm(pardon); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try { alice.signForm(pardon); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
    try { alice.executeForm(pardon); } catch (std::exception &e) { std::cout << e.what() << std::endl; }

    std::cout << "\n=== Forms Status ===\n";
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;

    return 0;
}
