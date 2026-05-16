#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "only takes 2 arguments" << std::endl;
		return (1);
	}

	Harl man;
	std::string level = argv[1];

	man.complainFiltered(level);
	return (0);
}
