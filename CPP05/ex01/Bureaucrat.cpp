/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:35:04 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:12:03 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("grade is too low");
}

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else
    this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
    : name(obj.name), grade(obj.grade) {
  std::cout << "Copy constructor has been called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
  if (this != &obj) {
    this->grade = obj.grade;
  }
  return (*this);
}

const std::string Bureaucrat::getName() const { return (this->name); }

int Bureaucrat::getGrade() const { return (this->grade); }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
  os << obj.getName() << ", bureaucrat grade: " << obj.getGrade();
  return (os);
}

void Bureaucrat::decrementGrade() {
  this->grade++;
  if (this->grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::incrementGrade() {
  this->grade--;
  if (this->grade < 1)
    throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << std::endl;
  } catch (const std::exception &e) {
    std::cout << this->name << " couldn't sign " << form.getName()
              << " because: " << e.what() << std::endl;
  }
}
