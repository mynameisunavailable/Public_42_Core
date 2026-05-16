#include "Zombie.hpp"

int main (void)
{
	std::string tool = "tool";
	int	num = 4;
	Zombie *heapZ = zombieHorde(num, tool);
	for (int i = 0; i < num; i++)
	{
		heapZ[i].announce();
	}
	delete[] heapZ;

	return (0);
}