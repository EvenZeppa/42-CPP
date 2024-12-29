CCPP = c++
CPPFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp
NAME = animal

all: $(NAME)

$(NAME):
	$(CCPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all