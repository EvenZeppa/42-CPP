CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
CPP_FLAGS = 
SRCS = main.cpp Fixed.cpp Point.cpp
NAME = bsp

all: $(NAME)

$(NAME):
	$(CPP) $(CPP_FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all