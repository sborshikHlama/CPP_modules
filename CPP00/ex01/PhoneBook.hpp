/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:37:10 by aevstign          #+#    #+#             */
/*   Updated: 2025/03/28 17:15:59 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
	private:
		int	_next_index;
		int	_counter;
	public:
    		Contact array_of_contacts[MAX_CONTACTS];
			PhoneBook();
			
			void addContact(std::string firstname,std::string lastname,
					std::string nickname, std::string phone_number, std::string darkest_secret);
			int	getCounter();
};

#endif