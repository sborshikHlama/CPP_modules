/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevsitgn@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:42:54 by aevstign          #+#    #+#             */
/*   Updated: 2025/10/11 12:07:04 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	
public:
	FragTrap(const std::string& name);
	~FragTrap();
	void attack(const std::string& target);
	void highFivesGuys(void);
};
