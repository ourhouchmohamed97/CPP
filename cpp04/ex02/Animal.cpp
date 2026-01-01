#include "Animal.hpp"

AAnimal::AAnimal() : _type("default") {
    std::cout << "AAnimal created! [default constructor]" << std::endl;
}

AAnimal::AAnimal( std::string const &type ) : _type(type) {
    std::cout << "AAnimal created! [parameterized constructor]" << std::endl;
}

AAnimal::AAnimal( const AAnimal& other ) : _type(other._type) {
    std::cout << "AAnimal copied! [copy constructor]" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other ) {
    std::cout << "AAnimal assigned! [copy assignment]" << std::endl;
    if(this != &other)
        this->_type = other._type;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal killed! [destructor]" << std::endl;
}

std::string const &AAnimal::getType( void )const {
    return this->_type;
}

void AAnimal::makeSound() const {
    std::cout << "* AAnimal makes a generic sound *" << std::endl;
}