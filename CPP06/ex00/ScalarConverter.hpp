#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &src);
  ~ScalarConverter();
  ScalarConverter &operator=(ScalarConverter const &rhs);

public:
  static void convert(std::string &literal);
};

#endif