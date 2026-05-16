#ifndef FRAGTRAP_HPP
#define  FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& item);
		FragTrap&	operator=	(const FragTrap& item);
		~FragTrap(void);

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif