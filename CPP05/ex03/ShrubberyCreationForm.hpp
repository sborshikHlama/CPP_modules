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

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
private:
  const std::string target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &obj);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
  void executeAction() const;
};

#endif
