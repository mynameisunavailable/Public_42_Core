#include "ScavTrap.hpp"
#include <iostream>

int main( void ) {
	ScavTrap	blue("Blue");
	ScavTrap	blueclone = blue;

	blue.attack("red");
	blue.takeDamage(10);
	blue.takeDamage(-1);
	blue.takeDamage(-1);
	blue.beRepaired(10);
	blue.beRepaired(-1);

	blueclone.attack("red");
	blueclone.guardGate();
	return 0;
}