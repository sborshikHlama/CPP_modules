/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aevstign <aevstign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:58:58 by aevstign          #+#    #+#             */
/*   Updated: 2026/04/18 18:24:24 by aevstign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool	isValidDate(const std::string &year, const std::string &month, const std::string &day)
{
	int year_int;
	int month_int;
	int day_int;
	int maxDays;

	year_int = atoi(year.c_str());
	month_int = atoi(month.c_str());
	day_int = atoi(day.c_str());

	if (month_int < 1 || month_int > 12)
		return (false);
	if (month_int == 2)
	{
		if (year_int % 400 == 0)
			maxDays = 29;
		else if (year_int % 100 == 0)
			maxDays = 28;
		else if (year_int % 4 == 0)
			maxDays = 29;
		else
			maxDays = 28;
	}
	else if (month_int == 4 || month_int == 6 || month_int == 9 || month_int == 11)
		maxDays = 30;
	else
		maxDays = 31;

	if (day_int < 1 || day_int > maxDays)
		return (false);

	return (true);
}

bool	isAllDigits(const std::string &substring)
{
	for (size_t i = 0; i < substring.length(); i++)
	{
		if (!std::isdigit(substring[i]))
			return (false);
	}
	return (true);
}

bool	checkDate(const std::string &line)
{
	std::string year;
	std::string month;
	std::string day;

	if (line.length() != 10)
	{
		return (false);
	}

	if ((line[4] != '-') || (line[7] != '-'))
	{
		return false;
	}
	
	year = line.substr(0, 4);
	month = line.substr(5, 2);
	day = line.substr(8, 2);
	if (!isAllDigits(year))
		return (false);
	if (!isAllDigits(month))
		return (false);
	if (!isAllDigits(day))
		return (false);
	if (!isValidDate(year, month, day))
		return (false);

	return (true);
}

bool	checkPrice(const std::string &price)
{
	if (price.empty())
		return (false);
	
}



int main(int argc, char **argv)
{
	std::string filepath;
	std::string line;
	std::string::iterator splitPos;
	std::string date;
	std::string price;

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
	while (std::getline(file, line))
	{
		splitPos = std::find(line.begin(), line.end(), '|');
		if (splitPos == line.end())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, splitPos - line.begin());
		if (!checkDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		price = line.substr(splitPos - line.begin() + 1);
	}

	return (0);
}
