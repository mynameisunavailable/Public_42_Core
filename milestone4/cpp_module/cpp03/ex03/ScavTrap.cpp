#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	print_line("Scavtrap Default constructor called");
	_hp = 100;
	_ep = 50;
	_ad = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	print_line("Scavtrap Name constructor called");
	_hp = 100;
	_ep = 50;
	_ad = 20;
}

ScavTrap::ScavTrap(const ScavTrap& item): ClapTrap(item)
{
	print_line("Scavtrap Copy constructor called");
	*this = item;
}

ScavTrap&	ScavTrap::operator=	(const ScavTrap& item)
{
	print_line("Scavtrap Copy assignment operator called");
	if (&item != this)
	{
		this->_name = item._name;
		this->_hp = item._hp;
		this->_ep = item._ep;
		this->_ad = item._ad;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	print_line("Scavtrap Destructor called");
}

void	ScavTrap::attack(const std::string& target)
{
	std::stringstream	msg;

	if (checkActionable() == false)
		return ;
	msg << "ScavTrap " << _name << " attacks " << target;
	msg << ", causing " << _ad << " points of damage!";
	print_line(msg.str());
	_ep--;
}

void ScavTrap::guardGate()
{
	print_line("Scavtrap " + _name + " is guarding the gate 😎");
}