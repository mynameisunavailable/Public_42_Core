/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safefree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:24:48 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/25 11:11:40 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_safefree(void **ptr)
{
	if (ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

void	safe_close_semaphore(t_stats *stats)
{
	if (stats->p_lock != SEM_FAILED && stats->p_lock != 0)
		sem_close(stats->p_lock);
	if (stats->ticket != SEM_FAILED && stats->ticket != 0)
		sem_close(stats->ticket);
	if (stats->cpstks != SEM_FAILED && stats->cpstks != 0)
		sem_close(stats->cpstks);
}

void	unlink_semaphore(void)
{
	sem_unlink("/p_lock");
	sem_unlink("/ticket");
	sem_unlink("/cpstks");
}

void	free_philo(t_philo *head)
{
	t_philo	*top;
	t_philo	*temp;

	if (!head)
		return ;
	top = head;
	head = head->next;
	while (head != top)
	{
		temp = head;
		if (temp->meal_l != SEM_FAILED && temp->meal_l != 0)
		{
			sem_close(temp->meal_l);
			sem_unlink(temp->meal_l_name);
		}
		head = head->next;
		ft_safefree((void **)&temp);
	}
	if (head->meal_l != SEM_FAILED && head->meal_l != 0)
	{
		sem_close(head->meal_l);
		sem_unlink(head->meal_l_name);
	}
	ft_safefree((void **)&head);
}

void	destroy_philo_forks(t_philo *philo)
{
	t_philo	*head;

	head = philo;
	while (TRUE)
	{
		if (philo->cpid > 0)
		{
			kill(philo->cpid, SIGKILL);
			waitpid(philo->cpid, NULL, 0);
		}
		philo = philo->next;
		if (head == philo)
			break ;
	}
}
