/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:24:36 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/18 13:02:45 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	time_now(void)
{
	struct timeval	tv;
	long long		usec;

	gettimeofday(&tv, NULL);
	usec = tv.tv_sec * 1000000 + tv.tv_usec;
	return (usec);
}

void	philo_syncstart(long long tstart)
{
	long long	now;
	long long	remaining;

	now = time_now();
	while (now <= tstart)
	{
		now = time_now();
		remaining = tstart - now;
		if (remaining > 950)
			usleep(remaining - 950);
		else if (remaining > 100)
			usleep(remaining - 100);
		else if (remaining > 0)
			usleep(remaining);
		else
			return ;
	}
}

void	state_usleep(long long usec, t_stats *stat)
{
	long long	remaining_time;
	long long	end_time;
	long long	now;

	now = time_now();
	end_time = now + usec;
	while (atomic_load(&stat->starve) == 0)
	{
		now = time_now();
		remaining_time = end_time - now;
		if (remaining_time > 950)
			usleep(remaining_time - 950);
		else if (remaining_time > 100)
			usleep(remaining_time - 100);
		else
			return ;
	}
}

// #define SAFETY_MARGIN (int)5
long long	smart_sleep(t_philo *philo, int offset)
{
	t_stats		*stat;
	long long	life;

	stat = philo->stat;
	life = stat->t_tdie - (time_now() - atomic_load(&philo->t_lastmeal));
	(void)life;
	return (0 + offset);
}
