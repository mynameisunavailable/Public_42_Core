#include "Harl.hpp"

void Harl::debug( void ) {
	std::string msg = "No extra bacon for my 7XL-special-ketchup burger. 😾";
	std::cout << msg << std::endl;
}

void Harl::info( void ) {
	std::string msg = "🙀 Adding extra bacon for the burger costs money. 😾";
	std::cout << msg << std::endl;
}

void Harl::warning( void ) {
	std::string msg = "Give extra bacon for free 😾. How old are you y. man.";
	std::cout << msg << std::endl;
}

void Harl::error( void ) {
	std::string msg = "😾 Let me talk to your manager. 😾";
	std::cout << msg << std::endl;
}

void Harl::complain( std::string level ) {
	void (Harl::*funcPtr[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	size_t levels_size = sizeof(levels) / sizeof(levels[0]);
	for (size_t i = 0; i < levels_size; i++) {
		if (levels[i] == level) {
			(this->*funcPtr[i])();
			return ;
		}
	}
}
