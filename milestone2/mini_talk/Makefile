LIB_NAME = libft/libft.a
S_NAME = server
C_NAME = client

S_SRCS_NAME =	server.c
C_SRCS_NAME =	client.c

S_SRCS = $(S_SRCS_NAME)
C_SRCS = $(C_SRCS_NAME)

S_OBJS = $(S_SRCS:.c=.o)
C_OBJS = $(C_SRCS:.c=.o)

all: $(S_NAME) $(C_NAME)

bonus: $(S_NAME) $(C_NAME)

$(S_NAME): $(S_OBJS)
	make -C libft
	cc -Wall -Wextra -Werror $(S_OBJS) $(LIB_NAME) -o $(S_NAME)

$(C_NAME): $(C_OBJS)
	make -C libft
	cc -Wall -Wextra -Werror $(C_OBJS) $(LIB_NAME) -o $(C_NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	make clean -C libft 
	rm -f $(S_OBJS) $(C_OBJS)

fclean: clean
	make fclean -C libft 
	rm -f $(S_NAME) $(C_NAME)

re: fclean all

.PHONY: all bonus clean fclean re