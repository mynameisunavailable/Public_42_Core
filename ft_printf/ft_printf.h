/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 07:55:04 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/25 21:09:33 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 07:55:04 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 09:57:19 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ft_print_info
{
	char			*c_flag;
	char			*c_conv;
	char			*d_flag;
	int				d_wide;
	int				d_prec;
	char			d_conv;
	char			*o_str;
	size_t			o_len;
}					t_ft_print_info;

typedef struct s_ft_print_var
{
	size_t			i;
	size_t			output_len;
	char			*temp;
	size_t			tlen;
}					t_ft_print_var;

union				u_ft_printf_subdata
{
	char			c;
	char			*s;
	void			*p;
	int				d;
	unsigned int	u;
};

char				*extract_d_flag(char *sstr, t_ft_print_info *info);
char				*f_next_data_num_pos_dash(char *tmp, size_t char_str_len,
						t_ft_print_info *info);
char				*ft_uitoh(unsigned int u);
char				*ft_ptoa(void *addr);
int					ft_cins(const char c, const char *str);
int					ft_isdigit(int c);
int					ft_atoi(char *str);
size_t				ft_strlen(const char *str);
char				*ft_strndup(const char *src, unsigned int n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*create_strwc(unsigned char c, size_t len);
char				*ft_strdup(const char *src);
void				*ft_memcpy(void *dest, const void *src, size_t size);
char				*ft_memjoin2(char const *s1, size_t len1, char const *s2,
						size_t len2);
char				*ft_reverse_string_malloc(char *string);
char				*concat_char_insitu(char *string, char c);
char				*ft_memappend_front(const char *s1, size_t len1, char *s2,
						size_t len2);
int					ini_ft_print_var(t_ft_print_var *var);
int					ini_ft_print_cinfo(t_ft_print_info *info);
int					ini_ft_print_dinfo(t_ft_print_info *info);
char				*extract_str(const char *f, t_ft_print_info *info,
						t_ft_print_var *var);
char				*extract_str(const char *f, t_ft_print_info *info,
						t_ft_print_var *var);
char				*extract_d_wide(char *sstr, t_ft_print_info *info);
char				*extract_d_prec(char *sstr, t_ft_print_info *info);
char				*extract_d_conv(char *sstr, t_ft_print_info *info);
void				extract_dinfo(char *sstr, t_ft_print_info *info);
void				extract_next_data(va_list *ap, t_ft_print_info *info,
						union u_ft_printf_subdata *data);
char				*f_next_data_padc(char *tmp, char c, size_t tmp_len,
						t_ft_print_info *info);
char				*f_next_data_char(t_ft_print_info *info,
						union u_ft_printf_subdata *data);
char				*f_next_data_str(t_ft_print_info *info,
						union u_ft_printf_subdata *data);
void				ft_reverse_string(char *string, char *reverse_string,
						int length);
char				*f_next_data_ptr(t_ft_print_info *info,
						union u_ft_printf_subdata *data);
char				*ft_itoa(int n);
char				*f_next_data_int_pad(char *tmp, size_t tmp_len,
						t_ft_print_info *info);
char				*f_next_data_num_sign_insc(char *tmp, char c);
char				*ft_ldtoa(long long n);
char				ft_num_char_long(long n);
char				*f_next_data_num_neg_dash(char *tmp, size_t char_str_len);
char				*f_next_data_num_neg_zero(char *tmp, size_t char_str_len);
char				*f_next_data_num_neg_space(char *tmp, size_t char_str_len);
char				*f_next_data_num_neg(char *tmp, t_ft_print_info *info);
char				*f_next_data_num_pos_zero(char *tmp, size_t char_str_len,
						t_ft_print_info *info);
char				*f_next_data_num_pos_space(char *tmp, size_t char_str_len,
						t_ft_print_info *info);
char				*f_next_data_num_pos_else(char *tmp, t_ft_print_info *info);
char				*f_next_data_num_pos(char *tmp, t_ft_print_info *info);
char				*f_next_data_int_prec(long long n, t_ft_print_info *info);
char				*f_next_data_int(t_ft_print_info *info,
						union u_ft_printf_subdata *data);
char				*f_next_data_hex_prec_padc(char *tmp,
						t_ft_print_info *info);
char				*f_next_data_hex_prec(unsigned int u,
						t_ft_print_info *info);
char				*f_n_n_hex_pad_dash(unsigned int u, char *tmp,
						size_t char_str_len, t_ft_print_info *info);
char				*f_next_data_hex_pad_zero(unsigned int u, char *tmp,
						size_t char_str_len, t_ft_print_info *info);
char				*f_next_data_hex_pad_space(unsigned int u, char *tmp,
						size_t char_str_len, t_ft_print_info *info);
char				*f_next_data_hex_pad(unsigned int u, char *tmp,
						t_ft_print_info *info);
char				*f_next_data_hex(t_ft_print_info *info,
						union u_ft_printf_subdata *data);
char				*ft_str_toupper(char *str);
char				*f_next_data_hex_upper(t_ft_print_info *info,
						union u_ft_printf_subdata *data);
char				*f_next_data_uint_prec(unsigned int u,
						t_ft_print_info *info);
char				*f_next_data_uint_pad(unsigned int u, char *tmp,
						t_ft_print_info *info);
char				*f_next_data_uint(t_ft_print_info *info,
						union u_ft_printf_subdata *data);
char				*f_next_data_pct(t_ft_print_info *info);
char				*f_next_data(t_ft_print_info *info,
						union u_ft_printf_subdata *data);
void				extract_dinfo_free(t_ft_print_info *info);
void				process_conv(char *substr, va_list *ap,
						t_ft_print_info *info, t_ft_print_var *var);
int					ft_printf(const char *f, ...);
int					ft_cins(const char c, const char *str);
size_t				ft_strlen(const char *str);
char				*ft_strndup(const char *src, unsigned int n);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_isdigit(int c);
char				*ft_strjoin2(char const *s1, char const *s2);
char				*create_strwc(unsigned char c, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t size);
char				*ft_memjoin2(char const *s1, size_t len1, char const *s2,
						size_t len2);
char				*concat_char_insitu(char *string, char c);

#endif
