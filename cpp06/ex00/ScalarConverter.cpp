#include "ScalarConverter.hpp"
#include <iostream>

void ScalarConverter::convert( const std::string& value ) {
    std::cout << "char: " static_cast<char>(value) << std::endl;
}