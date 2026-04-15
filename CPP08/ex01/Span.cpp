#include "include/Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span &other) : _size(other._size), _storage(other._storage) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _size = other._size;
    _storage = other._storage;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
  if (this->_storage.size() >= this->_size) {
    throw std::exception();
  }
  this->_storage.push_back(n);
}

int Span::shortestSpan() const {
  if (_storage.size() < 2) {
    throw std::exception();
  }
  std::vector<int> tmp(_storage);
  std::sort(tmp.begin(), tmp.end());
  std::vector<int> result(tmp.size());
  std::adjacent_difference(tmp.begin(), tmp.end(), result.begin());
  int min = *(std::min_element(result.begin() + 1, result.end()));
  return (min);
}

int Span::longestSpan() const {
  if (_storage.size() < 2) {
    throw std::exception();
  }
  int min = *(std::min_element(_storage.begin(), _storage.end()));
  int max = *(std::max_element(_storage.begin(), _storage.end()));

  return (max - min);
}
