#pragma once

#include <string>
#include <stack>

class RPN {
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN( const RPN &other );
        RPN& operator=( const RPN& other);
        ~RPN();

        bool valid( const std::string& input );
        int ExpressionEvaluator( const std::string& expression );
};