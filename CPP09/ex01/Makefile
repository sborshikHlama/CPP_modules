NAME = RPN
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = obj
SRCS = main.cpp RPN.cpp
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
	@echo "--- Valid Case 1 ---"
	./$(NAME) "8 9 * 9 - 9 - 4 - 1 +"
	@echo "\n--- Valid Case 2 ---"
	./$(NAME) "7 7 * 7 -"
	@echo "\n--- Valid Case 3 ---"
	./$(NAME) "1 2 * 2 / 2 * 5 2 * 1 + - 1 2 * +"
	@echo "\n--- Error Case (Empty) ---"
	-./$(NAME) ""
	@echo "\n--- Error Case (Div by Zero) ---"
	-./$(NAME) "1 0 /"

.PHONY: all clean fclean re test
