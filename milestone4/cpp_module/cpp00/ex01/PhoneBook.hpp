#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact p[8];
		int CurrentIdx;
	
	public:
		void addContact();
		void srchContct();
		void displaySavedContacts();
		
		PhoneBook();
};

#endif