/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_vi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:38:15 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/14 17:38:15 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static char	*skip_zeroes(char *str)
{
	while (*str == '0')
		str++;
	return (str);
}

int	ft_str_is_num(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if ((*str < '0') || ('9' < *str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_str_is_int(char *str)
{
	size_t	len;
	int		neg;

	neg = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	if (ft_str_is_num(str) == 0)
		return (0);
	if (*str == '0')
	{
		str = skip_zeroes(str);
		if (*str == '\0')
			str--;
	}
	len = ft_strlen(str);
	if (len < 10)
		return (1);
	if (len > 10 || (neg == -1 && ft_strcmp(str, "2147483648") > 0)
		|| len == 0 || (neg == 1 && ft_strcmp(str, "2147483647") > 0))
		return (0);
	return (1);
}
