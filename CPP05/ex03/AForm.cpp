/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:34:08 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:09:55 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
  return ("grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
  return ("grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
  return ("form is not signed");
}

AForm::AForm()
    : name("default"), isSigned(false), gradeSign(150), gradeExecute(150) {}

AForm::AForm(const std::string &name, int gradeSign, int gradeExecute)
    : name(name), isSigned(false), gradeSign(gradeSign),
      gradeExecute(gradeExecute) {
  if (this->gradeExecute > 150 || this->gradeSign > 150)
    throw AForm::GradeTooLowException();
  if (this->gradeExecute < 1 || this->gradeSign < 1)
    throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &obj)
    : name(obj.name), isSigned(obj.isSigned), gradeSign(obj.gradeSign),
      gradeExecute(obj.gradeExecute) {}

AForm &AForm::operator=(const AForm &obj) {
  if (this != &obj) {
    this->isSigned = obj.isSigned;
  }
  return (*this);
}

AForm::~AForm() {}

std::ostream &operator<<(std::ostream &os, const AForm &AForm) {
  os << "AForm name: " << AForm.getName()
     << " sign grade: " << AForm.getGradeSign()
     << " execute grade: " << AForm.getGradeExecute()
     << " is AForm signed?: " << AForm.getIsSigned();
  return (os);
}

void AForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= this->gradeSign)
    this->isSigned = true;
  else
    throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const {
  if (!this->isSigned)
    throw AForm::FormNotSignedException();
  if (executor.getGrade() > this->gradeExecute)
    throw AForm::GradeTooLowException();
  this->executeAction();
}

int AForm::getGradeSign() const { return (this->gradeSign); }

int AForm::getGradeExecute() const { return (this->gradeExecute); }

const std::string AForm::getName() const { return (this->name); }

bool AForm::getIsSigned() const { return (this->isSigned); }

void AForm::setIsSigned(bool value) { this->isSigned = value; }
