/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel <michel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:17:44 by michel            #+#    #+#             */
/*   Updated: 2025/08/19 19:10:08 by michel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp (void)
{
    std::time_t now = std::time(NULL);
    std::tm *ptm = std::localtime(&now);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", ptm);
    std::cout << "[" << buf << "] ";
}

Account::Account(int initial_deposit) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "Index: "<< _accountIndex
              <<";Amount: "<< _amount
              << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "Index: " << _accountIndex
              << ";Amount: " << _amount
              << ";Closed" << std::endl;
}

int Account::getNbAccounts() {return _nbAccounts;}
int Account::getNbDeposits() {return _totalNbDeposits;}
int Account::getTotalAmount() {return _totalAmount;}
int Account::getNbWithdrawals() {return _totalNbWithdrawals;}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "Account : " << getNbAccounts()
              << ";Deposit : " << getNbDeposits()
              << ";Amount : " << getTotalAmount()
              << ";Withdrawal : " << getNbWithdrawals()
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "Index : " << _accountIndex
              << ";p_amount : " << _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << "depot : " << deposit
              << ";amount : " << _amount
              << ";Nb Depot : " << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "Index : " << _accountIndex
              << "p_amount : " << _amount;
    if (withdrawal > _amount)
    {
        std::cout << "solde insufisant.\n solde restant : " << _amount << "\n";
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "Retrait : " << withdrawal
              << " ;Amount : " << _amount
              << " ;Nombre de retrait : " << _nbWithdrawals
              << std::endl;
    return true;
    
}

int Account::checkAmount() const {return _amount;}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "Index : " << _accountIndex
              << "Amount : " << _amount
              << " ;Nb de depot: " << _nbDeposits
              << " ;Nb de retrait: " << _nbWithdrawals
              << std::endl;
}