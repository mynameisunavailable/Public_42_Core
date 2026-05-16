#ifndef ZOMBIE_HPP
#define  ZOMBIE_HPP

#include  <climits>
#include  <iostream>

class Zombie {
	public:
		typedef Zombie z;

		void announce( void );
		void setZombieName( std::string name );

		Zombie() {};
		~Zombie( void );

	private:
		std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
