/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:24:15 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/21 22:35:42 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:46:27 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/20 14:51:02 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	char	*str_temp;
	char	*to_find_temp;
	size_t	len_temp;

	if (*to_find == '\0')
		return ((char *)str);
	while ((len > 0) && *str)
	{
		str_temp = (char *)str;
		to_find_temp = (char *)to_find;
		len_temp = len;
		while ((*str_temp == *to_find_temp) && *str_temp && (len_temp > 0))
		{
			str_temp++;
			to_find_temp++;
			len_temp--;
		}
		if (*to_find_temp == '\0')
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
