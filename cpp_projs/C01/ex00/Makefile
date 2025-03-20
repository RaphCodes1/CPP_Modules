NAME = zombie

SRC = main.cpp
GCC = g++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(GCC) $(CPPFLAGS) $^ -o $@

%.o:%.cpp
	$(GCC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean