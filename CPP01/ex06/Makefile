CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Harl.cpp
NAME = harlFilter

all: $(NAME)

$(NAME):
	$(CPP) $(CPP_FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
