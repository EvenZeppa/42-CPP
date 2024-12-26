CPP = g++
CPP_FLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
NAME = human

all: $(NAME)

$(NAME):
	$(CPP) $(CPP_FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all