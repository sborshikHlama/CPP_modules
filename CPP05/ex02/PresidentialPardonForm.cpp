/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:23:11 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 17:10:10 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {};

PresidentialPardonForm::~PresidentialPardonForm() {};

void PresidentialPardonForm::beSigned(const Bureaucrat &b) {
  if (b.getGrade() <= this->getGradeSign())
    this->setIsSigned(true);
  else
    throw PresidentialPardonForm::GradeTooLowException();
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) {
  if (executor.getGrade() <= this->getGradeExecute() && this->getGradeSign()) {

    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
  } else {
    throw PresidentialPardonForm::GradeTooLowException();
  }
};
