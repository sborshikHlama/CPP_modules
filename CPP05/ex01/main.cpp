#include "Bureaucrat.hpp"

int main(void)
{
	try 
	{
		Bureaucrat lipavsky = Bureaucrat("Jan", 160);

	} 
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
}