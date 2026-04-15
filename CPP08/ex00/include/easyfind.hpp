#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iterator>

class ValueNotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Value not found in container";
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int value);

#include "easyfind.tpp"

#endif