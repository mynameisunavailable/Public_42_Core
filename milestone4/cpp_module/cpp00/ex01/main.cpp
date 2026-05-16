#include "PhoneBook.hpp"

int main(void)
{
	std::string	fool;
	PhoneBook	contacts;

	while (true)
	{
		std::cout << "Enter ADD, SEARCH or EXIT: ";
		std::getline(std::cin, fool);
		if (std::cin.eof())
			break ;
		if		(fool == "ADD")
			contacts.addContact();
		else if (fool == "SEARCH")
			contacts.srchContct();
		else if (fool == "EXIT")
			break ;
	}
	return (0);
}