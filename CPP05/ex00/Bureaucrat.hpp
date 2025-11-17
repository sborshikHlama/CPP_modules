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

#pragma once
#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	class GradeTooHighException: public std::exception {
	public:
		const char* what() const noexcept override;
	};
	class GradeTooLowException: public std::exception {
	public:
		const char* what() const noexcept override;
	};
	Bureaucrat(const std::string name, const int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &obj);
	const std::string getName() const;
	const int getGrade() const;
	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &obj);
