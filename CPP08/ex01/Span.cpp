#include "include/Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span(unsigned int n) : _size(n) {}

void Span::addNumber(int n) {
  if (this->_storage.size() >= this->_size) {
    throw std::exception();
  }
  this->_storage.push_back(n);
}

int Span::shortestSpan() {
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

int Span::longestSpan() {
  if (_storage.size() < 2) {
    throw std::exception();
  }
  int min = *(std::min_element(_storage.begin(), _storage.end()));
  int max = *(std::max_element(_storage.begin(), _storage.end()));

  return (max - min);
}
