SRCS = megaphone.cpp \

OBJS = $(SRCS:.cpp = .o)
NAME = megaphone
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CXX = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $ < -o $@

clean:
	$(RM) $(OBJS)
flcean: clean
	$(RM) $(NAME)

re: fclean all
