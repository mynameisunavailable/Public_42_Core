NAME = get_next_line.a
SRCS_NAME =		get_next_line_utils.c			get_next_line.c
# BONUS_NAME =	get_next_line_utils_bonus.c		get_next_line_bonus.c
SRCS = $(SRCS_NAME)
OBJS = $(SRCS:.c=.o)
# BONUS = $(BONUS_NAME)
# BONUS_OBJS = $(BONUS:.c=.o)

$(NAME): $(OBJS)
# 	cc -Wall -Wextra -Werror $(OBJS) -o $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

# bonus: $(BONUS_OBJS)
# 	ar rcs $(NAME) $(BONUS_OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re