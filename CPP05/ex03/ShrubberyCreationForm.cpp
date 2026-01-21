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
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
    : AForm(obj), target(obj.target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
  if (this != &obj) {
    AForm::operator=(obj);
  }
  return (*this);
}

void ShrubberyCreationForm::executeAction() const {
  std::string filename;
  filename = this->target + "_shrubbery";
  std::ofstream ofs(filename.c_str());
  ofs << "       _-_ \n"
         "    /~~   ~~\\\n"
         " /~~         ~~\\\n"
         "{               }\n"
         " \\  _-     -_  /\n"
         "   ~  \\\\ //  ~\n"
         " - -   | | _- _\n"
         "  _ -  | |   -_\n"
         "      // \\\\\n";
}
