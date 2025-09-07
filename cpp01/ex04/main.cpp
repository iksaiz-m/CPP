#include "sed.hpp"

std::string replace_line(std::string line, std::string s1, std::string s2)
{
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos = pos + s2.length();
    }
    return (line);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (std::cout << "Error: use 3 arguments" << std::endl, 1);
    std::string filename = (av[1]);
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (filename.empty())
        return (std::cout << "Error, there should be a filename" << std::endl, 1);
    std::ifstream file_copy(filename.c_str());
    if (file_copy.is_open())
    {
        std::ofstream file_replace(filename.append(".replace").c_str());
        if (!file_replace.is_open())
            return (std::cout << "Error: couldn't create output file" << std::endl, 1);
        if (s1.empty() || s2.empty())
            file_replace << file_copy.rdbuf();
        else
        {
            std::string line;
            while (std::getline(file_copy, line))
            {
                line = replace_line(line, s1, s2);
                file_replace << line << '\n';
            }
        }
    }
    else
        return (std::cout << "Error, couldnt open " << filename << std::endl, 1);
     return (0);
}