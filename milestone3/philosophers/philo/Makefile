NAME = philo
SRCS_NAME =			debug_print.c\
ft_num_conv_str.c	ft_put_err.c	ft_safefree.c		ft_string_vi.c\
philo_init.c		philo_main.c	philo_thread_est.c	philo_thread.c\
philo_time.c		philo_v.c		t_cpstk_new.c	t_philo_new.c

SRCS 		= $(SRCS_NAME)
OBJS 		= $(SRCS:.c=.o)
CC_FLAGS 	= cc -Wall -Wextra -Werror -pthread
DEBUG_FLAGS = -fsanitize=thread -g 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC_FLAGS) $(OBJS) -o $(NAME)

debug: fclean
	@printf "$(YELLOW)Compiling in DEBUG mode (TSan)... $(RESET)\n"
	$(CC_FLAGS) $(DEBUG_FLAGS) $(SRCS) -o $(NAME)
	@printf "$(GREEN)Debug build ready. Run with setarch x86_64 -R ./$(NAME) (arg1) (arg2) (arg3) (arg4) (optional_arg5) to check race conditions. $(RESET)\n"

%.o: %.c
	$(CC_FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re debug