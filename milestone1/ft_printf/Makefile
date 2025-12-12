NAME =	libftprintf.a
SRCS_FOLDER = src
SRCS_NAME = \
		concat_char_insitu.c   f_next_data_hex_pad_space.c     f_next_data_num_pos_dash.c   ft_btmsk_ckrep_str.c        ft_str_toupper.c\
		create_strwc.c         f_next_data_hex_pad_zero.c      f_next_data_num_pos_else.c   ft_cins.c                   ft_strdup.c\
		extract_d_conv.c       f_next_data_hex_prec.c          f_next_data_num_pos_space.c  ft_isdigit.c\
		extract_d_flag.c       f_next_data_hex_prec_padc.c     f_next_data_num_pos_zero.c   ft_itoa.c                   ft_strlen.c\
		extract_d_prec.c       f_next_data_hex_upper.c         ft_ldtoa.c                 	ft_strndup.c\
		extract_d_wide.c       f_next_data_int.c               f_next_data_num_sign_insc.c  ft_memappend_back.c         ft_substr.c\
		extract_dinfo.c        f_next_data_int_pad.c           f_next_data_padc.c           ft_memappend_front.c        ft_uitoh.c\
		extract_dinfo_free.c   f_next_data_int_prec.c          f_next_data_pct.c            ft_memcpy.c                 ini_ft_print_cinfo.c\
		extract_next_data.c    f_next_data_num_hex_pad_dash.c  f_next_data_ptr.c            ft_memjoin2.c               ini_ft_print_dinfo.c\
		extract_str.c          f_next_data_num_neg.c           f_next_data_str.c            ft_num_char_long.c          ini_ft_print_var.c\
		f_next_data.c          f_next_data_num_neg_dash.c      f_next_data_uint.c           ft_printf.c                 process_conv.c\
		f_next_data_char.c     f_next_data_num_neg_space.c     f_next_data_uint_pad.c       ft_ptoa.c\
		f_next_data_hex.c      f_next_data_num_neg_zero.c      f_next_data_uint_prec.c      ft_reverse_string.c\
		f_next_data_hex_pad.c  f_next_data_num_pos.c           ft_atoi.c                    ft_reverse_string_malloc.c
SRCS = $(addprefix $(SRCS_FOLDER)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

bonus: all

clean:
	rm -f $(SRCS_FOLDER)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re