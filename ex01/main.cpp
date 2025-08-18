/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:36:09 by mm-furi           #+#    #+#             */
/*   Updated: 2025/08/18 18:06:52 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook	book;

	std::string cmd;
	std::cout << "Commands: ADD | SEARCH | EXIT\n";
	while (true)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << "\n";
			break ;
		}
		if (cmd == "ADD" || cmd == "Add" || cmd == "add")
			book.addContact();
		else if (cmd == "SEARCH" || cmd == "Search" || cmd == "search")
			book.searchContact();
		else if (cmd == "EXIT" || cmd == "Exit" || cmd == "exit")
			break ;
		else if (cmd.empty())
			continue ;
		else
			std::cout << "Commande inconnue.\n";
	}
	return (0);
}
