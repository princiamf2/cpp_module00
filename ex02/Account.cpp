/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:17:44 by michel            #+#    #+#             */
/*   Updated: 2025/08/20 13:37:35 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp (void)
{
    std::time_t t = std::time(NULL);
    std::tm *lt = std::localtime(&t);
    char buf[20];
    if (lt && std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", lt))
        std::cout << "[" << buf << "] ";
    else
        std::cout << "[00000000_000000] ";
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    ++_nbAccounts;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:"<< _accountIndex
              <<";amount:"<< _amount
              << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";Closed" << std::endl;
}

int Account::getNbAccounts() {return _nbAccounts;}
int Account::getNbDeposits() {return _totalNbDeposits;}
int Account::getTotalAmount() {return _totalAmount;}
int Account::getNbWithdrawals() {return _totalNbWithdrawals;}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "account:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposit:" << getNbDeposits()
              << ";withdrawal:" << getNbWithdrawals()
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << "deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawl:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;
    return true;

}

int Account::checkAmount() const {return _amount;}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}
