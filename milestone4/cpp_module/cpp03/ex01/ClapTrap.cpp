#include "ClapTrap.hpp"

void	print_line(std::string s)
{
	std::cout << s << std::endl;
}

ClapTrap::ClapTrap(void): _name("unnamed"), _hp(10), _ep(10), _ad(0)
{
	print_line("Default constructor called");
}

ClapTrap::ClapTrap(std::string name)
{
	print_line("Name constructor called");
	_name = name;
	_hp = 10;
	_ep = 10;
	_ad = 0;
}

ClapTrap::ClapTrap(const ClapTrap& item)
{
	print_line("Copy constructor called");
	*this = item;
}

ClapTrap&	ClapTrap::operator=	(const ClapTrap& item)
{
	print_line("Copy assignment operator called");
	if (&item != this)
	{
		this->_name = item._name;
		this->_hp = item._hp;
		this->_ep = item._ep;
		this->_ad = item._ad;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	print_line("Destructor called");
}

bool	ClapTrap::checkActionable(void)
{
	std::string	msg;
	bool		status = true;

	msg = "ClapTrap " + _name;
	if (_hp <= 0)
	{
		print_line(msg + " health point <= 0");
		status = false;
	}
	if (_ep <= 0)
	{
		print_line(msg + " energy point <= 0");
		status = false;
	}
	return (status);
}

void	ClapTrap::attack(const std::string& target)
{
	std::stringstream	msg;

	if (checkActionable() == false)
		return ;
	msg << "ClapTrap " << _name << " attacks " << target;
	msg << ", causing " << _ad << " points of damage!";
	print_line(msg.str());
	_ep--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::stringstream	msg;

	if ((long) _hp - (long) amount < INT_MIN)
	{
		print_line("damage value overflow");
		return ;
	}
	msg << "ClapTrap " << _name << " takes " << amount << " points of damage!";
	print_line(msg.str());
	_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::stringstream	msg;

	if (checkActionable() == false)
		return ;
	if ((long) _hp + (long) amount > INT_MAX)
	{
		print_line("HP value overflow");
		return ;
	}
	msg << "ClapTrap " << _name << " receives " << amount << " points of healing!";
	print_line(msg.str());
	_hp += amount;
	_ep--;
}
