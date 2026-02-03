#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./REPLACE <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (s1.empty())
    {
        std::cerr << "'s1' it doesn't have to be empty!" << std::endl;
        return (1);
    }
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening the file" << std::endl;
        return (1);
    }

    std::string line;
    std::ofstream replaceFile(filename + ".replace");
    if (!replaceFile.is_open())
    {
        std::cerr << "Error creating the file" << std::endl;
        return (1);
    }
    while (getline(file, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        replaceFile << line << std::endl;
    }
    
    return (0);
}