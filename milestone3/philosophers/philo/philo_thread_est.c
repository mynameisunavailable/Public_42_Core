/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_est.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:20:49 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/20 11:35:16 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define ODD_START_OFFSET 5000
#define SMART_SLEEP_TIMER 500

int	philo_est_odd_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left->lock);
	if (atomic_load(&philo->stat->starve) > 0)
		return (safe_unlock(philo->left, NULL), 1);
	state_message(philo->indx, "has taken a fork", philo);
	if (philo->left == philo->rigt)
		return (usleep(philo->stat->t_tdie), safe_unlock(philo->left, NULL), 1);
	pthread_mutex_lock(&philo->rigt->lock);
	if (atomic_load(&philo->stat->starve) > 0)
		return (safe_unlock(philo->left, philo->rigt), 2);
	state_message(philo->indx, "has taken a fork", philo);
	pthread_mutex_lock(&philo->meal_l);
	atomic_store(&philo->t_lastmeal, time_now());
	state_message(philo->indx, "is eating", philo);
	pthread_mutex_unlock(&philo->meal_l);
	state_usleep(philo->stat->t_teat, philo->stat);
	atomic_fetch_add(&philo->nmealsdone, 1);
	pthread_mutex_unlock(&philo->left->lock);
	pthread_mutex_unlock(&philo->rigt->lock);
	return (0);
}

void	*philo_est_odd(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo_syncstart(atomic_load(&philo->stat->tstart) + ODD_START_OFFSET);
	while (atomic_load(&philo->stat->starve) == 0 && (philo->nmealsdone
			< philo->stat->n_maxm || philo->stat->n_maxm == -1))
	{
		if (philo_est_odd_eat(philo) != 0)
			return (NULL);
		state_message(philo->indx, "is sleeping", philo);
		state_usleep(philo->stat->t_tslp, philo->stat);
		state_message(philo->indx, "is thinking", philo);
		state_usleep(smart_sleep(philo, SMART_SLEEP_TIMER), philo->stat);
	}
	return (NULL);
}

int	philo_est_even_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->rigt->lock);
	if (atomic_load(&philo->stat->starve) > 0)
		return (safe_unlock(NULL, philo->rigt), 1);
	state_message(philo->indx, "has taken a fork", philo);
	pthread_mutex_lock(&philo->left->lock);
	if (atomic_load(&philo->stat->starve) > 0)
		return (safe_unlock(philo->left, philo->rigt), 2);
	state_message(philo->indx, "has taken a fork", philo);
	pthread_mutex_lock(&philo->meal_l);
	atomic_store(&philo->t_lastmeal, time_now());
	state_message(philo->indx, "is eating", philo);
	pthread_mutex_unlock(&philo->meal_l);
	state_usleep(philo->stat->t_teat, philo->stat);
	atomic_fetch_add(&philo->nmealsdone, 1);
	pthread_mutex_unlock(&philo->rigt->lock);
	pthread_mutex_unlock(&philo->left->lock);
	return (0);
}

void	*philo_est_even(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo_syncstart(atomic_load(&philo->stat->tstart));
	while (atomic_load(&philo->stat->starve) == 0 && (philo->nmealsdone
			< philo->stat->n_maxm || philo->stat->n_maxm == -1))
	{
		if (philo_est_even_eat(philo) != 0)
			return (NULL);
		state_message(philo->indx, "is sleeping", philo);
		state_usleep(philo->stat->t_tslp, philo->stat);
		state_message(philo->indx, "is thinking", philo);
		state_usleep(smart_sleep(philo, SMART_SLEEP_TIMER), philo->stat);
	}
	return (NULL);
}
