#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
    : _name("default"),
    _isSigned(false),
    _signGrade(150),
    _execGrade(150)
{
    std::cout << "Form created! [default constructor called]" << std::endl;
}


Form::Form( const std::string& name, int signGrade, int execGrade ) 
    : _name(name),
    _isSigned(false),
    _signGrade(signGrade),
    _execGrade(execGrade)
{
    std::cout << "Form created! [parameterized constructor called]" << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::Form( const Form& other )
    : _name(other._name),
    _isSigned(other._isSigned),
    _signGrade(other._signGrade),
    _execGrade(other._execGrade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=( const Form& other ) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form() {
    std::cout << "Form destroyed! [destructor called]" << std::endl;
}

const std::string& Form::getName() const {
    return _name;
}
        
bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getSignGradee() const {
    return _signGrade;
}
        
int Form::getExecGradee() const {
    return _execGrade;
}

void Form::beSigned( const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _signGrade)
        _isSigned = true;
    else
        throw GradeTooLowException();
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName()
       << ", form is signed: " << (form.getIsSigned() ? "true" : "false")
       << ", sign grade " << form.getSignGradee()
       << ", exec grade " << form.getExecGradee();
    return os;
}