#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
  unsigned int _size;
  std::vector<int> _storage;
  Span();

public:
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  void addNumber(int n);
  int shortestSpan();
  int longestSpan();
  ~Span();
};

#endif
