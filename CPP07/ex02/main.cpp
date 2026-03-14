#include <iostream>
#include "include/Array.hpp"

int main(void) {

  Array<int> arr(5);
  std::cout << arr.size() << std::endl;
  arr[0] = 1;
  std::cout << arr[0] << std::endl;
  arr[1] = 2;
  std::cout << arr[1] << std::endl;
  arr[2] = 3;
  std::cout << arr[2] << std::endl;
  arr[3] = 4;
  std::cout << arr[3] << std::endl;
  arr[4] = 5;
  std::cout << arr[4] << std::endl;
}
