#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	std::string levels[4];

public:
	Harl();
	Harl(std::string debugStr, std::string infoStr, std::string warningStr, std::string errorStr);
	~Harl();

	int		getLevelI(std::string level);
	void	complain(std::string level);
	void	harlFilter(std::string level);
};

#endif