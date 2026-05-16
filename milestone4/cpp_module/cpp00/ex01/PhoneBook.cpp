#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cctype>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	CurrentIdx = 0;
}

static std::string inputField(std::string prompt)
{
	std::string buf;

	do {
		std::cout << prompt;
		std::getline(std::cin, buf);
		if (buf.empty())
			std::cout << "field cannot be empty.\n";
	} while (buf.empty());
	return (buf);
}

void PhoneBook::addContact()
{
	std::string buf;
	int i;

	i = CurrentIdx % 8;
	buf = inputField("first name:");
	p[i].SetFirstname(buf);
	buf = inputField("last name:");
	p[i].Setlastname(buf);
	buf = inputField("NickName:");
	p[i].SetNickName(buf);
	buf = inputField("phone number:");
	p[i].SetPhonenum(buf);
	buf = inputField("darkest secret:");
	p[i].SetDarkestSec(buf);
	CurrentIdx++;
}

static void printField10W(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) + ".";
	}
	else
	{
		std::cout << std::setw(10) << str;
	}
}

void PhoneBook::displaySavedContacts()
{
	std::string buffer;
	int			cur;
	
	std::cout << "     index|first name| last name|  NickName";
	std::cout << "\n";
	cur = 0;
	while (cur < CurrentIdx && cur < 8)
	{
		std::stringstream ss;
		ss << cur;
		printField10W(ss.str());
		std::cout << "|";
		printField10W(p[cur].GetFirstname());
		std::cout << "|";
		printField10W(p[cur].GetLastname());
		std::cout << "|";
		printField10W(p[cur].GetNickName());
		std::cout << "\n";
		cur++;
	}
}

static void srchContctPline(std::string prompt, std::string info)
{
	std::cout << prompt;
	std::cout << info;
	std::cout << "\n";
}

static bool strIsdigit(std::string str)
{
	if (str.empty())
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit((unsigned char) str[i]) == false)
			return (false);
	}
	return (true);
}

void PhoneBook::srchContct()
{
	std::string buffer;
	std::string fool;
	int			i;

	displaySavedContacts();
	std::cout << "enter the index of the entry: ";
	std::getline(std::cin, fool);
	i = -1;
	if (strIsdigit(fool) == false)
	{
		std::cout << "index is not digit\n";
		return ;
	}
	i = atoi(fool.c_str());
	if (i < 0 || i > 7 || i >= CurrentIdx)
	{
		std::cout << "index out of bound\n";
		return ;
	}
	srchContctPline("first name: ", p[i].GetFirstname());
	srchContctPline("last name: ", p[i].GetLastname());
	srchContctPline("NickName: ", p[i].GetNickName());
	srchContctPline("phone number: ", p[i].GetPhonenum());
	srchContctPline("darkest secret: ", p[i].GetDarkestSec());
}
