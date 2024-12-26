CPP = g++
CPP_FLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Harl.cpp
NAME = harl

all: $(NAME)

$(NAME):
	$(CPP) $(CPP_FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
