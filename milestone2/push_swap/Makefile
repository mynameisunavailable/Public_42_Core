LIB_NAME = libft/libft.a
NAME = push_swap
CHECKER = checker
# CC = cc -Wall -Wextra -Werror -g
CC = cc -Wall -Wextra -Werror

SRCS_NAME =	push_swap.c
BNUS_NAME = checker.c
HELPER_NAME = ps_helper_atob_helper.c\
			ps_helper_create.c		ps_helper_init.c	ps_helper_swap.c\
			ps_pushswap_helper.c	ps_rotate_helper.c	ps_rrotate_helper.c\
			ps_pushswap.c			ps_rotate.c			ps_rrotate.c\
			ps_helper_update.c		ps_helper_update_steptob.c	ps_helper_update_steptoa.c\
			ps_helper_validate.c	push_swap_lis.c

SRCS = $(SRCS_NAME)
OBJS = $(SRCS:.c=.o)
BNUS = $(BNUS_NAME)
BNUS_OBJS = $(BNUS:.c=.o)
HELPER = $(HELPER_NAME)
HELPER_OBJS = $(HELPER:.c=.o)

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJS) $(HELPER_OBJS) $(LIB_NAME)
	$(CC) $(OBJS) $(HELPER_OBJS) $(LIB_NAME) -o $(NAME)

$(LIB_NAME): force
	make -C libft

$(CHECKER): $(BNUS_OBJS) $(HELPER_OBJS) $(LIB_NAME)
	$(CC) $(BNUS_OBJS) $(HELPER_OBJS) $(LIB_NAME) -o $(CHECKER)

force:
	@true

%.o: %.c
	$(CC) -c $< -o $@

# test: all clean
# 	if [! -d "Push-Swap-Tester"]; then git clone https://github.com/gemartin99/Push-Swap-Tester; fi
#     cp push_swap Push-Swap-Tester/push_swap
#     cd Push-Swap-Tester && bash push_swap_test_linux.sh

# visualiser: all clean
#     if [! -d "push_swap_visualizer"]; then git clone https://github.com/o-reo/push_swap_visualizer.git; fi
#     cd push_swap_visualizer && \
#     mkdir build && \
#     cd build && \
#     cmake .. && \
#     make && \
#     ./bin/visualizer

clean:
	make clean -C libft 
	rm -f $(OBJS) $(BNUS_OBJS) $(HELPER_OBJS)

fclean: clean
	make fclean -C libft 
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re force