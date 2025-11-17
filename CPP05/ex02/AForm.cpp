/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:34:08 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:09:55 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const noexcept
{
	return ("grade is too high");
}

const char* AForm::GradeTooLowException::what() const noexcept 
{
	return ("grade is too low");
}

AForm::AForm(const std::string name, const int gradeExecute, const int gradeSign):
	name(name), gradeExecute(gradeExecute), gradeSign(gradeSign), isSigned(false)
{
	if (this->gradeExecute > 150 or this->gradeSign > 150)
		throw AForm::GradeTooLowException();
	if (this->gradeExecute < 1 or this->gradeSign < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& obj):
	name(obj.name), gradeExecute(obj.gradeExecute), gradeSign(obj.gradeSign), isSigned(obj.isSigned)
{}

AForm::~AForm(){}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << "AForm name: " << AForm.getName() 
		<< " sign grade: " << AForm.getGradeSign()
		<< " execute grade: " << AForm.getGradeExecute()
		<< " is AForm signed?: " << AForm.getIsSigned();
	return (os);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= this->gradeSign)
		this->isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat& executor)
{
	if (this->isSigned && (executor.getGrade() <= this->gradeExecute))
		this->isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

int	AForm::getGradeSign() const
{
	return (this->gradeSign);
}

int	AForm::getGradeExecute() const
{
	return (this->gradeExecute);
}

const	std::string	AForm::getName() const
{
	return (this->name);
}

bool	AForm::getIsSigned() const
{
	return (this->isSigned);
}

void	AForm::setIsSigned(bool value)
{
	this->isSigned = value;
}
