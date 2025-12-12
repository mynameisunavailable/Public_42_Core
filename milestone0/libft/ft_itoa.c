/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:24:15 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/21 10:24:15 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:53:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/20 10:54:04 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_reverse_string_malloc(char *string)
{
	int		length;
	char	*string_p;
	char	*reversed_string;
	int		j;

	length = ft_strlen(string);
	reversed_string = malloc((length + 1) * (sizeof(char)));
	if (!reversed_string)
		return (NULL);
	string_p = reversed_string;
	j = length - 1;
	while (j >= 0)
	{
		*string_p = string[j];
		string_p++;
		j--;
	}
	*string_p = '\0';
	return (reversed_string);
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	char	string[12];
	int		negative;

	negative = (n < 0);
	i = 0;
	num = (long)n;
	if (num < 0)
		num = -num;
	else if (num == 0)
		string[i++] = '0';
	while (num > 0)
	{
		string[i++] = '0' + (num % 10);
		num = num / 10;
	}
	if (negative)
		string[i++] = '-';
	string[i] = '\0';
	return (ft_reverse_string_malloc(string));
}
