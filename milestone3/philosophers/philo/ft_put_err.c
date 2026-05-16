/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:34:48 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/27 17:34:48 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_puterr(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

int	ft_puterr_no(char *msg, int err)
{
	ft_puterr(msg);
	return (err);
}
