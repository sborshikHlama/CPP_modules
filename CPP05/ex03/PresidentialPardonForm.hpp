/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:22:16 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 17:08:36 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
private:
  const std::string target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  ~PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &obj);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
  void executeAction() const;
};

#endif
