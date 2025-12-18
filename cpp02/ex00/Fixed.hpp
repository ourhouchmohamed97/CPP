#pragma once

#include <iostream>


class Fixed {
    private:
        int value;
        static const int fractional = 8;

    public:
        Fixed(); // default constructor
        Fixed(
            
            const Fixed& other); // copy constructor
        Fixed& operator=(const Fixed& other); // copy assignment
        ~Fixed(); // destructor

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};