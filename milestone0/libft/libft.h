/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:24:15 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/21 22:41:26 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:54:21 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/20 13:11:12 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>

// ft_ctype_is.c
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// ft_ctype_to.c
int		ft_toupper(int c);
int		ft_tolower(int c);

// ft_mem.c
void	*ft_memset(void *dest, int n, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *src, int c, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// ft_string.c
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

// ft_string_cmp.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strchr(const char *str, int to_find);
char	*ft_strrchr(const char *str, int to_find);

// ft_atoi.c
int		ft_atoi(const char *str);

// ft_string_mem.c
void	*ft_bzero(void *dest, size_t size);
void	*ft_calloc(size_t len, size_t size);
char	*ft_strdup(const char *src);

// ft_substr.c
char	*ft_substr(char const *s, unsigned int start, size_t len);

// ft_strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);

// ft_strtrim.c
char	*ft_strtrim(char const *s1, char const *set);

// ft_split.c
char	**ft_split(char const *s, char c);

// ft_itoa.c
char	*ft_itoa(int n);

// ft_strmapi.c
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// ft_striteri.c
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

// ft_put_fd.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// ft_lstnew_bonus_bonus.c
t_list				*ft_lstnew(void *content);

// ft_lstadd_front_bonus.c
void				ft_lstadd_front(t_list **lst, t_list *new);

// ft_lstsize_bonus.c
int					ft_lstsize(t_list *lst);

// ft_lstlast_bonus.c
t_list				*ft_lstlast(t_list *lst);

// ft_lstadd_back_bonus.c
void				ft_lstadd_back(t_list **lst, t_list *new);

// ft_lstdelone_bonus.c
void				ft_lstdelone(t_list *lst, void (*del)(void *));

// ft_lstclear_bonus.c
void				ft_lstclear(t_list **lst, void (*del)(void *));

// ft_lstiter_bonus.c
void				ft_lstiter(t_list *lst, void (*f)(void *));

// ft_lstmap_bonus.c
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif