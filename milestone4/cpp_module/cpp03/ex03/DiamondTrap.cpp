#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap()
{
	print_line("DiamondTrap Default constructor called");
	_ep = 50;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	print_line("DiamondTrap Name constructor called");
	this->_name = name;
	_ep = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap& item):
	ClapTrap(item), ScavTrap(item), FragTrap(item)
{
	print_line("DiamondTrap Copy constructor called");
	*this = item;
}

DiamondTrap&	DiamondTrap::operator=	(const DiamondTrap& item)
{
	print_line("DiamondTrap Copy assignment operator called");
	if (&item != this)
	{
		this->_name = item._name;
		this->_hp = item._hp;
		this->_ep = item._ep;
		this->_ad = item._ad;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	print_line("DiamondTrap Destructor called");
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	print_line(_name + " " + ClapTrap::_name);
}