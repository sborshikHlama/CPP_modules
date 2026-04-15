#include "include/easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main(void) {
    std::cout << "--- Vector Test (Success) ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(8);

    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- List Test (Failure) ---" << std::endl;
    std::list<int> lst;
    lst.push_back(20);
    lst.push_back(30);

    try {
        std::list<int>::iterator it = easyfind(lst, 1000);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    return 0;
}