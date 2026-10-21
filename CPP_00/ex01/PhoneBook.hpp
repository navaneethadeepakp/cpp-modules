/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:52:47 by naperisw          #+#    #+#             */
/*   Updated: 2026/05/07 16:32:19 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <cctype>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int     currentIndex;
    int     totalContacts;

	std::string formatColumn(std::string text) const;
	bool getField(std::string prompt, std::string &field);

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContacts() const;
};

#endif