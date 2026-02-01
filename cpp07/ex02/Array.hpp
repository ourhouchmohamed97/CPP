#pragma once

#include <iostream>

class Array {
    private:

    public:
        Array();
        Array( unsigned int n );
        Array( const Array& other );
        Array& operator=( const Array& other );
        ~Array();
};