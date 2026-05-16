#include "DiamondTrap.hpp"
#include <iostream>

int main( void ) {
	DiamondTrap	blue("Blue");
	DiamondTrap	blueclone = blue;

	blue.attack("red");
	blue.takeDamage(10);
	blue.takeDamage(-1);
	blue.takeDamage(-1);
	blue.beRepaired(10);
	blue.beRepaired(-1);

	blueclone.attack("red");
	blueclone.guardGate();
	blueclone.highFivesGuys();
	blueclone.whoAmI();
	return 0;
}