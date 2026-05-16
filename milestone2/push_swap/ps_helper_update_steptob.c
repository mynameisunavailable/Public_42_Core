/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper_update_steptob.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:32:00 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/20 17:32:00 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_dlist_update_steptob_emptyb(t_ps_dlist **heada)
{
	t_ps_dlist	*curr;
	t_ps_dlist	*top;
	int			min;

	if (!heada || !*heada)
		return ;
	top = *heada;
	curr = top;
	while (TRUE)
	{
		min = ft_min(curr->l, curr->r);
		curr->steptob = min + 1;
		curr = curr->next;
		if (curr == top)
			break ;
	}
}
// void	ps_dlist_update_steptob_emptyb(t_ps_dlist **heada)
// {
// 	t_ps_dlist	*curr;
// 	t_ps_dlist	*top;
// 	int			min;

// 	if (!heada || !*heada)
// 		return ;
// 	top = *heada;
// 	curr = top;
// 	while (TRUE)
// 	{
// 		if (curr->lis == TRUE)
// 			curr->steptob = INT_MAX;
// 		else
// 		{
// 			min = ft_min(curr->l, curr->r);
// 			curr->steptob = min + 1;
// 		}
// 		curr = curr->next;
// 		if (curr == top)
// 			break ;
// 	}
// }

t_ps_dlist	*ft_max_rank(t_ps_dlist *max, t_ps_dlist *curr)
{
	if (max->rank >= curr->rank)
		return (max);
	return (curr);
}

t_ps_dlist	*ps_dlist_find_ins_node(t_ps_dlist *a, t_ps_dlist *headb)
{
	t_ps_dlist	*curr;
	t_ps_dlist	*rslt;
	t_ps_dlist	*max;
	int			diff;

	curr = headb;
	rslt = NULL;
	max = curr;
	while (TRUE)
	{
		max = ft_max_rank(max, curr);
		diff = a->rank - curr->rank;
		if (diff > 0 && (!rslt || diff < a->rank - rslt->rank))
			rslt = curr;
		curr = curr->next;
		if (curr == headb)
			break ;
	}
	if (!rslt)
		return (max);
	return (rslt);
}

int	ps_dlist_find_stepto_node(t_ps_dlist *a, t_ps_dlist *b)
{
	int	totopa;
	int	min;

	totopa = ft_max(a->l, b->l);
	min = totopa;
	totopa = ft_max(a->r, b->r);
	min = ft_min(min, totopa);
	totopa = a->l + b->r;
	min = ft_min(min, totopa);
	totopa = a->r + b->l;
	min = ft_min(min, totopa);
	return (min + 1);
}

void	ps_dlist_update_steptob(t_ps_dlist **heada, t_ps_dlist **headb)
{
	t_ps_dlist	*tmpa;
	t_ps_dlist	*tmpb;

	if (!heada || !*heada)
		return ;
	if (!headb || !*headb)
	{
		ps_dlist_update_steptob_emptyb(heada);
		return ;
	}
	tmpa = *heada;
	while (TRUE)
	{
		if (tmpa->lis == TRUE)
			tmpa->steptob = INT_MAX;
		else
		{
			tmpb = ps_dlist_find_ins_node(tmpa, *headb);
			tmpa->targetb = tmpb;
			tmpa->steptob = ps_dlist_find_stepto_node(tmpa, tmpb);
		}
		tmpa = tmpa->next;
		if (tmpa == *heada)
			break ;
	}
}
