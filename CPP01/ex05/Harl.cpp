#include "Harl.hpp"

HARL::HARL() {}

HARL::~HARL() {}

void	HARL::debug(void)
{
	std::cout << "DEBUG" << std::endl;
}

void	HARL::info(void)
{
	std::cout << "INFO" << std::endl;
}

void	HARL::warning(void)
{
	std::cout << "WARNING" << std::endl;
}

void	HARL::error(void)
{
	std::cout << "ERROR" << std::endl;
}

void	HARL::complain(std::string level)
{
	void	(HARL::*complaints[4])(void) = {&HARL::debug, &HARL::info, &HARL::warning, &HARL::error};

	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complaints[i])();
			return ;
		}
	}
}