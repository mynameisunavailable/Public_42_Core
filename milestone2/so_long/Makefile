NAME = so_long
SRCS_NAME =	main.c	create_map.c	key_press.c	put_error.c	validation_path.c	validation.c	free_game.c	load_stuff.c	mob_move.c\
			winlose.c
SRCS = $(SRCS_NAME)
OBJS = $(SRCS:.c=.o)
RANDOM_FLAGS = -lmlx -lXext -lX11 -lm -lz
MINILIBX = -L minilibx-linux
INCLUDE = -I minilibx-linux -I include

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C minilibx-linux
	cc -Wall -Wextra -Werror $(OBJS) $(MINILIBX) $(RANDOM_FLAGS) libft/libft.a -o $(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror $(INCLUDE) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re