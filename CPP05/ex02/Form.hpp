/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:34:51 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:28:14 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeSign;
	const int gradeExecute;
public:
	class GradeTooHighException: public std::exception {
	public:
		const char* what() const noexcept override;
	};
	class GradeTooLowException: public std::exception {
	public:
		const char* what() const noexcept override;
	};
	Form(const std::string name, const int gradeExecute, const int gradeSign);
	Form(const Form& obj);
	void	beSigned(const Bureaucrat& obj);
	int		getGradeSign() const;
	int		getGradeExecute() const;
	const	std::string getName() const;
	bool	getIsSigned() const;
	~Form();
};
std::ostream& operator<<(std::ostream &os, const Form &f);
