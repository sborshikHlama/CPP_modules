#include <iostream>
#include "include/Array.hpp"

int main(void) {
    std::cout << "--- 1. Default constructor and size() ---" << std::endl;
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;

    std::cout << "\n--- 2. Parameter constructor and value-initialization ---" << std::endl;
    unsigned int n = 5;
    Array<int> arr(n);
    std::cout << "Size: " << arr.size() << std::endl;
    bool all_zeros = true;
    for (unsigned int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) all_zeros = false;
    }
    std::cout << "All elements zero-initialized: " << (all_zeros ? "YES" : "NO") << std::endl;

    std::cout << "\n--- 3. Modifying elements ---" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++) {
        arr[i] = i * 10;
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    std::cout << "\n--- 4. Deep copy: Copy Constructor ---" << std::endl;
    Array<int> copy(arr);
    std::cout << "Copy size: " << copy.size() << std::endl;
    copy[0] = 42;
    std::cout << "Original arr[0]: " << arr[0] << " (should be 0)" << std::endl;
    std::cout << "Copy copy[0]: " << copy[0] << " (should be 42)" << std::endl;

    std::cout << "\n--- 5. Deep copy: Assignment Operator ---" << std::endl;
    Array<int> assigned;
    assigned = arr;
    assigned[1] = 99;
    std::cout << "Original arr[1]: " << arr[1] << " (should be 10)" << std::endl;
    std::cout << "Assigned assigned[1]: " << assigned[1] << " (should be 99)" << std::endl;

    std::cout << "\n--- 6. Exception handling (out of bounds) ---" << std::endl;
    try {
        std::cout << "Accessing positive out of bounds..." << std::endl;
        arr[arr.size()] = 100;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- 7. Const correctness ---" << std::endl;
    const Array<int> const_arr(3);
    std::cout << "Const size: " << const_arr.size() << std::endl;
    std::cout << "Const arr[0]: " << const_arr[0] << std::endl;
    // const_arr[0] = 5; // This should fail to compile if uncommented

    std::cout << "\n--- 8. Different type (std::string) ---" << std::endl;
    Array<std::string> str_arr(2);
    str_arr[0] = "Hello";
    str_arr[1] = "World";
    std::cout << str_arr[0] << " " << str_arr[1] << "!" << std::endl;

    return 0;
}
