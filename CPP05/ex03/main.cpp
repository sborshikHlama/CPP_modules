/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:05:00 by aevstign          #+#    #+#             */
/*   Updated: 2026/01/21T23:05:00 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

void printHeader(const std::string &title) {
  std::cout << "\n--- " << title << " ---" << std::endl;
}

int main(void) {
  Intern someRandomIntern;
  AForm *rrf;

  printHeader("Valid internal creation");
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  if (rrf) {
    Bureaucrat b("Boss", 1);
    b.signForm(*rrf);
    b.executeForm(*rrf);
    delete rrf;
  }

  printHeader("Invalid form creation");
  rrf = someRandomIntern.makeForm("coffee request", "Intern");
  if (rrf) {
    delete rrf;
  }

  printHeader("Other forms");
  rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
  if (rrf) {
    Bureaucrat b("Gardener", 1);
    b.signForm(*rrf);
    b.executeForm(*rrf);
    delete rrf;
  }

  rrf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
  if (rrf) {
    Bureaucrat b("President", 1);
    b.signForm(*rrf);
    b.executeForm(*rrf);
    delete rrf;
  }

  return 0;
}
