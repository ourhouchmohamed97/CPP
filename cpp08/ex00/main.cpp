#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {

    std::vector<int> arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    int value_to_find = 30;
    try {
        easyfind(arr, value_to_find);
        std::cout << "value found!" << std::endl;
        value_to_find = 60;
        easyfind(arr, value_to_find);
    }
    catch (std::exception  &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}