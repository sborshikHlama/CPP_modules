/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:34:51 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:08:42 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
  const std::string name;
  bool isSigned;
  const int gradeSign;
  const int gradeExecute;

public:
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  Form();
  Form(const std::string &name, int gradeExecute, int gradeSign);
  Form(const Form &obj);
  Form &operator=(const Form &obj);
  ~Form();
  void beSigned(const Bureaucrat &obj);
  int getGradeSign() const;
  int getGradeExecute() const;
  const std::string getName() const;
  bool getIsSigned() const;
};
std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
