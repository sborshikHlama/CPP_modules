#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &db_path) {
    loadDB(db_path);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->_db = other._db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::_trim(const std::string &str) const {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::_isAllDigits(const std::string &str) const {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return !str.empty();
}

bool BitcoinExchange::_isValidDate(int year, int month, int day) const {
    if (month < 1 || month > 12 || day < 1)
        return false;
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        daysInMonth[1] = 29;
    
    if (day > daysInMonth[month - 1])
        return false;
    return true;
}

bool BitcoinExchange::_checkDate(const std::string &date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    
    if (!_isAllDigits(yearStr) || !_isAllDigits(monthStr) || !_isAllDigits(dayStr))
        return false;
    
    return _isValidDate(std::atoi(yearStr.c_str()), std::atoi(monthStr.c_str()), std::atoi(dayStr.c_str()));
}

bool BitcoinExchange::_checkPrice(const std::string &price) const {
    if (price.empty() || price == ".")
        return false;
    
    size_t dotPos = price.find('.');
    if (dotPos != std::string::npos) {
        if (price.find('.', dotPos + 1) != std::string::npos)
            return false;
        std::string before = price.substr(0, dotPos);
        std::string after = price.substr(dotPos + 1);
        if ((!before.empty() && !_isAllDigits(before)) || (!_isAllDigits(after)))
            return false;
    } else {
        if (!_isAllDigits(price))
            return false;
    }
    return true;
}

void BitcoinExchange::loadDB(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = _trim(line.substr(0, commaPos));
            std::string rateStr = _trim(line.substr(commaPos + 1));
            
            if (_checkDate(date)) {
                this->_db[date] = std::atof(rateStr.c_str());
            }
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    std::getline(file, line); // Skip header (date | value)
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = _trim(line.substr(0, pipePos));
        std::string valueStr = _trim(line.substr(pipePos + 1));
        
        if (!_checkDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        
        if (valueStr.empty() || (valueStr[0] == '-' && valueStr.length() == 1)) {
             std::cout << "Error: bad input => " << valueStr << std::endl;
             continue;
        }

        bool isNegative = (valueStr[0] == '-');
        std::string absValueStr = isNegative ? valueStr.substr(1) : valueStr;

        if (!_checkPrice(absValueStr)) {
            std::cout << "Error: bad input => " << valueStr << std::endl;
            continue;
        }
        
        double value = std::atof(valueStr.c_str());
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        
        std::map<std::string, double>::iterator it = _db.lower_bound(date);
        if (it != _db.end() && it->first == date) {
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        } else if (it != _db.begin()) {
            --it;
            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
        } else {
            std::cout << "Error: date too early => " << date << std::endl;
        }
    }
    file.close();
}