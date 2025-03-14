NAME = megaphone

GCC = g++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
$(GCC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(GCC) $(GCCFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

