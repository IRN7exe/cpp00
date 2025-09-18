/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:25:38 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/04/26 17:45:54 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

std::string checkInput(std::string message);

int	PhoneBook::checkIndex() const
{
	int num;
	int	size;

	while (1)
	{
		std::cout << "Enter index to see more info: ";
		std::cin >> num;
		if (std::cin.eof()) break;
		if (this->numContact >= SIZE)
			size = SIZE;
		else
			size = this->numContact;
		// while (char(std::cin.peek()) != '\n')
		// 	std::cin.get();
		// std::cin.get();
		// std::cin.clear();
		// if (char(std::cin.peek()) == '\n')
    	// 	std::cin.ignore();
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid index. Try again " << std::endl;
			continue;
		}
		else
		{
			std::cin.ignore(32767, '\n');
			if (std::cin.gcount() > 1)
				continue;
		}
		if (num < 0 || num >= size)
		{
			std::cout << "Invalid index. Try again " << std::endl;
			continue;
		}
		break;
	}
	return num;
}

std::string checkInput(std::string message)
{
	std::string str;
	
	if (std::cin.eof()) return (str);
	std::cout << message;
	std::getline (std::cin, str);
	while (str.empty())
	{
		if (std::cin.eof()) break;
		std::cout << "You can not send an empty line, try again: " << std::endl;
		std::cout << message;
		std::getline (std::cin, str);
	}
	return (str);
}

int main(void)
{
	int i;
	int index;
	PhoneBook phoneBook;
	std::string str;

	i = 0;
	while (1)
	{
		std::cout << "Print ADD, SEARCH or EXIT command: ";
		std::getline(std::cin, str);
		if (std::cin.eof()) break;
		if (str == "ADD")
		{
			std::string first = checkInput("First name: ");
			std::string last = checkInput("Last name: ");
			std::string nick = checkInput("Nickname: ");
			std::string phone = checkInput("Phone number: ");
			std::string secret = checkInput("Darkest secret: ");
			Contact contact(i % 8, first, last, nick, phone, secret);
			phoneBook.addContact(contact);
			i++;
		}
		else if ((str == "SEARCH") && (phoneBook.getNumContact() == 0))
			std::cout << "PhoneBook is empty" << std::endl;
		else if ((str == "SEARCH") && (phoneBook.getNumContact() != 0))
		{
			phoneBook.printBook();
			index = phoneBook.checkIndex();
			if (std::cin.eof()) return (1);
			phoneBook.printAllContactsData(index);
		}
		else if (str == "EXIT")
			return (1);
	}
	return (0);
}

//  c++ -Wall -Wextra -Werror -std=c++98 phonebook.cpp contact.cpp main.cpp