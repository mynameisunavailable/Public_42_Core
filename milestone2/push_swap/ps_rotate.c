/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 23:30:10 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/13 23:30:10 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_ps_dlist **head)
{
	s_ra(head);
	ft_putstr("ra\n");
}

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_ps_dlist **head)
{
	s_rb(head);
	ft_putstr("rb\n");
}

// rr : ra and rb at the same time.
void	rr(t_ps_dlist **heada, t_ps_dlist **headb)
{
	s_rr(heada, headb);
	ft_putstr("rr\n");
}
