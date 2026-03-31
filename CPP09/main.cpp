#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
    return (1);
  }
  std::string filename = argv[1];
  std::map<std::string, float> db;

  std::ifstream file("data.csv");
  if (!file.is_open()) {
    std::cout << "Error: couldn't open file" << std::endl;
    return 1;
  }
  std::string line;

  std::getline(file, line);
  while (std::getline(file, line)) {
    size_t commaPos = line.find(',');
    if (commaPos != std::string::npos) {
      std::string date = line.substr(0, commaPos);
      float rate = std::atof(line.substr(commaPos + 1).c_str());
      db[date] = rate;
    }
  }

  file.close();

  std::ifstream file2("data.csv");
  if (!file2.is_open()) {
    std::cout << "Error: couldn't open file" << std::endl;
    return 1;
  }

  while (std::getline(file, line)) {

  }

  return (0);
}