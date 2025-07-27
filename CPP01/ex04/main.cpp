#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    // if (argc != 4)
    //     return 1;

    std::ifstream inFile;
    std::ofstream outFile;
    std::string line;
    std::string s1 = argv[3];
    std::string s2 = argv[4];
    std::string modified_line;

    inFile.open(argv[1]);
    outFile.open(argv[2]);

    if (!inFile.is_open() || !outFile.is_open())
    {
        std::cout << "Error opening file" << std::endl;
    }

    while (std::getline(inFile, line))
    {
        if (s1.empty())
            return (1);
        modified_line = "";
        size_t pos = 0;
        size_t start = 0;
        while ((pos = line.find(s1, start)) != std::string::npos)
        {
            std::cout << "Found at position " << pos << std::endl;
            modified_line += line.substr(start, pos - start);
            modified_line += s2;
            start += pos + s1.length();
        }
        modified_line += line.substr(start);
        if (!modified_line.empty())
            outFile << modified_line << std::endl;
        else
            outFile << line << std::endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}