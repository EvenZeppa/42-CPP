CCPP = c++
CFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp ClapTrap.cpp
NAME = clapTrap

all: $(NAME)

$(NAME): $(SRCS)
	$(CCPP) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all