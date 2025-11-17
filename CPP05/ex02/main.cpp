/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:35:14 by aevstign          #+#    #+#             */
/*   Updated: 2025/11/17 16:32:25 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try 
	{
		Bureaucrat lipavsky = Bureaucrat("Jan", 20);
		AForm	f = AForm("build a road", 13, 15);
		lipavsky.signForm(f);
		std::cout << f << std::endl;
	} 
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
