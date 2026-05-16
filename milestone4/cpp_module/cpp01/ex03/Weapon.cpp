#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	_type = type;
}

const std::string& Weapon::getType(void){
	const std::string& res = _type;
	return (res);
}

void Weapon::setType(std::string type){
	_type = type;
}
