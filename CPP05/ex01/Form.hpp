#pragma once
#include "Bureaucrat.hpp"

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
	Form(const std::string name);
	Form(const Form& obj);
	void beSigned(const Bureaucrat& obj);
	~Form();
};