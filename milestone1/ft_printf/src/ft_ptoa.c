/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:01:11 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// pointer to malloc'd str
char	*ft_ptoa(void *addr)
{
	char		*base;
	char		rev_res[17];
	char		*res;
	uintptr_t	i;
	uintptr_t	n;

	base = "0123456789abcdef";
	n = (uintptr_t)addr;
	i = 0;
	while (n >= 16)
	{
		rev_res[i++] = base[n % 16];
		n = n / 16;
	}
	rev_res[i++] = base[n % 16];
	res = malloc(i + 1);
	ft_reverse_string(rev_res, res, i);
	return (res);
}
