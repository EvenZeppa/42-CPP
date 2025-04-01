CPP = c++
CPP_FlAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Account.cpp tests.cpp
NAME = tests

all: $(NAME)

$(NAME):
	$(CPP) $(CPP_FlAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
