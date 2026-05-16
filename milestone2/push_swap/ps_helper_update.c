/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:26:25 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/19 14:26:25 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_dlist_update_lr(t_ps_dlist **head)
{
	t_ps_dlist	*top;
	t_ps_dlist	*temp;
	int			l;

	if (!head || !*head)
		return ;
	top = *head;
	temp = *head;
	l = 0;
	temp->l = l;
	l++;
	temp = temp->next;
	while (temp != top)
	{
		temp->l = l++;
		temp = temp->next;
	}
	temp->r = l;
	l--;
	temp = temp->next;
	while (temp != top)
	{
		temp->r = l--;
		temp = temp->next;
	}
}

void	update_list_lista(t_ps_dlist *heada, t_ps_dlist *headb)
{
	ps_dlist_update_lr(&heada);
	ps_dlist_update_lr(&headb);
	ps_dlist_update_steptob(&heada, &headb);
}

void	update_list_listb(t_ps_dlist *heada, t_ps_dlist *headb)
{
	ps_dlist_update_lr(&heada);
	ps_dlist_update_lr(&headb);
	ps_dlist_update_steptoa(&headb, &heada);
}

void	sort_by_rank_b(t_ps_dlist **headb)
{
	t_ps_dlist	*curr;

	curr = *headb;
	while (curr->rank != 0)
	{
		curr = curr->next;
		if (curr == *headb)
			return ;
	}
	if (curr->l < curr->r)
	{
		while ((*headb)->prev->rank != 0)
			rb(headb);
	}
	else
	{
		while ((*headb)->prev->rank != 0)
			rrb(headb);
	}
}

void	sort_by_rank_a(t_ps_dlist **heada)
{
	t_ps_dlist	*curr;

	curr = *heada;
	while (curr->rank != 0)
	{
		curr = curr->next;
		if (curr == *heada)
			return ;
	}
	if (curr->l < curr->r)
	{
		while ((*heada)->rank != 0)
			ra(heada);
	}
	else
	{
		while ((*heada)->rank != 0)
			rra(heada);
	}
}
