#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << "Bureaucrat created! [default constructor called]" << std::endl;
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ) 
    : _name(name)
{
    std::cout << "Bureaucrat created! [parameterized constructor called]" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) 
    : _name(other._name), _grade(other._grade)
{
    std::cout << "copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other) {
    std::cout << "copy assignment called" << std::endl;
    if(this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destroyed! [destructor called]" << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const  {
    return _grade;
}


void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << _name << " couldn’t sign "
                  << form.getName()
                  << " because " << e.what() << std::endl;
    }
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat ) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}