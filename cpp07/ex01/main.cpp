#include "iter.hpp"

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    size_t len = 7;

    iter(arr, len, print<int>);
    std::cout << "--- increment ---" << std::endl;
    iter(arr, len, increment<int>);
    iter(arr, len, print<int>);

    std::cout << "--- strs ---" << std::endl;
    std::string strs[] = {"hello", "world"};
    iter(strs, 2, print<std::string>);

    return 0;
}