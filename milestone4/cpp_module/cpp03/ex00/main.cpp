#include "ClapTrap.hpp"
#include <iostream>

int main( void ) {
	ClapTrap	blue("Blue");
	ClapTrap	blueclone = blue;

	blue.attack("red");
	blue.takeDamage(10);
	blue.beRepaired(10);
	blue.takeDamage(-1);
	blue.takeDamage(-1);
	blue.beRepaired(10);
	blue.beRepaired(-1);

	blueclone.attack("red");
	return 0;
}