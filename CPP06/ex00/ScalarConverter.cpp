#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
  return (*this);
}

static void print_literal(double d) {
  // 1. Char Output
  std::cout << "char: ";
  if (d != d || d > 127 || d < 0) {
    std::cout << "impossible" << std::endl;
  } else if (!std::isprint(static_cast<int>(d))) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
  }

  // 2. Int Output
  std::cout << "int: ";
  if (d != d || d > std::numeric_limits<int>::max() ||
      d < std::numeric_limits<int>::min()) {
    std::cout << "impossible" << std::endl;
  } else {
    std::cout << static_cast<int>(d) << std::endl;
  }

  // 3. Float Output
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

  // 4. Double Output
  std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string &literal) {
  if (literal.empty()) {
    std::cout << "Error: empty literal" << std::endl;
    return;
  }

  double d;
  char *endptr;

  if (literal.length() == 1 && !std::isdigit(literal[0])) {
    d = static_cast<double>(literal[0]);
    print_literal(d);
    return;
  }

  // Use strtod for all other cases
  d = std::strtod(literal.c_str(), &endptr);

  // Validation: if endptr stops before \0 and it's not a single 'f' suffix,
  // it's malformed
  if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
    return;
  }

  print_literal(d);
}
