NAME = serialization
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Serialization.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm -f

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean