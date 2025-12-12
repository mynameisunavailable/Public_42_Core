/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:24:15 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/21 23:07:20 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:46:47 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/20 11:10:45 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *src, size_t n)
{
	size_t	len;
	char	*dest;
	char	*dest_start;

	len = ft_strlen(src);
	if (len > n)
		len = n;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest_start = dest;
	while (len > 0 && *src)
	{
		*dest++ = *src++;
		len--;
	}
	*dest = '\0';
	return (dest_start);
}

static unsigned int	find_split_count(const char *str, char charset)
{
	int	i;
	int	c;
	int	len;

	i = 0;
	c = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == charset)
		{
			if (len > 0)
				c++;
			len = 0;
		}
		else
			len++;
		i++;
	}
	if (len > 0)
		c++;
	return (c + 1);
}

static int	add_word(const char *str, char ***res, int *c, int len)
{
	(*res)[*c] = ft_strndup(str - len, len);
	if ((*res)[*c] == NULL)
	{
		while (*c >= 0)
		{
			c--;
			free((*res)[*c]);
		}
		return (0);
	}
	(*c)++;
	return (1);
}

static int	ft_sp_run(const char *str, char charset, char ***res)
{
	int	i;
	int	c;
	int	len;

	i = 0;
	c = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == charset)
		{
			if (len > 0)
				if (add_word(str + i, res, &c, len) == 0)
					return (0);
			len = 0;
		}
		else
			len++;
		i++;
	}
	if (len > 0)
		if (add_word(str + i, res, &c, len) == 0)
			return (0);
	(*res)[c] = NULL;
	return (1);
}

char	**ft_split(char const *s, char charset)
{
	char			**res;
	unsigned int	res_count;

	if (!s)
		return (NULL);
	res_count = find_split_count(s, charset);
	res = malloc(sizeof(char *) * (res_count));
	if (!res)
		return (NULL);
	if (ft_sp_run(s, charset, &res) != 1)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
