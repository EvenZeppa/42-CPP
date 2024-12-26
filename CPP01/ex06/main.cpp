#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Error: need log level !" << std::endl, 1);
	
	Harl	harl("DEBUG", "INFO", "WARNING", "ERROR CUSTOM");

	harl.harlFilter(av[1]);

	return (0);
}