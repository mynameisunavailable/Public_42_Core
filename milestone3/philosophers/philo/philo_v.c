/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:23:29 by yunguo            #+#    #+#             */
/*   Updated: 2026/01/07 23:23:29 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	int_is_odd(int n)
{
	if ((n & 1) == 1)
		return (TRUE);
	return (FALSE);
}

t_bool	all_full(t_philo *philo)
{
	t_philo	*philo_1;

	if (philo->stat->n_maxm == -1)
		return (FALSE);
	philo_1 = philo;
	while (TRUE)
	{
		if (philo->nmealsdone < philo->stat->n_maxm)
			return (FALSE);
		philo = philo->next;
		if (philo == philo_1)
			break ;
	}
	return (TRUE);
}
