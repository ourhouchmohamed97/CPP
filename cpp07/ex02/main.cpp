#include "Array.hpp"
#include <iostream>
#include <string>

static void printSection(const std::string &title)
{
    std::cout << "\n" << title << std::endl;
    std::cout << std::string(title.length(), '-') << std::endl;
}

int main()
{
    printSection("Default constructor");
    Array<int> empty;
    std::cout << "empty array size = " << empty.size() << std::endl;

    printSection("Constructor with size (default initialization)");
    Array<int> numbers(5);
    std::cout << "numbers size = " << numbers.size() << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;

    printSection("Copy constructor (deep copy)");
    Array<int> copy(numbers);
    copy[0] = 999;

    std::cout << "numbers[0] = " << numbers[0] << std::endl;
    std::cout << "copy[0]    = " << copy[0] << std::endl;

    printSection("Assignment operator (deep copy)");
    Array<int> assigned;
    assigned = numbers;
    assigned[1] = 888;

    std::cout << "numbers[1]  = " << numbers[1] << std::endl;
    std::cout << "assigned[1] = " << assigned[1] << std::endl;

    printSection("Out-of-range access");
    try
    {
        std::cout << numbers[10] << std::endl;
    }
    catch (std::exception &)
    {
        std::cout << "Exception caught: index out of bounds" << std::endl;
    }

    printSection("Test with another type");
    Array<std::string> strs(2);
    strs[0] = "hello";
    strs[1] = "world";

    std::cout << strs[0] << " " << strs[1] << std::endl;

    return 0;
}
