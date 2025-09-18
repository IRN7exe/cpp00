/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:33:53 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/04/26 16:52:23 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cassert>

PhoneBook::PhoneBook()
{
	numContact = 0;
	lastIndex = 0;
}

PhoneBook::PhoneBook(int id)
{
	lastIndex = id;
}

int PhoneBook::getNumContact() const
{
	return numContact;
}

void PhoneBook::addContact(const Contact &newContact)
{
	int index;

	numContact += 1;
	index = newContact.getIdx();
	lastIndex = index % SIZE;	
	arr_cont[lastIndex] = newContact;
}

std::string PhoneBook::checkLen(std::string str) const
{
	if (str.length() > 10)
	    str = str.substr(0, 9) + ".";
	return (str);
}

void PhoneBook::printBook() const
{
	int i;
	int size;
	std::string str;

	i = 0;
	size = 0;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	if (numContact > SIZE)
		size = SIZE;
	else
		size = numContact;
	while (i < size)
	{
		const Contact &contact = this->arr_cont[i];
		std::cout << std::setw(10) << contact.getIdx() << "|";
		std::cout << std::setw(10) << checkLen(contact.getFirst()) << "|";
		std::cout << std::setw(10) << checkLen(contact.getLast()) << "|";
		std::cout << std::setw(10) << checkLen(contact.getNick()) << std::endl;
		i++;
	}
}

void PhoneBook::printAllContactsData(int index) const
{
	//assert(index >= 0 && index <= SIZE);
	const Contact &contact = arr_cont[index];
	std::cout << "\nFirst name: " << contact.getFirst();
	std::cout << "\nLast name: " << contact.getLast();
	std::cout << "\nNickname: " << contact.getNick();
	std::cout << "\nPhone number: " << contact.getPhone();
	std::cout << "\nDarkest secret: " << contact.getSecret() << std::endl;
}
