CCPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = *.cpp
NAME = intern

all: $(NAME)

$(NAME):
	$(CCPP) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all