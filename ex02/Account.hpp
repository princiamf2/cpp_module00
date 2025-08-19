/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: michel <michel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:12:51 by michel            #+#    #+#             */
/*   Updated: 2025/08/19 16:44:41 by michel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <ctime>

class Account
{
    private:
        int _accountIndex;
        int _amount;
        int _nbDeposits;
        int _nbWithdrawals;

        static int _nbAccounts;
        static int _totalAmount;
        static int _totalNbDeposits;
        static int _totalNbWithdrawals;

        static void _displayTimestamp(void);

    public:
        Account(int initial_deposit);
        ~Account(void);

        void makeDeposit(int deposit);
        bool makeWithdrawal(int withdrawal);
        int checkAmount(void) const;
        void displayStatus(void) const;

        static int getNbAccounts(void);
        static int getTotalAmount(void);
        static int getNbDeposits(void);
        static int getNbWithdrawals(void);
        static void displayAccountsInfos(void);

};

#endif
