#include "include/Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : _size(n) {}

void Span::addNumber(int n) {
  if (n >= this->_size()) {
    throw std::exception();
  }
  this->_storage.push_back(n);
}

int Span::shortestSpan() {}

int Span::longestSpan() {
  int min = *(std::min_element(_storage.begin(), _storage.end()));
  int max = *(std::max_element(_storage.begin(), _storage.end()));

  return (max - min);
}
