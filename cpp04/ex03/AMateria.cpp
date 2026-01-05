#include "AMateria.hpp"


AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria parameterized constructor called!" << std::endl;
}

std::string const & AMateria::getType() const {
    return this->_type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* AMateria used on " << target.getName() << " *" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria destroyed" << std::endl;
}
