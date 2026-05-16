#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
	_weapon = NULL;
}

void HumanB::attack(void){
	if (_weapon == NULL)
		std::cout << _name << " stands helplessly" << std::endl;
	else
	{
		const std::string& weapon = _weapon->getType();
		std::cout << _name << " attacks with their " << weapon << std::endl;
	}
}

void HumanB::setWeapon(Weapon& w){
	_weapon = &w;
}
