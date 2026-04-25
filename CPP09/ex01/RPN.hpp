#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <vector>
#include <string>

class RPN {
    public:
        RPN();
        RPN(const std::string &input);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        double getResult();
        ~RPN();

    private:
      std::stack<double, std::vector<double> > _stack; // Changed to double, std::vector<double> > for consistency with _execOp and C++98
      void _execOp(double (RPN::*callback)(double &, double &));
      double _plusOp(double &a, double &b);
      double _minusOp(double &a, double &b);
      double _multOp(double &a, double &b);
      double _divOp(double &a, double &b);

};

#endif