/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:18:27 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:19:23 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {};

RobotomyRequestForm::~RobotomyRequestForm() {};

void RobotomyRequestForm::beSigned(const Bureaucrat &obj) {
  if (obj.getGrade() <= this->getGradeSign())
    this->setIsSigned(true);
  else
    throw RobotomyRequestForm::GradeTooLowException();
}

const char *
RobotomyRequestForm::RobotomyFailedException::what() const noexcept {
  return ("robotomy failed");
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) {
  if (!this->getIsSigned()) {
    std::cout << "robotomy failed" << std::endl;
    throw RobotomyRequestForm::FormNotSignedException();
  }
  if (executor.getGrade() <= this->getGradeExecute()) {
    std::cout << "Brrrrr, " << this->target
              << " has been robotomized successfully 50% of the time."
              << std::endl;
  } else {
    std::cout << this->getIsSigned() << std::endl;
    std::cout << "here" << std::endl;
    throw RobotomyRequestForm::GradeTooLowException();
  }
}
