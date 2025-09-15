CXX			 = c++
CXXFLAGS       = -Wall -Wextra -Werror -g3 -std=c++98

NAME         = Animal
RM           = rm -f
SRC =	main.cpp  Animal.cpp Dog.cpp Cat.cpp

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