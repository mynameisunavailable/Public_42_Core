/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 00:02:02 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/14 00:02:02 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_dlist	*ps_dlist_x(t_ps_dlist *a, t_ps_dlist *b)
{
	if (!a || !b)
		return (NULL);
	a->next = b->next;
	b->next->prev = a;
	b->next = a;
	b->prev = a->prev;
	a->prev->next = b;
	a->prev = b;
	return (b);
}

void	ps_dlist_insf(t_ps_dlist **head, t_ps_dlist *new)
{
	t_ps_dlist	*top;

	if (!new)
		return ;
	if (!head)
		return ;
	if (!*head)
	{
		new->next = new;
		new->prev = new;
		*head = new;
		return ;
	}
	top = *head;
	top->prev->next = new;
	new->next = top;
	new->prev = top->prev;
	top->prev = new;
	*head = new;
}

void	ps_dlist_inse(t_ps_dlist **head, t_ps_dlist *new)
{
	t_ps_dlist	*top;

	if (!new)
		return ;
	if (!head)
		return ;
	if (!*head)
	{
		new->next = new;
		new->prev = new;
		*head = new;
		return ;
	}
	top = *head;
	top->prev->next = new;
	new->next = top;
	new->prev = top->prev;
	top->prev = new;
}
