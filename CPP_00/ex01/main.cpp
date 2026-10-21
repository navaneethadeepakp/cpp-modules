/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naperisw <naperisw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 12:18:06 by naperisw          #+#    #+#             */
/*   Updated: 2026/05/07 13:11:30 by naperisw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook myBook;
	std::string command;

	std::cout << "Welcome to the 80s PhoneBook" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true) {
		std::cout << "\nPhoneBook> ";
		if (!std::getline(std::cin, command)) {
			std::cout << "\nEOF detected. Exiting PhoneBook." << std::endl;
			break;
		}
		for (size_t i = 0; i < command.length(); i++) {
            command[i] = toupper(command[i]);
        }

		if (command == "ADD"){
			myBook.addContact();
		}
		else if (command == "SEARCH") {
			myBook.searchContacts();
		}
		else if (command == "EXIT") {
			std::cout << "Shuting down PhoneBook. Goodbye!" <<std::endl;
			break;
		}
		else if (!command.empty()) {
			std::cout << "Command not recognized, Please use ADD, SEARCH, or EXIT" << std::endl;
		}
	}
	return 0;
}