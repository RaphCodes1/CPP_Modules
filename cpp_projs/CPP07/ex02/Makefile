NAME = array
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./
SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = Array.hpp Array.tpp
RM = rm -f

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o:%.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean