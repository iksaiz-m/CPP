CXX			 = c++
CXXFLAGS       = -Wall -Wextra -Werror -g3 -std=c++98

NAME         = Hi_Brain
RM           = rm -f
SRC =	main.cpp

OBJS = $(SRC:.cpp=.o)

all:$(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re