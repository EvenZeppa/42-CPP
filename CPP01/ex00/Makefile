CPP = g++
CPP_FLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
NAME = zombie

all: $(NAME)

$(NAME):
	$(CPP) $(CPP_FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all