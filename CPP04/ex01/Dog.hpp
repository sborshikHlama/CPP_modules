/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:24 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 23:19:39 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog& obj);
	Dog& operator=(const Dog& rightStamp);
	~Dog();
	void makeSound() const override;
	void setIdea(int index, std::string const & idea);
	std::string	getIdea(int index) const;
};