/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:31 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 19:29:39 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#define DEBUG 0

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& obj);
	virtual ~Animal();
	Animal& operator=(const Animal& rightStamp);
	virtual void makeSound() const;
	std::string getType() const;
};