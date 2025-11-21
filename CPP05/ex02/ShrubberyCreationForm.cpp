/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:15:09 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:18:05 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {};

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beSigned(const Bureaucrat &obj) {
  if (obj.getGrade() <= this->getGradeSign())
    this->setIsSigned(true);
  else
    throw ShrubberyCreationForm::GradeTooLowException();
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) {
  std::string filename;

  if (!this->getIsSigned()) {
    throw ShrubberyCreationForm::FormNotSignedException();
  }
  if (executor.getGrade() <= this->getGradeExecute()) {
    filename = this->target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    ofs << R"(       _-_ 
        /~~   ~~\
     /~~         ~~\
    {               }
     \  _-     -_  /
       ~  \\ //  ~
     - -   | | _- _
      _ -  | |   -_
          // \\
    )";
  } else {
    throw ShrubberyCreationForm::GradeTooLowException();
  }
}
