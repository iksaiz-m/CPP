CXX			 = c++
CXXFLAGS       = -Wall -Wextra -Werror -g3 -std=c++98

NAME         = Violence_for_fun
RM           = rm -f
SRC =	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

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