#pragma once 

#include "AForm.hpp"
#include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm {
    private:
        const std::string _target;

    public:
        PresidentialPardonForm( const std::string& target );
        PresidentialPardonForm( const PresidentialPardonForm& other );
        PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
        virtual ~PresidentialPardonForm();

        void execute( const Bureaucrat& presidential ) const;
};