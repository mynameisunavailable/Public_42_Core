#include <iostream>
#include <cctype>

void	PrintStrUpper(char *str)
{
	int		j;

	j = 0;
	while (str[j])
	{
		std::cout << (char)std::toupper(str[j]);
		j++;
	}
}

int main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 1;
	while (argc > i)
	{
		PrintStrUpper(argv[i]);
		i++;
	}
	std::cout << "\n";
	return (0);
}
