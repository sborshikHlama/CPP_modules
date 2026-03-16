#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <stdexcept>
#include <iostream>

template <typename T> Array<T>::Array(): _data(NULL), _size(0) {}
template <typename T> Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T> Array<T>::Array(const Array<T> &other) {
  this->_data = new T[other._size]();
  this->_size = other._size;
  for (unsigned int i = 0; i < other._size; i++) {
    this->_data[i] = other._data[i];
  }
}

template <typename T> Array<T>& Array<T>::operator=(const Array<T> &other) {
  if (this != &other) {
    T *new_data = new T[other._size]();
    for (unsigned int i = 0; i < other._size; i++) {
      new_data[i] = other._data[i];
    }
    delete[] this->_data;
    this->_data = new_data;
    this->_size = other._size;
  }
  return (*this);
}

template <typename T> T& Array<T>::operator[](unsigned int index) {
  if (index >= this->_size)
    throw std::exception();
  return (this->_data[index]);
}

template <typename T> const T& Array<T>::operator[](unsigned int index) const {
  if (index >= this->_size) {
    throw std::exception();
  }
  return (this->_data[index]);
}

template <typename T> unsigned int Array<T>::size() const { return (this->_size); }

template <typename T> Array<T>::~Array() { delete[] this->_data; }

#endif