SRCS = main.cpp Contact.cpp PhoneBook.cpp

OBJ = $(SRCS:.cpp=.o)

NAME = phonebook
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
CPP = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CPP) $(CPPFLAGS) -c $ < -o $@

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all
