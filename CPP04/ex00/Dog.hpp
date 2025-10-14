/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:17 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 17:17:27 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
public:
	Dog();
	Dog(const Dog& obj);
	Dog& operator=(const Dog& rightStamp);
	~Dog();
	void makeSound() const override;
};