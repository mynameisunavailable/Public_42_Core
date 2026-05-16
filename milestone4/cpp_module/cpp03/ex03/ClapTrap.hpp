#ifndef CLAPTRAP_HPP
#define  CLAPTRAP_HPP

#include <iostream>
// #include <string>
#include <sstream>
#include <climits>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& item);
		ClapTrap&	operator=	(const ClapTrap& item);
		~ClapTrap(void);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		bool	checkActionable(void);

	protected:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_ad;
};

void	print_line(std::string s);

#endif