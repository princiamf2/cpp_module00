/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:54:11 by mm-furi           #+#    #+#             */
/*   Updated: 2025/08/12 18:32:18 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CPP
#define CONTACT_CPP

#include <string>

class contact
{
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkestsecret;
	public:
		contact();

		void setFirstName(const std::string& s);
		void setLastName(const std::string& s);
		void setNickName(const std::string& s);
		void setPhoneNumber(const std::string& s);
		void setDarkestSecret(const std::string& s);

		const std::string& firstName() const;
		const std::string& lastName() const;
		const std::string& nickName() const;
		const std::string& phoneNumber() const;
		const std::string& darkestSecret() const;
		bool isEmpty() const;
};
#endif
