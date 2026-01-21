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

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
private:
  const std::string target;

public:
  class RobotomyFailedException : public std::exception {
  public:
    const char *what() const throw();
  };
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &obj);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
  ~RobotomyRequestForm();
  void executeAction() const;
};

#endif
