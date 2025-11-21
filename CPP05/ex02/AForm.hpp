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

#pragma once
#include <iostream>

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
    const char *what() const noexcept override;
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const noexcept override;
  };
  class FormNotSignedException : public std::exception {
  public:
    const char *what() const noexcept override;
  };
  AForm(const std::string name, const int gradeSign, const int gradeExecute);
  AForm(const AForm &obj);
  virtual void beSigned(const Bureaucrat &obj);
  virtual void execute(const Bureaucrat &executor);
  int getGradeSign() const;
  int getGradeExecute() const;
  const std::string getName() const;
  bool getIsSigned() const;
  void setIsSigned(bool value);
  virtual ~AForm();
};
std::ostream &operator<<(std::ostream &os, const AForm &f);
