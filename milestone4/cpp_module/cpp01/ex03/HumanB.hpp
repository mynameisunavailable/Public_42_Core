#ifndef HUMANB_HPP
#define  HUMANB_HPP

#include  "Weapon.hpp"

class HumanB
{
	public:
		void attack(void);
		void setWeapon(Weapon& w);

		HumanB(std::string name);

	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif