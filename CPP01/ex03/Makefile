NAME = ex03
CPP = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	@echo "Removing everything but the source files"
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
