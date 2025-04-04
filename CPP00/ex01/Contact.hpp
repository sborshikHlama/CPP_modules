/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 08:41:31 by aevstign          #+#    #+#             */
/*   Updated: 2025/03/28 15:47:46 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact {
  private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
	public:
		Contact();
		Contact(std::string firstname,std::string lastname,
			std::string nickname, std::string phone_number, std::string darkest_secret);
		
		std::string getFirstname();
		std::string getLastname();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

