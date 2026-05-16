#include "Zombie.hpp"

int main (void)
{
	std::string tool = "tool";
	Zombie *heapZ = newZombie(tool);
	heapZ->announce();
	delete heapZ;

	std::string fool = "fool";
	randomChump(fool);
	return (0);
}