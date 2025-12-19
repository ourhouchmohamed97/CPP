#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int n) {
    value = n << fractional;
}

Fixed::Fixed(const float f) {
    value = roundf(f * (1 << fractional));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        value = other.value;
    return *this;
}

Fixed::~Fixed() {}

float Fixed::toFloat( void ) const {
    return (float)value / (1 << fractional);
}

int Fixed::toInt( void ) const {
    return value >> fractional;
}

// comparison operators

bool Fixed::operator<(const Fixed& other) const {
    return this->value < other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->value <= other.value;
}

bool Fixed::operator>(const Fixed& other) const {
    return this->value > other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->value >= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->value != other.value;
}

// arithmetic operators

Fixed Fixed::operator+(const Fixed& other) const{
    Fixed result;
    result.value = this->value + other.value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const{
    Fixed result;
    result.value = this->value - other.value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const{
    Fixed result;
    result.value = (this->value * other.value) >> fractional;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const{
    Fixed result;
    result.value = (this->value << fractional) / other.value;
    return result;
}

// Increment / Decrement operators

Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    this->value++;
    return tmp;
}

Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    this->value--;
    return tmp;
}


// Min and Max functions
Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2) {
    return (fixed1.value < fixed2.value) ? fixed1 : fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
    return (fixed1.value < fixed2.value) ? fixed1 : fixed2;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
    return (fixed1.value > fixed2.value) ? fixed1 : fixed2;
}
const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
    return (fixed1.value > fixed2.value) ? fixed1 : fixed2;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}