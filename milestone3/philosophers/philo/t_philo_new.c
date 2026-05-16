/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 09:28:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/18 11:14:03 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*t_philo_new(int indx, t_stats *stats)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->phil = TRUE;
	new->indx = indx;
	new->t_lastmeal = 0;
	new->nmealsdone = 0;
	new->thrd = 0;
	if (pthread_mutex_init(&new->meal_l, NULL) != 0)
		return (ft_safefree((void **)&new), NULL);
	new->next = new;
	new->prev = new;
	new->left = NULL;
	new->rigt = NULL;
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
