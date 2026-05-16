/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 09:28:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/19 22:04:07 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*t_philo_new(int indx, t_stats *stats)
{
	t_philo	*new;
	char	meal_l_name[36];

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->indx = indx;
	new->t_lastmeal = 0;
	new->nmealsdone = 0;
	atomic_store(&new->t_lastmeal, 0);
	atomic_store(&new->nmealsdone, 0);
	new->cpid = -1;
	ft_strcpy(meal_l_name, "/meal_l_");
	ft_itoa_fast(indx, meal_l_name + ft_strlen("/meal_l_"));
	new->meal_l = sem_open(meal_l_name, O_CREAT, 0644, 1);
	if (new->meal_l == SEM_FAILED)
		return (unlink_semaphore(), ft_safefree((void **)&new),
			ft_puterr("meal_l sem_open fail\n"), NULL);
	ft_strcpy(new->meal_l_name, meal_l_name);
	new->next = new;
	new->prev = new;
	new->stat = stats;
	return (new);
}

t_philo	*t_philo_pushnext(t_philo **head, int indx, t_stats *stats)
{
	t_philo	*new;
	t_philo	*temp;

	new = t_philo_new(indx, stats);
	if (!new)
		return (NULL);
	if (*head == NULL)
		*head = new;
	else
	{
		temp = (*head)->next;
		(*head)->next = new;
		new->next = temp;
		temp->prev = new;
		new->prev = *head;
	}
	return (*head);
}

t_philo	*t_philo_pushprev(t_philo **head, int indx, t_stats *stats)
{
	if (*head == NULL)
	{
		*head = t_philo_new(indx, stats);
		if (!*head)
			return (NULL);
	}
	else
	{
		if (t_philo_pushnext(&(*head)->prev, indx, stats) == NULL)
			return (NULL);
	}
	return (*head);
}
