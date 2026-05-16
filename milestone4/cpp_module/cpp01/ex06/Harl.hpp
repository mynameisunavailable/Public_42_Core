#ifndef HARL_HPP
#define  HARL_HPP

#include  <iostream>
#include  <cstdlib>

class Harl
{
	public:
		void complain( std::string level );
		void complainFiltered( std::string level );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif