#include "ScalarConverter.hpp"

bool isPseudo( const std::string& value ) {
    return (
        value == "nan" || value == "nanf" ||
        value == "+inf" || value == "-inf" ||
        value == "+inff" || value == "-inff"
    );
}

bool isChar( const std::string& value ) {
    return (value.length() == 1 && !std::isdigit(value[0]));
}

bool isInt( const std::string& value ) {
    size_t i = 0;

    if (value[i] == '-' || value[i] == '+')
        i++;
    if (i == value.length())
        return false;
    for(; i < value.length(); i++) {
        if (!std::isdigit(value[i]))
            return false;
    }
    return true;
}

bool isFloat( const std::string& value ) {
    if (value.back() != 'f')
        return false;
    bool dot = false;
    size_t i = 0;
    if (value[i] == '+' || value[i] == '-')
        i++;
    if (i == value.length())
        return false;
    for(; i < value.length(); i++) {
        if (value[i] == '.') {
            if(dot)
                return false;
            dot = true;
        }
        else if (!std::isdigit(value[i]))
            return false;
    }
    return dot;
}

bool isDouble( const std::string& value ) {
    bool dot = false;
    size_t i = 0;

    if (value[i] == '+' || value[i] == '-')
        i++;
    if (i == value.length())
        return false;
    for(; i < value.length(); i++) {
        if (value[i] == '.') {
            if (dot)
                return false;
            dot = true;
        }
        else if (!std::isdigit(value[i]))
            return false;
    }
    return dot;
}
