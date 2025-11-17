#include "Form.hpp"

const char* Form::GradeTooHighException::what() const noexcept
{
	return ("grade is too high");
}

const char* Form::GradeTooLowException::what() const noexcept 
{
	return ("grade is too low");
}

Form::Form(const std::string name): name(name), gradeExecute(0), gradeSign(0)
{
	this->isSigned = false;
}

Form::~Form(){}