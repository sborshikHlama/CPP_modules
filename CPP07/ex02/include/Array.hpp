#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T> class Array {

private:
  T *_data;
  unsigned int _size;

public:
  Array();
  Array(unsigned int n);
  Array(const Array &other);
  Array &operator=(const Array &other);
  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;
  unsigned int size() const;
  ~Array();
};

#include "Array.tpp"

#endif