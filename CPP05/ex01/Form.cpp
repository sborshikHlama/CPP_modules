/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:34:08 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:09:55 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw() {
  return ("grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
  return ("grade is too low");
}

Form::Form()
    : name("default"), isSigned(false), gradeSign(150), gradeExecute(150) {}

Form::Form(const std::string &name, int gradeExecute, int gradeSign)
    : name(name), isSigned(false), gradeSign(gradeSign),
      gradeExecute(gradeExecute) {
  if (this->gradeExecute > 150 || this->gradeSign > 150)
    throw Form::GradeTooLowException();
  if (this->gradeExecute < 1 || this->gradeSign < 1)
    throw Form::GradeTooHighException();
}

Form::Form(const Form &obj)
    : name(obj.name), isSigned(obj.isSigned), gradeSign(obj.gradeSign),
      gradeExecute(obj.gradeExecute) {}

Form &Form::operator=(const Form &obj) {
  if (this != &obj) {
    this->isSigned = obj.isSigned;
  }
  return (*this);
}

Form::~Form() {}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "form name: " << form.getName()
     << " sign grade: " << form.getGradeSign()
     << " execute grade: " << form.getGradeExecute()
     << " is form signed?: " << form.getIsSigned();
  return (os);
}

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= this->gradeSign)
    this->isSigned = true;
  else
    throw Form::GradeTooLowException();
}

int Form::getGradeSign() const { return (this->gradeSign); }

int Form::getGradeExecute() const { return (this->gradeExecute); }

const std::string Form::getName() const { return (this->name); }

bool Form::getIsSigned() const { return (this->isSigned); }
