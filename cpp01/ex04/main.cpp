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
    // ❗ Why we do this?
    // Because it is MUCH easier to search and replace inside a big string than inside a file stream.
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


// **npos** is a static member constant value with the greatest possible value for an element of type size_t.
// As a return value, it is usually used to indicate no matches.
// This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest possible representable value for this type.