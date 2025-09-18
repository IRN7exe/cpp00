/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:13:31 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/05/16 17:42:47 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(): idx(0) {}

Contact::Contact(int i, std::string fn, std::string ln, std::string nn, \
		std::string pn, std::string ds): idx(i), first(fn), last(ln), \
		nick(nn), phone(pn), secret(ds) {}

int Contact::getIdx() const {return idx;}

std::string Contact::getFirst() const {return first;}

std::string Contact::getLast() const {return last;}

std::string Contact::getNick() const {return nick;}

std::string Contact::getPhone() const {return phone;}

std::string Contact::getSecret() const {return secret;}
