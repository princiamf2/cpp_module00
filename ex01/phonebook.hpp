/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:34:51 by mm-furi           #+#    #+#             */
/*   Updated: 2025/08/18 18:41:47 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHONEBOOK_HPP
#define  PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		contact _contact[8];
		int _count;
	public:
		PhoneBook();
		void addContact();
		void searchContact() const;
	private:
		static std::string promptLine(const std::string& label);
		static std::string trim(const std::string& s);
		static std::string shorten(const std::string& s);
		void displayTable() const;
		void displayContactAt(int idx) const;
	private:
		static bool readNonEmpty(const std::string& label, std::string& out);
		static bool isAllDigits(const std::string& s);
		static bool readPhone(std::string& out, std::size_t minLen, std::size_t maxLen);
};

#endif
