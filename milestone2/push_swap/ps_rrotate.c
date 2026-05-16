/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 07:42:57 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/14 07:42:57 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra(t_ps_dlist **head)
{
	s_rra(head);
	ft_putstr("rra\n");
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_ps_dlist **head)
{
	s_rrb(head);
	ft_putstr("rrb\n");
}

// rrr : rra and rrb at the same time.
void	rrr(t_ps_dlist **heada, t_ps_dlist **headb)
{
	s_rrr(heada, headb);
	ft_putstr("rrr\n");
}
