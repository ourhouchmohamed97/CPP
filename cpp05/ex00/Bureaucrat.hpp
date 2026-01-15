#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

    public:
        // OCF
        Bureaucrat();
        Bureaucrat( const std::string& name, int grade );
        Bureaucrat( const Bureaucrat& other );
        Bureaucrat& operator=( const Bureaucrat& other );
        ~Bureaucrat();

        // Getters
        const std::string& getName() const;
        int getGrade() const;

        // Grade modification
        void incrementGrade();
        void decrementGrade();

        // Exceptions
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bureaucrat );
