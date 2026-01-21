/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:18:27 by aevstign          #+#    #+#             */
/*   Updated: 2026/01/21T22:55:12+01:00 by aevstign         ###   ########.fr */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
    : AForm(obj), target(obj.target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
  if (this != &obj) {
    AForm::operator=(obj);
  }
  return (*this);
}

const char *RobotomyRequestForm::RobotomyFailedException::what() const throw() {
  return ("robotomy failed");
}

void RobotomyRequestForm::executeAction() const {
  std::cout << "* intense drilling noises *" << std::endl;
  if (std::rand() % 2) {
    std::cout << this->target << " has been robotomized successfully!"
              << std::endl;
  } else {
    std::cout << "Robotomy on " << this->target << " failed." << std::endl;
  }
}
