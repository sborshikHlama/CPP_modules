/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:24 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 17:04:47 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
public:
	Cat();
	Cat(const Cat& obj);
	Cat& operator=(const Cat& rightStamp);
	~Cat();
	void makeSound() const override;
};