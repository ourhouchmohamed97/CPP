#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    int i = 1;
    while (i < ac)
    {
        int j = 0;
        while (av[i][j])
        {
            av[i][j] = std::toupper(static_cast<unsigned char>(av[i][j]));
            j++;
        }
        std::cout << av[i];
        if (i + 1 < ac)
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;
    return 0;
}