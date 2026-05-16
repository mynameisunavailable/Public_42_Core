/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:38:32 by yunguo            #+#    #+#             */
/*   Updated: 2026/01/08 11:38:32 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	ft_puterr("\n");
	return (err);
}

void	state_message(int indx, char *msg, t_philo *philo)
{
	long long	ms;

	sem_wait(philo->stat->p_lock);
	ms = time_now() - philo->stat->tstart;
	ms = ms / 1000;
	if (atomic_load(&philo->stat->starve) == 0)
	{
		if (indx == -1)
			printf("%s\n", msg);
		else
			printf("%lld %d %s\n", ms, indx, msg);
	}
	sem_post(philo->stat->p_lock);
}
