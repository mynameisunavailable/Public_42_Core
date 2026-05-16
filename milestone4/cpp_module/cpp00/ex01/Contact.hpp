#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNum;
		std::string DarkestSec;

	public:
		Contact();
		
		void SetFirstname(std::string s);
		void Setlastname(std::string s);
		void SetNickName(std::string s);
		void SetPhonenum(std::string s);
		void SetDarkestSec(std::string s);

		std::string GetFirstname();
		std::string GetLastname();
		std::string GetNickName();
		std::string GetPhonenum();
		std::string GetDarkestSec();
};

#endif