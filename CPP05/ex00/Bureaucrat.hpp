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