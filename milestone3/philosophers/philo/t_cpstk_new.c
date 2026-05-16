/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cpstk_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 09:54:57 by yunguo            #+#    #+#             */
/*   Updated: 2026/01/01 09:16:28 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_cpstk	*t_cpstk_new(int indx)
{
	t_cpstk	*new;

	new = malloc(sizeof(t_cpstk));
	if (!new)
		return (NULL);
	new->phil = FALSE;
	new->indx = indx;
	if (pthread_mutex_init(&new->lock, NULL) != 0)
		return (ft_safefree((void **)&new), NULL);
	new->next = NULL;
	new->prev = NULL;
	new->left = new;
	new->rigt = new;
	return (new);
}

t_philo	*t_cpstk_pushnext(t_philo **head, int indx)
{
	t_cpstk	*new;
	t_philo	*curr;

	if (*head == NULL)
		return (NULL);
	new = t_cpstk_new(indx);
	if (!new)
		return (NULL);
	curr = *head;
	curr->rigt = new;
	new->prev = curr;
	if (curr->left != NULL)
	{
		curr->left->rigt = new;
		new->left = curr->left;
	}
	curr->next->left = new;
	new->next = curr->next;
	if (curr->next->rigt != NULL)
	{
		curr->next->rigt->left = new;
		new->rigt = curr->next->rigt;
	}
	return (*head);
}

// t_philo	*t_cpstk_pushprev(t_philo **head, int indx)
// {
// 	if (*head == NULL)
// 		return (NULL);
// 	// new = t_cpstk_new(indx);
// 	// if (!new)
// 	// 	return (NULL);
// 	if (t_cpstk_pushnext(&(*head)->prev, indx) == NULL)
// 		return (NULL);
// 	return (*head);
// }

	// else if ((*head)->next->phil == TRUE)
	// {
	// 	t_cpstk_pushlast(head, 1);
	// 	t_philo_pushlast(head, indx);
	// 	t_cpstk_pushlast(head, 2);
	// }