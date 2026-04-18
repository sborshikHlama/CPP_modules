/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:58:58 by aevstign          #+#    #+#             */
/*   Updated: 2026/04/18 16:35:24 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <fstream>
#include <string>

bool	isValidDate(std::string &line)
{
	int year;
	int month;
	int day;

	year = atoi(line.substr(0, 4).c_str());
	month = atoi(line.substr(4, 6).c_str());
	day = atoi(line.substr(6, 8).c_str());

	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);

	return (true);
}

bool	isDigit(std::string &substring)
{
	for (size_t i = 0; i < substring.length(); i++)
	{
		if (!isdigit(substring[i]))
			return (false);
	}
	return (true);
}

bool	parseDate(std::string &line)
{
	std::string year;
	std::string month;
	std::string day;

	if (line.length() != 10)
	{
		return (false);
	}
	if ((line.substr(4, 5) != "-") || (line.substr(7, 8) != "-"))
	{
		return false;
	}
	
	year = line.substr(0, 4);
	month = line.substr(5, 7);
	day = line.substr(8, 10);
	if (!isDigit(year))
		return (false);
	if (!isDigit(month))
		return (false);
	if (!isDigit(day))
		return (false);

	return (true);
}

int main(int argc, char **argv)
{
	std::string filepath;
	std::string line;

	if (argc < 2)
	{
		std::cout << "Error: could not open the file." << std::endl;
		return (1);
	}

	filepath = argv[1];
	if (filepath.length() == 0)
	{
		std::cout << "Error: could not open the file." << std::endl;
		return (1);
	}

	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cout << "Error: could not open the file." << std::endl;
		return (1);
	}
	
	std::getline(file, line);
	while (std::getline(file, line)) {

	}

	return (0);
}
