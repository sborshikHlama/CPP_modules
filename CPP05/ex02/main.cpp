/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:35:14 by aevstign          #+#    #+#             */
/*   Updated: 2026/01/21T22:55:12+01:00 by aevstign         ###   ########.fr */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

void printHeader(const std::string &title) {
  std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void) {
  std::srand(std::time(NULL));

  printHeader("Bureaucrat Initialization Tests");
  try {
    Bureaucrat top("President", 1);
    std::cout << top << std::endl;
    Bureaucrat bottom("Intern", 150);
    std::cout << bottom << std::endl;
  } catch (std::exception &e) {
    std::cout << "Initialization failed: " << e.what() << std::endl;
  }

  printHeader("ShrubberyCreationForm Tests (Req: sign 145, exec 137)");
  {
    Bureaucrat b("B1", 140);
    ShrubberyCreationForm f("home");
    b.signForm(f);
    b.executeForm(f); // Should fail to execute (140 > 137)

    Bureaucrat bHigh("B2", 130);
    bHigh.executeForm(f); // Should work
  }

  printHeader("RobotomyRequestForm Tests (Req: sign 72, exec 45)");
  {
    Bureaucrat low("LowB", 70);
    RobotomyRequestForm f("TargetA");
    low.signForm(f);
    low.executeForm(f); // Should fail to execute (70 > 45)

    Bureaucrat high("HighB", 1);
    high.executeForm(f); // Should work 50%
    high.executeForm(f); // Should work 50%
    high.executeForm(f); // Should work 50%
  }

  printHeader("PresidentialPardonForm Tests (Req: sign 25, exec 5)");
  {
    Bureaucrat b("B3", 20);
    PresidentialPardonForm f("CriminalX");
    b.signForm(f);
    b.executeForm(f); // Should fail to execute (20 > 5)

    Bureaucrat president("Zaphod", 1);
    president.executeForm(f); // Should work
  }

  printHeader("Unsigned Form Execution Test");
  {
    Bureaucrat b("B4", 1);
    PresidentialPardonForm f("Loki");
    b.executeForm(f); // Should fail (not signed)
  }

  return 0;
}
