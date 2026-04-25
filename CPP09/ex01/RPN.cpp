#include "RPN.hpp"
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN::RPN(const std::string &input) {
    for (std::string::const_iterator it = input.begin(); it != input.end(); it++) {
        if (std::isdigit(*it)) {
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

double RPN::_plusOp(double &a, double &b) {
  return b + a;
}
double RPN::_minusOp(double &a, double &b) {
  return b - a;
}
double RPN::_multOp(double &a, double &b) {
  return b * a;
}
double RPN::_divOp(double &a, double &b) {
  if (a == 0)
    throw std::runtime_error("Error");
  return b / a;
}

void RPN::_execOp(double (RPN::*callback)(double &a, double &b)) {
  if (this->_stack.size() < 2)
    throw std::runtime_error("Error");

  double a = this->_stack.top();
  this->_stack.pop();
  double b = this->_stack.top();
  this->_stack.pop();
  this->_stack.push((this->*callback)(a, b));
}

double RPN::getResult() 
{
	if (_stack.empty())
		throw std::runtime_error("Error");
	else if (_stack.size() > 1)
		throw std::runtime_error("Error");
	return (_stack.top());
}