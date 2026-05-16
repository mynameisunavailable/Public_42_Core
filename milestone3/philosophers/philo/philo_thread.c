/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:18:29 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/19 11:55:05 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_threads(t_philo *philo)
{
	t_philo	*philo_1;
	int		err;

	philo_1 = philo;
	atomic_store(&philo->stat->tstart, time_now() + 20000);
	while (TRUE)
	{
		atomic_store(&philo->t_lastmeal, atomic_load(&philo->stat->tstart));
		if (int_is_odd(philo->indx) == TRUE)
			err = pthread_create(&philo->thrd, NULL, &philo_est_odd, philo);
		else
			err = pthread_create(&philo->thrd, NULL, &philo_est_even, philo);
		if (err != 0)
		{
			atomic_store(&philo->stat->starve, 1);
			return (clean_philo_upto(philo_1, philo->indx),
				ft_puterr("failed to create philo thread\n"), -1);
		}
		philo = philo->next;
		if (philo == philo_1)
			break ;
	}
	while (time_now() < atomic_load(&philo->stat->tstart))
		usleep(10);
	return (0);
}

void	clean_philo_upto(t_philo *philo, int indx)
{
	while (philo->indx < indx)
	{
		pthread_join(philo->thrd, NULL);
		philo = philo->next;
	}
}

void	cleanup_philo_threads(t_philo *philo)
{
	t_philo	*philo_1;

	philo_1 = philo;
	while (TRUE)
	{
		pthread_join(philo->thrd, NULL);
		philo = philo->next;
		if (philo == philo_1)
			break ;
	}
}
