#include "FragTrap.hpp"
#include <iostream>

int main( void ) {
	FragTrap	blue("Blue");
	FragTrap	blueclone = blue;

	blue.attack("red");
	blue.takeDamage(10);
	blue.takeDamage(-1);
	blue.takeDamage(-1);
	blue.beRepaired(10);
	blue.beRepaired(-1);
	blue.highFivesGuys();

	blueclone.attack("red");
	blueclone.highFivesGuys();
	return 0;
}