#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        int _signGrade;
        int _execGrade;
    
    public:
        // OCF
        Form();
        Form( const std::string& name, int signGrade, int execGrade );
        Form( const Form& other );
        Form& operator=( const Form& other );
        ~Form();

        // Getters
        const std::string& getName() const;
        bool getIsSigned() const;
        int getsignGradee() const;
        int getexecGradee() const;

        void beSigned( const Bureaucrat& bureaucrat);

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

std::ostream& operator<<( std::ostream& os, const Form& form );