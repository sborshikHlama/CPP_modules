#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
    public:
        RPN();
        RPN(const std::string &input);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        int getResult();
        ~RPN();

    private:
      std::stack<int> _stack;
      void _execOp(int (RPN::*callback)(int &, int &));
      int _plusOp(int &a, int &b);
      int _minusOp(int &a, int &b);
      int _multOp(int &a, int &b);
      int _divOp(int &a, int &b);

};

#endif