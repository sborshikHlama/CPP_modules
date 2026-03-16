#include "include/whatever.hpp"
#include <iostream>

class Awesome {
public:
  Awesome(void) : _n(0) {}
  Awesome(int n) : _n(n) {}
  Awesome &operator=(Awesome &a) {
    _n = a._n;
    return *this;
  }
  bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
  bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
  bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
  bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
  bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
  bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
  int get_n() const { return _n; }

private:
  int _n;
};
std::ostream &operator<<(std::ostream &o, const Awesome &a) {
  o << a.get_n();
  return o;
}

int main(void) {
  std::cout << "--- 1. Testing with Integers ---" << std::endl;
  int a = 2;
  int b = 3;
  std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
  ::swap(a, b);
  std::cout << "After swap:  a = " << a << ", b = " << b << std::endl;
  std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
  std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

  std::cout << "\n--- 2. Testing with Strings ---" << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
  ::swap(c, d);
  std::cout << "After swap:  c = " << c << ", d = " << d << std::endl;
  std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
  std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

  std::cout << "\n--- 3. Testing with Floats ---" << std::endl;
  float e = 42.42f;
  float f = 21.21f;
  std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
  ::swap(e, f);
  std::cout << "After swap:  e = " << e << ", f = " << f << std::endl;
  std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
  std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

  std::cout << "\n--- 4. Testing with Complex Type (Awesome class) ---" << std::endl;
  Awesome a1(10), a2(20);
  std::cout << "Before swap: a1 = " << a1 << ", a2 = " << a2 << std::endl;
  ::swap(a1, a2);
  std::cout << "After swap:  a1 = " << a1 << ", a2 = " << a2 << std::endl;
  std::cout << "min(a1, a2) = " << ::min(a1, a2) << std::endl;
  std::cout << "max(a1, a2) = " << ::max(a1, a2) << std::endl;

  std::cout << "\n--- 5. Edge Case: Equal Values ---" << std::endl;
  int x = 42;
  int y = 42;
  // min/max return the second argument if they are equal
  std::cout << "min(42, 42) address match: " << (::min(x, y) == y ? "YES" : "NO") << std::endl;
  std::cout << "max(42, 42) address match: " << (::max(x, y) == y ? "YES" : "NO") << std::endl;

  return 0;
}
