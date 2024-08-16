/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:52:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/20 10:40:54 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "iostream"
#include "ctime"

int Account::_nbAccounts = -1;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    time_t t;
    t = time(NULL);

    tm *c_t = localtime(&t);
    std::cout << "[" << c_t->tm_year + 1900 << c_t->tm_mon << c_t->tm_mday << "_" << c_t->tm_hour << c_t->tm_min << c_t->tm_sec << "] ";
}

Account::Account(int initial_deposit)
{
    this->_nbAccounts++;
    this->_totalAmount += initial_deposit;
    this->_totalNbDeposits = 0;
    this->_totalNbWithdrawals = 0;
    this->_accountIndex = this->_nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << this->_nbAccounts \
        << ";" << "amount:" << initial_deposit << ";" << "created" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex \
        << ";" << "p_amount:" << this->_amount << ";deposit:" \
        << deposit << ";amount:" << this->_amount + deposit \
        << ";nb_deposits:" << this->_nbDeposits << std::endl;
    this->_amount = this->_amount + deposit;
    this->_totalAmount += deposit;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    if (this->_amount < withdrawal)
    {
        _displayTimestamp();
        std::cout << "index:" << this->_accountIndex \
        << ";" << "p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;   
        return (1);
    }
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex \
        << ";" << "p_amount:" << this->_amount << ";withdrawal:" \
        << withdrawal << ";amount:" << this->_amount - withdrawal \
        << ";nb_withdrawals:" << this->_nbDeposits << std::endl;
    this->_amount = this->_amount - withdrawal;
    this->_totalAmount -= withdrawal;
    return (0);
}
int		Account::checkAmount( void ) const
{
    return (_amount > 0);
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex \
        << ";" << "amount:" << this->_amount << ";deposits:" << this->_nbDeposits \
        << ";withdrawals:" <<this->_nbWithdrawals << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex \
        << ";" << "amount:" << this->_amount << ";" << "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() + 1 \
        << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() \
        << ";withdrawals:" << getNbWithdrawals() << std::endl;
}