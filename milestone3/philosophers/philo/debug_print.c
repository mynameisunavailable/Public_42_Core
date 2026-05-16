/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:43:37 by yunguo            #+#    #+#             */
/*   Updated: 2026/01/07 23:44:19 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_philo *head)
{
	t_philo	*top;

	top = head;
	printf("philo list: ");
	if (head == head->next)
	{
		printf("%d\n", head->indx);
		return ;
	}
	while (TRUE)
	{
		printf("%d, ", head->indx);
		head = head->next;
		if (head->next == top)
			break ;
	}
	printf("%d\n", head->indx);
}

void	print_cpstk(t_cpstk *head)
{
	t_cpstk	*top;

	top = head;
	printf("cpstk list: ");
	if (head == head->rigt)
	{
		printf("%d\n", head->indx);
		return ;
	}
	while (TRUE)
	{
		printf("%d, ", head->indx);
		head = head->rigt;
		if (head->rigt == top)
			break ;
	}
	printf("%d\n", head->indx);
}

void	print_philocpstk(t_philo *head)
{
	t_philo	*top;

	top = head;
	printf("philocpstk list: ");
	if (head == head->next)
	{
		printf("%d\n", head->indx);
		return ;
	}
	while (TRUE)
	{
		printf("%d, ", head->indx);
		printf("%d; ", head->rigt->indx);
		head = head->next;
		if (head->next == top)
			break ;
	}
	printf("%d, ", head->indx);
	printf("%d\n", head->rigt->indx);
}
