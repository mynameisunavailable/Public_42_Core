/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
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
/*   ft_string_mem copy 3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:45:40 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/20 14:43:54 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t len, size_t size)
{
	void	*dest;
	size_t	max_size;
	size_t	i;
	char	*d;

	if ((len == 0) || (size == 0))
		return (malloc(1));
	if ((len > 0) && (SIZE_MAX / len) < size)
		return (NULL);
	max_size = len * size;
	dest = malloc(max_size);
	if (!dest)
		return (NULL);
	d = (char *)dest;
	i = 0;
	while (i < max_size)
	{
		d[i] = 0;
		i++;
	}
	return (dest);
}
