/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:34:51 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:28:14 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
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
  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  AForm();
  AForm(const std::string &name, int gradeSign, int gradeExecute);
  AForm(const AForm &obj);
  AForm &operator=(const AForm &obj);
  virtual void beSigned(const Bureaucrat &obj);
  void execute(const Bureaucrat &executor) const;
  virtual void executeAction() const = 0;
  int getGradeSign() const;
  int getGradeExecute() const;
  const std::string getName() const;
  bool getIsSigned() const;
  void setIsSigned(bool value);
  virtual ~AForm();
};
std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
