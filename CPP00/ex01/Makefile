CPP = c++
CPP_FlAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp PhoneBook.cpp Contact.cpp
NAME = phone-book

all: $(NAME)

$(NAME):
	$(CPP) $(CPP_FlAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
