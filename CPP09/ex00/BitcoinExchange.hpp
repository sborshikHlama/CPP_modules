#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <cstdlib>
# include <algorithm>

class BitcoinExchange {
  private:
    std::map<std::string, double> _db;

    bool _isValidDate(int year, int month, int day) const;
    bool _checkDate(const std::string &date) const;
    bool _checkPrice(const std::string &price) const;
    bool _isAllDigits(const std::string &str) const;
    std::string _trim(const std::string &str) const;

  public:
    BitcoinExchange();
    BitcoinExchange(const std::string &db_path);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDB(const std::string &filename);
    void processInput(const std::string &filename);
};

#endif