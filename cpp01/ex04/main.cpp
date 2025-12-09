#include "header.hpp"

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }
 
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty()) {
    std::cerr << "Error: s1 cannot be empty." << std::endl;
    return 1;
    }

    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error: cannot open file." << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());
    infile.close();

    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    std::ofstream outfile(filename + ".replace");
    outfile << content;
    outfile.close();
}