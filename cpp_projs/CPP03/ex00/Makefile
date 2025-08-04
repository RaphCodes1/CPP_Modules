NAME = claptrap

SRC = main.cpp ClapTrap.cpp
CXX = c++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@

%.o:%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean