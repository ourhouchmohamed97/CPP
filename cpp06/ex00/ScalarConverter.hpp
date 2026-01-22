#pragma once

#include <string>
#include <iostream>
#include <cstdlib>   // strtod
#include <climits>   // INT_MIN, INT_MAX
#include <cctype>    // isprint
#include <cmath>     // isnan, isinf

class ScalarConverter {
    private:
        ScalarConverter();
    public: 
        static void convert( const std::string& value );
};