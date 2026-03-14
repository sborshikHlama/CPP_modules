#include "include/iter.hpp"
#include <iostream>

template <typename T> void print(T a) { std::cout << a << std::endl; }

int main(void) {
  int arr_int[] = {1, 2, 3, 4, 5};
  float arr_float[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
  std::string arr_string[] = {"hello", "world", "!"};
  iter(arr_int, 5, print<int>);
  iter(arr_float, 5, print<float>);
  iter(arr_string, 3, print<std::string>);
  return 0;
}