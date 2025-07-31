#include <iostream>
#include <fstream>

std::string processLine(const std::string& line, const std::string& s1,
            const std::string& s2)
{
    std::string result;
    size_t      start;
    size_t      pos;

    start = 0;
    pos = line.find(s1, start);
    while (pos != std::string::npos)
    {
        result += line.substr(start, pos - start) + s2;
        start = pos + s1.length();
        pos = line.find(s1, start);
    }
    result += line.substr(start);
    return result;
}

void    processFiles(const std::string& input_filename,
        const std::string& output_filename,
        const std::string& s1, const std::string& s2)
{
    std::string   line;
    std::ifstream inFile(input_filename);
    std::ofstream outFile(output_filename);

    if (!inFile.is_open() || !outFile.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return ;
    }
    while (std::getline(inFile, line))
    {
        outFile << processLine(line, s1, s2) << std::endl;
    }
    inFile.close();
    outFile.close();
}

int main(int argc, char** argv)
{
    if (argc != 5)
    {
        std::cout << "Usage: input_filename output_filename s1 s2 \n" ;
        return (1);
    }

    std::string input_filename = argv[1];
    std::string output_filename = argv[2];
    std::string orig_s = argv[3];
    std::string new_s = argv[4];

    if (new_s.empty() || orig_s.empty() || new_s == orig_s)
        return (1);

    processFiles(input_filename, output_filename, orig_s, new_s);
    return 0;
}