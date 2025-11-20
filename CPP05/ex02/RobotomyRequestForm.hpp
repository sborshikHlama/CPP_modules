/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:18:31 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:33:19 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : AForm {
private:
  const std::string &target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  ~RobotomyRequestForm();
  void beSigned(const Bureaucrat &obj) override;
  void execute(const Bureaucrat &executor) override;
};
