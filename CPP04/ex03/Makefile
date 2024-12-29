CPP = c++
CPPFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp
NAME = prog

all: $(NAME)

$(NAME):
	$(CPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all