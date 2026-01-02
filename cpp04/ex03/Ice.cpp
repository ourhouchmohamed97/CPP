#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice created!" << std::endl;
}

Ice::~Ice() {
    std::cout << "Ice killed!" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << _name << " *" << std::endl;
}

