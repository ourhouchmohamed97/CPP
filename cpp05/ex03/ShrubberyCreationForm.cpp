#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) 
    : AForm("ShrubberyCreationForm", 145, 137),
    _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) 
    : AForm(other),
    _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other ) {
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute( const Bureaucrat& presidential ) const {
    if (!getIsSigned())
        throw AForm::GradeTooLowException();

    if (presidential.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    
    std::ofstream outfile(_target + "_shrubbery");
    if (!outfile) {
        std::cerr << "Error creating file!" << std::endl;
        return ;
    }

    outfile << "                       ,@@@@@@@,         \n";
    outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.     \n";
    outfile << "    ,&@@&%&&%,@@@@@/@@@@@@,8888/88/8o    \n";
    outfile << "   ,%&/%&&%&&%,@@@/@@@/@@@88/88888/88'   \n";
    outfile << "   %&&%&%&/%&&%@@/@@/ /@@@88888/88888'   \n";
    outfile << "   %&&%/ %&@%&&@@/ V /@@' `88/8 `/88'    \n";
    outfile << "   `&%@ ` /%&'    |.|         | |8'     \n";
    outfile << "       |o|        | |         | |        \n";
    outfile << "       |.|        | |         | |        \n";
    outfile << "    \\/ ._///_/__/  ,/_//__\\/.  /_//__/_\n";

    outfile.close();
}
