CPP = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp zombieHorde.cpp
OBJ = $(SRC:.cpp=.o)
NAME = zombie

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	@echo "Removing everything but the source files"
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re