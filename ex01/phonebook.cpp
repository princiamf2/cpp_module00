/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:56:30 by mm-furi           #+#    #+#             */
/*   Updated: 2025/08/18 18:51:57 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : _count(0) {}

std::string PhoneBook::trim(const std::string& s)
{
	std::string::size_type a = 0, b = s.size();
	while (a < b && (s[a] == ' ' || s[a] == '\t')) a++;
	while (b > a && (s[b-1] == ' ' || s[b-1] == '\t')) b--;
	return (s.substr(a, b-a));
}
std::string PhoneBook::promptLine(const std::string& label)
{
	std::string Line;
	while (true)
	{
		std::cout << label;
		if (!std::getline(std::cin, Line))
		{
			std::cin.clear();
			break;
		}
		Line = trim(Line);
		if (!Line.empty())
			break;
		std::cout << "(champ obligatoire)\n";
	}
	return Line;
}
std::string PhoneBook::shorten(const std::string& s)
{
	if (s.size() <= 10) return s;
	std::string t = s.substr(0, 9);
	t += '.';
	return t;
}

bool PhoneBook::readNonEmpty(const std::string& label, std::string& out)
{
	std::string line;
	while (true)
	{
		std::cout << label;
		if (!std::getline(std::cin, line))
		{
			std::cin.clear();
			return false;
		}
		line = trim(line);
		if (!line.empty())
		{
			out = line;
			return true;
		}
		std::cout << "(champ obligatoire)\n";
	}
}

bool PhoneBook::isAllDigits(const std::string& s)
{
	if (s.empty()) return false;
	for (std::string::size_type i = 0; i < s.size(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
		return false;
	}
	return true;
}

bool PhoneBook::readPhone(std::string &out, std::size_t minLen, std::size_t maxLen)
{
	std::string line;
	while (true)
	{
		std::cout << "Phone Number :";
		if (!std::getline(std::cin, line))
		{
			std::cin.clear();
			return false;
		}
		line = trim(line);
		if (line.empty())
		{
			std::cout << "champ obligatoire\n";
			continue;
		}
		if (!isAllDigits(line))
		{
			std::cout << "le numero doit contenir que des chiffre\n";
			continue;
		}
		if (line.size() < minLen || line.size() > maxLen)
		{
			std::cout << "numero incorect\n";
			continue;
		}
		out = line;
		return true;
	}
}

void PhoneBook::addContact()
{
	contact c;
	std::string s;

	if (!readNonEmpty("First Name :", s))
	{
		std::cout << "Ajout annuler\n";
		return;
	}
	c.setFirstName(s);
	if (!readNonEmpty("Last Name :", s))
	{
		std::cout << "Ajout annuler\n";
		return;
	}
	c.setLastName(s);
	if (!readNonEmpty("Nick Name :", s))
	{
		std::cout << "Ajout annuler'\n";
		return;
	}
	c.setNickName(s);
	if (!readPhone(s, 10u, 13u))
	{
		std::cout << "Ajout annuler\n";
		return;
	}
	c.setPhoneNumber(s);
	if (!readNonEmpty("Darkest Secret :", s))
	{
		std::cout << "Ajout annuler\n";
		return;
	}
	c.setDarkestSecret(s);

	if (_count < 8)
	{
		_contact[_count] = c;
		_count++;
	}
	else
	{
		for (int i = 0; i < 7; ++i)
			_contact[i] = _contact[i + 1];
		_contact[7] = c;
	}
	std::cout << "Ajouter  avec succes (total :" << _count << ")\n";
}

void PhoneBook::displayTable() const
{
	std::cout << "|" << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "First Name"
			  << "|" << std::setw(10) << "Last Name"
			  << "|" << std::setw(10) << "Nick Name"
			  << "|\n";
	for (int i = 0; i < _count; ++i)
	{
		const contact &c = _contact[i];
		std::cout << "|" << std::setw(10) << (i + 1)
				  << "|" << std::setw(10) << shorten(c.firstName())
				  << "|" << std::setw(10) << shorten(c.lastName())
				  << "|" << std::setw(10) << shorten(c.nickName())
				  << "|\n";
	}
}

void PhoneBook::displayContactAt(int idx) const
{
	if (idx < 1 || idx > _count)
	{
		std::cout << "Index invalide\n";
		return;
	}
	const contact &c = _contact[idx -1];
	if (c.isEmpty())
	{
		std::cout << "Aucune donnée pour cet index.\n";
		return;
	}
	std::cout << "First name:     " << c.firstName() << "\n";
	std::cout << "Last name:      " << c.lastName() << "\n";
	std::cout << "Nick name;      " << c.nickName() << "\n";
	std::cout << "Phone number    " << c.phoneNumber() << "\n";
	std::cout << "Darkest secret  " << c.darkestSecret() << "\n";
}

void PhoneBook::searchContact() const
{
	if (_count == 0)
	{
		std::cout << "Le carnet est vide.\n";
		return;
	}
	displayTable();
	std::cout << "Index à afficher (1.." << _count << "): ";
	std::string line;
	if (!std::getline(std::cin, line))
	{
		std::cin.clear();
		return;
	}
	int idx = 0;
	for (std::string::size_type k = 0; k < line.size(); ++k)
	{
		if (line[k] < '0' || line[k] > '9') {idx = -1; break;}
		idx = idx * 10 + (line[k] - '0');
	}
	if (idx <= 0)
	{
		std::cout << "Entrée invalide.\n";
		return;
	}
	displayContactAt(idx);
}
