#include "Point.hpp"

int main(void)
{
    Point A(0,0), B(10,0), C(0,10);

    Point const P1(3,3);
    Point const P2(0,0);
    Point const P3(5,0);
    Point const P4(10,10);

    std::cout << bsp(A, B, C, P1) << std::endl; // 1
    std::cout << bsp(A, B, C, P2) << std::endl; // 0
    std::cout << bsp(A, B, C, P3) << std::endl; // 0
    std::cout << bsp(A, B, C, P4) << std::endl; // 0

    return 0;
}