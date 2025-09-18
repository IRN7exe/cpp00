/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:33:57 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/04/26 16:52:32 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#ifndef SIZE
#define SIZE 8
#endif

class PhoneBook {
private:
	Contact arr_cont[SIZE];
	int numContact;
	int	lastIndex;
public:
	PhoneBook();
	PhoneBook(int id);
	void addContact(const Contact &newContact);
	std::string checkLen(std::string str) const;
	void printBook() const;
	void printAllContactsData(int index) const;
	int getNumContact() const;
	int	checkIndex() const;
};

#endif