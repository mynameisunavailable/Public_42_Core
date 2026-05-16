/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:21:45 by yunguo            #+#    #+#             */
/*   Updated: 2026/01/08 11:21:45 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arguments_isvalid(int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (ft_str_is_int(argv[i]) == 0)
			return (0);
		num = ft_atoi(argv[i]);
		if (num < 0)
			return (0);
		i++;
	}
	return (1);
}

int	philo_arg_isinvalid(char *arg)
{
	int	temp;

	temp = ft_atoi(arg);
	if (temp < 0)
		return (0);
	if (temp < 1)
		return (1);
	return (2);
}

int	init_t_stats(int argc, char **argv, t_stats *stats)
{
	if (philo_arg_isinvalid(argv[1]) < 2)
		return (ft_puterr_no("Invalid Philosopher number", 11));
	if (philo_arg_isinvalid(argv[2]) < 2)
		return (ft_puterr_no("Invalid time_to_die", 12));
	if (philo_arg_isinvalid(argv[3]) < 2)
		return (ft_puterr_no("Invalid time_to_eat", 13));
	if (philo_arg_isinvalid(argv[4]) == 0)
		return (ft_puterr_no("Invalid time_to_sleep", 14));
	if (argc == 6 && philo_arg_isinvalid(argv[5]) == 0)
		return (ft_puterr_no("Invalid number_each_philosopher_must_eat", 15));
	stats->n_phil = ft_atoi(argv[1]);
	stats->t_tdie = ft_atoi(argv[2]) * 1000;
	stats->t_teat = ft_atoi(argv[3]) * 1000;
	stats->t_tslp = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		stats->n_maxm = ft_atoi(argv[5]);
	else
		stats->n_maxm = -1;
	atomic_init(&stats->starve, FALSE);
	atomic_init(&stats->ploser, -1);
	atomic_init(&stats->tstart, 0);
	pthread_mutex_init(&stats->p_lock, NULL);
	return (0);
}

int	initialise_table(int argc, char **argv, t_philo **philo, t_stats *stats)
{
	int		i;
	t_philo	*check;
	t_philo	*temp;

	if (init_t_stats(argc, argv, stats) != 0)
		return (1);
	i = 0;
	while (++i <= stats->n_phil)
	{
		check = t_philo_pushprev(philo, i, stats);
		if (!check)
			return (free_philocpstk(*philo), 2);
	}
	i = 0;
	temp = *philo;
	while (++i <= stats->n_phil)
	{
		check = t_cpstk_pushnext(&temp, i);
		if (!check)
			return (free_philocpstk(*philo), 3);
		temp = temp->next;
	}
	return (0);
}
