/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:15:09 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:33:29 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : AForm {
private:
  const std::string target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm();
  void beSigned(const Bureaucrat &obj) override;
  void execute(const Bureaucrat &executor) override;
};
