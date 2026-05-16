#include "Zombie.hpp"

void Zombie::setZombieName( std::string name ) {
	_name = name;
}

Zombie* zombieHorde( int N, std::string name ) {
	if (N < 1 || N > INT_MAX)
		return (NULL);

	Zombie	*z1 = new Zombie[N];
	int		i = 0;
	while (N > 0)
	{
		z1[i].setZombieName(name);
		i++;
		N--;
	}
	return (z1);
}