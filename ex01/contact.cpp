/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:18:02 by mm-furi           #+#    #+#             */
/*   Updated: 2025/08/12 18:36:58 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

contact::contact() {}

void	contact::setFirstName(const std::string& s) {_firstname = s;}
void	contact::setLastName(const std::string& s) {_lastname = s;}
void	contact::setNickName(const std::string& s) {_nickname = s;}
void	contact::setPhoneNumber(const std::string& s) {_phonenumber = s;}
void	contact::setDarkestSecret(const std::string& s) {_darkestsecret = s;}

const std::string& contact::firstName() const {return _firstname;}
const std::string& contact::lastName() const {return _lastname;}
const std::string& contact::nickName() const {return _nickname;}
const std::string& contact::phoneNumber() const {return _phonenumber;}
const std::string& contact::darkestSecret() const {return _darkestsecret;}
bool contact::isEmpty() const {
	return _firstname.empty() &&
			_lastname.empty() &&
			_nickname.empty() &&
			_phonenumber.empty() &&
			_darkestsecret.empty();
}

