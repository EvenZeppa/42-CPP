CCPP = c++
CPPFLAGS = -g -Wall -Wextra -Werror
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
NAME = brain

all: $(NAME)

$(NAME):
	$(CCPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all