#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {

    // Vector conatiner test
    std::vector<int> vect;

    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
    vect.push_back(40);
    vect.push_back(50);

    int value_to_find;

    std::cout << "Vector test:" << std::endl;
    try {
        value_to_find = 30;
        easyfind(vect, value_to_find);
        std::cout << "value founded: " << value_to_find << std::endl;
        value_to_find = 60;
        easyfind(vect, value_to_find);
    }
    catch (std::exception  &e) {
        std::cout << e.what() << std::endl;
    }

    // List container test
    std::list<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    std::cout << "List test:" << std::endl;
    try {
        value_to_find = 20;
        easyfind(list, value_to_find);
        std::cout << "value founded: " << value_to_find << std::endl;
        value_to_find = 60;
        easyfind(vect, value_to_find);
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}