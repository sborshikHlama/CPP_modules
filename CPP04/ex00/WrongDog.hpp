/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:27:44 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 17:18:59 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongDog: public WrongAnimal
{
public:
	WrongDog();
	WrongDog(const WrongDog& obj);
	WrongDog& operator=(const WrongDog& rightStamp);
	~WrongDog();
	void makeSound() const;
};