/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:28:24 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/14 23:21:52 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(const Cat& obj);
	Cat& operator=(const Cat& rightStamp);
	~Cat();
	void makeSound() const override;
	void setIdea(int index, std::string const & idea);
	std::string	getIdea(int index) const;
};