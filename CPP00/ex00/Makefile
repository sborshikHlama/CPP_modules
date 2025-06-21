SRCS = megaphone.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
NAME = megaphone
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
CPP = c++
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CPP) $(CPPFLAGS) -c $ < -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
