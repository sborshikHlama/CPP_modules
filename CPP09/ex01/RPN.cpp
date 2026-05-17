#include "RPN.hpp"
#include <cctype>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN::RPN(const std::string &input) {
    for (std::string::const_iterator it = input.begin(); it != input.end(); it++) {
        if (std::isdigit(*it) ) {
            this->_stack.push(*it - '0');
        } else if (*it == '+') {
            _execOp(&RPN::_plusOp);
        } else if (*it == '-') {
            _execOp(&RPN::_minusOp);
        } else if (*it == '*') {
            _execOp(&RPN::_multOp);
        } else if (*it == '/') {
            _execOp(&RPN::_divOp);
        } else if (*it != ' ') {
            throw std::runtime_error("Error");
        }
    }
}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    this->_stack = other._stack;
  }
  return *this;
}

RPN::~RPN() {}

int RPN::_plusOp(int &a, int &b) {
  return b + a;
}
int RPN::_minusOp(int &a, int &b) {
  return b - a;
}
int RPN::_multOp(int &a, int &b) {
  return b * a;
}
int RPN::_divOp(int &a, int &b) {
  if (a == 0)
    throw std::runtime_error("Error");
  return b / a;
}

void RPN::_execOp(int (RPN::*callback)(int &a, int &b)) {
  if (this->_stack.size() < 2)
    throw std::runtime_error("Error");

  int a = this->_stack.top();
  this->_stack.pop();
  int b = this->_stack.top();
  this->_stack.pop();
  this->_stack.push((this->*callback)(a, b));
}

int RPN::getResult() 
{
	if (_stack.empty())
		throw std::runtime_error("Error");
	else if (_stack.size() > 1)
		throw std::runtime_error("Error");
	return (_stack.top());
}