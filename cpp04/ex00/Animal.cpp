#include "Animal.hpp"

Animal::Animal() : _type("default") {
    std::cout << "Animal created! [default constructor]" << std::endl;
}

Animal::Animal( std::string const &type ) : _type(type) {
    std::cout << "Animal created! [parameterized constructor]" << std::endl;
}

Animal::Animal( const Animal& other ) : _type(other._type) {
    std::cout << "Animal created! [copy constructor]" << std::endl;
}

Animal& Animal::operator=(const Animal& other ) {
    std::cout << "Animal assigned! [copy assignment]" << std::endl;
    if(this != &other)
        this->_type = other._type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal killed! [destructor]" << std::endl;
}

std::string const &Animal::getType( void )const {
    return this->_type;
}

void Animal::makeSound() const {
    std::cout << "* Animal makes a generic sound *" << std::endl;
}