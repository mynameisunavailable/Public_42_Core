/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:10:06 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/21 00:10:06 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_dlist	*min_steptob(t_ps_dlist *head)
{
	t_ps_dlist	*min;
	t_ps_dlist	*cur;

	if (!head)
		return (NULL);
	cur = head;
	min = cur;
	while (TRUE)
	{
		if (min->steptob > cur->steptob)
			min = cur;
		cur = cur->next;
		if (cur == head)
			break ;
	}
	return (min);
}

t_ps_dlist	*init_list_rank(t_ps_dlist *head, int *s_stack, int argc)
{
	t_ps_dlist	*curr;

	curr = head;
	curr->rank = binary_search_sorted(curr->cont, s_stack, argc);
	curr = curr->next;
	while (curr != head)
	{
		curr->rank = binary_search_sorted(curr->cont, s_stack, argc);
		curr = curr->next;
	}
	return (head);
}

t_ps_dlist	*init_list(int *stack, int *s_stack, int argc)
{
	t_ps_dlist	*heada;
	t_ps_dlist	*end;
	int			i;

	i = 0;
	heada = ps_dlist_new(stack[i]);
	if (!heada)
		return (NULL);
	i++;
	while (i < argc)
	{
		end = ps_dlist_newend(&heada, stack[i]);
		if (!end)
			t_ps_dlist_clear(&heada);
		i++;
	}
	ps_dlist_update_lr(&heada);
	init_list_rank(heada, s_stack, argc);
	ps_dlist_update_steptob(&heada, NULL);
	return (heada);
}
