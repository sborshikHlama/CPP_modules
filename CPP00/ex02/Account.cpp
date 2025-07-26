//
// Created by Arsenii on 20.07.2025.
//

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
    Account::_displayTimestamp();
    _accountIndex =  Account::_nbAccounts++;
    _amount = initial_deposit;
    std::cout << "index:"
              << _accountIndex
              << ";amount:" << initial_deposit
              << ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
    Account::_nbAccounts--;
}

int Account::getNbAccounts()
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

int Account::checkAmount( void ) const
{
    return (_amount);
}

void Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts
              << ";total:" << Account::_totalAmount
              << ";deposits:" << Account::_totalNbDeposits
              << ";withdrawals:" << Account::_totalNbWithdrawals
              << std::endl;
};

void Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    if (deposit <= 0) return;
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;

    _amount += deposit;
    _nbDeposits++;
    std::cout << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;

    if (_amount >= withdrawal && withdrawal > 0)
    {
        std::cout << ";withdrawal:" << withdrawal;
        _amount -= withdrawal;
        _nbWithdrawals++;
        std::cout << ";amount:" << _amount
                  << ";nb_withdrawals:" << _nbWithdrawals
                  << std::endl;
        Account::_totalNbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        return true;
    }
    else
    {
        std::cout << ";withdrawal:refused"  << std::endl;
        return false;
    }
}

// [YYYYMMDD_HHMMSS]
void    Account::_displayTimestamp()
{
    const time_t      timestamp = time( nullptr );
    const std::tm*    local_tm = std::localtime( &timestamp );
    char        buffer[80];

    std::strftime(buffer, 80, "%Y%m%d_%H%M%S", local_tm);
    std::cout << "[" << buffer << "] ";
}