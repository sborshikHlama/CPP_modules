/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:45:52 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 15:45:53 by aevstign         ###   ########.fr       */
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
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
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
  os << "Bureaucrat name:" << obj.getName()
     << ", bureaucrat grade: " << obj.getGrade();
  return (os);
}

void Bureaucrat::decrementGrade() {
  if (this->grade + 1 > 150)
    throw Bureaucrat::GradeTooLowException();
  this->grade++;
}

void Bureaucrat::incrementGrade() {
  if (this->grade - 1 < 1)
    throw Bureaucrat::GradeTooHighException();
  this->grade--;
}
