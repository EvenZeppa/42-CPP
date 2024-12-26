#include "Harl.hpp"

Harl::Harl()
{
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
}

Harl::Harl(std::string debugStr, std::string infoStr, std::string warningStr, std::string errorStr) 
{
	this->levels[0] = debugStr;
	this->levels[1] = infoStr;
	this->levels[2] = warningStr;
	this->levels[3] = errorStr;
}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int	Harl::getLevelI(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->levels[i] == level)
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	void	(Harl::*complaints[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int		levelI = getLevelI(level);

	if (levelI == -1)
	{
		std::cout << "Error: unknown log level !" << std::endl;
		return ;
	}

	std::cout << "[" << this->levels[levelI] << "]" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complaints[i])();
			return ;
		}
	}
}

void	Harl::harlFilter(std::string level)
{
	int	levelI = getLevelI(level);
	
	if (levelI == -1)
	{
		std::cout << "Error: unknown log level !" << std::endl;
		return ;
	}
	switch (levelI)
	{
		case 0:
			this->complain(this->levels[0]);
			this->complain(this->levels[1]);
			this->complain(this->levels[2]);
			this->complain(this->levels[3]);
			break;
		case 1:
			this->complain(this->levels[1]);
			this->complain(this->levels[2]);
			this->complain(this->levels[3]);
			break;
		case 2:
			this->complain(this->levels[2]);
			this->complain(this->levels[3]);
			break;
		case 3:
			this->complain(this->levels[3]);
			break;
		default:
			break;
	}
}