#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
    : _name("default"),
    _isSigned(false),
    _signGrade(150),
    _execGrade(150)
{
    std::cout << "AForm created! [default constructor called]" << std::endl;
}


AForm::AForm( const std::string& name, int signGrade, int execGrade ) 
    : _name(name),
    _isSigned(false),
    _signGrade(signGrade),
    _execGrade(execGrade)
{
    std::cout << "AForm created! [parameterized constructor called]" << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm( const AForm& other )
    : _name(other._name),
    _isSigned(other._isSigned),
    _signGrade(other._signGrade),
    _execGrade(other._execGrade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=( const AForm& other ) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destroyed! [destructor called]" << std::endl;
}

const std::string& AForm::getName() const {
    return _name;
}
        
bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getSignGrade() const {
    return _signGrade;
}
        
int AForm::getExecGrade() const {
    return _execGrade;
}

void AForm::beSigned( const Bureaucrat& bureaucrat) {
    if (_isSigned)
        return;
    if (bureaucrat.getGrade() <= _signGrade)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << form.getName()
       << ", form is signed: " << (form.getIsSigned() ? "true" : "false")
       << ", sign grade " << form.getSignGrade()
       << ", exec grade " << form.getExecGrade();
    return os;
}