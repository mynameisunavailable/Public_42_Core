/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper_update_steptoa.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:51:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/21 16:51:52 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
// 		min = ft_min(curr->l, curr->r);
// 		curr->steptob = min + 1;
// 		curr = curr->next;
// 		if (curr == top)
// 			break ;
// 	}
// }

static t_ps_dlist	*ft_min_rank(t_ps_dlist *min, t_ps_dlist *curr)
{
	if (min->rank <= curr->rank)
		return (min);
	return (curr);
}

static t_ps_dlist	*ps_dlist_find_ins_node_a(t_ps_dlist *a, t_ps_dlist *headb)
{
	t_ps_dlist	*curr;
	t_ps_dlist	*rslt;
	t_ps_dlist	*min;
	int			diff;

	curr = headb;
	rslt = NULL;
	min = curr;
	while (TRUE)
	{
		min = ft_min_rank(min, curr);
		diff = a->rank - curr->rank;
		if (diff < 0 && (!rslt || diff > a->rank - rslt->rank))
			rslt = curr;
		curr = curr->next;
		if (curr == headb)
			break ;
	}
	if (!rslt)
		return (min);
	return (rslt);
}

// int	ps_dlist_find_stepto_node(t_ps_dlist *a, t_ps_dlist *b)
// {
// 	int	totopa;
// 	int	min;

// 	totopa = ft_max(a->l, b->l);
// 	min = totopa;
// 	totopa = ft_max(a->r, b->r);
// 	min = ft_min(min, totopa);
// 	totopa = a->l + b->r;
// 	min = ft_min(min, totopa);
// 	totopa = a->r + b->l;
// 	min = ft_min(min, totopa);
// 	return (min + 1);
// }

void	ps_dlist_update_steptoa(t_ps_dlist **heada, t_ps_dlist **headb)
{
	t_ps_dlist	*tmpa;
	t_ps_dlist	*tmpb;
	t_ps_dlist	*topa;
	t_ps_dlist	*topb;

	if (!heada || !*heada)
		return ;
	if (!headb || !*headb)
	{
		ps_dlist_update_steptob_emptyb(heada);
		return ;
	}
	topa = *heada;
	tmpa = topa;
	topb = *headb;
	while (TRUE)
	{
		tmpb = ps_dlist_find_ins_node_a(tmpa, topb);
		tmpa->targetb = tmpb;
		tmpa->steptob = ps_dlist_find_stepto_node(tmpa, tmpb);
		tmpa = tmpa->next;
		if (tmpa == topa)
			break ;
	}
}
