NAME = account
COMP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SCRS = \
Account.cpp\
tests.cpp

all: $(NAME)

OBJS = $(SCRS:.cpp=.o)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -o $(NAME)
# .\a.exe | awk '{$1=""; print $0}' > a.log

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re