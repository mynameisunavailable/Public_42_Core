#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	print_line("Fragtrap Default constructor called");
	_hp = 100;
	_ep = 100;
	_ad = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	print_line("Fragtrap Name constructor called");
	_hp = 100;
	_ep = 100;
	_ad = 30;
}

FragTrap::FragTrap(const FragTrap& item): ClapTrap(item)
{
	print_line("Fragtrap Copy constructor called");
	*this = item;
}

FragTrap&	FragTrap::operator=	(const FragTrap& item)
{
	print_line("Fragtrap Copy assignment operator called");
	if (&item != this)
	{
		this->_name = item._name;
		this->_hp = item._hp;
		this->_ep = item._ep;
		this->_ad = item._ad;
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	print_line("Fragtrap Destructor called");
}

void	FragTrap::attack(const std::string& target)
{
	std::stringstream	msg;

	if (checkActionable() == false)
		return ;
	msg << "FragTrap " << _name << " attacks " << target;
	msg << ", causing " << _ad << " points of damage!";
	print_line(msg.str());
	_ep--;
}

void	FragTrap::highFivesGuys(void)
{
	print_line("Fragtrap " + _name + " positive high-five request sent ✋");
}