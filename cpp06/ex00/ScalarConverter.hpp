#pragma once

#include <string>

class ScalarConverter {
    private:
        ScalarConverter();
    public: 
        static void convert( const std::string& value );
};