/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:52:47 by naperisw          #+#    #+#             */
/*   Updated: 2026/05/11 20:00:29 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    currentIndex = 0;
    totalContacts = 0;
}

PhoneBook::~PhoneBook() {
}

bool::PhoneBook::getField(std::string prompt, std::string &field) {
	while (field.empty()) {
		std::cout << prompt;
		if (!std::getline(std::cin, field)) {
			return 0;
		}
		std::string upperCheck = field;
		for (size_t i = 0; i < upperCheck.length(); i++) {
			upperCheck[i] = toupper(upperCheck[i]);
		}
		if (upperCheck == "CANCEL") {
			std::cout << "Add Conatct Aborted.\n";
			return false;
		}
	}
	return true;
}

void PhoneBook::addContact() {
	std::string fName, lName, nName, phone, secret;

	std::cout << "--- ADD NEW CONTACT---" << std::endl;
	std::cout << "(Type 'CANCEL' at any point to abort and return to main menu)" << std::endl;

	if (!getField("First Name: ", fName)) return ;
	if (!getField("Last Name: ", lName)) return ;
	if (!getField("Nick Name: ", nName)) return ;
	if (!getField("Phone Number: ", phone)) return ;
	if (!getField("Darkest Secret: ", secret)) return ;

	contacts[currentIndex].setContact(fName, lName, nName, phone, secret);

	if (totalContacts < 8)
		totalContacts++;
	currentIndex = (currentIndex + 1) % 8;
	std::cout << " Contact Succesfully Added" << std::endl;
}

std::string PhoneBook::formatColumn(std::string text) const {
	if (text.length() > 10) {
		return text.substr(0,9) + ".";
	}
	return text;
}

void PhoneBook::searchContacts() const {
	if (totalContacts == 0) {
    	std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------" <<std::endl;
	std::cout << "|" << std::setw(10) << "Index"
			  << "|" << std::setw(10) << "First Name"
			  << "|" << std::setw(10) << "Last Name"
			  << "|" << std::setw(10) << "Nick Name" << "|" << std::endl;
	std::cout << "---------------------------------------------" <<std::endl;

	for (int i = 0; i < totalContacts; i++) {
		std::cout << "|" << std::setw(10) << i
				  << "|" << std::setw(10) << formatColumn(contacts[i].getFirstName())
				  << "|" << std::setw(10) << formatColumn(contacts[i].getLastName())
				  << "|" << std::setw(10) << formatColumn(contacts[i].getNickName()) << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" <<std::endl;

	std::string indexStr;
	std::cout << "Enter the index of the conatct to view details: ";
	std::getline(std::cin, indexStr);

	if (indexStr.length() == 1 && indexStr[0] >= '0' && indexStr[0] <= '7') {
		int index = indexStr[0] - '0';
		if (index < totalContacts) {
			std::cout << "\n--- CONTACT INFO ---" << std::endl;
			contacts[index].displayFullContact();
		} else {
			std::cout << "Invalid index! No contact exists at that number." << std::endl;
		}
	} else {
		std::cout << "Invalid input! Please enter the valid number." << std::endl;
	}
}