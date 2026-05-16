/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 23:22:40 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/26 23:22:40 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state_message(int indx, char *msg, t_philo *philo)
{
	long long	ms;
	t_bool		full;

	pthread_mutex_lock(&philo->stat->p_lock);
	ms = time_now() - philo->stat->tstart;
	ms = ms / 1000;
	if (atomic_load(&philo->stat->starve) == 0)
	{
		full = all_full(philo);
		if (full == TRUE && indx == -1)
			printf("%s\n", msg);
		else if (full == FALSE)
			printf("%lld %d %s\n", ms, indx, msg);
	}
	pthread_mutex_unlock(&philo->stat->p_lock);
}

void	safe_unlock(t_cpstk *left, t_cpstk *rigt)
{
	if (left != NULL)
		pthread_mutex_unlock(&left->lock);
	if (rigt != NULL)
		pthread_mutex_unlock(&rigt->lock);
}

static void	check_starve(t_philo *philo, t_stats *stats)
{
	t_philo	*start;

	start = philo;
	while (TRUE)
	{
		pthread_mutex_lock(&philo->meal_l);
		if (stats->n_maxm != -1 && atomic_load(&philo->nmealsdone)
			>= stats->n_maxm)
			;
		else if (atomic_load(&philo->t_lastmeal) + stats->t_tdie <= time_now())
		{
			atomic_store(&stats->starve,
				(time_now() - atomic_load(&stats->tstart)));
			atomic_store(&stats->ploser, philo->indx);
			pthread_mutex_unlock(&philo->meal_l);
			break ;
		}
		pthread_mutex_unlock(&philo->meal_l);
		philo = philo->next;
		if (philo == start)
			break ;
	}
}

int	run_sim(t_philo *philo, t_stats *stats)
{
	if (create_philo_threads(philo) != 0)
		return (-1);
	while (atomic_load(&stats->starve) == 0 && all_full(philo) == FALSE)
	{
		usleep(500);
		check_starve(philo, stats);
	}
	if (all_full(philo) == TRUE)
		state_message(-1, "All full 😸", philo);
	else if (atomic_load(&stats->starve) > 0)
	{
		pthread_mutex_lock(&philo->stat->p_lock);
		printf("%lld %d died\n", atomic_load(&stats->starve) / 1000,
			atomic_load(&stats->ploser));
		pthread_mutex_unlock(&philo->stat->p_lock);
	}
	cleanup_philo_threads(philo);
	pthread_mutex_destroy(&stats->p_lock);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_stats	stats;
	int		err;

	err = 0;
	philo = NULL;
	if (argc != 5 && argc != 6)
	{
		err = ft_puterr_no("Wrong number of arguments (invalid)\n", 1);
		return (err);
	}
	if (arguments_isvalid(argc, argv) == 1)
	{
		if (initialise_table(argc, argv, &philo, &stats) != 0)
			err = ft_puterr_no("Failed initalisation (invalid)\n", -1);
		else
			err = run_sim(philo, &stats);
	}
	else
		err = ft_puterr_no("Arguments invalid\n", 2);
	free_philocpstk(philo);
	return (err);
}
