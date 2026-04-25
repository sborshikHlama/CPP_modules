NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = obj
SRCS = main.cpp PmergeMe.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	@echo "--- Basic Test (Subject Example) ---"
	./$(NAME) 3 5 9 7 4
	@echo "\n--- Odd Count Test ---"
	./$(NAME) 1 5 3 4 2
	@echo "\n--- Large Random Test (3000 elements) ---"
	./$(NAME) $$(jot -r 3000 1 100000 | tr '\n' ' ') | tail -n 2
	@echo "\n--- Error Handling (Negative Number) ---"
	-./$(NAME) 1 2 -3 4
	@echo "\n--- Error Handling (Non-numeric) ---"
	-./$(NAME) 1 2 abc 4

.PHONY: all clean fclean re test
