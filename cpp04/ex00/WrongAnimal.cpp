#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("default") {
    std::cout << "WrongAnimal created! [default constructor]" << std::endl;
}

WrongAnimal::WrongAnimal( std::string const &type ) : _type(type) {
    std::cout << "WrongAnimal created! [parameterized constructor]" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) : _type(other._type) {
    std::cout << "WrongAnimal created! [copy constructor]" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other ) {
    std::cout << "WrongAnimal assigned! [copy assignment]" << std::endl;
    if(this != &other)
        this->_type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal killed! [destructor]" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "* WrongAnimal makes a generic sound *" << std::endl;
}