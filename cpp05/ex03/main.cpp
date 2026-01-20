#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main() {
    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm* f1 = intern.makeForm("robotomy request", "Bender");
    AForm* f2 = intern.makeForm("shrubbery creation", "Home");
    AForm* f3 = intern.makeForm("presidential pardon", "Fry");
    AForm* f4 = intern.makeForm("unknown form", "Nobody");

    if (f1) {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }

    if (f2) {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }
    if (f3) {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }

    delete f4;
}