CCPP = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wno-shadow
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
NAME = diamondTrap

all: $(NAME)

$(NAME): $(SRCS)
	$(CCPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all