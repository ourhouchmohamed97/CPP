#include "ScalarConverter.hpp"
#include <iostream>

static void printImpossible() {
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

void ScalarConverter::convert( const std::string& value ) {
    char *end;
    double d = std::strtod(value.c_str(), &end);

    bool isFloatLiteral = (*end == 'f' && *(end + 1) == '\0');
    if (*end != '\0' && !isFloatLiteral) {
        printImpossible();
        return;
    }
    
    // char 
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(d) << std::endl;

    // int
    if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    // float
    float f = static_cast<float>(d);
    std::cout << "float: " << f;
    if (!std::isnan(f) && !std::isinf(f) && f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    // double 
    std::cout << "double: " << d;
    if (!std::isnan(f) && !std::isinf(f) && f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "\n";
}
