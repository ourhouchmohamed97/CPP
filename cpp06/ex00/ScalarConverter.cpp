#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter& other ) {
    *this = other;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& other ) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::toChar( double value ) {
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::toInt( double value ) {
    if (std::isnan(value) || std::isinf(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::toFloat( double value ) {
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << "float: " << (value < 0 ? "-inff" : "+inff") << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
}

void ScalarConverter::toDouble( double value ) {
    if(std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
        std::cout << "double: " << (value < 0 ? "-inf" : "+inf") << std::endl;
    else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << value << std::endl;
    }
}

void ScalarConverter::convert( const std::string& param ) {
    double value;
    if (isPseudo(param))
        value = std::strtod(param.c_str(), NULL);
    else if (isChar(param))
        value = static_cast<double>(param[0]);
    else if (isInt(param) || isFloat(param) || isDouble(param))
        value = std::strtod(param.c_str(), NULL);
    else {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    ScalarConverter::toChar(value);
    ScalarConverter::toInt(value);
    ScalarConverter::toFloat(value);
    ScalarConverter::toDouble(value);
}
