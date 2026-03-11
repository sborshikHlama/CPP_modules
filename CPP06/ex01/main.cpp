#include "Serializer.hpp"
#include <iostream>

int main() {
  Data myData;
  myData.value = 42;
  myData.name = "Test Data";

  std::cout << "Original Data pointer: " << &myData << std::endl;
  std::cout << "Value: " << myData.value << ", Name: " << myData.name
            << std::endl;

  uintptr_t raw = Serializer::serialize(&myData);
  std::cout << "Serialized (uintptr_t): " << raw << std::endl;

  Data *ptr = Serializer::deserialize(raw);
  std::cout << "Deserialized pointer: " << ptr << std::endl;

  if (ptr == &myData) {
    std::cout << "SUCCESS: Pointers match!" << std::endl;
    std::cout << "Deserialized Value: " << ptr->value << ", Name: " << ptr->name
              << std::endl;
  } else {
    std::cout << "FAILURE: Pointers do NOT match!" << std::endl;
    return 1;
  }

  return 0;
}
