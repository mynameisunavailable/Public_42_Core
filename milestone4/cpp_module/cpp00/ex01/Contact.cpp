#include "Contact.hpp"

Contact::Contact(void) {
	FirstName = "";
	LastName = "";
	NickName = "";
	PhoneNum = "";
	DarkestSec = "";
}

void Contact::SetFirstname(std::string s) {FirstName = s;}
void Contact::Setlastname(std::string s) {LastName = s;}
void Contact::SetNickName(std::string s) {NickName = s;}
void Contact::SetPhonenum(std::string s) {PhoneNum = s;}
void Contact::SetDarkestSec(std::string s) {DarkestSec = s;}

std::string Contact::GetFirstname() {return (FirstName);}
std::string Contact::GetLastname() {return (LastName);}
std::string Contact::GetNickName() {return (NickName);}
std::string Contact::GetPhonenum() {return (PhoneNum);}
std::string Contact::GetDarkestSec() {return (DarkestSec);}