/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21T23:00:00+01:00 by aevstign          #+#    #+# */
/*   Updated: 2026/01/21T23:00:00 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
public:
  Intern();
  Intern(const Intern &obj);
  Intern &operator=(const Intern &obj);
  ~Intern();

  AForm *makeForm(const std::string &formName, const std::string &target);

private:
  AForm *createShrubbery(const std::string &target);
  AForm *createRobotomy(const std::string &target);
  AForm *createPresidential(const std::string &target);
};

#endif
