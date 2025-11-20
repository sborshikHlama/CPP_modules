/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:35:14 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:32:25 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  try {
    Bureaucrat b("MisterN", 1);
    PresidentialPardonForm pf("Ivan Zolo");
    b.signForm(pf);
    b.executeForm(pf);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
