#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) 
    : AForm("RobotomyRequestForm", 72, 45),
    _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) 
    : AForm(other),
    _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other ) {
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute( const Bureaucrat& presidential ) const {
    if (!getIsSigned())
        throw AForm::GradeTooLowException();
    if (presidential.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << "* drilling noises *" << std::endl;

    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy failed" << std::endl;
}
