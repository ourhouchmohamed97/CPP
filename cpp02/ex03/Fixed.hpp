#pragma once

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int value;
        static const int fractional = 8;

    public:
        Fixed();
        Fixed( const int n );
        Fixed( const float f );
        Fixed( const Fixed& other );
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        float toFloat( void ) const;
        int toInt( void ) const; 

        // comparison operators
        bool operator<(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // arithmetic operators
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

         // Increment / Decrement operators
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        // Min and Max functions
        static Fixed& min(Fixed& fixed1, Fixed& fixed2);
        static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
        static Fixed& max(Fixed& fixed1, Fixed& fixed2);
        static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
