/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:37:37 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/25 10:37:37 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	s_ra(t_ps_dlist **head)
{
	if (!head || !*head)
		return ;
	*head = (*head)->next;
	ps_dlist_update_lr(head);
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	s_rb(t_ps_dlist **head)
{
	if (!head || !*head)
		return ;
	*head = (*head)->next;
	ps_dlist_update_lr(head);
}

// rr : ra and rb at the same time.
void	s_rr(t_ps_dlist **heada, t_ps_dlist **headb)
{
	if (heada && *heada)
	{
		*heada = (*heada)->next;
		ps_dlist_update_lr(heada);
	}
	if (headb && *headb)
	{
		*headb = (*headb)->next;
		ps_dlist_update_lr(headb);
	}
}
