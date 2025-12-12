/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
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
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:46:27 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/20 14:51:38 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int to_find)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)to_find)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)*str == (unsigned char)to_find)
	{
		return ((char *)str);
	}
	return (NULL);
}
