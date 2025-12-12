/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:24:15 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/21 22:41:02 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:35:30 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/20 11:12:45 by yunguo           ###   ########.fr       */
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

static unsigned char	*ft_btmsk_cins_cm(const char *str, unsigned char *mask)
{
	int	a;

	while (*str)
	{
		a = (unsigned char)*str;
		mask[a / 8] = (mask[a / 8]) | (1u << (a % 8));
		str++;
	}
	return (mask);
}

static int	ft_btmsk_cins_mm(const char c, const unsigned char *mask)
{
	int	a;

	a = (unsigned char)c;
	if (mask[a / 8] & (1u << (a % 8)))
	{
		return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			l;
	size_t			r;
	unsigned char	mask[32];

	ft_memset(mask, 0, 32);
	if (!s1 || !set)
		return (NULL);
	ft_btmsk_cins_cm(set, mask);
	l = 0;
	while (s1[l] && ft_btmsk_cins_mm(s1[l], mask) > 0)
		l++;
	r = ft_strlen(s1);
	if (r > 0)
		r--;
	while ((r > 0) && (ft_btmsk_cins_mm(s1[r], mask) > 0))
		r--;
	if (l > r)
		return (ft_strndup(s1 + l, 0));
	else
		return (ft_strndup(s1 + l, (r - l + 1)));
}
