/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_est.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:47:18 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/19 21:47:56 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

#define ODD_START_OFFSET 5000
#define SMARTSLEEPTIMER 500

void	*check_starve(void *arg)
{
	t_philo		*philo;
	long long	t_tdie;
	long long	now;
	long long	lastmeal;

	philo = (t_philo *)arg;
	t_tdie = philo->stat->t_tdie;
	while (TRUE)
	{
		usleep(1000);
		sem_wait(philo->meal_l);
		lastmeal = atomic_load(&philo->t_lastmeal);
		now = time_now();
		if (atomic_load(&philo->stat->starve) == -69)
			return (sem_post(philo->meal_l), NULL);
		if (lastmeal + t_tdie <= now)
			break ;
		sem_post(philo->meal_l);
	}
	sem_wait(philo->stat->p_lock);
	atomic_store(&philo->stat->starve, now - philo->stat->tstart);
	printf("%lld %d died\n", atomic_load(&philo->stat->starve) / 1000,
		philo->indx);
	exit(0);
	return (NULL);
}

void	philo_est_single(t_philo *philo)
{
	philo_syncstart(philo->stat->tstart);
	sem_wait(philo->stat->cpstks);
	state_message(philo->indx, "has taken a fork", philo);
	check_starve((void *)philo);
}

void	return_ticket_and_cpstks_dcheck(t_philo *philo)
{
	sem_post(philo->stat->ticket);
	sem_post(philo->stat->cpstks);
	sem_post(philo->stat->cpstks);
	check_completion(philo);
}

void	philo_est_odd(t_philo *philo)
{
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, &check_starve, philo) != 0)
		return (ft_puterr("failed to create thread at child"), exit(0));
	pthread_detach(monitor);
	philo_syncstart(philo->stat->tstart + ODD_START_OFFSET);
	while (TRUE)
	{
		sem_wait(philo->stat->ticket);
		sem_wait(philo->stat->cpstks);
		state_message(philo->indx, "has taken a fork", philo);
		sem_wait(philo->stat->cpstks);
		state_message(philo->indx, "has taken a fork", philo);
		sem_wait(philo->meal_l);
		atomic_store(&philo->t_lastmeal, time_now());
		state_message(philo->indx, "is eating", philo);
		sem_post(philo->meal_l);
		state_usleep(philo->stat->t_teat, philo->stat);
		atomic_fetch_add(&philo->nmealsdone, 1);
		return_ticket_and_cpstks_dcheck(philo);
		state_message(philo->indx, "is sleeping", philo);
		state_usleep(philo->stat->t_tslp, philo->stat);
		state_message(philo->indx, "is thinking", philo);
		state_usleep(smart_sleep(philo, SMARTSLEEPTIMER), philo->stat);
	}
}

void	philo_est_even(t_philo *philo)
{
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, &check_starve, philo) != 0)
		return (ft_puterr("failed to create thread at child"), exit(0));
	pthread_detach(monitor);
	philo_syncstart(philo->stat->tstart);
	while (TRUE)
	{
		sem_wait(philo->stat->ticket);
		sem_wait(philo->stat->cpstks);
		state_message(philo->indx, "has taken a fork", philo);
		sem_wait(philo->stat->cpstks);
		state_message(philo->indx, "has taken a fork", philo);
		sem_wait(philo->meal_l);
		atomic_store(&philo->t_lastmeal, time_now());
		state_message(philo->indx, "is eating", philo);
		sem_post(philo->meal_l);
		state_usleep(philo->stat->t_teat, philo->stat);
		atomic_fetch_add(&philo->nmealsdone, 1);
		return_ticket_and_cpstks_dcheck(philo);
		state_message(philo->indx, "is sleeping", philo);
		state_usleep(philo->stat->t_tslp, philo->stat);
		state_message(philo->indx, "is thinking", philo);
		state_usleep(smart_sleep(philo, SMARTSLEEPTIMER), philo->stat);
	}
}
