/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:31 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 16:38:37 by aevstign         ###   ########.fr       */
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
	~Animal();
	Animal& operator=(const Animal& rightStamp);
	virtual void makeSound() const;
	std::string getType() const;
};