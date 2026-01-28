#pragma once

#include <string>
#include <iostream>
#include <cstdlib>  // strtod
#include <climits>  // INT_MIN, INT_MAX
#include <cctype>   // isprint
#include <cmath>    // isnan, isinf
#include <limits>   // std::numeric_limits
#include <iomanip>  //std::setprecision and std::fixed

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter( const ScalarConverter& other );
        ScalarConverter& operator=( const ScalarConverter& other );
        ~ScalarConverter();
    public:
        static void convert( const std::string& value );
        static void toChar( double d );
        static void toInt( double d );
        static void toFloat( double d );
        static void toDouble( double d );
};

bool isPseudo( const std::string& value );
bool isChar( const std::string& value );
bool isInt( const std::string& value );
bool isFloat( const std::string& value );
bool isDouble( const std::string& value );