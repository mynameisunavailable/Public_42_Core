/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safefree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 17:24:48 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/19 11:22:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_safefree(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	free_philocpstk(t_philo *head)
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
		pthread_mutex_destroy(&temp->meal_l);
		head = head->next;
		if (temp->rigt != NULL)
			pthread_mutex_destroy(&temp->rigt->lock);
		ft_safefree((void **)&temp->rigt);
		ft_safefree((void **)&temp);
	}
	pthread_mutex_destroy(&head->meal_l);
	if (head->rigt != NULL)
		pthread_mutex_destroy(&head->rigt->lock);
	ft_safefree((void **)&head->rigt);
	ft_safefree((void **)&head);
}
