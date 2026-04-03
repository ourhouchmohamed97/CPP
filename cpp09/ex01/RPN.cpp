#include "RPN.hpp"
#include <stdexcept>
#include <sstream>

RPN::RPN() {}

RPN::RPN( const RPN &other ) {
    *this = other;
}

RPN& RPN::operator=( const RPN &other ) {
    if (this != &other) {}
    return *this;
}

RPN::~RPN() {}

bool RPN::valid( const std::string& input) {
    for (size_t i = 0; i < input.size(); i++) {
        if (!isdigit(input[i]) &&
               input[i] != ' ' &&
               input[i] != '+' &&
               input[i] != '-' &&
               input[i] != '*' &&
               input[i] != '/')
            return false;
    }
    return true;
}


int RPN::ExpressionEvaluator(const std::string &expression)
{
    for (size_t i = 0; i < expression.size(); i++) {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i]))
            _stack.push(expression[i] - '0');
        else {
            if (_stack.size() < 2)
                throw std::runtime_error("Error");

            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            if (expression[i] == '+')
                _stack.push(a + b);
            else if (expression[i] == '-')
                _stack.push(a - b);
            else if (expression[i] == '*')
                _stack.push(a * b);
            else if (expression[i] == '/')
            {
                if (b == 0)
                    throw std::runtime_error("Error");
                _stack.push(a / b);
            }
            else
                throw std::runtime_error("Error");
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}