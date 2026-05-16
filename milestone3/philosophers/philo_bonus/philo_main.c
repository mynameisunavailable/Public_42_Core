/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:43:10 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/18 13:02:40 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_completion(t_philo *philo)
{
	t_stats	*stats;

	stats = philo->stat;
	if (stats->n_maxm != -1 && atomic_load(&philo->nmealsdone) >= stats->n_maxm)
	{
		atomic_store(&stats->starve, -69);
		exit(1);
	}
}

int	create_philo_forks(t_philo *philo)
{
	t_philo	*head;

	head = philo;
	philo->stat->tstart = time_now() + 20000;
	while (TRUE)
	{
		atomic_store(&philo->t_lastmeal, philo->stat->tstart);
		philo->cpid = fork();
		if (philo->cpid == -1)
		{
			destroy_philo_forks(philo);
			ft_puterr("failed to create child fork()\n");
			return (1);
		}
		else if (philo->cpid == 0 && philo == philo->next)
			philo_est_single(philo);
		else if (philo->cpid == 0 && int_is_odd(philo->indx) == TRUE)
			philo_est_odd(philo);
		else if (philo->cpid == 0 && int_is_odd(philo->indx) == FALSE)
			philo_est_even(philo);
		philo = philo->next;
		if (philo == head)
			break ;
	}
	return (0);
}

int	run_sim(t_philo *philo, t_stats *stats)
{
	int	status;
	int	n_full;
	int	pid;

	if (create_philo_forks(philo) != 0)
		return (-1);
	n_full = 0;
	while (n_full < stats->n_phil)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
			break ;
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
			n_full++;
		else if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			break ;
		else if (WIFSIGNALED(status) == TRUE)
			break ;
	}
	destroy_philo_forks(philo);
	if (n_full >= stats->n_phil)
		state_message(-1, "All full 😸", philo);
	safe_close_semaphore(stats);
	unlink_semaphore();
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
		err = ft_puterr_no("Wrong number of arguments (invalid)", 1);
		return (err);
	}
	if (arguments_isvalid(argc, argv) == 1)
	{
		if (initialise_table(argc, argv, &philo, &stats) != 0)
			err = ft_puterr_no("Failed initalisation (invalid)", -1);
		else
			err = run_sim(philo, &stats);
	}
	else
		err = ft_puterr_no("Arguments invalid", 2);
	free_philo(philo);
	return (err);
}
