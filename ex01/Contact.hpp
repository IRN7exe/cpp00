/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:44:58 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/04/26 16:52:49 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include <stdlib.h>

class Contact
{
	private:
		int idx;
		std::string first;
		std::string last;
		std::string nick;
		std::string phone;
		std::string secret;
	public:
		Contact();
		Contact(int i, std::string fn, std::string ln, std::string nn, \
			std::string pn, std::string ds);
		int getIdx() const;
		std::string getFirst() const;
		std::string getLast() const;
		std::string getNick() const;
		std::string getPhone() const;
		std::string getSecret() const;
};

#endif