#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class HARL
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	HARL();
	~HARL();

	void	complain(std::string level);
};

#endif