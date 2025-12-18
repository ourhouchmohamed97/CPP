#pragma once

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int value;
        static const int fractional = 8;

    public:
        Fixed(); // default constructor
        Fixed( const int n );
        Fixed( const float f );
        Fixed( const Fixed& other );
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        float toFloat( void ) const;
        int toInt( void ) const; 

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);