CPP = g++
CPP_FLAGS = -Wall -Werror -Wextra
SRCS = main.cpp
NAME = replace

all: $(NAME)

$(NAME):
	$(CPP) $(CPP_FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f *.replace

re: fclean all