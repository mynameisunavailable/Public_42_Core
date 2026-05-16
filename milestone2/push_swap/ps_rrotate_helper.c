/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrotate_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:37:23 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/25 10:37:23 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	s_rra(t_ps_dlist **head)
{
	if (!head || !*head)
		return ;
	*head = (*head)->prev;
	ps_dlist_update_lr(head);
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	s_rrb(t_ps_dlist **head)
{
	if (!head || !*head)
		return ;
	*head = (*head)->prev;
	ps_dlist_update_lr(head);
}

// rrr : rra and rrb at the same time.
void	s_rrr(t_ps_dlist **heada, t_ps_dlist **headb)
{
	if (heada && *heada)
	{
		*heada = (*heada)->prev;
		ps_dlist_update_lr(heada);
	}
	if (headb && *headb)
	{
		*headb = (*headb)->prev;
		ps_dlist_update_lr(headb);
	}
}
