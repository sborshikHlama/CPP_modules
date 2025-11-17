/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:35:00 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:05:49 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Form.hpp"

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
	void signForm(Form& form);
};