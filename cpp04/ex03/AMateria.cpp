#include "AMateria.hpp"


AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria parameterized constructor called!" << std::endl;
}

std::string const & AMateria::getType() const {
    return this->_type;
}

AMateria::~AMateria() {
    std::cout << "AMateria destroyed" << std::endl;
}
