CCPP = c++
CPPFLAGS = -g -Wall -Wextra -Werror
SRCS = main.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp
NAME = abstract

all: $(NAME)

$(NAME):
	$(CCPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all