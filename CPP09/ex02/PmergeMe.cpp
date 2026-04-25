#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cmath>

typedef std::pair<int, int> Pair;

PmergeMe::PmergeMe(const std::string &s) {
  std::stringstream ss(s);
  std::string token;
  std::vector<int> raw_nums;

  while (ss >> token) {
    for (size_t i = 0; i < token.length(); ++i) {
      if (!isdigit(token[i]))
        throw std::runtime_error("Error");
    }
    long val = std::atol(token.c_str());
    if (val < 0 || val > 2147483647)
      throw std::runtime_error("Error");
    raw_nums.push_back(static_cast<int>(val));
  }
  if (raw_nums.empty())
    throw std::runtime_error("Error");

  _printSequence("Before: ", raw_nums);

  double time_vec = _timeAndSolve(_vec, raw_nums);
  double time_deq = _timeAndSolve(_deq, raw_nums);

  _printSequence("After:  ", _vec);

  _printTime(raw_nums.size(), "std::vector", time_vec);
  _printTime(raw_nums.size(), "std::deque ", time_deq);
}

void PmergeMe::_printSequence(const std::string &prefix,
                              const std::vector<int> &nums) const {
  std::cout << prefix;
  for (size_t i = 0; i < nums.size(); ++i)
    std::cout << nums[i] << (i == nums.size() - 1 ? "" : " ");
  std::cout << std::endl;
}

void PmergeMe::_printTime(size_t size, const std::string &name,
                          double time) const {
  std::cout << "Time to process a range of " << size << " elements with "
            << name << " : " << std::fixed << std::setprecision(5) << time
            << " us" << std::endl;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    _vec = other._vec;
    _deq = other._deq;
  }
  return *this;
}

std::vector<int> &PmergeMe::getVec() { return _vec; }

std::deque<int> &PmergeMe::getDeq() { return _deq; }

long _generateJacobsthal(long n) {
  return ((1L << (n + 1)) + (n % 2 == 0 ? 1 : -1)) / 3;
}

std::vector<size_t> _generateInsertionOrder(size_t size) {

  std::vector<size_t> insertionOrder;
  std::vector<size_t> jacob;

  jacob.push_back(0);
  jacob.push_back(1);

  while (jacob.back() < size)
    jacob.push_back(_generateJacobsthal(jacob.size()));

  for (size_t i = 1; i < jacob.size() && insertionOrder.size() < size; i++) {

    size_t prev = jacob[i - 1];
    size_t curr = jacob[i];
    size_t upperLimit = std::min(curr, size);

    // Why preincrement?
    for (size_t j = upperLimit; j > prev; --j) {
      insertionOrder.push_back(j - 1);
    }
  }

  return insertionOrder;
}
