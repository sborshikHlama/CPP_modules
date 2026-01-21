/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:45:49 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 15:51:09 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &obj);
  Bureaucrat &operator=(const Bureaucrat &obj);
  ~Bureaucrat();
  const std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif
