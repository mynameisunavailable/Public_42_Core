NAME = zombieHorde
COMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SCRS = \
Zombie.cpp\
zombieHorde.cpp\
main.cpp

all: $(NAME)

OBJS = $(SCRS:.cpp=.o)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re