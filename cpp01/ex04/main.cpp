#include <iostream>
#include <fstream>
#include <string>

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

    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "Error: cannot open file." << std::endl;
        return 1;
    }

    std::string content;
    std::string line;

    while (std::getline(input, line)) {
        content += line;
        if (!input.eof()) {
            content += "\n";
        }
    }
    input.close();

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