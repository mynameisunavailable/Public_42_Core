#ifndef DIAMONDTRAP_HPP
#define  DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& item);
		DiamondTrap&	operator=	(const DiamondTrap& item);
		~DiamondTrap(void);

		void	attack(const std::string& target);
		void	whoAmI();

	private:
		std::string	_name;
};

#endif