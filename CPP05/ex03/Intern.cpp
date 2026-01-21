/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21T23:00:00 by aevstign          #+#    #+#             */
/*   Updated: 2026/01/21T23:00:00 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &obj) { (void)obj; }

Intern &Intern::operator=(const Intern &obj) {
  (void)obj;
  return (*this);
}

AForm *Intern::createShrubbery(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
  std::string formNames[] = {"shrubbery creation", "robotomy request",
                             "presidential pardon"};
  AForm *(Intern::*funcs[])(const std::string &) = {
      &Intern::createShrubbery, &Intern::createRobotomy,
      &Intern::createPresidential};

  for (int i = 0; i < 3; i++) {
    if (name == formNames[i]) {
      std::cout << "Intern creates " << name << std::endl;
      return (this->*funcs[i])(target);
    }
  }
  std::cout << "Error: Intern cannot create form " << name << std::endl;
  return (NULL);
}
